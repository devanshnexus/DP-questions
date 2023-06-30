#include<iostream>
#include<vector>

using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
//left side view
void recursion(node *root, int level, vector<int> &res){
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->data);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
}
vector<int> leftSideView(node *root) {
    vector<int> res;
    recursion(root, 0, res);
    return res;
}
//right side view
void recursion(node *root, int level, vector<int> &res){
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->data);
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res);
}
vector<int> rightSideView(node *root) {
    vector<int> res;
    recursion(root, 0, res);
    return res;
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