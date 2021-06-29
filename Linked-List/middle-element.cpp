#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* middleNode(ListNode* head) {
    
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode *fast = head, *slow = head;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
        if(fast->next) {
            fast = fast->next;
        }
    }
    
    return slow;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    ListNode *node = middleNode(head);
    if(!node)
        cout << "Middle node not found\n";
    else
        cout << node->data << "\n";

    return 0;
}