// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int nxt[N];
int in[N], col[N], cycle[N];
int ans[N];

void dfs(int cur) {
  if(ans[cur] != -1) return;
  dfs(nxt[cur]);
  ans[cur] = 1 + ans[nxt[cur]];
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> nxt[i];
    --nxt[i];
    in[nxt[i]] = 1;
    col[i] = 0;
    ans[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    if(!col[i]) {
      int root = -1;
      for(int cur = i; root == -1 && col[cur] != 2; cur = nxt[cur]) {
        if(col[cur] == 1) root = cur;
        else col[cur] = 1;
      }
      if(root != -1) {
        int len = 1;
        for(int cur = nxt[root]; cur != root; cur = nxt[cur])
          len++;
        ans[root] = len;
        for(int cur = nxt[root]; cur != root; cur = nxt[cur])
          ans[cur] = len;
      }
      for(int cur = i; col[cur] != 2; cur = nxt[cur])
        col[cur] = 2;
    }
  }

  for(int i = 0; i < n; i++) {
    if(!in[i]) {
      dfs(i);
    }
  }

  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
  
  return 0;
}
