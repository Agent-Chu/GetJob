//
//  main.cpp
//  Code
//
//  Created by ChuangLiu.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

#define MaxSize 1000

typedef struct{
    int data;
    int next;
} Component,StaticLinkList[MaxSize];

//初始化
bool InitList(StaticLinkList space){
    int i;
    for (i=0;i<MaxSize-1;i++){
        space[i].next = i+1;
    }
    space[MaxSize-1].next = 0;
    return true;
}

//插入需要设计一个函数模拟malloc，用于返回第一个空闲的下表，并且更新数组[0]的next
int mallocStaticLinkList(StaticLinkList space){
    int i = space[0].next;
    
    if(space[0].next){
        space[0].next = space[i].next;
    }
    
    return i;
}

int LengthList(StaticLinkList L){
    int i = 0;
    int first = L[MaxSize-1].next;
    while(first){
        first = L[first].next;
        i++;
    }
    return i;
}

//让e成为第i个元素
bool ListInsert(StaticLinkList L, int i, int e){
    if(i<1 || i>LengthList(L)+1 ){
        return false;
    }
    int freeblock = mallocStaticLinkList(L);
    if(freeblock){
        L[freeblock].data = e;
        
        int insertblock = MaxSize-1;
        
        for(int j=1 ; j<=i-1 ; j++){
            insertblock = L[insertblock].next;
        }
        L[freeblock].next = L[insertblock].next;
        L[insertblock].next = freeblock;
    }
    return false;
}

void freeStaticLinkList(StaticLinkList space, int i){
    space[i].next = space[0].next;
    space[0].next = i;
}

bool deleteList(StaticLinkList L, int i){
    if(i<1 || i>LengthList(L)+1 ){
        return false;
    }
    int deleteblock = MaxSize-1;
    
    for(int j=1 ; j<=i-1 ; j++){
        deleteblock = L[deleteblock].next;
    }
    int j = L[deleteblock].next;
    
    L[deleteblock].next = L[j].next;
    
    freeStaticLinkList(L,j);
    return true;
}

int main(int argc, const char * argv[]) {
    StaticLinkList space;
    if (InitList(space)){
        cout<<"yes\n";
    }
    return 0;
}
