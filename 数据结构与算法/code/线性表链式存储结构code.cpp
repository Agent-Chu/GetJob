//
//  main.cpp
//  Code
//
//  Created by ChuangLiu.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode * initList(int value){
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;
    
    return pNode;
}

void AddtoTail(ListNode **pHead, int value){
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;
    
    if (*pHead == nullptr){
        *pHead = pNew;
    }
    else{
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode **pHead, int value){
    if (*pHead == nullptr || pHead == nullptr){
        //如果传入为空，或者链表为空
        return ;
    }
    
    ListNode* pDeleted = nullptr;//被删除标记
    if((*pHead)->m_nValue==value){//需要删的是第一个头结点
        pDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else{
        ListNode *pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value){//找
            pNode = pNode->m_pNext;
        }
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value){//删，断开链
            pDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pDeleted != nullptr){
        delete pDeleted;
        pDeleted = nullptr;
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    
    printf("\nPrintList ends.\n");
}

int main(int argc, const char * argv[]) {
    int length = 0;
    ListNode* pNode = initList(1);
    AddtoTail(&pNode,7);//取指针变量的指针，就能把指针变量传进去
    length++;
    PrintList(pNode);
    RemoveNode(&pNode,1);
    PrintList(pNode);
    return 0;
}
