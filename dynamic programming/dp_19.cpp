#include<iostream>
#include<vector>
using namespace std;
// int f(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){
//     if(ind == 0){
//         if(wt[0] <=W) return val[0];
//         else return 0;
//     }
//     if(dp[ind][W]!=-1)
//         return dp[ind][W];   
//     int notTaken = 0 + f(wt,val,ind-1,W,dp);
//     int taken = INT_MIN;
//     if(wt[ind] <= W)
//         taken = val[ind] + f(wt,val,ind-1,W-wt[ind],dp);
//     return dp[ind][W] = max(notTaken,taken);
// }
int knapsack(vector<int>& wt, vector<int>& val, int n, int W){   
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    for (int i = wt[0]; i <= W; i++) dp[0][i] = val[0];
    for (int ind = 1; ind < n; ind++){
        for (int w = 0; w <= W; w++){
            int notTaken = 0 + dp[ind-1][w];
            int taken = INT_MIN;
            if(wt[ind] <= w) 
                taken = val[ind] + dp[ind-1][w-wt[ind]];
            dp[ind][w] = max(taken,notTaken);
        }
    }
    return dp[n-1][W];
}

int knapsack2(vector<int>& wt, vector<int>& val, int n, int W){
    vector<int> prev(W+1,0);
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){       
            int notTaken = 0 + prev[cap];
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];
                
            prev[cap] = max(notTaken, taken);
        }
    } 
    return prev[W];
}

int main() { 
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    int W=5;
    int n = wt.size();                       
    cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W)<<endl;
    cout<<"The Maximum value of items, thief can steal is " <<knapsack2(wt,val,n,W);
}