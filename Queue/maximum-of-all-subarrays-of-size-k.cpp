#include <bits/stdc++.h>
using namespace std;

void slidingWindowMax(int arr[], int n, int k) {
    
    deque<int> dq;
    
    for(int i=0; i<k; i++) {
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k; i<n; i++) {
        cout << arr[dq.front()] << " ";
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << "\n";
}

int main() {
	
	int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	slidingWindowMax(arr, n, k);
	
	return 0;
}
