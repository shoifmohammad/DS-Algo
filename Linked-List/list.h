#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode *next;
        ListNode() {}
        ListNode(int val) {
            data = val;
            next = NULL;
        }
};

void printList(ListNode *head) {

    ListNode *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

ListNode* arrayToList(int arr[], int n) {

    if(n == 0)
        return NULL;
    if(n == 1)
        return new ListNode(arr[0]);
    
    ListNode *head = new ListNode(arr[0]), *temp;
    temp = head;
    for(int i=1; i<n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

ListNode* arrayToListWithLoop(int arr[], int n, int k) {

    if(k>n || n == 0)
        return NULL;

    ListNode* nodes[n];
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    nodes[0] = head;

    for(int i=1; i<n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
        nodes[i] = temp;
    }

    if(k>0) {
        temp->next = nodes[k-1];
    }

    return head;
}

ListNode* reverseList(ListNode *head) {

    ListNode *prev = NULL, *curr = head, *link = head;
    while(curr) {
        link = curr->next;
        curr->next = prev;
        prev = curr;
        curr = link;
    }
    return prev;
}