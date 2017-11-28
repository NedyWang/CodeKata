//
// Created by root on 11/28/17.
//

#include <iostream>
#include <vector>
#include "ListNode.h"


ListNode* BuildList(std::vector<int> &data)
{
    ListNode * pHead = nullptr;
    ListNode * pNode = nullptr;
    for (auto x: data) {
        auto pNext = new ListNode(x);
        if (pHead == nullptr) {
            pHead = pNext;
            pNode = pNext;
            continue;
        }
        pNode->next = pNext;
        pNode = pNode->next;
    }
    return pHead;
}

void DestroyList(ListNode *pHead)
{
    while(pHead) {
        ListNode * pNode = pHead;
        pHead = pHead->next;
        delete pNode;
    }
}

void PrintList(ListNode *pHead)
{
    while(pHead) {
        std::cout << pHead->m_value << " ";
        pHead = pHead->next;
    }
    std::cout << std::endl;
}
