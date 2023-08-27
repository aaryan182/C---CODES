#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* a = A;
    ListNode* b = B;
    
    while (a != b) {
        a = a ? a->next : B;
        b = b ? b->next : A;
    }
    
    return a;
}

int main() {
    ListNode* commonNode = new ListNode(7);
    
    ListNode* A = new ListNode(3);
    A->next = new ListNode(6);
    A->next->next = commonNode;
    
    ListNode* B = new ListNode(2);
    B->next = new ListNode(5);
    B->next->next = new ListNode(8);
    B->next->next->next = new ListNode(4);
    B->next->next->next->next = commonNode;
    
    ListNode* intersection = getIntersectionNode(A, B);
    
    if (intersection) {
        cout << "Intersection point: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    
    return 0;
}

// This code defines a struct called `ListNode` which represents a node in a linked list. Each node has an integer value and a pointer to the next node in the list.

// The function `getIntersectionNode` takes two linked lists as input, `A` and `B`, and returns the node at which the two lists intersect. If the lists do not intersect, it returns `NULL`.

// The function starts by creating two pointers, `a` and `b`, which initially point to the heads of the input lists `A` and `B`, respectively.

// The function then enters a loop that continues until `a` and `b` are equal. In each iteration of the loop, `a` and `b` are updated as follows:
// - If `a` is not `NULL`, `a` is updated to point to the next node in list `A`. Otherwise, `a` is updated to point to the head of list `B`.
// - If `b` is not `NULL`, `b` is updated to point to the next node in list `B`. Otherwise, `b` is updated to point to the head of list `A`.

// This loop continues until `a` and `b` are equal, which means that they have either reached the intersection point or both reached the end of their respective lists.

// Finally, the function returns the value of `a`, which is the node at which the two lists intersect (or `NULL` if they do not intersect).