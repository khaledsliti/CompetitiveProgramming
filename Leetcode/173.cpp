#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class BSTIterator{
  vector<TreeNode*> st;
public:
  BSTIterator(TreeNode* root) {
    st.push_back(new TreeNode(INT_MIN));
    st.back()->right = root;
  }
  int next() {
    int sz = st.size();
    if(st[sz - 1]->right){
      TreeNode* cur = st[sz - 1]->right;
      while(cur != NULL){
        st.push_back(cur);
        cur = cur->left;
      }
    }else{
      while(true){
        int child_value = st.back()->val;
        st.pop_back();
        int cur_value = st.back()->val;
        if(cur_value > child_value)
          break;
      }
    }
    return st.back()->val;
  }
  bool hasNext() {
    if(!st.size())
      return false;
    int sz = st.size();
    if(st[sz-1]->right)
      return true;
    for(int i = sz - 2 ; i >= 0 ; i--){
      if(st[i]->val > st[i + 1]->val)
        return true;
    }
    return false;
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