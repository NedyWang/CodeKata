//
// Created by root on 11/17/17.
//

#ifndef LEET_CODE_LISTNODE_H
#define LEET_CODE_LISTNODE_H

typedef struct ListNode {
    int m_value;
    ListNode *next;

    explicit ListNode(int value) {
        this->m_value = value;
        next = nullptr;
    }

} ListNode;
#endif //LEET_CODE_LISTNODE_H
