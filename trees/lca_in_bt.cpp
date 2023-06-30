#include<iostream>
#include<vector>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
node* lowestCommonAncestor(node* root, node* p, node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { 
        return root;
    }
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