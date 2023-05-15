/*
Discuss section links
https://leetcode.com/discuss/interview-question/3171616/Intuit-Intern-OA-oror-Offcampus-oror-India
https://leetcode.com/discuss/interview-question/2481231/Intuit-or-OA-or-Robber-on-Tree
https://leetcode.com/discuss/interview-question/2313460/Intuit-or-OA

Similar LC Q: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

LC Q you can practice: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

*/

class Solution {
public:
    vector<int>parent, disFromRoot;

    void dfsFromRoot(vector<int>adj[], int currNode, int par, int dis) {
        disFromRoot[currNode] = dis;
        parent[currNode] = par;

        for (auto neighbour : adj[currNode]) {
            if (neighbour != par)
                dfsFromRoot(adj, neighbour, currNode, dis+1);
        }
    }

    int maximumPathSum(vector<int>adj[], vector<int>&amount, int node, int parent) {
        int currAmount = amount[node];
        int maxAmountFromChild = INT_MIN;

        for (auto child : adj[node]) {
            if (child != parent) {
                maxAmountFromChild = max(maxAmountFromChild, maximumPathSum(adj, amount, child, node));
            }
        }
        if (maxAmountFromChild == INT_MIN)
            return currAmount;
        return currAmount+maxAmountFromChild;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int>adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.resize(n, 0);
        disFromRoot.resize(n, 0);
        dfsFromRoot(adj, 0, 0, 0);

        int bobCurrNode = bob, bobDis = 0;

        while (bobCurrNode != 0) {  //when bobCurrNode = 0 means it reached root
            if (disFromRoot[bobCurrNode] > bobDis) {
                amount[bobCurrNode] = 0; //bob will consume it first
            }
            else if (disFromRoot[bobCurrNode] == bobDis) {
                amount[bobCurrNode] /= 2;
            }
            bobCurrNode = parent[bobCurrNode];
            bobDis++;
        }

        return maximumPathSum(adj, amount, 0, 0);
    }
};