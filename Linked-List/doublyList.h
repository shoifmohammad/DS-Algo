#include <bits/stdc++.h>
using namespace std;

class DLL {
    public:
        int data;
        DLL *prev, *next;
        DLL() {}
        DLL(int val) {
            data = val;
            prev = NULL;
            next = NULL;
        }
};

void printDLL(DLL *head) {

    DLL *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

DLL *arrayToDLL(int arr[], int n) {

    if(n == 0)
        return NULL;
    if(n == 1)
        return new DLL(arr[0]);
    
    DLL *head = new DLL(0);
    DLL *tail = head;

    for(int i=0; i<n; i++) {
        tail->next = new DLL(arr[i]);
        tail->next->prev = tail;
        tail = tail->next;
    }

    DLL *newHead = head->next;
    head->next = NULL;
    newHead->prev = NULL;

    return newHead;
}