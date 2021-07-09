#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* deleteNodes(ListNode *head) {

    if(!head || !head->next)
        return head;
        
    head = reverseList(head);

    int mx = INT_MIN;
    ListNode *curr = head, *prev = NULL;
    while(curr) {
        if(curr->data >= mx) {
            if(prev)
                prev->next = curr;
            prev = curr;
            mx = curr->data;
        }
        curr = curr->next;
    }
    prev->next = NULL;
    
    return reverseList(head);
}

int main() {

    int arr[] = {2, 5, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    head = deleteNodes(head);
    printList(head);

    return 0;
}