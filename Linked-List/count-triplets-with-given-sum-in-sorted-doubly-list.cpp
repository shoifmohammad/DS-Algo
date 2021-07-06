#include <bits/stdc++.h>
#include "doublyList.h"
using namespace std;

int countPairs(DLL *first, DLL *last, int sum) {

    if(!first)
        return 0;
    
    int count = 0;
    while(last->next != first && first != last) {
        int s = first->data + last->data;
        if(s == sum) {
            count++;
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

    return count;
}

int countTriplets(DLL *head, int sum) {

    if(!head || !head->next)
        return 0;

    DLL *curr = head, *last = head;
    while(last->next) {
        last = last->next;
    }

    int count = 0;
    while(curr->next) {
        count += countPairs(curr->next, last, sum-curr->data);
        curr = curr->next;
    }

    return count;
}

int main() {

    int arr[] = {1, 2, 4, 5, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    DLL *head = arrayToDLL(arr, n);

    int sum = 17;
    cout << countTriplets(head, sum) << "\n";

    return 0;
}