// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  vector<int> dfs(TreeNode* cur) {
    // Base case
    if(!cur) return {0, -1, -1};
    vector<int> left = dfs(cur->left), right = dfs(cur->right);
    int res = max(max(left[0], right[0]), max(1 + left[2], 1 + right[1]));
    return { res, 1 + left[2], 1 + right[1] };
  }
public:
  int longestZigZag(TreeNode* root) {
    if(root == NULL)
      return 0;
    return dfs(root)[0];
  }
};

int main()
{
  
  return 0;
}
