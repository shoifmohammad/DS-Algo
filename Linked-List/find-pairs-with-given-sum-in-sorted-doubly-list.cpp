#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

void findPairs(DLL *head, int sum) {

    if(!head || !head->next)
        return;

    DLL *first = head, *last = head;
    while (last->next) {
        last = last->next;
    }
    
    while(last->next != first && first != last) {
        int s = first->data + last->data;
        if(s == sum) {
            cout << "[" << first->data << ", " << last->data << "]\n";
            first = first->next;
            last = last->prev;
        }
        else if(s < sum) {
            first = first->next;
        }
        else {
            last = last->prev;
        }
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);

    int sum = 7;
    findPairs(head, 7);

    return 0;
}