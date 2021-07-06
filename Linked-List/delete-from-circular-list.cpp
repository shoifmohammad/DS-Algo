#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* deleteNode(ListNode *head, int val) {

    if(!head)
        return head;

    ListNode *curr = head;

    if(head->data == val) {
        if(head->next == head)
            return NULL;
        while(curr->next != head) {
            curr = curr->next;
        }
        curr->next = head->next;
        free(head);
        return curr->next;
    }
    
    while(curr->next != head && curr->next->data != val) {
        curr = curr->next;
    }
    if(curr->next->data == val) {
        ListNode *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}

int main() {

    int arr[] = {8, 10,  7, 5, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToListWithLoop(arr, n, 1);
    
    printCircularList(head);
    head = deleteNode(head, 7);
    printCircularList(head);

    return 0;
}