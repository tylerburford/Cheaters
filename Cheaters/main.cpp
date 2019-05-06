#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <fstream>
#include "helper.h"
#include <locale>


using namespace std;
int main() {
    string dir = string("/Users/barrett/Xcode Projects/Cheaters/sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    int nWord=4;
    HashMap ourMap;
    nSeq(files, nWord, ourMap);
    //everything is hashed
    


    return 0;
}
