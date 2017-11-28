//
// Created by root on 11/28/17.
//

#include "ListUtility.h"

void ReverseList(ListNode ** pHead)
{
    if (*pHead == nullptr || (*pHead)->next == nullptr) {
        return;
    }

    ListNode * pNode = *pHead;
    ListNode * pNext = (*pHead)->next;
    pNode->next = nullptr;

    while(pNext) {
        ListNode * pTmp = pNext->next;
        if (pTmp == nullptr) {
            *pHead = pNext;
        }
        pNext->next = pNode;
        pNode = pNext;
        pNext = pTmp;
    }
}

void unitTestReverseList()
{
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> list_data_1(data, data + sizeof(data) / sizeof(data[0]));
    ListNode *pHead = BuildList(list_data_1);
    ReverseList(&pHead);
    PrintList(pHead);
    DestroyList(pHead);
}
