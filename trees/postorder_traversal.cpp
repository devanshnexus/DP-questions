#include<iostream>
#include<vector>
using namespace std;
struct node {
  int data;
  struct node * left, * right;
};
void postOrderTrav(node * node, vector < int > & postOrder) {
    if (node == NULL)
      return;
    postOrderTrav(node -> left, postOrder);
    postOrderTrav(node -> right, postOrder);
    postOrder.push_back(node -> data);
}
int main()
{
    return 0;
}