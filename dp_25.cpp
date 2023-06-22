#include<iostream>
#include<vector>
using namespace std;
// recursion with memoisation
// int lcsUtil(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
//     if(ind1<0 || ind2<0)
//         return 0;
//     if(dp[ind1][ind2]!=-1)
//         return dp[ind1][ind2];
//     if(s1[ind1] == s2[ind2])
//         return dp[ind1][ind2] = 1 + lcsUtil(s1,s2,ind1-1,ind2-1,dp);
//     else 
//         return dp[ind1][ind2] = 0 + max(lcsUtil(s1,s2,ind1,ind2-1,dp),lcsUtil
//        (s1,s2,ind1-1,ind2,dp));}
int lcs(string s1, string s2) {
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    return dp[n][m];
}
int lcs2(string s1, string s2) {
    int n=s1.size();
    int m=s2.size();
    vector<int> prev(m+1,0), cur(m+1,0);    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    return prev[m];
}

int main() {
    string s1= "acd";
    string s2= "ced";                     
    cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2)<<endl;
    cout<<"The Length of Longest Common Subsequence is "<<lcs2(s1,s2)<<endl;
}