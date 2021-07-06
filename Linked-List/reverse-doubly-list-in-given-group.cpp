#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

DLL* reverse_in_group(DLL *head, int k) {

    if(head == NULL)
        return head;
            
    DLL *left = NULL, *curr = head, *right, *tail = head;
    for(int i=0; i<k && curr!=NULL; i++) {
        right = curr->next;
        curr->prev = right;
        curr->next = left;
        left = curr;
        curr = right;
    }
    left->prev = NULL;
    tail->next = reverse_in_group(curr, k);
    if(tail->next)
        tail->next->prev = head;
    
    return left;
}

int main() {

    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8, 5, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);
    int k = 4;

    head = reverse_in_group(head, k);
    printDLL(head);
    
    return 0;
}