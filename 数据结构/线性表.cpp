//
//  main.cpp
//  Data_Structure
//
//  Created by ChuangLiu on 2018/12/23.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

#define MaxSize 20
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//初始化
void InitList(SqList *L){
    (*L).length = 0;
}

//使用地址获取一个元素
//直接用地址保存查找值
int GetElem(SqList L,int i,ElemType *e){
    if(L.length == 0 || i<1 || i>L.length){
        return 0;
    }
    *e = L.data[i-1];
    return 1;
}

//在第i个位置插入一个元素
int ListInsert(SqList *L, int i, ElemType e){
    //插入判满
    if (L->length == MaxSize){
        return 0;
    }
    if (i < 1 || i > L->length+1){//最后一个不能和插入的元素有间隔
        return 0;
    }
    if (i <= L->length){
        for (int k = L->length-1 ; k>=i-1 ; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length ++;
    return 1;
}

//删除第i个元素
int ListDelete(SqList *L, int i, ElemType *e){
    if (i<1 || i> L->length+1){
        return 0;
    }
    //删除判空
    if (L->length == 0)
    {
        return 0;
    }
    *e = L->data[i-1];
    //删除的不是最后一个，则需要移动
    if (i < L->length){
        for (int j = i-1 ; j < L->length-1 ; j++){
            L->data[j] = L->data[j+1];
        }
    }
    L->length--;
    return 1;
}


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    SqList L;
    InitList(&L);
    std::cout<<L.length<<"\n";
    ListInsert(&L,1,3);
    int a;
    if (GetElem(L,1,&a)){
        std::cout<<a<<"\n";
    }
    return 0;
}
