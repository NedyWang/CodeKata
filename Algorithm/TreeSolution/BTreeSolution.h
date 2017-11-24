//
// Created by root on 11/17/17.
//

#ifndef LEET_CODE_BTREESOLUTION_H
#define LEET_CODE_BTREESOLUTION_H


#include "TreeNode.h"
#include "../Common/Solution.h"

class BTreeSolution : public Solution {
public:
    static BTreeNode *reConstructBTree(int *pPrev, int *pIn, int length);

    static BTreeNode *doReContructBTree(int *pPrevStart, int *pPrevEnd, int *pInStart, int *pInEnd);

    static void unitTestReConstructBTree();

    virtual void unitTest() {
        unitTestReConstructBTree();
    }
};

#endif //LEET_CODE_BTREESOLUTION_H
