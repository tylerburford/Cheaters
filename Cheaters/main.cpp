#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <fstream>
#include "helper.h"
#include <locale>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
    string filePath=string(argv[1]);    //set variables from command line arguements
    string dir = string(filePath);
    vector<string> files = vector<string>();
    getdir(dir,files);          //helper function to open the directory
    files.erase(files.begin(), files.begin()+2);    //erase "." and ".."
    int nWord=atoi(argv[2]);
    int limit=atoi(argv[3]);
    HashMap ourMap;
    nSeq(files, nWord, ourMap, filePath);    //busiest function; fills a vector with n-word sequences, then outputs that vector into a 2d array
    //everything is hashed
    vector<HashMap::colPair> final=ourMap.fillArr(files);
    ourMap.~HashMap();
    sort(final.rbegin(), final.rend());
    for(vector<HashMap::colPair>::iterator it=final.begin();it!=final.end();it++){
        if(it->collisions>limit)
            cout << it->collisions << ": "<<it->file1<<" and " << it->file2<<endl;
    }
    return 0;
}
