// Q) Given a sorted linked list, delete all duplicates such that each element appear only once.

ListNode* deleteDuplicates(ListNode* A) {

    if (A == nullptr || A->next == nullptr) {
        return A;
    }

    ListNode* current = A;
    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }

    return A;
}


// This code is a function that takes in a linked list as input and removes any duplicate nodes from the list. 

// First, the function checks if the input list is empty or has only one node. If so, it returns the list as it is, since there are no duplicates to remove.

// Next, the function initializes a pointer called `current` to the head of the list. This pointer will be used to iterate through the list.

// The function then enters a while loop that continues until the `current` pointer reaches the last node of the list. 

// Inside the loop, the function checks if the value of the current node is equal to the value of the next node. If they are equal, it means that the current node is a duplicate. 

// To remove the duplicate, the function creates a new pointer called `duplicate` and sets it to point to the next node. Then, it updates the `next` pointer of the current node to skip over the duplicate node and point to the node after it. Finally, it deletes the duplicate node to free up memory.

// If the values of the current and next nodes are not equal, it means that there is no duplicate. In this case, the function simply moves the `current` pointer to the next node.

// Once the loop finishes, the function returns the modified list, which now has all duplicates removed.