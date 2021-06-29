#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* startOfLoop(ListNode* head) {

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
        return NULL;

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

    return fast->next;
}

int main() {

    int arr[] = {1, 12, 21, 4, 5, 6, 17, 8, 15, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 7;
    ListNode *head = arrayToListWithLoop(arr, n, k);

    ListNode *rel = startOfLoop(head);
    if(rel)
        cout << rel->data << "\n";
    else
        cout << "Loop doesn't exist\n";

    return 0;
}