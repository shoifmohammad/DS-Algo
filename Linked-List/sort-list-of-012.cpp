#include <bits/stdc++.h>
#include "list.h"
using namespace std;

void sort012(ListNode *head) {

    if(head == NULL)
        return;
            
    int count[3] = {0, 0, 0};
    ListNode *temp = head;
    while(temp) {
        count[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    for(int i=0; i<3; i++) {
        for(int j=0; j<count[i]; j++) {
            temp->data = i;
            temp = temp->next;
        }
    }
}

int main() {

    int arr[] = {1, 2, 0, 2, 1, 2, 2, 1, 2, 0, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    sort012(head);
    printList(head);

    return 0;
}