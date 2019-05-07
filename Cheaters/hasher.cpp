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
void HashMap::fillArr(vector<string> files) {
    int fileSize = files.size();
    int comparisons[25][25]; //TODO: fix weird issue with wrong 2d array size when using fileSize
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
    cout << "begingging of table";
    for(int i=0;i<fileSize;i++){
        for(int j=i+1;j<fileSize;j++){
            cout << "Collisions between "<< files[i] << " and " << files[j] << ": "<<comparisons[i][j] << "\n ";
        }cout << "\n";
    }
}

int HashMap::hash(string hashee){
    unsigned long result=0;
    for(int i=0;i<hashee.length();i++){
        result+=((long)hashee[i]* (long)pow(3,i));
    }
    return result % 100000;

}