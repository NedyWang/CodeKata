//
// Created by root on 11/28/17.
//

#include "ListUtility.h"

ListNode* MergeTwoSortedList(ListNode * pHead_1, ListNode * pHead_2)
{
    if (!pHead_1) {
        return pHead_2;
    }

    if (!pHead_2) {
        return pHead_1;
    }

    ListNode * pHead = nullptr, *pNode = nullptr;
    while(pHead_1 && pHead_2) {
        ListNode *pNext = nullptr;
        if (pHead_1->m_value <= pHead_2->m_value) {
            pNext = pHead_1;
            pHead_1 = pHead_1->next;
        } else {
            pNext = pHead_2;
            pHead_2 = pHead_2->next;
        }
        if (pNode == nullptr) {
            pNode = pNext;
            pHead = pNext;
        } else {
            pNode->next = pNext;
            pNode = pNode->next;
        }
    }

    while (pHead_1) {
        pNode->next = pHead_1;
        pNode = pNode->next;
        pHead_1 = pHead_1->next;
    }

    while (pHead_2) {
        pNode->next = pHead_2;
        pNode = pNode->next;
        pHead_2 = pHead_2->next;
    }

    return pHead;
}


void unitTestMerge2SortedList()
{
    int data_1[] = {0, 2, 4, 6, 8};
    std::vector<int> list_data_1(data_1, data_1 + sizeof(data_1) / sizeof(data_1[0]));

    int data_2[] = {1, 3, 5, 7, 9};
    std::vector<int> list_data_2(data_2, data_2 + sizeof(data_2) / sizeof(data_2[0]));

    ListNode * pHead_1 = BuildList(list_data_1);
    ListNode * pHead_2 = BuildList(list_data_2);
    ListNode * pHead = MergeTwoSortedList(pHead_1, pHead_2);

    PrintList(pHead);
    DestroyList(pHead);
}
