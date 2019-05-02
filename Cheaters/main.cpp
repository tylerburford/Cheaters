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

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }

    ifstream inFile;
    inFile.open("/Users/barrett/Xcode Projects/Cheaters/sm_doc_set/abf70402.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string s;
    vector<string> words = vector<string>();
    while (inFile) {
        inFile >> s;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])==0)
                s.erase(i,1);
        }
        words.push_back(s);
    }
    for(int i=0; i<words.size();i++){
        cout << words[i] + " ";
    }

    return 0;
}
