#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

struct comparator{
    bool operator()(const DLL *a, const DLL *b) {
        return a->data > b->data;
    }
};

DLL* sortKsorted(DLL *head, int k) {

    if(!head)
        return head;

    priority_queue<DLL*, vector<DLL*>, comparator> pq;
    DLL *curr = head; 
    for(int i=0; i<=k && curr; i++) {
        pq.push(curr);
        curr = curr->next;
    }

    DLL *newHead = NULL, *tail;
    while(!pq.empty()) {
        if(!newHead) {
            newHead = pq.top();
            newHead->prev = NULL;
            tail = newHead;
        }
        else {
            tail->next = pq.top();
            pq.top()->prev = tail;
            tail = tail->next;
        }
        pq.pop();
        if(curr) {
            pq.push(curr);
            curr = curr->next;
        }
    }
    tail->next = NULL;

    return newHead;
}

int main() {

    int arr[] = {3, 6, 2, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);

    int k = 2;
    head = sortKsorted(head, k);
    printDLL(head);

    return 0;
}