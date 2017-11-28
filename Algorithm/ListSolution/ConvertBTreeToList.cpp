//
// Created by root on 11/28/17.
//
#include "ListNode.h"
#include "../TreeSolution/TreeNode.h"

void DoConvert(BTreeNode *pRoot, BTreeNode **pLastNodeInList);

template<typename T>
BTreeNode *ConvertBTreeToList(BTreeNode *pRoot) {
    if (pRoot == nullptr) {
        return pRoot;
    }

    BTreeNode *pLastNodeInList = nullptr;
    DoConvert(pRoot, &pLastNodeInList);
    BTreeNode *pHead = pLastNodeInList;
    while(pHead->m_pLeft) {
        pHead = pHead->m_pLeft;
    }
    return pHead;
}

void DoConvert(BTreeNode *pRoot, BTreeNode **pLastNodeInList) {
    if (pRoot == nullptr) {
        return;
    }

    BTreeNode* pCurrent = pRoot;
    if (pRoot->m_pLeft) {
        DoConvert(pRoot->m_pLeft, pLastNodeInList);
    }

    pCurrent->m_pLeft = *pLastNodeInList;

    if ((*pLastNodeInList) != nullptr) {
        pCurrent->m_pRight = *pLastNodeInList;
    }

    *pLastNodeInList = pCurrent;
    if (pRoot->m_pRight) {
        DoConvert(pRoot->m_pRight, pLastNodeInList);
    }
}
