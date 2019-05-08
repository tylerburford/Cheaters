#include <vector>
#include <string>
#include "hasher.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
HashMap::HashMap(){
    for (int i = 0; i < SIZEOFMAP; i++) {
        HashElement *tmp=new HashElement();
        tmp->key = -1;
        tmp->fileInd =-1;
        tmp->next = NULL;
        theMap[i]=tmp;
    }
}
//default destructor
HashMap::~HashMap()=default;

//adds hash elements to hash map
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
    //detects collisions from hashmap and puts them into 2d array
vector<HashMap::colPair> HashMap::fillArr(vector<string> files){
    int fileSize = files.size();
    int** comparisons = new int*[fileSize];
    for(int i = 0; i < fileSize; ++i)
        comparisons[i] = new int[fileSize];
    for(int h=0;h<fileSize;h++){
        for(int r=0;r<fileSize;r++) {
            comparisons[h][r]=0;
        }
    }
    //2d array has been initialized
    HashElement *ptr;
    for(int i=0;i<SIZEOFMAP;i++){
        if(theMap[i]!= NULL){   //check if there are any collisions
            vector<int> coll;   //if so, go to the end of the linked list and attach the collision there
            ptr = theMap[i];
            while (ptr!= NULL) {
                coll.push_back(ptr->fileInd);
                ptr = ptr->next;
            }
            if(coll.size() > 1){
                for (int j = 0; j < coll.size(); j++) {
                    for (int k = j + 1; k < coll.size(); k++) {
                        comparisons[coll[j]][coll[k]]++;
                        comparisons[coll[k]][coll[j]]++;
                    }
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
        }
    }
    return results;
}

int HashMap::hash(string hashee){   //hashing function
    unsigned long result=0;
    for(int i=0;i<hashee.length();i++){
        result+=((long)hashee[i]* (long)pow(3,i));
    }
    return result % 100000;

}

//overloaded operator for use in sorting function
bool operator<(const HashMap::colPair &lval,const HashMap::colPair &rval ){
    if(lval.collisions<rval.collisions)
        return true;
    else
        return false;
}

//overloaded operator for use in sorting function
bool operator>(const HashMap::colPair &lval,const HashMap::colPair &rval ){
    if(lval.collisions>rval.collisions)
        return true;
    else
        return false;
}