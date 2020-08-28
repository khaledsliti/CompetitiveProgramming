// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 200007;
const int V = 207;

int n;
int arr[N];
int cnt[N][V];
vector<int> pos[V];

void solve() {
  scanf("%d", &n);
  for(int j = 0 ; j < V ; j++) {
    for(int i = 0 ; i < n ; i++)
      cnt[i][j] = 0;
    pos[j].clear();
  }
  int best = 0;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
    pos[arr[i]].pb(i);
    for(int j = 0 ; j < V ; j++)
      if(i > 0)
        cnt[i][j] = cnt[i - 1][j];
    cnt[i][arr[i]]++;
    best = max(best, cnt[i][arr[i]]);
  }
  for(int i = 0 ; i < n - 2 ; i++) {
    int a = arr[i];
    int left = cnt[i][a];
    if(left * 2 <= cnt[n - 1][a]) {
      int r_idx = pos[a][cnt[n - 1][a] - left] - 1;
      for(int b = 1 ; b < V ; b++)
        if(a != b) {
          int tot = cnt[r_idx][b] - cnt[i][b];
          best = max(best, left * 2 + tot);
        }
    }
  }
  printf("%d\n", best);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}
