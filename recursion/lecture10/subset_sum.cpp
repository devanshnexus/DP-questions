#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
        void f(int ind, vector<int> &arr,int n, vector<int> &ans, int sum){
            if(ind==n){
                ans.push_back(sum);
                return;
            }
            //element is picked
            f(ind+1,arr,n,ans,sum+arr[ind]);
            // element is not picked
            f(ind+1,arr,n,ans,sum);
        }
        vector<int> subsetSum(vector<int> &arr, int n){
            vector<int> ans;
            f(0,arr,n,ans,0);
            sort(ans.begin(),ans.end());
            return ans;
        }
};
int main()
{
    vector < int > arr{3,1,2};
    Solution ob;
    vector < int > ans = ob.subsetSum(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout<<"The sum of each subset is "<<endl;
    for (auto sum: ans) {
        cout << sum << " ";
        }
    cout << endl;
    return 0;
}