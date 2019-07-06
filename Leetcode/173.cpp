#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class BSTIterator{
  stack<TreeNode*> st;
public:
  BSTIterator(TreeNode* root) {
    auto cur = root;
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }
  }
  int next() { // you can not call next more than O(N) so this will be O(1) per call in average
    auto node = st.top();
    st.pop();
    int val = node->val;
    auto cur = node->right;
    while (cur) {
      st.push(cur);
      cur = cur->left;
    }
    return val;
  }
  bool hasNext() {
    return !st.empty();
  }
};

void print(TreeNode* root){
  if(!root)
    return;
  print(root->left);
  cout << root->val << endl;
  print(root->right);
}

int main(){
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator iterator = BSTIterator(root);
  cout << iterator.next() << endl;
  cout << iterator.next() << endl;
  cout << iterator.hasNext() << endl;
  cout << iterator.next() << endl;
  cout << iterator.hasNext() << endl;
  cout << iterator.next() << endl;
  cout << iterator.hasNext() << endl;
  cout << iterator.next() << endl;
  cout << iterator.hasNext() << endl;
  return 0;
}