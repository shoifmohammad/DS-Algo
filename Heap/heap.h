#include <bits/stdc++.h>
using namespace std;
int MAX_LIMIT = 100000;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

class MinHeap {

    private:    
        int* arr;
        int size;
        int capacity;
        
        int left(int i) {
            return (2*i+1);
        }

        int right(int i) {
            return (2*i+2);
        }

        int parent(int i) {
            return (i-1)/2;
        }

        void minHeapify(int i) {
            if(i>=size)
                return;
            int l = left(i), r = right(i);
            int smallest = i;
            if(l<size && arr[l]<arr[smallest])
                smallest = l;
            if(r<size && arr[r]<arr[smallest])
                smallest = r;
            if(smallest != i) {
                swap(arr[i], arr[smallest]);
                minHeapify(smallest);
            }
        }

        void buildHeap() {
            for(int i=(size-2)/2; i>=0; i--)
                minHeapify(i);
        }

    public:
        MinHeap(int capacity=MAX_LIMIT) {
            this->arr = new int[capacity];
            this->size = 0;
            this->capacity = capacity;
        }

        MinHeap(MinHeap& hp) {
            this->arr = new int [hp.capacity];
            this->size = hp.size;
            this->capacity = hp.capacity;
            for(int i=0; i<size; i++) {
                this->arr[i] = hp.arr[i];
            }
        }

        MinHeap(int arr[], int n) {
            this->arr = new int[MAX_LIMIT];
            this->size = n;
            this->capacity = MAX_LIMIT;
            for(int i=0; i<n; i++)
                this->arr[i] = arr[i];
            buildHeap();
        }
        
        bool empty() {
            return size == 0;
        }

        int size() {
            return size;
        }

        int top() {
            if(size>0)
                return arr[0];
            else
                return INT_MAX;
        }

        void push(int val) {
            if(size == capacity) {
                return;
            }
            arr[size++] = val;
            for(int i=size-1; i>0 && arr[parent(i)] > arr[i]; ) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void pop() {
            if(size == 0) {
                return;
            }
            swap(arr[0], arr[--size]);
            minHeapify(0);
        }

        void decreaseKey(int i, int val) {
            if(i>=size)
                return;
            arr[i] = val;
            for( ; i>0 && arr[parent(i)] > arr[i]; ) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void erase(int i) {
            if(i>=size)
                return;
            decreaseKey(i, INT_MIN);
            pop();
        }
};

class MaxHeap {

    private:    
        int* arr;
        int size;
        int capacity;
        
        int left(int i) {
            return (2*i+1);
        }

        int right(int i) {
            return (2*i+2);
        }

        int parent(int i) {
            return (i-1)/2;
        }

        void maxHeapify(int i) {
            if(i>=size)
                return;
            int l = left(i), r = right(i);
            int largest = i;
            if(l<size && arr[l]>arr[largest])
                largest = l;
            if(r<size && arr[r]>arr[largest])
                largest = r;
            if(largest != i) {
                swap(arr[i], arr[largest]);
                maxHeapify(largest);
            }
        }

        void buildHeap() {
            for(int i=(size-2)/2; i>=0; i--)
                maxHeapify(i);
        }

    public:
        MaxHeap(int capacity=MAX_LIMIT) {
            this->arr = new int[capacity];
            this->size = 0;
            this->capacity = capacity;
        }

        MaxHeap(MaxHeap& hp) {
            this->arr = new int [hp.capacity];
            this->size = hp.size;
            this->capacity = hp.capacity;
            for(int i=0; i<size; i++) {
                this->arr[i] = hp.arr[i];
            }
        }

        MaxHeap(int arr[], int n) {
            this->arr = new int[MAX_LIMIT];
            this->size = n;
            this->capacity = MAX_LIMIT;
            for(int i=0; i<n; i++)
                this->arr[i] = arr[i];
            buildHeap();
        }
        
        bool empty() {
            return size == 0;
        }

        int size() {
            return size;
        }

        int top() {
            if(size>0)
                return arr[0];
            else
                return INT_MIN;
        }

        void push(int val) {
            if(size == capacity) {
                return;
            }
            arr[size++] = val;
            for(int i=size-1; i>0 && arr[parent(i)] < arr[i]; ) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void pop() {
            if(size == 0) {
                return;
            }
            swap(arr[0], arr[--size]);
            maxHeapify(0);
        }

        void increaseKey(int i, int val) {
            if(i>=size)
                return;
            arr[i] = val;
            for( ; i>0 && arr[parent(i)] < arr[i]; ) {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
        }

        void erase(int i) {
            if(i>=size)
                return;
            increaseKey(i, INT_MAX);
            pop();
        }      
};