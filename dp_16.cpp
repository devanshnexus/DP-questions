#include<iostream>
#include<vector>
using namespace std;
int minSubsetSumDiff(vector<int> &arr, int n){
    int totSum = 0;
    for(int i = 0; i<n; i++) totSum += arr[i];
    vector < bool > prev(totSum + 1, false);
    prev[0] = true;
    if (arr[0] <= totSum) prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++) {
        vector < bool > cur(totSum + 1, false);
        cur[0] = true;
        for (int target = 1; target <= totSum; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target) taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    int mini =1e9;
    for (int s1 = 0; s1 <= totSum/2; s1++){
        if(prev[s1] == true){
            mini = min(mini, abs((totSum - s1)- s1));
        }
    }
    return mini;
}
int main()
{
    vector<int> arr = {1,2,3,4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDiff(arr, n);
  }