#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int UNITSIZE = 8;

struct Hash{
  int operator()(const pair<int, int>& p) const {
    return (p.first << UNITSIZE) + p.second;
  }
};

class trie{
  vector<bool> leaf;
  vector<vector<int>> children;
  unordered_map<pair<int, int>, int, Hash> edges;
  vector<vector<int>> dp;

  int solve(int cur, int t)
  {
    if(!sz(children[cur]))
      return t ? 0 : 1;
    int& r = dp[cur][t];
    if(r != -1)
      return r;
    for(int c : children[cur]){
      int nxt = edges[{cur, c}];
      if(!solve(nxt, t))
        return r = 1;
    }
    return r = 0;
  }

public:
  trie()
  {
    leaf.emplace_back(0);
    children.emplace_back(vector<int>());
  }
  void insert(char* s)
  {
    int cur = 0;
    for(; *s ; s++){
      int c = *s;
      int& nxt = edges.insert({{cur, c}, -1}).first->second;
      if(nxt == -1){
        children[cur].emplace_back(c);
        nxt = leaf.size();
        leaf.emplace_back(false);
        children.emplace_back(vector<int>());
      }
      cur = nxt;
    }
    leaf[cur] = 1;
  }
  int solve(int k)
  {
    dp.clear();
    dp.resize(leaf.size(), vector<int>(2, -1));
    int canWin = solve(0, 1);
    int canLose = solve(0, 0);
    if(!canWin)
      return k & 1 == 0;
    if(!canLose)
      return k & 1 != 0;
    return 1;
  }
};

const int N = 1e5 + 5;

int n, k;
char s[N];

int main()
{
  while(~scanf("%d%d", &n, &k)){
    trie tr;
    for(int i = 0 ; i < n ; i++){
      scanf("%s", s);
      tr.insert(s);
    }
    if(tr.solve(k)) cout << "First" << endl;
    else cout << "Second" << endl;
  }
  return 0;
}
