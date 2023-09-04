// Q) Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.


ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;


    while (A != nullptr && B != nullptr) {
        if (A->val <= B->val) {
            current->next = A;
            A = A->next;
        } else {
            current->next = B;
            B = B->next;
        }
        current = current->next;
    }


    if (A != nullptr) {
        current->next = A;
    } else {
        current->next = B;
    }

    ListNode* mergedList = dummy->next;
    delete dummy;
    return mergedList;
}


// This code is a function that merges two sorted linked lists into a single sorted linked list. 

// The function takes in two parameters, A and B, which are the heads of the two linked lists to be merged. 

// First, the function creates a new ListNode called "dummy" with a value of 0. This dummy node will serve as the head of the merged list. 

// Then, it creates a pointer called "current" and sets it to point to the dummy node. This pointer will be used to traverse the merged list and add nodes to it. 

// The function enters a while loop that continues as long as both A and B are not nullptr (i.e., there are still nodes in both lists to be merged). 

// Inside the loop, the function compares the values of the current nodes in A and B. If the value in A is less than or equal to the value in B, the function sets the next pointer of the current node to point to A, and advances the A pointer to the next node in A. Otherwise, it sets the next pointer of the current node to point to B, and advances the B pointer to the next node in B. 

// After updating the next pointer of the current node, the function moves the current pointer to the next node in the merged list. 

// Once the while loop ends, it checks if there are any remaining nodes in either A or B. If there are, it appends the remaining nodes to the merged list by setting the next pointer of the current node to point to the remaining nodes. 

// Finally, the function sets the mergedList pointer to point to the next node after the dummy node, deletes the dummy node, and returns the mergedList pointer.