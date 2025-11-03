#include <bits/stdc++.h>
using namespace std;

// Merge two skylines
vector<vector<int>> mergeSkylines(vector<vector<int>>& left, vector<vector<int>>& right)
{
    // TC: O(1), SC: O(1) -> variables
    int h1 = 0, h2 = 0, i = 0, j = 0;
    vector<vector<int>> merged;  // TC: O(1), SC: O(n)
    while (i < left.size() && j < right.size())
    {  // TC: O(n)
        int x;
        if (left[i][0] < right[j][0])
        {  // TC: O(1)
            x = left[i][0];
            h1 = left[i][1];
            i++;  // TC: O(1)
        }
        else
        {
            x = right[j][0];
            h2 = right[j][1];
            j++;  // TC: O(1)
        }
        int max_h = max(h1, h2);                          // TC: O(1)
        if (merged.empty() || merged.back()[1] != max_h)  // TC: O(1)
            merged.push_back({x, max_h});                 // TC: O(1)
    }
    while (i < left.size()) merged.push_back(left[i++]);    // TC: O(n), SC: O(n)
    while (j < right.size()) merged.push_back(right[j++]);  // TC: O(n), SC: O(n)
    return merged;                                          // TC: O(1)
}

// Recursive skyline function
vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
    if (buildings.empty())
        return {};  // TC: O(1)
    if (buildings.size() == 1)
    {  // TC: O(1)
        int x1 = buildings[0][0], x2 = buildings[0][1], h = buildings[0][2];
        return {{x1, h}, {x2, 0}};  // TC: O(1)
    }
    int mid = buildings.size() / 2;                                        // TC: O(1)
    vector<vector<int>> left(buildings.begin(), buildings.begin() + mid);  // TC: O(n/2)
    vector<vector<int>> right(buildings.begin() + mid, buildings.end());   // TC: O(n/2)
    auto lSky = getSkyline(left);                                          // TC: T(n/2)
    auto rSky = getSkyline(right);                                         // TC: T(n/2)
    return mergeSkylines(lSky, rSky);                                      // TC: O(n)
}

// Driver
int main()
{
    vector<vector<int>> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    auto result = getSkyline(buildings);
    cout << "Skyline: ";
    for (auto& p : result) cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;

    /*
    Overall Time Complexity: O(n log n)
    - Divide & Conquer with merging at each level

    Overall Space Complexity: O(n)
    - Recursion O(log n)
    - Skyline storage O(n)
    */
}
