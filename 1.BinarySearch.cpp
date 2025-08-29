// Implement standard binary search.
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int left, int right , int target){
    if(left>right) return -1;                                               // TC :- O(1) 
    int mid = left + (right  - left)/2;                                     // TC :- O(1)
    if(arr[mid] == target)                                                  // TC :- O(1)
        return mid;                                                         // TC :- O(1)
    else if(arr[mid]>target)                                                // TC :- O(1)
        return binarySearch(arr, left, right,target);                       // TC :- T(n/2)
    else                                                                    // TC :- O(1)
        return binarySearch(arr, mid + 1, right,target);                    // TC :- T(n/2)
}
int main(){
    vector<int> arr = {2,4,6,8,10,12,14} ;
    int target;
    cout<<" Enter Target Element ";
    cin >> target;
    int result = binarySearch(arr,0,arr.size() - 1, target);
    if(result != -1)
    cout<<result<<endl;
    else
    cout<<"Element not found!"<<endl;
    return 0;
}