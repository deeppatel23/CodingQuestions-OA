/*
OA Q Source:    https://leetcode.com/discuss/interview-question/1733741/Amazon-OA-or-SDE-Intern
                https://leetcode.com/discuss/interview-question/2093758/amazon-oa-2022-fall-sde-intern-europe   
You are given a black & white image in form of m*n pixel matrix grid.

if pixel[i][j] = 0 then pixel is black
if pixel[i][j] = 1 then pixel is white
Calculate maximum greyness of image.
Where greyness of a pixel[i][j] = (number of 1s in ith row + number of 1s in jth column) - (number of 0s in ith row + number of 0s in jth column)


Ip   
3 3
1 1 1
0 0 0
0 0 1
Op: 4

Ip
3 3
1 1 1
0 0 0
0 0 0
OP: 2

*/

#include<bits/stdc++.h>
using namespace std;

int maximumGreyness(int n, int m, vector<vector<int>>&grid) {
    vector<int>onesInRows(n);
    vector<int>onesInCols(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            onesInRows[i] += grid[i][j];
            onesInCols[j] += grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr = 2*(onesInRows[i] + onesInCols[j]) - n - m;
            ans = max(ans, curr);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>>grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << maximumGreyness(n, m, grid) << endl;
    return 0;
}

//TC: O(N+M)
//SC: O(N*M)