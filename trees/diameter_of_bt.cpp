#include<iostream>
#include<vector>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
int diameterOfBinaryTree(node* root) {
    int d = 0;
    height(root, d);
    return d;
}
int height(node* node, int& d) {
    if (!node) {
        return 0;
    }
    int lh = height(node->left, d);
    int rh = height(node->right, d);
    d = max(d, lh + rh);
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