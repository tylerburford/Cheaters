//
// Created by Barrett Stricklin on 2019-05-05.
//

#ifndef CHEATERS_HASHER_H
#define CHEATERS_HASHER_H

#endif //CHEATERS_HASHER_H

#include <vector>
#include <string>

using namespace std;

class HashMap
{
    struct HashElement{
        int key;
        string fileName;
        struct HashElement* next;
    };
    static const int SIZEOFMAP=100000;

public:
    HashMap();
   // ~HashMap();
    void add(int key, string fileName);
    int hash(string hashee);

private:
    HashElement* theMap[SIZEOFMAP];
};
