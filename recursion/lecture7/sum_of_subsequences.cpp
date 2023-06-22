#include<iostream>
#include<vector>
using namespace std;
void printF(int i, vector<int> &ds,int s,int sum, int arr[], int n ){
    if(i == n){
        if (s==sum){
            for(auto it:ds){
            cout<< it<< "";
        }
        if(ds.size() ==0){
            cout<<"{}";
        }
        cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    s +=arr[i];
    printF(i+1,ds,s,sum,arr,n);
    s -= arr[i];
    ds.pop_back();
    printF(i+1, ds, s, sum, arr, n);
}
int main()
{
    int arr[] = {1,2,1};
    int n=3;
    int sum =2;
    vector<int> ds;
    printF(0, ds, 0, sum, arr, n);
    return 0;
}