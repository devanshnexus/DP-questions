#include<iostream>
#include<vector>
using namespace std;
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    int right = INT_MAX;
    if(ind>1)
        right = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(left, right);
}
int frogJump(int n, vector<int> &height){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        int fs = dp[i-1]+abs(height[i]-height[i-1]);
        int ss = INT_MAX;
        if (i>1) ss = dp[i-2]+abs(height[i]-height[i-2]);
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}

int frogJump2(int n, vector<int> &height){
    int prev = 0;
    int prev2 = 0;
    int curr_i = 0;
    for (int i = 1; i < n; i++){
        int fs = prev+abs(height[i]-height[i-1]);
        int ss = INT_MAX;
        if (i>1) ss = prev2+abs(height[i]-height[i-2]);
        curr_i = min(fs,ss);
        prev2 = prev;
        prev = curr_i;
    }
    return prev;
}

int main() {
    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n=height.size();
    vector<int> dp(n,-1);
    cout<<solve(n-1,height,dp)<<endl;
    cout<<frogJump(n,height)<<endl;
    cout<<frogJump2(n,height)<<endl;
}