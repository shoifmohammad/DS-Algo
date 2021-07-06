#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

//  Here rotation is counter-clockwise.

DLL* rotate(DLL *head, int k) {

    if(head == NULL)
        return head;
        
    DLL *tail = head;
    int size = 1;
    while(tail->next) {
        size++;
        tail = tail->next;
    }
    
    k %= size;
    if(k == 0)
        return head;
    
    DLL *temp = head;
    for(int i=0; i<k; i++)
        temp = temp->next;
    
    temp->prev->next = NULL;
    temp->prev = NULL;
    
    tail->next = head;
    head->prev = tail;
    
    return temp;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);

    int k = 8;
    printDLL(head);
    head = rotate(head, k);
    printDLL(head);

    return 0;
}