#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>
#include "helper.h"
#include <stdlib.h>
#include <algorithm>
using namespace std;

//function to get directory and open files
int getdir (string dir, vector<string> &files){
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL)
        files.push_back(string(dirp->d_name));
    closedir(dp);
    return 0;
}

//generates n-word sequences
void nSeq(vector<string> &files, int nWord, HashMap ourMap, string filePath){
    int fileIndex=0;
    for(int f=0;f<files.size();f++) {
        ifstream inFile;
        string fileName=filePath;
        fileName+="/"+files[f];
        inFile.open(fileName);
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        //file is opened
        string s;
        vector<string> words = vector<string>();
        while(inFile) {     //move words from the file into words
            inFile >> s;
            s.erase(remove(s.begin(), s.end(), '\n'), s.end());
            for (int i = 0; i < s.length(); i++) {
                if (isalnum(s[i]) == 0  ){
                    s.erase(i, 1);
                    i--;}
            }
            transform(s.begin(), s.end(), s.begin(), ::tolower);    //makes everything lowercase for more accurate comparisons
            words.push_back(s);
        }
        //Words from the file we are on have been sanitized and pushed into the vector "words"
        for (int i = 0; i < words.size(); i++) {
            string *seq=new string;
            for (int j = i; j < (i + nWord) && j< (words.size()); j++) {
                *seq+=string(words[j]);
            }
            ourMap.add(ourMap.hash(*seq),f);    //adds the n-sequence words to a 2d array that compares
            delete seq;
        }
    }
}

