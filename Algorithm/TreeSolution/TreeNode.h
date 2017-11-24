//
// Created by root on 11/17/17.
//

#ifndef LEET_CODE_TREENODE_H
#define LEET_CODE_TREENODE_H

typedef struct BTreeNode {
public:
    explicit BTreeNode(int value) : m_value(value) {
        m_pLeft = nullptr;
        m_pRight = nullptr;
    }

    ~BTreeNode() {
        delete m_pLeft;
        delete m_pRight;
    }
public:
    BTreeNode *m_pLeft;
    BTreeNode *m_pRight;
    int m_value;
}TreeNode;
#endif //LEET_CODE_TREENODE_H
