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

void deleteLoop(ListNode* head) {

    ListNode *fast = head, *slow = head;
    bool flag = true;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            flag = false;
            break;
        }
    }

    if(flag)
        return;

    int count = 0;
    while(fast->next != slow) {
        count++;
        fast = fast->next;
    }

    fast = head; slow = head;
    for(int i=0; i<count; i++) {
        fast = fast->next;
    }

    while(fast->next != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = NULL;
}

int main() {

    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    ListNode *head = arrayToListWithLoop(arr, n, k);

    if(loopExists(head))
        cout << "Loop detected\n";
    else
        cout << "No loop found\n";

    deleteLoop(head);

    if(loopExists(head))
        cout << "Loop detected\n";
    else
        cout << "No loop found\n";

    return 0;
}