#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* findIntersection(ListNode* head1, ListNode* head2) {
    
    ListNode *temp1 = head1, *temp2 = head2;
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    
    while(temp1 && temp2) {
        if(temp1->data == temp2->data) {
            tail->next = temp1;
            tail = tail->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data) {
            temp1 = temp1->next;
        }
        else {
            temp2 = temp2->next;
        }
    }
    
    return head->next;
}

int main() {

    int arr1[] = {-1, 2, 3, 4, 4, 6, 8, 9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    ListNode *head1 = arrayToList(arr1, n1);

    int arr2[] = {1, 4, 5, 6, 7, 8, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    ListNode *head2 = arrayToList(arr2, n2);

    ListNode *intersection = findIntersection(head1, head2);
    printList(intersection);

    return 0;
}