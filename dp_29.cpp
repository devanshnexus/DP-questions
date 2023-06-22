#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lcs(string s1, string s2) {   
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

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int minInsertion(string s){
    int n = s.size();
    int k = longestPalindromeSubsequence(s);
    return n-k;
}

int main() {

    string s= "abcaa";
    cout<<"The Minimum insertions required to make string palindrome: "<<minInsertion(s);
}