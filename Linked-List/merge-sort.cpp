#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* merge(ListNode *head1, ListNode *head2) {

    if(!head1)
        return head2;
    if(!head2)
        return head1;

    ListNode *head;
    if(head1->data < head2->data) {
        head = head1;
        head->next = merge(head1->next, head2);
    }
    else {
        head = head2;
        head->next = merge(head1, head2->next);
    }

    return head;
}

ListNode* mergeSort(ListNode *head) {

    if(head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head, *fast = head;
    while(fast->next) {
        fast = fast->next;
        if(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    ListNode *head2 = slow->next;
    slow->next = NULL;

    head = mergeSort(head);
    head2 = mergeSort(head2);

    return merge(head, head2);
}

int main() {

    int arr[] = {3, 0, 4, -1, 6, 4, 9, 11, 5, 10, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    printList(head);
    head = mergeSort(head);
    printList(head);

    return 0;
}