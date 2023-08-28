// Q)Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.
//  You should preserve the original relative order of the nodes in each of the two partitions.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *A, int B)
{
    ListNode *lessThanBHead = new ListNode(0);       
    ListNode *greaterOrEqualBHead = new ListNode(0); 

    ListNode *lessThanBCurr = lessThanBHead;
    ListNode *greaterOrEqualBCurr = greaterOrEqualBHead;

    ListNode *current = A;

    while (current != NULL)
    {
        if (current->val < B)
        {
            lessThanBCurr->next = current;
            lessThanBCurr = lessThanBCurr->next;
        }
        else
        {
            greaterOrEqualBCurr->next = current;
            greaterOrEqualBCurr = greaterOrEqualBCurr->next;
        }
        current = current->next;
    }

    lessThanBCurr->next = NULL;
    greaterOrEqualBCurr->next = NULL;

    lessThanBCurr->next = greaterOrEqualBHead->next;


    delete greaterOrEqualBHead;

    ListNode *resultHead = lessThanBHead->next;

    delete lessThanBHead;

    return resultHead;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    int B = 5;

    ListNode *partitionedList = partition(head, B);

    while (partitionedList != NULL)
    {
         cout << partitionedList->val << " ";
        partitionedList = partitionedList->next;
    }
     cout <<  endl;

    return 0;
    return 0;
}

// This code is a function that takes in a linked list and a value `B`, and partitions the linked list such that all nodes with values less than `B` come before all nodes with values greater than or equal to `B`.

// To do this, the code creates two new linked lists: `lessThanBHead` and `greaterOrEqualBHead`. These two linked lists will be used to store the nodes with values less than `B` and greater than or equal to `B`, respectively.

// The code then initializes two pointers, `lessThanBCurr` and `greaterOrEqualBCurr`, to point to the heads of the two new linked lists.

// Next, the code iterates through the original linked list, starting from the head (`A`). For each node in the original linked list, the code checks if its value is less than `B`. If it is, the node is appended to the `lessThanBHead` linked list and `lessThanBCurr` is updated to point to the newly appended node. If the value is greater than or equal to `B`, the node is appended to the `greaterOrEqualBHead` linked list and `greaterOrEqualBCurr` is updated.

// After iterating through all the nodes in the original linked list, the code sets the `next` pointers of `lessThanBCurr` and `greaterOrEqualBCurr` to `NULL` to terminate the two new linked lists.

// Then, the code sets the `next` pointer of `lessThanBCurr` to the head of the `greaterOrEqualBHead` linked list, effectively combining the two linked lists.

// The code then deletes the `greaterOrEqualBHead` linked list, as it is no longer needed.

// Finally, the code sets the `resultHead` pointer to the head of the `lessThanBHead` linked list and deletes the `lessThanBHead` linked list.

// The function returns the `resultHead`, which is the head of the partitioned linked list.

