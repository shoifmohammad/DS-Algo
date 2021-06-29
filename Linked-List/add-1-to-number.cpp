#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* addOne(ListNode *head) {

    head = reverseList(head);
    
    ListNode *temp = head;
    int carry, sum = head->data+1;
    head->data = sum%10;
    carry = sum/10;
    while(temp->next) {
        sum = carry+temp->next->data;
        temp->next->data = sum%10;
        carry = sum/10;
        temp = temp->next;
    }
    while(carry) {
        temp->next = new ListNode(carry%10);
        carry /= 10;
        temp = temp->next;
    }

    return reverseList(head);
}

int main() {

    int arr[] = {1, 2, 9, 9};
    int n  = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    head = addOne(head);
    printList(head);

    return 0;
}