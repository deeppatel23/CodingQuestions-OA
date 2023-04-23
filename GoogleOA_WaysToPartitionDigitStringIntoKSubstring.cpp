/*
Discuss: https://leetcode.com/discuss/interview-question/2257966/Google-OA
Video: https://youtu.be/8xm6564R5O0

You are given a string S of lenght N of digits 0 - 9. You need to partiton strings into K substrings such that

Each substring has a minimum lenght of M
Substring must start with even digit and ends with odd digit number
Determine the number of ways to partitioin the strings which satisfy the above condition
You should find answer modulo 1e9 + 7

constraints :
1 <= n<= 2x10^3
1<= m<= n
1<=k<=n


Input: N = 9, M = 2, k = 3, S = '432387429'
Output: 3
Explanation: 43|23|87429, 4323|87|429, 43|2387|429

Ip: 
9 2 5
232387421
Op: 0

Ip:
9 2 4
232387421
Op: 1

Ip
18 2 5
232387421232387421
Op: 35

Ip
18 2 4
232387421232387421
Op: 35
*/

#include<bits/stdc++.h>
using namespace std;

//==============================================================================================================================
// int solve(int m, int k, int idx, int partitionCount, int currSubStringLength, string &s) {
//     if (idx == s.size()-1) {
//         if (partitionCount == k && currSubStringLength+1 >= m && (s[idx]-'0')%2 != 0) {
//             return 1;
//         }
//         else {
//             return 0;
//         }
//     }

//     int ways1 = 0, ways2 = 0;
//     if (currSubStringLength+1 >= m && (s[idx]-'0')%2 != 0 && partitionCount < k && idx+1 < s.size() && (s[idx+1]-'0')%2 == 0) {
//         ways1 = solve(m, k, idx+2, partitionCount+1, 1, s);
//     }
//     ways2 = solve(m, k, idx+1, partitionCount, currSubStringLength+1, s);
//     return ways1+ways2;
// }

//==============================================================================================================================
// int solve(int m, int k, int idx, int partitionCount, string &s) {
//     if (idx == s.size()) {
//         return k == partitionCount;
//     }
    
//     if (partitionCount > k) {
//       return 0;
//     }
    
//     if (partitionCount == k) {
//         if (s.size()-idx+1 >= m && s[s.size()-1]%2 != 0) {
//             return 1; 
//         }
//         else {
//             return 0;
//         }
//     }

//     int ways = 0;
//     if ((s[idx]-'0') % 2 == 0) {
//         for (int j = idx+m-1; j < s.size()-1; j++) {
//             int currNum = s[j]-'0';
//             int nextNum = s[j+1]-'0';
//             if (currNum%2 != 0 && nextNum%2 == 0) {
//                 ways += solve(m, k, j+1, partitionCount+1, s);
//             }
//         }
//     }
//     return ways;
// }
//==============================================================================================================================


vector<vector<int>>dp;
int MOD = 1e9+7;
int solve(int m, int k, int idx, int partitionCount, string &s) {
    if (idx == s.size()) {
        return k == partitionCount;
    }
    
    if (partitionCount > k) {
      return 0;
    }
    
    if (partitionCount == k) {
        if (s.size()-idx+1 >= m && s[s.size()-1]%2 != 0) {
            return 1; 
        }
        else {
            return 0;
        }
    }
    
    if (dp[idx][partitionCount] != -1) {
        return dp[idx][partitionCount];
    }

    int ways = 0;
    if ((s[idx]-'0') % 2 == 0) {
        for (int j = idx+m-1; j < s.size()-1; j++) {
            int currNum = s[j]-'0';
            int nextNum = s[j+1]-'0';
            if (currNum%2 != 0 && nextNum%2 == 0) {
                ways += solve(m, k, j+1, partitionCount+1, s);
            }
        }
    }
    return dp[idx][partitionCount] = ways%MOD;
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    if ((s[0]-'0')%2 != 0 || (s[s.size()-1]-'0')%2 == 0) {
        cout << 0 << endl;
    }
    else {
        dp.resize(n, vector<int>(k, -1));
        cout << solve(m, k, 0, 1, s) << endl;
    }
    return 0;
}