#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        void findComb(int i, int target, vector<int> &arr, vector<vector <int>> &ans, vector<int> &ds){
            if (i == arr.size()){
                if(target == 0){
                    ans.push_back(ds);
                }
                return;
            }
            if (arr[i]<=target){
                ds.push_back(arr[i]);
                findComb(i,target-arr[i], arr, ans, ds);
                ds.pop_back();
            }
            findComb(i+1,target, arr, ans, ds);
        }
    public:
        vector<vector<int>> combSum(vector<int> &cand, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findComb(0, target, cand, ans, ds);
            return ans;
        }
};
int main()
{
    Solution obj;
    vector < int > v {2,3,6,7};
    int target = 7;
    vector < vector < int >> ans = obj.combSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
        cout << ans[i][j] << " ";
    cout << endl;}
    return 0;
}