//
// Created by Barrett Stricklin on 2019-05-05.
//

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
        tmp->fileName = "";
        tmp->next = NULL;
        theMap[i]=tmp;
    }
}
void HashMap::add(int key, string fileName){
    HashElement *tba=new HashElement;
    tba->key=key;
    tba->fileName=fileName;
    if(key==9601)
        cout << "found";
    if(theMap[key]->key==-1) {
        theMap[key]->key=key;
        theMap[key]->fileName=fileName;
    }
    else if(fileName!=theMap[key]->fileName){
        HashElement *search= new HashElement;
        search = theMap[key];
        while(search->next!=NULL) {
            search = search->next;
        }
        HashElement *temp=new HashElement;
        temp->key=key;
        temp->fileName=fileName;
        temp->next=NULL;
        search->next=temp;
    }
}

int HashMap::hash(string hashee){
    unsigned long result=0;
    for(int i=0;i<hashee.length();i++){
        result+=((long)hashee[i]* (long)pow(3,i));
    }
    return result % 100000;

}