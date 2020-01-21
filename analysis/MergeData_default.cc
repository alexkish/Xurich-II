/*

  This macro will add histograms from a list of root files and write them
  to a target root file. The target file is newly created and must not be
  identical to one of the source files.

  Author: Sven A. Schmidt, sven.schmidt@cern.ch
  Date:   13.2.2001

  This code is based on the hadd.C example by Rene Brun and Dirk Geppert,
  which had a problem with directories more than one level deep.
  (see macro hadd_old.C for this previous implementation).
  
  The macro from Sven has been enhanced by 
     Anne-Sylvie Nicollerat <Anne-Sylvie.Nicollerat@cern.ch>
   to automatically add Trees (via a chain of trees).
  
  Further "enhanced" by S. Dasu <dasu@hep.wisc.edu>
  
  NB: This macro was provided as a tutorial.
      Used to be $ROOTSYS/bin/hadd to merge many histogram files
      Modified now to take directory with root files as an argument

*/

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <string.h>
#include "TSystem.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1.h"
#include "TTree.h"
#include "TKey.h"
#include "Riostream.h"

TFile *Target = NULL;
TFile *FirstSource = NULL;
bool InitializedMergeObjects = false;
TMap MergeObjects;
TMap MergeChains;


void MergeRootfile( TDirectory *target, TString source_name );

void MergeData_default(const char* outputFile, const char* inputFilesDirectory) {
  // In an interactive ROOT session
  // Do the following
  // root > .L mergeFiles.C
  // root > mergeFiles("<outputFile>", "<inputFilesDirectory>")

  Target = TFile::Open(outputFile, "RECREATE");

  if(strncmp(inputFilesDirectory,"list-in-file:",13)==0) {
	  // Read input file list from a file
	  char const *list_in_file = inputFilesDirectory+13;
	  FILE *fp = fopen(list_in_file,"r");
	  if( !fp ) {
		  int the_errno = errno;
		  cerr << "Failed to open " << list_in_file << ": errno=" << the_errno << " " << strerror(errno) << endl;
		  return;
	  }
	  char fname[2048];
	  while( fgets(fname,sizeof(fname),fp)!=NULL ) {
		  char *newline = strchr(fname,'\n');
		  if( newline ) *newline = '\0';
		  if( !fname[0] ) continue;

          cout << "Merging root file: " << fname << endl;
          MergeRootfile( Target, fname );
	  }
	  fclose(fp);
  }
  else {
	void* dirp = gSystem->OpenDirectory(inputFilesDirectory);
	const char *entry = gSystem->GetDirEntry(dirp);
	while(entry != 0)
	{
		int len = strlen(entry);
		if(len >= 5 && strcmp(&entry[len - 5], ".root") == 0)
		{
			TString fileName;
			if(strncmp(inputFilesDirectory, "/pnfs", 5) == 0)
			{
				fileName = "dcap://";
            }
			fileName += inputFilesDirectory;
			if( !fileName.EndsWith("/") ) fileName += "/";
			fileName += entry;

			cout << "Merging root file: " << fileName << endl;
			MergeRootfile( Target, fileName );
        }
		entry = gSystem->GetDirEntry(dirp);
    }
  }

  // save modifications to target file
  WriteMergeObjects( Target );

  delete Target;
  Target = NULL;
}

void SplitPathName(TString pathname,TString *path,TString *name) {
    int slash = pathname.Last('/');
    *path = pathname(0,slash);
    *name = pathname(slash+1,pathname.Length()-slash-1);
}

void WriteMergeObjects( TFile *target ) {
  cout << "Writing the merged data." << endl;

  TIterator *nextobj = MergeObjects.MakeIterator();
  TObjString *pathname_obj;
  while( (pathname_obj = (TObjString *)nextobj->Next()) ) {
    TString path,name;
    SplitPathName(pathname_obj->String(),&path,&name);

    TObject *obj = MergeObjects.GetValue(pathname_obj);
    target->cd(path);

    obj->Write( name );

    delete obj;
  }
  MergeObjects.Clear();

  target->Write();

  // Temporarily let multiple root files remain if > 2GB
  // Prevent Target_1.root Target_2.root, ... from happening.
  //  long long max_tree_size = 200000000000LL; // 200 GB
  //  if(TTree::GetMaxTreeSize() < max_tree_size ) {
  //    TTree::SetMaxTreeSize(max_tree_size);
  //  }

  nextobj = MergeChains.MakeIterator();
  TObjString *pathname_obj;
  while( (pathname_obj = (TObjString *)nextobj->Next()) ) {
    TString path,name;
    SplitPathName(pathname_obj->String(),&path,&name);

    TChain *ch = (TChain *)MergeChains.GetValue(pathname_obj);
    target->cd(path);
    ch->Merge(target,0,"KEEP");

    delete ch;

	// in case of multiple objects with same pathname, must remove
	// this one from the list so we don't get the same (deleted)
	// one next time we look up the same name
	MergeChains.Remove(pathname_obj);
  }
  MergeChains.Clear();

  InitializedMergeObjects = false;
}

