/*
OA Q Source:    https://leetcode.com/discuss/interview-question/1733741/Amazon-OA-or-SDE-Intern
                https://leetcode.com/discuss/interview-question/2093758/amazon-oa-2022-fall-sde-intern-europe  

Several satellites provide observational black and white images which are stored in data centers at Amazon Web Services (AWS), 
A black and white image is composed of pixels and is represented as an (n*m) grid of cells, Each pixel can have a value of 0 or 1, where 0 represents a white pixel and 1 represents a black pixel. 
The greyness of a cell (i,j) is affected by the pixel values in the th row and the th column. More formally, the greyness of the cell (i,j) is the difference between the number of black pixels in the i'th row and the j'th column and the number of white pixels in the i'th row and the j'th column. 
Find the maximum greyness among all the cells of the grid.

Example : pixels = ['101','001','110']

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

int maximumGreyness(int n, int m, vector<vector<char>>&grid) {
    vector<int>onesInRows(n);
    vector<int>onesInCols(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            onesInRows[i] += grid[i][j] - '0';
            onesInCols[j] += grid[i][j] - '0';
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
    
    vector<vector<char>>grid(n, vector<char>(m));
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