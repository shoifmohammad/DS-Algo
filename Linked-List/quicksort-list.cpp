#include <bits/stdc++.h>
#include "list.h"
using namespace std;

ListNode* getTail(ListNode *head) {
    
    ListNode *temp = head;
    while(temp && temp->next) {
        temp = temp->next;
    }
    return temp;
}

ListNode* partition(ListNode *head, ListNode *tail, ListNode **newHead, ListNode **newTail) {

    ListNode *pivot = tail, *prev = NULL, *curr = head, *end = tail;

    while(curr != pivot) {
        if(curr->data < pivot->data) {
            if((*newHead) == NULL)
                (*newHead) = curr;
            prev = curr;
            curr = curr->next;
        }
        else {
            if(prev != NULL)
                prev->next = curr->next;
            ListNode *temp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = end->next;
            curr = temp;
        }
    }

    if((*newHead) == NULL)
        (*newHead) = pivot;

    (*newTail) = end;
    return curr;
}

ListNode* quickSort(ListNode *head, ListNode *tail) {

    if(!head || head == tail)
        return head;

    ListNode *newHead = NULL, *newTail = NULL;
    ListNode *pivot = partition(head, tail, &newHead, &newTail);

    if(newHead != pivot) {
        
        ListNode *temp = newHead;
        while(temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSort(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newTail);

    return newHead;
}

void sort(ListNode** head) {
    
    (*head) = quickSort(*head, getTail(*head));
}

int main() {
	
	int arr[] = {3, 1, 4, 2, -1, 9, 0, 7, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	ListNode *head = arrayToList(arr, n);
	
    sort(&head);
	printList(head);
	
	return 0;
}
