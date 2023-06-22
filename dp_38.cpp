#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& Arr, int n, int k){
    vector<vector<int>> ahead(2,vector<int> (k+1,0));
    vector<vector<int>> cur(2,vector<int> (k+1,0));
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=k; cap++){
                if(buy==0){
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);}
                if(buy==1){
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    return ahead[0][k];
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();
    int k=2;                             
    cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n,k);
}