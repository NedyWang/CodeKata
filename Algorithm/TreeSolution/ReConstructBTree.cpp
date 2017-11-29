//
// Created by root on 11/29/17.
// According to the pre-order and in-order sequence to re-construct BTree
//

#include <iostream>
#include "TreeNode.h"

bool __debug = true;


BTreeNode *
doReConstructBTree(int *pPrevStart, int *pPrevEnd, int *pInStart, int *pInEnd) {
    auto *pNode = new BTreeNode(*pPrevStart);
    if (__debug) {
        std::cout << pNode->m_value << " ";
    }

    if (pPrevStart == pPrevEnd) {
        if (pInStart == pInEnd && *pPrevStart == *pInStart) {
            return pNode;
        } else {
            throw std::exception();
        }
    }

    int *index = pInStart;
    while (index != pInEnd) {
        if (*pPrevStart == *index) {
            break;
        }
        ++index;
    }
    auto distance = static_cast<int>(index - pInStart);
    if (distance > 0)
        pNode->m_pLeft = doReConstructBTree(pPrevStart + 1,
                                            pPrevStart + distance,
                                            pInStart,
                                            pInStart + distance - 1);
    if (distance < pPrevEnd - pPrevStart)
        pNode->m_pRight = doReConstructBTree(pPrevStart + distance + 1,
                                             pPrevEnd,
                                             pInStart + distance + 1,
                                             pInEnd);

    return pNode;
}

BTreeNode* reConstructBTree(int *pPrev, int *pIn, int length) {
    return doReConstructBTree(pPrev, pPrev + length - 1, pIn, pIn + length - 1);
}

void unitTestReConstructBTree() {
    int prevOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    __debug = true;
    BTreeNode *pTreeRoot = reConstructBTree(prevOrder, inOrder, 8);
    delete pTreeRoot;
}
