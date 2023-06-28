#include<iostream>
#include<vector>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            bool notTaken = dp[ind-1][target];
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
            dp[ind][target]= notTaken||taken;
        }
    }
    return dp[n-1][k];
}
bool subsetSumToK2(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    prev[0] = true;// first element of any row must be true
    if(arr[0]<=k)
        prev[arr[0]] = true;
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;// first element of any row must be true
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main() {
    vector<int> arr = {1,2,3,4};
    int k=4;
    int n = arr.size();                     
    if(subsetSumToK(n,k,arr))
        cout<<"Subset with given target found";
    else 
        cout<<"Subset with given target not found";
}