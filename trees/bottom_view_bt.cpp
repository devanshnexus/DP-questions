#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
vector <int> bottomView(node *root) {
    vector<int> ans; 
    if(root == NULL) return ans; 
    map<int,int> mpp; 
    queue<pair<node*, int>> q; 
    q.push({root, 0}); 
    while(!q.empty()) {
        auto it = q.front(); 
        q.pop(); 
        node* node = it.first; 
        int line = it.second; 
        mpp[line] = node->data;     
        if(node->left != NULL) {
            q.push({node->left, line-1}); 
        }
        if(node->right != NULL) {
            q.push({node->right, line + 1}); 
        }
    }
    for(auto it : mpp) {
        ans.push_back(it.second); 
    }
    return ans;  
}
struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return (node);
}

int main()
{
    return 0;
}