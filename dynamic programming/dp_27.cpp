#include<iostream>
#include<vector>
using namespace std;
int lcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
int lcs2(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    return ans;
}
int main() {
    string s1= "abcjklp";
    string s2= "acjkp";                     
    cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2)<<endl;
    cout<<"The Length of Longest Common Substring is "<<lcs2(s1,s2)<<endl;
}