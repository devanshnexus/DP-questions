#include<iostream>
#include<vector>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
int maxDepth(node* root) {
    if(root == NULL) return 0; 
    int lh = maxDepth(root->left); 
    int rh = maxDepth(root->right); 
    return 1 + max(lh, rh); 
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