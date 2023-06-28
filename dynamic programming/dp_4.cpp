#include<iostream>
#include<vector>
using namespace std;
int frogJump(int ind, vector<int>& height, int n, int k){
    vector<int> dp(n,-1);
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump = frogJump(ind-j, height, n, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
}
int frogJump2(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}
int main() {
    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n=height.size();
    int k=2;
    vector<int> dp(n,-1);
    cout<< frogJump(n-1, height, n, k);
    cout<< frogJump2(n, height, dp, k);
}
