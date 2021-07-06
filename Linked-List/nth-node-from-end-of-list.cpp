#include <bits/stdc++.h>
#include "list.h"
using namespace std;

int nthFromLast(ListNode *head, int n) {

    if(!head)
        return -1;
        
    int i=1;
    ListNode *fast = head, *slow = head;
    for( ; i<n && fast->next; i++) {
        fast = fast->next;
    }

    if(i != n)
        return -1;

    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}

int main() {

    int arr[] = {1, 2, 5, 3, 8, 5, 9, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, size);

    int n = 4;
    cout << nthFromLast(head, n) << "\n";

    return 0;
}