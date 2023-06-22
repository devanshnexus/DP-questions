#include<iostream>
#include<vector>
using namespace std;
int mod = (int)(1e9 + 7);
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if (i>= 0 && j >= 0 && mat[i][j] == -1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j,mat,dp);
    int left = f(i, j-1,mat,dp);
    return dp[i][j] = (up + left);
}
// int uniquePaths(int m, int n, vector<vector<int>> &mat){
//     vector<vector<int>> dp(m, vector<int>(n,-1));
//     return f(m-1,n-1,mat, dp);
// }
int uniquePaths2(int m, int n){
    int dp[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(dp[i][j] == -1) dp[i][j]= 0;
            if(i==0 && j==0) dp[i][j] = 1;
            else{
                int up =0;
                int left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left =dp[i][j-1];
                dp[i][j] = (up + left)%mod;
            }
        }
        
    }
    return dp[n-1][m-1];
}
int main()
{
    int m=3;
    int n=2;
  
    cout<<uniquePaths2(m,n);
    return 0;
}
