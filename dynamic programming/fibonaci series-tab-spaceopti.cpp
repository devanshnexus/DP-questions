#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // tabulation
    // int dp[n];
    // dp[0] = 0;
    // dp[1] =1;
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout<<dp[n];
    // return 0;
    // space optimization
    int p2 = 0;
    int p = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr_i = p + p2;
        p2 = p;
        p = curr_i;
    }
    cout<< p;
}