#ifndef CHEATERS_HELPER_H
#define CHEATERS_HELPER_H
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>
#include <stdlib.h>
#include "hasher.h"
#include <algorithm>

using namespace std;

int getdir (string dir, vector<string> &files);

void nSeq (vector<string> &files, int nWord, HashMap ourMap, string filePath);







#endif //CHEATERS_HELPER_H

