#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int prime = 1e9+7;
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){       
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}
int subsequenceCounting2(string &s1, string &s2, int n, int m) {
    vector<int> prev(m+1,0);
    prev[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--){ 
            if(s1[i-1]==s2[j-1])
                prev[j] = (prev[j-1] + prev[j])%prime;
            else
                prev[j] = prev[j]; 
        }
    }
    return prev[m];
} 

int main() {
    string s1 = "babgbag";
    string s2 = "bag";
    cout << "The Count of Distinct Subsequences is "<<subsequenceCounting(s1,s2,s1.size(),s2.size())<<endl;
    cout << "The Count of Distinct Subsequences is "<<subsequenceCounting2(s1,s2,s1.size(),s2.size());
}