#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

void print_list(ListNode *head) {

    ListNode *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->data > b->data;
    }
};

ListNode* mergeKsortedLists(ListNode* arr[], int k) {

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(int i=0; i<k; i++) {
        if(arr[i])
            pq.push(arr[i]);
    }
    
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    
    while(!pq.empty()) {
        ListNode* curr = pq.top();
        pq.pop();
        
        tail->next = curr;
        tail = tail->next;
        
        if(curr->next)
            pq.push(curr->next);
    }
    
    return head->next;
}

int main() {

    int k = 4;
    ListNode* arr[k];

    arr[0] = new ListNode(7);
    arr[0]->next = new ListNode(9);
    arr[0]->next->next = new ListNode(15);
    arr[0]->next->next->next = new ListNode(22);

    arr[1] = NULL;

    arr[2] = new ListNode(2);
    arr[2]->next = new ListNode(6);
    arr[2]->next->next = new ListNode(9);
    arr[2]->next->next->next = new ListNode(13);

    arr[3] = new ListNode(-3);
    arr[3]->next = new ListNode(1);
    arr[3]->next->next = new ListNode(4);

    ListNode* rel = mergeKsortedLists(arr, k);
    print_list(rel);

    return 0;
}