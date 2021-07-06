#include <bits/stdc++.h>
#include "list.h"
using namespace std;

bool isPalindrome(ListNode *head) {

    if(!head || !head->next)
        return true;
    
    ListNode *fast = head, *slow = head;
    while(fast->next) {
        fast = fast->next;
        if(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    ListNode *tail = slow->next;
    slow->next = NULL;
    ListNode *head2 = reverseList(tail);
    tail->next = slow;

    while(head && head2) {
        if(head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main() {

    int arr[] = {1, 3, 4, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    if(isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not-Palindrome\n";

    return 0;
}