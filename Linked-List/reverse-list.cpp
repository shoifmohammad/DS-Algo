#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* reverse_iterative(ListNode *head) {

    ListNode *prev = NULL, *curr = head, *link = head;
    while(curr) {
        link = curr->next;
        curr->next = prev;
        prev = curr;
        curr = link;
    }
    return prev;
}

ListNode* reverse_recursive(ListNode *head) {

    if(head == NULL || head->next == NULL)
        return head;

    ListNode *first = head, *second = head->next;
    head = reverse_recursive(second);
    second->next = first;
    first->next = NULL;
    return head;
}

int main() {

    int arr[] = {3, 7, 2, 5, -4};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    printList(head);

    head = reverse_iterative(head);
    printList(head);

    head = reverse_recursive(head);
    printList(head);

    return 0;
}