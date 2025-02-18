#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *nodeAddNode(Node *head, int data);
void nodePrint(Node *head);
Node *nodeClear(Node *head);
Node *nodeDelete(Node *head, int value);
Node *nodeDeleteByPosition(Node *head, size_t pos);
Node *reverseList(Node *head);

#endif