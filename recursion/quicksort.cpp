#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i<j){
        while (arr[i]<=pivot && i<=h-1){
            i++;
        }
        while (arr[j]>pivot && j>=l+1){
            j--;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}
void qS(vector<int> &arr, int l, int h){
    if (l<h){
        int part = partition(arr, l, h);
        qS(arr, l, part-1);
        qS(arr, part+1, h);
    }
    
}
int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();  
    qS(arr, 0, n-1);
    for(auto it:arr){
            cout<< it<< " ";}
    return 0;
}