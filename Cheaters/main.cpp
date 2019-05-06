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
    int nWord=4;

    nSeq(files, nWord);

    return 0;
}
