#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        void permutations(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
            if (ds.size() == nums.size())
            {
                ans.push_back(ds);
                return;
            }
            for(int i =0; i<nums.size();i++){
                if(!freq[i]){
                    ds.push_back(nums[i]);
                    freq[i] = 1;
                    permutations(ds, nums, ans, freq);
                    freq[i] = 0;
                    ds.pop_back();
                }
            }
        }
        vector<vector<int>> p(vector<int> &nums){
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[nums.size()] = {0};
            for (int i = 0; i < nums.size(); i++) freq[i] = 0;
            permutations(ds, nums, ans, freq);
            return ans;
        }
};

int main()
{
    Solution obj;
    vector<int> v{1,2,3};
    vector < vector < int >> sum = obj.p(v);
    cout << "All Permutations are " << endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++) cout << sum[i][j] << " ";
        cout << endl;
        }
    return 0;
}