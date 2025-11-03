// Implement convex hull (divide-and-conquer approach).
#include <bits/stdc++.h>
using namespace std;

using P = pair<double, double>;

// -------------- Utility --------------

static inline double cross(const P& o, const P& a, const P& b)
{
    // TC: O(1), SC: O(1)
    return (a.first - o.first) * (b.second - o.second) -
           (a.second - o.second) * (b.first - o.first);
}

static int rightmost(const vector<P>& h)
{
    // TC: O(|h|), SC: O(1)
    int idx = 0;
    for (int i = 1; i < (int)h.size(); ++i)
    {
        if (h[i].first > h[idx].first ||
            (h[i].first == h[idx].first && h[i].second < h[idx].second))
            idx = i;
    }
    return idx;  // O(1)
}

static int leftmost(const vector<P>& h)
{
    // TC: O(|h|), SC: O(1)
    int idx = 0;
    for (int i = 1; i < (int)h.size(); ++i)
    {
        if (h[i].first < h[idx].first ||
            (h[i].first == h[idx].first && h[i].second < h[idx].second))
            idx = i;
    }
    return idx;  // O(1)
}

// -------------- Merge two convex hulls (both CCW) --------------

static vector<P> mergeHulls(const vector<P>& L, const vector<P>& R)
{
    // Assumes L and R are convex hulls (CCW, no duplicates across them).
    // TC: O(|L| + |R|), SC: O(1) extra (excluding output)
    int ui = rightmost(L);  // TC: O(|L|)
    int uj = leftmost(R);   // TC: O(|R|)

    // Upper tangent
    bool moved = true;  // O(1)
    while (moved)
    {                   // Amortized ≤ |L|+|R|
        moved = false;  // O(1)
        // advance uj while turn (L[ui], R[uj], R[uj+1]) is CCW
        while (cross(L[ui], R[uj], R[(uj + 1) % R.size()]) > 0)
        {                              // amort. O(|R|)
            uj = (uj + 1) % R.size();  // O(1)
            moved = true;              // O(1)
        }
        // advance ui while turn (R[uj], L[ui], L[ui-1]) is CW
        while (cross(R[uj], L[ui], L[(ui - 1 + L.size()) % L.size()]) < 0)
        {                                         // amort. O(|L|)
            ui = (ui - 1 + L.size()) % L.size();  // O(1)
            moved = true;                         // O(1)
        }
    }

    // Lower tangent
    int li = rightmost(L);  // TC: O(|L|)
    int lj = leftmost(R);   // TC: O(|R|)
    moved = true;           // O(1)
    while (moved)
    {                   // Amortized ≤ |L|+|R|
        moved = false;  // O(1)
        // advance lj while turn (L[li], R[lj], R[lj-1]) is CW
        while (cross(L[li], R[lj], R[(lj - 1 + R.size()) % R.size()]) < 0)
        {                                         // amort. O(|R|)
            lj = (lj - 1 + R.size()) % R.size();  // O(1)
            moved = true;                         // O(1)
        }
        // advance li while turn (R[lj], L[li], L[li+1]) is CCW
        while (cross(R[lj], L[li], L[(li + 1) % L.size()]) > 0)
        {                              // amort. O(|L|)
            li = (li + 1) % L.size();  // O(1)
            moved = true;              // O(1)
        }
    }

    // Build merged hull in CCW: L from ui→li, then R from lj→uj
    vector<P> merged;        // SC: O(|L|+|R|) for output
    int k = ui;              // O(1)
    merged.push_back(L[k]);  // O(1)
    while (k != li)
    {                                 // visits ≤ |L| vertices → O(|L|)
        k = (k + 1) % (int)L.size();  // O(1)
        merged.push_back(L[k]);       // O(1)
    }
    k = lj;                  // O(1)
    merged.push_back(R[k]);  // O(1)
    while (k != uj)
    {                                 // visits ≤ |R| vertices → O(|R|)
        k = (k + 1) % (int)R.size();  // O(1)
        merged.push_back(R[k]);       // O(1)
    }
    return merged;  // O(1)
}

// -------------- Base hull for ≤ 3 points --------------

static vector<P> baseHull(vector<P> pts)
{
    // Returns CCW hull for ≤3 points; keeps only endpoints if collinear.
    // TC: O(1) (size ≤ 3), SC: O(1)
    sort(pts.begin(), pts.end());  // O(1) for ≤3
    if (pts.size() <= 1)
        return pts;  // O(1)
    if (pts.size() == 2)
        return pts;                        // O(1)
    P a = pts[0], b = pts[1], c = pts[2];  // O(1)
    double cr = cross(a, b, c);            // O(1)
    if (fabs(cr) < 1e-12)
        return {a, c};  // collinear → keep endpoints
    if (cr > 0)
        return {a, b, c};  // CCW
    else
        return {a, c, b};  // CW → flip to CCW
}

// -------------- Divide & Conquer driver --------------

static vector<P> solveRec(vector<P> pts)
{
    // Assumes pts are distinct and sorted by (x,y)
    // TC: T(n) = 2T(n/2) + O(n) → O(n log n); SC: O(log n) recursion + output
    int n = (int)pts.size();  // O(1)
    if (n <= 3)
        return baseHull(pts);  // O(1)

    int mid = n / 2;                              // O(1)
    vector<P> L(pts.begin(), pts.begin() + mid);  // O(n/2) copy
    vector<P> R(pts.begin() + mid, pts.end());    // O(n/2) copy
    auto LH = solveRec(L);                        // T(n/2)
    auto RH = solveRec(R);                        // T(n/2)
    return mergeHulls(LH, RH);                    // O(n)
}

vector<P> convex_hull_divide_and_conquer(vector<P> points)
{
    // Sort & unique
    // TC: O(n log n), SC: O(n)
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());  // O(n)
    if ((int)points.size() <= 3)
        return baseHull(points);  // O(1)
    return solveRec(points);      // O(n log n)
}

// ------------------ Example ------------------

int main()
{
    vector<P> pts = {{0, 0}, {1, 1}, {2, 2}, {0, 3}, {3, 0}, {3, 3}, {1, 2}, {2, 1}};
    auto hull = convex_hull_divide_and_conquer(pts);
    for (auto& p : hull) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";
    return 0;
}

/*
==================== OVERALL COMPLEXITY ====================
Time Complexity:
- Sort points: O(n log n)
- Divide & Conquer hull merge: T(n)=2T(n/2)+O(n) → O(n log n)
- Overall: O(n log n)

Space Complexity:
- Sorting copy + unique + output hull: O(n)
- Recursion depth: O(log n)
- Merge uses O(1) extra (besides output)
- Overall: O(n)
============================================================
*/
