/*
LeetCode Qs: https://leetcode.com/discuss/interview-question/2029495/ADOBE-or-MTS-or-DSA

Check if the array has i<=j<k such that nums[i]*nums[j]=nums[k]

Input: [2,3,4,12,6]
    4 = 2*2
    12 = 3*4
    6 = 2*3
Output = 3

Input: [2,4,8,16]
    4 = 2*2
    8 = 2*4
    16 = 4*4
    16 = 2*8
Output = 4

*/
#include<bits/stdc++.h>
using namespace std;

int countOfValidTriplets(int n, vector<int>&v) {
    int count = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                if (v[i]*v[j] == v[k]) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countOfValidTriplets(int n, vector<int>&v) {
    unordered_map<int, int>u;
    int count = 0;

    for (int i = 0; i < n; i++) {
        u[v[i]]++;
        for (int j = 2; j <= sqrt(v[i]); j++) {
            if (v[i]%j == 0 && u[j] > 0 && u[v[i]/j] > 0) {
                count++;
            }
        }
    }
    return count;
}

int countOfValidTriplets(int n, vector<int>&v) {
    unordered_map<int, int> u;
    int count = 0;

    for (int i = n-2; i >= 0; i--) {
        u[v[i+1]]++;
        for (int j = i; j >= 0; j--) {
            int prod = v[i] * v[j];
            if (u.count(prod) > 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countOfValidTriplets(n, arr);
}