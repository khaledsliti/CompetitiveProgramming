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
  int best = 0;
  int oo = 1e5;
  vector<int> dfs(TreeNode* root) {
    if(!root) return {1, 0, oo, -oo};
    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);
    int cur = root->val;
    int isBST = left[0] && right[0] && cur > left[3] && cur < right[2];
    if(isBST) {
      int cur_min = min(min(left[2], right[2]), cur);
      int cur_max = max(max(left[3], right[3]), cur);
      int sum = left[1] + right[1] + cur;
      best = max(best, sum);
      return { isBST, sum, cur_min, cur_max };
    }
    return {0, 0, oo, -oo};
  }
public:
  int maxSumBST(TreeNode* root) {
    best = 0;
    dfs(root);
    return best;
  }
};

int main()
{
  
  return 0;
}
