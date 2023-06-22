#include<iostream>
#include<vector>
using namespace std;

long long int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
long long int houseRobber(vector<int> &valueInHouse){
    vector<int> temp1,temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for (int i = 0; i < n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(solve(n, temp1),solve(n, temp2));
}

int main() {
    vector<int> arr{2,1,4,9};
    int n=arr.size();
    cout<<solve(n,arr);

}