/*
Got this question in microsoft OA round:

A garbage truck collects plastic, metal and glass garbages(one at a time) from N houses. Array D consists of time taken by the truck to carry a particular garbage from ith house. Array T consists of string values(M -> Metal, G -> Glass, P -> Plastic) stating the type of garbages present in ith house.
Calculate the minimum time taken by the truck to collect all the garbages and return back to its garage.

Input:
            D: [3, 2, 4]
            T: ["MPM", "", "G"]
Output:     19
Explanation:
Metal Truck Time:   3 (time to reach 0th house) + 2 (pick 2 unit of metal) + 3 (return from 0th home to back) = 8
Plastic Truck Time: 3 (time to reach 0th house) + 1 (pick 1 unit of plastic) + 3 (return from 0th home to back) = 7
Glass Truck Time:   3 (time to reach 0th house) + 2 (time to reach 1st house) + 4 (time to reach 2nd house) + 1 (pick 1 unit of glass)
                    + 4 + 2 + 3 (time to return) = 19
Maximum time taken by glass truck, so answer is 19


Input:
            D: [2,1,1,1,2]
            T: ["", "PP", "PP", "GM", ""]
Output:     12
Explanation:
Metal Truck Time:   2 (0th house) + 1 (1st house) + 1 (2nd house) + 1 (3rd house) + 1 (pick) + 5 (return) = 11
Plastic Truck Time: 2 (0th house) + 1 (1st house) + 2 (pick 2 unit) + 1 (2nd house) + 2 (pick 2 unit) + 4 (return) = 12
Glass Truck Time:   2 (0th house) + 1 (1st house) + 1 (2nd house) + 1 (3rd house) + 1 (pick) + 5 (return) = 11
Maximum time taken by plastic truck, so answer is 19

*/
#include<bits/stdc++.h>
using namespace std;

/*
//BRUTE-FORCE Approach
int minTimeToCollectGarbage(vector<int>&d, vector<string>&t) {
    int pTravel = 0, pPick = 0, mTravel = 0, mPick = 0, gTravel = 0, gPick = 0;
    int n = d.size();
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += d[i];
        for (auto s : t[i]) {
            if (s == 'P') {
                pPick++;
                pTravel = temp;
            }
        }
    }
    pTravel = 2 * pTravel;

    temp = 0;
    for (int i = 0; i < n; i++) {
        temp += d[i];
        for (auto s : t[i]) {
            if (s == 'M') {
                mPick++;
                mTravel = temp;
            }
        }
    }
    mTravel = 2 * mTravel;

    temp = 0;
    for (int i = 0; i < n; i++) {
        temp += d[i];
        for (auto s : t[i]) {
            if (s == 'G') {
                gPick++;
                gTravel = temp;
            }
        }
    }
    gTravel = 2 * gTravel;

    int ans = max({pTravel+pPick, mTravel+mPick, gTravel+gPick});
    return ans;
}
*/

int minTimeToCollectGarbage(vector<int>&d, vector<string>&t) {
    int pTravel = 0, pPick = 0, mTravel = 0, mPick = 0, gTravel = 0, gPick = 0;
    int n = d.size();
    int pTemp = 0, mTemp = 0, gTemp = 0;
    for (int i = 0; i < n; i++) {
        pTemp += d[i];
        mTemp += d[i];
        gTemp += d[i];
        for (auto s : t[i]) {
            if (s == 'P') {
                pPick++;
                pTravel = pTemp;
            }
            else if (s == 'M') {
                mPick++;
                mTravel = pTemp;
            }
            else if (s == 'G') {
                gPick++;
                gTravel = pTemp;
            }
        }
    }
    pTravel = 2 * pTravel;
    mTravel = 2 * mTravel;
    gTravel = 2 * gTravel;

    int ans = max({pTravel+pPick, mTravel+mPick, gTravel+gPick});
    return ans;
}

int main() {

    // vector<int>d = {2,1,1,1,2} ;
    // vector<string>t = {"", "PP", "PP", "GM", ""};

    vector<int>d = {3, 2, 4} ;
    vector<string>t = {"MPM", "", "G"};

    cout << minTimeToCollectGarbage(d, t) << endl;
    return 0;
}