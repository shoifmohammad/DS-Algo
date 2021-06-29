#include <bits/stdc++.h>
#include "list.h"
using namespace std;

bool loopExists(ListNode *head) {

    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }

    return false;
}

int main() {

    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    ListNode *head = arrayToListWithLoop(arr, n, k);

    if(loopExists(head))
        cout << "Loop detected\n";
    else
        cout << "No loop found\n";

    return 0;
}