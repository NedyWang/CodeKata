//
// Created by root on 11/28/17.
//
#include "ListNode.h"
#include "../TreeSolution/TreeNode.h"

void DoConvert(BTreeNode *pNode, BTreeNode **pLastNodeInList);

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

void DoConvert(BTreeNode *pNode, BTreeNode **pLastNodeInList) {
    if (pNode == nullptr) {
        return;
    }

    BTreeNode* pCurrent = pNode;
    if (pNode->m_pLeft) {
        DoConvert(pNode->m_pLeft, pLastNodeInList);
    }

    pCurrent->m_pLeft = *pLastNodeInList;

    if ((*pLastNodeInList) != nullptr) {
        pCurrent->m_pRight = *pLastNodeInList;
    }

    *pLastNodeInList = pCurrent;
    if (pNode->m_pRight) {
        DoConvert(pNode->m_pRight, pLastNodeInList);
    }
}
