#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include <unordered_map>
using namespace std;
class Solution{
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word, vector<string> &seq){ 
        if (word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];
        for (int i = 0; i < sz; i++){
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string bW, string eW, vector<string> &wL){
        unordered_set<string> st(wL.begin(), wL.end());
        queue<string> q;
        b = bW;
        q.push({bW});
        mpp[bW] = 1;
        int sz = bW.size();
        st.erase(bW);
        while (!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if (word == eW)
                break;
            for (int i = 0; i < sz; i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(eW) != mpp.end()){
            vector<string> seq;
            seq.push_back(eW);
            dfs(eW, seq);
        }
        return ans;
    }
};
bool comp(vector<string> a, vector<string> b){
    string x = "", y = "";
    for (string i : a) x += i;
    for (string i : b) y += i;
    return x < y;
}

int main(){
    vector<string> wL = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findLadders(startWord, targetWord, wL);
    if (ans.size() == 0)
        cout << -1 << endl;
    else{
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}