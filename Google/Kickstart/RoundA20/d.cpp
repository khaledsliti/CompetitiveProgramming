#include <bits/stdc++.h>
using namespace std;

const int A = 26;

struct TrieNode {
  int nxt[A];
  bool leaf;
  int cnt;
  TrieNode(){
    cnt = leaf = 0;
    memset(nxt, -1, sizeof nxt);
  }
};

void insert(vector<TrieNode>& tr, string& s) {
  int cur = 0;
  for(int i = 0; i < (int)s.size(); i++) {
    int d = s[i] - 'A';
    if(tr[cur].nxt[d] == -1) {
      tr[cur].nxt[d] = tr.size();
      tr.push_back(TrieNode());
    }
    cur = tr[cur].nxt[d];
    tr[cur].cnt++;
  }
  tr[cur].leaf = 1;
}

int dfs(vector<TrieNode>& tr, int node, int k) {
  int res = tr[node].cnt / k;
  for(int d = 0 ; d < A ; d++)
    if(~tr[node].nxt[d]) {
      res += dfs(tr, tr[node].nxt[d], k);
    }
  return res;
}

void solve() {
  int n, k;
  vector<TrieNode> tr { TrieNode() };
  cin >> n >> k;
  string s;
  for(int i = 0 ; i < n ; i++) {
    cin >> s;
    insert(tr, s);
  }
  cout << dfs(tr, 0, k) << endl;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--){
    cout << "Case #" << tc++ << ": ";
    solve();
  }
  return 0;
}