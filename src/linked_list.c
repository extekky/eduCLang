#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int data;
        struct Node *next;
} Node;

Node *nodeAddNode(Node *head, int data)
{
        Node *temp = malloc(sizeof(Node));
        if (NULL == temp)
                return NULL;

        temp->data = data;
        temp->next = NULL;

        if (NULL == head)
                return temp;

        Node *iter = head;
        while (iter->next != NULL)
                iter = iter->next;

        iter->next = temp;

        return head;
}

void nodePrint(Node *head)
{
        Node *iter = head;
        while (iter != NULL) {
                printf("%d\n", iter->data);
                iter = iter->next;
        }
}

Node *nodeClear(Node *head)
{
        while (head != NULL) {
                Node *temp = head->next;
                free(head);
                head = temp;
        }
        return head;
}

Node *nodeDelete(Node *head, int value)
{
        Node *previous = NULL;
        Node *current = head;

        while (current != NULL) {
                if (current->data == value) {
                        if (previous == NULL)
                                head = head->next;
                        else
                                previous->next = current->next;

                        free(current);
                        return head;
                }
                previous = current;
                current = current->next;
        }
        return head;
}

Node *nodeDeleteByPosition(Node *head, size_t pos)
{
        Node *previous = NULL;
        Node *currentNode = head;
        size_t currentPos = 0;

        while (currentNode != NULL) {
                if (currentPos == pos) {
                        if (currentPos == 0)
                                head = head->next;

                        else
                                previous->next = currentNode->next;

                        free(currentNode);
                        return head;
                }
                currentPos += 1;
                previous = currentNode;
                currentNode = currentNode->next;
        }
        return head;
}

Node *nodeReverse(Node *head)
{
        int *vals = malloc(sizeof(int) * 5000);
        Node *temp = head;
        int idx = 0;

        while (temp != NULL) {
                vals[idx] = temp->data;
                temp = temp->next;
                idx += 1;
        }

        temp = head;
        while (temp != NULL) {
                temp->data = vals[idx - 1];
                temp = temp->next;
                idx -= 1;
        }
        free(vals);
        return head;
}

Node *nodeAddTwoNumbers(Node *l1, Node *l2)
{
        Node *result = NULL;
        int unit = 0, current_sum = 0;
        while (l1 != NULL || l2 != NULL) {
                if (l1 != NULL) {
                        current_sum += l1->data;
                        l1 = l1->next;
                }
                if (l2 != NULL) {
                        current_sum += l2->data;
                        l2 = l2->next;
                }

                unit = current_sum % 10;
                current_sum = (current_sum - unit) / 10;

                result = nodeAddNode(result, unit);
        }
        if (current_sum > 0)
                result = nodeAddNode(result, current_sum);
        return result;
}