#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* segregate(ListNode *head) {

    if(!head)
        return head;
        
    ListNode *even = new ListNode(0), *odd = new ListNode(0);
    ListNode *temp = head, *temp_even = even, *temp_odd = odd;
    while(temp) {
        if(temp->data%2 == 0) {
            temp_even->next = temp;
            temp_even = temp_even->next;
        }
        else {
            temp_odd->next = temp;
            temp_odd = temp_odd->next;
        }
        temp = temp->next;
    }
    
    temp_odd->next = NULL;
    temp_even->next = odd->next;
    head = even->next;
    free(even);
    free(odd);

    return head;
}

int main() {

    int arr[] = {13, 21, 2, 7, 12, 9, 1, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    head = segregate(head);
    printList(head);

    return 0;
}