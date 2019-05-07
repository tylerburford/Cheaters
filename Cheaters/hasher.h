
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
        int fileInd;
        struct HashElement* next;
    };

    static const int SIZEOFMAP=100000;

public:
    HashMap();
   // ~HashMap();
    void add(int key, int fileInd);
    int hash(string hashee);
    struct colPair{
        int collisions;
        string file1;
        string file2;
    };
    vector<HashMap::colPair> fillArr(vector<string> files);
    friend bool operator<(const HashMap::colPair &lval,const HashMap::colPair &rval );
    friend bool operator>(const HashMap::colPair &lval, const HashMap::colPair &rval);
    HashElement* theMap[SIZEOFMAP];
};
