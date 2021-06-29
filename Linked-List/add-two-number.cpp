#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* sum(ListNode *head1, ListNode *head2) {

    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    ListNode *tail = head1;
    head1 = reverseList(head1);
    head2 = reverseList(head2);



    ListNode *temp1 = head1, *temp2 = head2;
    int carry, sum = head1->data+head2->data;
    head1->data = sum%10;
    carry = sum/10;
    while(temp1->next && temp2->next) {
        int sum = temp1->next->data + temp2->next->data + carry;
        temp1->next->data = sum%10;
        carry = sum/10;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(!temp1->next && !temp2->next) {
        if(carry)
            temp1->next = new ListNode(carry);
    }

    if(!temp2->next) {
        temp1->next = temp2->next;
    }

    while(temp1->next) {
        sum = temp1->data+carry;
        temp1->data = sum%10;
        carry = sum/10;
    }
    if(carry)
        temp1->next = new ListNode(carry);

    return reverseList(head1);
}

int main() {

    int arr1[] = {9, 8};
    int n1  = sizeof(arr1)/sizeof(arr1[0]);
    ListNode *head1 = arrayToList(arr1, n1);

    int arr2[] = {4, 2, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    ListNode *head2 = arrayToList(arr2, n2);

    ListNode *s = sum(head1, head2);
    printList(s);

    return 0;
}