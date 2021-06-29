#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* reverse_in_group(ListNode *head, int k) {

    if(head == NULL)
        return head;
            
    ListNode *prev = NULL, *curr=head, *link, *tail = head;
    for(int i=0; i<k && curr!=NULL; i++) {
        link = curr->next;
        curr->next = prev;
        prev = curr;
        curr = link;
    }
    tail->next = reverse_in_group(curr, k);
    
    return prev;
}

int main() {

    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);
    int k = 4;

    head = reverse_in_group(head, k);
    printList(head);

    return 0;
}