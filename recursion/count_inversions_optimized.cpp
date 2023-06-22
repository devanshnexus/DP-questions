#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int count =0;
    while (left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            count += (mid - left +1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for ( int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    return count;   
}
int mS(vector<int> &arr, int low, int high){
    int count =0;
    if(low == high) return count;
    int mid = (low + high)/2;
    count += mS(arr, low, mid);
    count += mS(arr, mid+1, high);
    count += merge(arr,low,mid,high);
    return count;
}

int countInversions(vector<int> &a, int n){
    return mS(a, 0, n-1);
}
int main()
{
    vector<int> arr = { 5 , 3 , 2 , 4 , 1};
    int n = arr.size();
    cout<< countInversions(arr,n);
    return 0;
}