void InitMergeObjects( TDirectory *target, TFile *source ) {
  TString path( (char*)strstr( target->GetPath(), ":" ) );
  path.Remove( 0, 1 );

  source->cd( path );
  TDirectory *current_sourcedir = gDirectory;

  // loop over all keys in this directory
  TIter nextkey( current_sourcedir->GetListOfKeys() );
  TKey *key;
  while ( (key = (TKey*)nextkey())) {

    // read object from source file
    source->cd( path );
    TObject *obj = key->ReadObj();

    const char* obj_name= obj->GetName();
    TString pathname = path + TString("/") + key->GetName();

    if ( obj->IsA()->InheritsFrom( "TH1" ) ) {
      target->cd( path );
      TObject *h2 = obj->Clone();
      MergeObjects.Add(new TObjString(pathname),h2);
    }
    else if ( obj->IsA()->InheritsFrom( "TTree" ) ) {
        //TChain *ch = new TChain(obj_name); // Not quite right. Mike Anderson Julyl 1 2008
        TChain *ch = new TChain(pathname);
        MergeChains.Add(new TObjString(pathname),ch);

        ch->Add(source->GetName());

    } else if ( obj->IsA()->InheritsFrom( "TDirectory" ) ) {
      // it's a subdirectory

      cout << "Found subdirectory " << obj->GetName() << endl;

      // create a new subdir of same name and title in the target file
      target->cd();
      TDirectory *newdir = target->mkdir( obj->GetName(), obj->GetTitle() );

      // newdir is now the starting point of another round of merging
      // newdir still knows its depth within the target file via
      // GetPath(), so we can still figure out where we are in the recursion
      InitMergeObjects( newdir, source );

    } else {

      // object is of no type that we know or can handle
      cout << "Unknown object type, name: " 
           << obj->GetName() << " title: " << obj->GetTitle() << endl;
    }

  } // while ( ( TKey *key = (TKey*)nextkey() ) )
}

void MergeRootfile( TDirectory *target, TString source_name ) {

  TFile *source = NULL;
  if( !InitializedMergeObjects ) {
    InitializedMergeObjects = true;
    source = TFile::Open(source_name);
    cout << "Initializing merge objects from " << source_name << endl;
    InitMergeObjects( target, source );
    delete source;
    return;
  }

  // loop over all objects to be merged
  TIterator *nextobj = MergeObjects.MakeIterator();
  TObjString *pathname_obj;
  while( (pathname_obj = (TObjString *)nextobj->Next()) ) {
    TString path,name;
    SplitPathName(pathname_obj->String(),&path,&name);

    TObject *obj = MergeObjects.GetValue(pathname_obj);

    if ( obj->IsA()->InheritsFrom( "TH1" ) ) {
      // descendant of TH1 -> merge it

      TH1 *h1 = (TH1*)obj;

      if( !source ) {
        source = TFile::Open(source_name);
      }
      // make sure we are at the correct directory level by cd'ing to path
      source->cd( path );
      TH1 *h2 = (TH1*)gDirectory->Get( h1->GetName() );
      if ( h2 ) {
        h1->Add( h2 );
        delete h2;
      }
    }
  }

  delete nextobj;
  nextobj = NULL;

  // loop over all chains to be merged
  nextobj = MergeChains.MakeIterator();
  TObjString *pathname_obj;
  while( (pathname_obj = (TObjString *)nextobj->Next()) ) {
    TString path,name;
    SplitPathName(pathname_obj->String(),&path,&name);

    TChain *ch = (TChain *)MergeChains.GetValue(pathname_obj);

    ch->Add(source_name);
  }

  delete nextobj;
  nextobj = NULL;

  if( source ) {
    delete source;
  }
}
