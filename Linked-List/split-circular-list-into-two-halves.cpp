#include <bits/stdc++.h>
#include "list.h"
using namespace std;

/*
    for circular list having only 1 element,
    both the new lists will be the same as original.
*/

void splitCircularList(ListNode *head, ListNode **head1, ListNode **head2) {

    if(head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }
    
    if(head->next == head) {
        *head1 = head;
        *head2 = head;
        return;
    }
    
    ListNode *fast = head, *slow = head;
    while(fast->next != head) {
        fast = fast->next;
        if(fast->next != head) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    *head1 = head;
    *head2 = slow->next;
    slow->next = *head1;
    fast->next = *head2;
}

int main() {

    int arr[] = {1, 3, 7, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToListWithLoop(arr, n, 1);

    ListNode *first, *second;
    splitCircularList(head, &first, &second);

    printCircularList(first);
    printCircularList(second);

    return 0;
}