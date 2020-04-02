// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, a, b, T;
int hard[N];

void solve() {
  scanf("%d%d%d%d", &n, &T, &a, &b);
  int tot_h = 0, tot_e = 0;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", hard + i);
    if(hard[i]) tot_h++;
    else tot_e++;
  }
  vector<pair<int, int>> tasks;
  for(int i = 0 ; i < n ; i++) {
    int t; scanf("%d", &t);
    tasks.pb({t, hard[i]});
  }
  tasks.pb({T + 1, 0});
  sort(all(tasks));
  int h = 0, e = 0;
  int best = 0;
  long long need = 0;
  for(int i = 0 ; i <= n ; i++) {
    long long have = tasks[i].first - 1 - need;
    if(have >= 0) {
      int take = min((long long)(tot_e - e), have / a);
      have -= take * a;
      take += min((long long)(tot_h - h), have / b);
      best = max(best, i + take);
    }
    int j = i;
    while(j < n && tasks[i].first == tasks[j].first) {
      if(tasks[j].second) h++, need += b;
      else e++, need += a;
      j++;
    }
    if(i == n) break;
    i = j - 1;
  }
  printf("%d\n", best);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
