//
// Created by Barrett Stricklin on 2019-05-01.
//
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>
#include "helper.h"


using namespace std;
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void nSeq(vector<string> &files, int nWord, HashMap ourMap){


    int fileIndex=0;
    for(int f=2;f<files.size();f++) {
        ifstream inFile;
        string fileName="/Users/barrett/Xcode Projects/Cheaters/sm_doc_set/";
        fileName+=files[f];
        cout<<files[f];
        inFile.open(fileName);
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        //file opened

        string s;
        vector<string> words = vector<string>();
        while (inFile) {
            inFile >> s;
            for (int i = 0; i < s.length(); i++) {
                if (isalnum(s[i]) == 0)
                    s.erase(i, 1);
            }
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            words.push_back(s);
        }

        for (int i = 0; i < words.size(); i++) {
            string seq="";
            for (int j = i; j < i + nWord; j++) {
                cout << words[j] + " ";
                seq+=words[j];
            }
            ourMap.add(ourMap.hash(seq),files[f]);
            cout<< ourMap.hash(seq);
        }
        cout << "\n";
    }
}