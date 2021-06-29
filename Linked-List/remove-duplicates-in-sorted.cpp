#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* removeDuplicates(ListNode *head) {

    ListNode* curr = head, *temp;
    while(curr) {
        temp = curr;
        while(temp->next && temp->next->data == curr->data)
            temp = temp->next;
        curr->next = temp->next;
        curr = curr->next;
    }
    
    return head;
}

int main() {

    int arr[] = {-3, -1, -1, 2, 4, 4, 4, 4, 5, 6, 7, 7, 11, 11, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    removeDuplicates(head);
    printList(head);

    return 0;
}