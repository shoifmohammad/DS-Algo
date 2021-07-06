#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* deleteNodes(ListNode *head) {

    if(!head || !head->next)
        return head;
        
    deque<int> dq;
    ListNode *curr = head, *prev = NULL;
    while(curr) {
        while(!dq.empty() && dq.back() < curr->data)
            dq.pop_back();
        dq.push_back(curr->data);
        curr = curr->next;
    }
    
    curr = head;
    while(!dq.empty()) {
        curr->data = dq.front();
        dq.pop_front();
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    
    return head;
}

int main() {

    int arr[] = {2, 5, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    head = deleteNodes(head);
    printList(head);

    return 0;
}