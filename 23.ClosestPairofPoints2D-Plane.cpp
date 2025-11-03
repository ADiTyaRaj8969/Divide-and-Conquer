// Implement divide-and-conquer algorithm for closest pair of points in 2D plane.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance
double dist(pair<int, int> p1, pair<int, int> p2)
{
    // O(1)
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

// Brute force for small subarrays (<=3 points)
double bruteForce(vector<pair<int, int>>& pts, int l, int r)
{
    // O((r-l)^2) in worst case small subset
    double mn = DBL_MAX;
    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            mn = min(mn, dist(pts[i], pts[j]));  // O(1)
        }
    }
    return mn;
}

// Function to calculate minimum distance in strip
double stripClosest(vector<pair<int, int>>& strip, double d)
{
    // Sort by y-coordinate -> O(n log n) but n is small
    sort(strip.begin(), strip.end(), [](auto& a, auto& b) { return a.second < b.second; });

    double mn = d;
    // Compare each point with next up to 6 neighbors
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < mn; j++)
        {
            mn = min(mn, dist(strip[i], strip[j]));  // O(1)
        }
    }
    return mn;  // O(n) overall
}

// Divide and Conquer function
double closestUtil(vector<pair<int, int>>& pts, int l, int r)
{
    if (r - l <= 3)
        return bruteForce(pts, l, r);  // base case O(1)

    int mid = (l + r) / 2;
    pair<int, int> midPoint = pts[mid];

    // Solve for left half
    double dl = closestUtil(pts, l, mid);  // T(n/2)
    // Solve for right half
    double dr = closestUtil(pts, mid + 1, r);  // T(n/2)

    double d = min(dl, dr);  // O(1)

    // Build strip of points within distance d from mid line
    vector<pair<int, int>> strip;
    for (int i = l; i <= r; i++)
    {
        if (abs(pts[i].first - midPoint.first) < d)
        {
            strip.push_back(pts[i]);  // O(n)
        }
    }
    // Find closest in strip
    return min(d, stripClosest(strip, d));  // O(n)
}

// Main function
double closestPair(vector<pair<int, int>>& pts)
{
    sort(pts.begin(), pts.end());  // Sort by x-coordinate O(n log n)
    return closestUtil(pts, 0, pts.size() - 1);
}

int main()
{
    int n;
    cin >> n;  // Input number of points
    vector<pair<int, int>> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    cout << "Closest distance = " << closestPair(pts) << endl;
    return 0;
}

/*
Time Complexity:
- Sorting: O(n log n)
- Divide and Conquer recurrence: T(n) = 2T(n/2) + O(n) → O(n log n)
Space Complexity:
- Recursive stack O(log n)
- Strip temporary vector O(n)
Overall: O(n)
*/
