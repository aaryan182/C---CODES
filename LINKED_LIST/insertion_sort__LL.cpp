// Q) insertion sort using linked list 

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* A) {
    ListNode* sortedHead = NULL; 
    
    ListNode* current = A;
    
    while (current != NULL) {
        ListNode* nextNode = current->next; 
        
        if (sortedHead == NULL || current->val < sortedHead->val) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            ListNode* sortedCurrent = sortedHead;
            while (sortedCurrent->next != NULL && sortedCurrent->next->val < current->val) {
                sortedCurrent = sortedCurrent->next;
            }
            current->next = sortedCurrent->next;
            sortedCurrent->next = current;
        }
        
        current = nextNode; 
    }
    
    return sortedHead;
}

int main()
{  
   ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    

    ListNode* sortedList = insertionSortList(head);

    while (sortedList != NULL) {
         cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
     cout <<  endl;
     
   return 0;
}

// This code is an implementation of the insertion sort algorithm for a linked list. The goal of the algorithm is to sort the elements of the linked list in ascending order.

// The code starts by initializing a variable called `sortedHead` to `NULL`. This variable will keep track of the head of the sorted list.

// Then, a variable called `current` is initialized to the head of the input list `A`. This variable will be used to iterate through the input list.

// The code enters a while loop that continues until `current` becomes `NULL`. This loop iterates through each node in the input list.

// Inside the loop, the code first stores the next node of `current` in a variable called `nextNode`. This is done to prevent losing the reference to the next node when modifying the `current` node.

// Next, the code checks if the `sortedHead` is `NULL` or if the value of `current` is less than the value of the `sortedHead`. If either of these conditions is true, it means that the `current` node should become the new head of the sorted list. In this case, the code updates the `next` pointer of the `current` node to point to the current `sortedHead`, and then updates the `sortedHead` to point to the `current` node.

// If the above conditions are not true, it means that the `current` node should be inserted somewhere in the middle or at the end of the sorted list. To find the correct position, the code initializes a variable called `sortedCurrent` to the `sortedHead`. Then, it enters a while loop that continues until either the `sortedCurrent` reaches the end of the sorted list or the value of the next node of `sortedCurrent` is greater than the value of `current`. This loop is used to find the correct position to insert the `current` node.

// Once the correct position is found, the code updates the `next` pointer of the `current` node to point to the next node of `sortedCurrent`, and then updates the `next` pointer of `sortedCurrent` to point to the `current` node. This effectively inserts the `current` node into the sorted list.

// Finally, the code updates the `current` variable to the `nextNode` that was stored earlier. This moves the iteration to the next node in the input list.

// After the while loop finishes, the code returns the `sortedHead`, which is the head of the sorted list.

// In summary, this code uses the insertion sort algorithm to sort a linked list. It iterates through each node in the input list and inserts it into the correct position in the sorted list. The sorted list is built incrementally as the algorithm progresses.