#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
    int data;
    struct node * left, * right;
};

vector<int> levelOrder(Node* root) {
    vector<int> ans; 
    if(root == NULL) 
        return ans; 
    queue<Node*> q; 
    q.push(root); 
    while(!q.empty()) {
        Node *temp = q.front(); 
        q.pop(); 
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
        ans.push_back(temp->data); 
    }
    return ans; 
}

int main()
{
    return 0;
}