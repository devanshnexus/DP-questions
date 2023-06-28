#include<iostream>
#include<vector>
using namespace std;
// recursion with memoisation
// long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){
//     if(ind==n) return 0;
//     if(dp[ind][buy]!=-1) return dp[ind][buy];
//     long profit;
//     if(buy==0){// We can buy the stock
//         profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));}
//     if(buy==1){// We can sell the stock
//         profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));}
//     return dp[ind][buy] = profit;}
long getMaximumProfit(long *Arr, int n){
    vector<vector<long>> dp(n+1,vector<long>(2,-1));
    dp[n][0] = dp[n][1] = 0;
    long profit;
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
            if(buy==1){
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+1][0]);
            }
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];
}
long getMaximumProfit2(long *Arr, int n){
    vector<long> ahead (2,0);
    vector<long> cur(2,0);
    ahead[0] = ahead[1] = 0;
    long profit;
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){
                profit = max(0+ahead[0], -Arr[ind] + ahead[1]);
            }
            if(buy==1){
                profit = max(0+ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy]  = profit;
        }
        ahead = cur;
    }
    return cur[0];
}
int main() {
    int n =6;
    long Arr[n] = {7,1,5,3,6,4};                     
    cout<<"The maximum profit that can be generated is "<<getMaximumProfit(Arr, n)<<endl;
    cout<<"The maximum profit that can be generated is "<<getMaximumProfit2(Arr, n);
}