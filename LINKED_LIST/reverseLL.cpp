#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *A)
{
    ListNode *prev = NULL;
    ListNode *curr = A;

    while (curr != NULL)
    {
        ListNode *nextNode = curr->next; // Store the next node
        curr->next = prev;               // Reverse the next pointer

        prev = curr; // Move prev and curr pointers forward
        curr = nextNode;
    }

    return prev; // The new head of the reversed list
}

int main()
{

    // Creating a sample linked list: 1->2->3->4->5->NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reversing the linked list
    ListNode *reversedHead = reverseList(head);

    // Printing the reversed linked list: 5->4->3->2->1->NULL
    ListNode *current = reversedHead;
    while (current != NULL)
    {
        cout << current->val << "->";
        current = current->next;
    }
    cout << "NULL" << endl;

    return 0;
}

// This code defines a struct called ListNode, which represents a node in a linked list. Each node has an integer value and a pointer to the next node in the list.

// The function `reverseList` takes a pointer to the head of a linked list as input and returns a pointer to the head of the reversed list.

// Inside the function, two pointers `prev` and `curr` are initialized. `prev` is set to NULL and `curr` is set to the input pointer `A`.

// A while loop is used to iterate through the linked list. The loop continues as long as `curr` is not NULL.

// Inside the loop, the next node in the list is stored in a pointer called `nextNode`. This is done to prevent losing the reference to the next node when the current node's next pointer is modified.

// The next pointer of the current node `curr` is then set to `prev`, effectively reversing the direction of the pointer.

// The `prev` pointer is then updated to point to the current node `curr`, and the `curr` pointer is updated to point to the next node `nextNode`.

// This process continues until the end of the linked list is reached, at which point the loop exits.

// Finally, the function returns the `prev` pointer, which now points to the head of the reversed list.