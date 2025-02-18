#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "convenience_function.h"
#include "leetcode.h"
#include "lib_of_books.h"
#include "linked_list.h"
#include "makeMassive.h"
#include "mystring.h"

int main(void)
{
        Node *head = NULL;
        for (int i = 1; i < 10; i++)
                head = nodeAddNode(head, i * 10);

        for (int i = 0; i <= 100; i += 20)
                head = nodeDelete(head, i);

        nodePrint(head);
        head = nodeClear(head);
        printf("%p\n", head);
        return 0;
}
