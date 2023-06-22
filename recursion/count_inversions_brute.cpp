#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {5 , 3 , 2 , 4 , 1};
    int n = arr.size();
    int count =0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (arr[i]>arr[j]){
                count +=1;
            }
        }   
    }
    cout<<count;
    return 0;
}