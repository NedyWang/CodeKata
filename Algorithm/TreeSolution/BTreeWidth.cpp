//
// Created by root on 11/29/17.
// Get the width of BTree
//


#include "TreeNode.h"
#include <queue>

int getBTreeWidth(BTreeNode *pRoot) {
    if (pRoot == nullptr) return 0;
    if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) return 1;

    std::queue<BTreeNode *> nodes;
    nodes.push(pRoot);
    int maxWidth = 0;

    while (!nodes.empty()) {
        unsigned long size = nodes.size();
        int width = 0;

        while (size > 0) {
            --size;
            BTreeNode *node = nodes.back();
            nodes.pop();

            if (node->m_pLeft) {
                ++width;
                nodes.push(node->m_pLeft);
            }

            if (node->m_pRight) {
                ++width;
                nodes.push(node->m_pRight);
            }

            maxWidth = std::max(width, maxWidth);
        }
    }

    return maxWidth;
}

