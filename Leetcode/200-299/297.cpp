#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
  string toString(int x){
    if(x == 0)
      return "0";
    long long y = x;
    int sign = y > 0 ? 1 : -1;
    y = llabs(y);
    string r = "";
    while(y){
      r += char('0' + y % 10);
      y /= 10;
    }
    if(sign == -1)
      r += '-';
    reverse(r.begin(), r.end());
    return r;
  }
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string r = "[";
    queue<TreeNode*> q;
    vector<TreeNode*> order;
    q.push(root);
    while(!q.empty()){
      TreeNode* cur = q.front();
      q.pop();
      order.push_back(cur);
      if(cur)
        q.push(cur->left), q.push(cur->right);
    }
    for(int i = 0 ; i < (int) order.size() ; i++){
      if(i)
        r += ',';
      if(order[i])
        r += toString(order[i]->val);
      else
        r += "null";
    }
    r += ']';
    return r;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int n = data.size();
    assert(data[0] == '[');
    assert(data[n - 1] == ']');
    queue<TreeNode**> q;
    TreeNode* root = NULL;
    q.push(&root);
    for(int i = 1 ; i < n - 1 ; i++){
      int sign = 1;
      TreeNode* cur = NULL;
      if(data[i] == 'n'){ // NULL
        i += 4;
      }else{
        int sign = 1;
        if(data[i] == '-'){
          sign = -1;
          i++;
        }
        int val = 0;
        while(data[i] >= '0' && data[i] <= '9')
          val = val * 10 + data[i++] - '0';
        val = sign * val;
        cur = new TreeNode(val);
      }
      *q.front() = cur;
      q.pop();
      if(cur != NULL){
        q.push(&(cur->left));
        q.push(&(cur->right));
      }
    }
    return root;
  }
  void Run(TreeNode* root){
    if(root == NULL)
      return;
    Run(root->left);
    cout << root->val << endl;
    Run(root->right);
  } 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
  Codec codec;
  cout << codec.serialize(codec.deserialize("[1,2,3,null,null,4,5]")) << endl;
  return 0;
}