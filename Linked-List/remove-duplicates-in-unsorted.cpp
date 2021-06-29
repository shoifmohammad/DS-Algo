#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* removeDuplicates(ListNode *head) {

    if(head == NULL || head->next == NULL)
        return head;
    
    unordered_set<int> st;    
    st.insert(head->data);
    ListNode *temp = head;

    while(temp->next) {
        if(st.find(temp->next->data) != st.end()) {
            temp->next = temp->next->next;
        }
        else {
            st.insert(temp->next->data);
            temp = temp->next;
        }
    }
    
    return head;
}

int main() {

    int arr[] = {5, 2, 4, 2, 4, 3, 2, 2, 1, 4, 7, 4, 7, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = arrayToList(arr, n);

    removeDuplicates(head);
    printList(head);

    return 0;
}