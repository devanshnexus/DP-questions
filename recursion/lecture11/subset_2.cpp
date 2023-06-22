#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printAns(vector < vector < int >> & ans) {
    cout << "The unique subsets are " << endl;
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
        }
    cout << " ]";
}
class Solution{
    public:
        void findSubsets(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans ){
            ans.push_back(ds);
            for(int i = ind; i<arr.size(); i++){
                if(i!=ind && arr[i]==arr[i-1]) continue;
                ds.push_back(arr[i]);
                findSubsets(i+1, arr, ds, ans);
                ds.pop_back();   
            }
        }
    public:
        vector<vector<int>> List(vector<int> &arr){
            vector<vector<int>> ans;
            vector<int> ds;
            sort(arr.begin(), arr.end());
            findSubsets(0, arr, ds, ans);
            return ans;
        }
};
int main()
{
    Solution obj;
    vector < int > nums = {1, 2, 2};
    vector < vector < int >> ans = obj.List(nums);
    printAns(ans);
  return 0;
    return 0;
}