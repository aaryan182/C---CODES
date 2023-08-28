#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *solve(ListNode *A)
{
    ListNode *zeroDummy = new ListNode(0);
    ListNode *oneDummy = new ListNode(0);

    ListNode *zeroCurr = zeroDummy;
    ListNode *oneCurr = oneDummy;

    ListNode *current = A;

    while (current != NULL)
    {
        if (current->val == 0)
        {
            zeroCurr->next = current;
            zeroCurr = zeroCurr->next;
        }
        else
        {
            oneCurr->next = current;
            oneCurr = oneCurr->next;
        }
        current = current->next;
    }

    zeroCurr->next = oneDummy->next;
    oneCurr->next = NULL;

    ListNode *sortedList = zeroDummy->next;

    delete zeroDummy;
    delete oneDummy;

    return sortedList;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);

    ListNode *sortedList = solve(head);

    while (sortedList != NULL)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    cout << endl;

    return 0;
}


// This code is a function that takes in a linked list as input and returns a sorted version of that linked list. The linked list is made up of nodes, where each node has a value and a pointer to the next node in the list.

// The function starts by creating two dummy nodes, `zeroDummy` and `oneDummy`, both initialized with a value of 0. These dummy nodes will be used to build two separate lists: one for nodes with a value of 0 and one for nodes with a value of 1.

// Next, two pointers, `zeroCurr` and `oneCurr`, are initialized to point to the dummy nodes. These pointers will be used to keep track of the current node in each list as we iterate through the input list.

// The `current` pointer is set to point to the head of the input list.

// The code then enters a while loop that continues until the `current` pointer reaches the end of the input list (i.e., it becomes `NULL`).

// Inside the loop, the code checks the value of the current node. If the value is 0, the current node is appended to the end of the list for nodes with a value of 0 (`zeroCurr->next = current`) and the `zeroCurr` pointer is updated to point to the newly added node (`zeroCurr = zeroCurr->next`). If the value is 1, the same process is followed for the list for nodes with a value of 1.

// After processing the current node, the `current` pointer is updated to point to the next node in the input list.

// Once the while loop finishes, the code connects the end of the list for nodes with a value of 0 to the beginning of the list for nodes with a value of 1 (`zeroCurr->next = oneDummy->next`). This ensures that all nodes with a value of 0 come before nodes with a value of 1 in the sorted list. The `oneCurr->next` pointer is set to `NULL` to mark the end of the list for nodes with a value of 1.

// The `sortedList` pointer is set to point to the first node in the list for nodes with a value of 0.

// Finally, the dummy nodes (`zeroDummy` and `oneDummy`) are deleted to free up the memory they occupy.

// The function returns the `sortedList` pointer, which points to the sorted linked list.