#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

DLL* reverseDLL(DLL *head) {
    
    DLL *left = NULL, *curr = head, *right = curr;
    while(curr) {
        right = curr->next;
        curr->prev = right;
        curr->next = left;
        left = curr;
        curr = right;
    }
    
    return left;
}

int main() {

    int arr[] = {2, 4, 1, 2, 6, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);

    printDLL(head);
    head = reverseDLL(head);
    printDLL(head);

    return 0;
}