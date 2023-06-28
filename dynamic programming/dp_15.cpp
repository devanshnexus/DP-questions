#include<iostream>
#include<vector>
using namespace std;
bool canPartition(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    prev[0] = true;// first element of any row must be true
    if(arr[0]<=k)
        prev[arr[0]] = true;
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;// first element of any row must be true
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main() {
    vector<int> arr = {2,3,3,3,4,5};
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    if (sum%2 != 0){
        cout<<"The Array cannot be partitioned into two equal subsets";
    }
    int k=sum/2;
    if(canPartition(n,k,arr))
        cout<<"The Array can be partitioned into two equal subsets";
    else 
        cout<<"The Array cannot be partitioned into two equal subsets";
}