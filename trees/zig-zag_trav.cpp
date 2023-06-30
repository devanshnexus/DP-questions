#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node {
    int data;
    struct node * left, * right;
};
vector < vector < int >> zigzagLevelOrder(node * root) {
    vector < vector < int >> result;
    if (root == NULL) {
        return result;
    }
    queue < node * > nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;
    while (!nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector < int > row(size);
        for (int i = 0; i < size; i++) {
        node * node = nodesQueue.front();
        nodesQueue.pop();
        int index = (leftToRight) ? i : (size - 1 - i);
        row[index] = node -> data;
        if (node -> left) {
            nodesQueue.push(node -> left);
        }
        if (node -> right) {
            nodesQueue.push(node -> right);
        }
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return (node);
}

int main(){
    int i, j;
    node * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);
    vector < vector < int >> ans;
    ans = zigzagLevelOrder(root);
    cout << "Zig Zag Traversal of Binary Tree" << endl;
    for (i = 0; i < ans.size(); i++) {
        for (j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}