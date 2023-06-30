#include<iostream>
#include<vector>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
bool isBalanced(node* root) {
    return dfsHeight (root) != -1;
}
int dfsHeight (node *root) {
    if (root == NULL) return 0;
    int lh = dfsHeight (root -> left);
    int rh = dfsHeight (root -> right);
    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max (lh, rh) + 1;
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