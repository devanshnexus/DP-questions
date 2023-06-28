#include<iostream>
#include<vector>
using namespace std;
int matrixMultiplication(vector<int>& arr, int N){
    vector<vector<int>> dp(N,vector<int>(N,-1));
    for(int i=1; i<N; i++){
        dp[i][i] = 0;}
    for(int i=N-1; i>=1; i--){
        for(int j=i+1; j<N; j++){
            int mini = INT_MAX;
            for(int k = i; k<= j-1; k++){
                int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini,ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

int main() {
	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();
	cout<<"The minimum number of operations are "<<matrixMultiplication(arr,n);
	return 0;
}