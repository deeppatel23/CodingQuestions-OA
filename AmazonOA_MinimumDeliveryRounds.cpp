/*
OA Q Source:    https://leetcode.com/discuss/interview-question/1733741/Amazon-OA-or-SDE-Intern
                https://leetcode.com/discuss/interview-question/2093758/amazon-oa-2022-fall-sde-intern-europe   

You are an amazon delivery and you have some boxes that you have to deliver, but there are some conditions -

You can take 2 boxes of same weight in one round
you can take 3 boxes of same weight in one round
You have to find the minimum number of rounds to deliver the boxes or -1 if it is not possible to deliver them.

Example cases -
Input: n = 10 boxes - {2 2 3 3 2 4 4 4 4 4}
Output: 4
Explanation: 3 boxes of weight 2 in 1st round, 2 boxes of weight 3 in 2nd round, 3 boxes of wt 4 in 3rd and 2 boxes of wt 4 in 4th round.

Input: n = 3 boxes - {2 3 3}
Output: -1
Explanation: There is only one box with weight 2 and we can only take either 2 or 3 boxes in one round not lesser.

Similar LeetCode Q: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

-----------------------------------------------------------------------
NOTE: Any number of except 1 can be represented by sum of 2s and 3s
EG: 7 = 3 + 2 + 2
    11 = 3 + 3 + 3 + 2
    19 = 3(5) + 2 + 2 
-----------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

int minimumDeliveryRounds(int n, vector<int>&boxes) {
    unordered_map<int, int>u;

    for (auto &b : boxes) {
        u[b]++;
    }

    int count = 0;
    for (auto it : u) {
        int freq = it.second;
        if (freq == 1) {
            return -1;
        }
        else {
            if (freq%3 != 0) {
                count += freq/3 + 1;
            }
            else {
                count += freq/3;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int>boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }
    cout << minimumDeliveryRounds(n, boxes) << endl;
    return 0;
}


//TC: O(N)
//SC: O(N)