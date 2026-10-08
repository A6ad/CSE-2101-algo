#include<bits/stdc++.h>

using namespace std;

// Returns LIS of subarray ending with index i.
int lisEndingAtIdx(vector<int>& arr, int idx) {
    
    // Base case
    if (idx == 0)
        return 1;

    // Consider all elements on the left of i,
    // recursively compute LISs ending with 
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < idx; prev++)
        if (arr[prev] < arr[idx])
            mx = max(mx, lisEndingAtIdx(arr, prev) + 1);
    return mx;
}

int lis(vector<int>& arr) {
    int n = arr.size();
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndingAtIdx(arr, i));
    return res;
}

int main() {
    vector<int> arr = {3, 10, 2, 1, 20};
    cout << lis(arr);
    return 0;
}