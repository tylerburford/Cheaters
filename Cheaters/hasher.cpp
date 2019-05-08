#include <vector>
#include <string>
#include "hasher.h"
#include <iostream>
#include <cmath>
using namespace std;

HashMap::HashMap() {
    for (int i = 0; i < SIZEOFMAP; i++) {
        HashElement *tmp=new HashElement();
        tmp->key = -1;
        tmp->fileInd =-1;
        tmp->next = NULL;
        theMap[i]=tmp;
    }
}
HashMap::~HashMap()=default;

void HashMap::add(int key, int fileInd){
    HashElement *tba=new HashElement;
    tba->key=key;
    tba->fileInd=fileInd;
    if(theMap[key]->key==-1) {
        theMap[key]->key=key;
        theMap[key]->fileInd=fileInd;
    }
    else if(fileInd!=theMap[key]->fileInd){
        HashElement *search= new HashElement;
        search = theMap[key];
        while(search->next!=NULL) {
            search = search->next;
        }
        HashElement *temp=new HashElement;
        temp->key=key;
        temp->fileInd=fileInd;
        temp->next=NULL;
        search->next=temp;
    }
}
vector<HashMap::colPair> HashMap::fillArr(vector<string> files) {
    int fileSize = files.size();
    int** comparisons = new int*[fileSize];
    for(int i = 0; i < fileSize; ++i)
        comparisons[i] = new int[fileSize];
    for(int h=0;h<fileSize;h++){
        for(int r=0;r<fileSize;r++) {
            comparisons[h][r]=0;
        }
        }
    HashElement *ptr;
    for(int i=0;i<SIZEOFMAP;i++){
        if(theMap[i]!= NULL){
            vector<int> coll;
            ptr = theMap[i];
            while (ptr!= NULL) {
                coll.push_back(ptr->fileInd);
                ptr = ptr->next;
            }
            if(coll.size() > 1)
                for(int j=0;j<coll.size();j++){
                    for(int k=j+1;k<coll.size();k++){
                        comparisons[coll[j]][coll[k]]++;
                        comparisons[coll[k]][coll[j]]++;
                    }
                }
        }
    }
    vector<colPair> results;
    results.push_back(colPair());
    results.clear();
    for(int i=0;i<fileSize;i++){
        for(int j=i+1;j<fileSize;j++){
            colPair *current=new colPair;
            current->collisions=comparisons[i][j];
            current->file1=files[i];
            current->file2=files[j];
            results.push_back(*current);
            //cout << "Collisions between "<< files[i] << " and " << files[j] << ": "<<comparisons[i][j] << "\n ";
        }//cout << "\n";
    }
    return results;
}

int HashMap::hash(string hashee){
    unsigned long result=0;
    for(int i=0;i<hashee.length();i++){
        result+=((long)hashee[i]* (long)pow(3,i));
    }
    return result % 100000;

}

bool operator<(const HashMap::colPair &lval,const HashMap::colPair &rval ){
    if(lval.collisions<rval.collisions)
        return true;
    else
        return false;
}
bool operator>(const HashMap::colPair &lval,const HashMap::colPair &rval ){
    if(lval.collisions>rval.collisions)
        return true;
    else
        return false;
}