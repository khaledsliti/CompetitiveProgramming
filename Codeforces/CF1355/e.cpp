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

const int N = 1e5 + 5;

int n, A, R, M;
int h[N];
ll pref[N];

ll solve(ll target) {
  int idx = upper_bound(h, h + n, target) - h;
  ll del = 0, add = 0;
  if(idx > 0){
    add = idx * target - pref[idx - 1];
  }
  if(idx < n) { 
    del = (pref[n - 1] - (idx > 0 ? pref[idx - 1] : 0)) - (n - idx) * target;
  }
  if(add >= del) {
    return A * (add - del) + M * del;
  } else {
    return R * (del - add) + M * add;
  }
}

int main()
{
  scanf("%d%d%d%d", &n, &A, &R, &M);
  for(int i = 0; i < n; i++)
    scanf("%d", h + i);
  M = min(M, A + R);
  sort(h, h + n);
  pref[0] = h[0];
  for(int i = 1; i < n; i++)
    pref[i] = h[i] + pref[i - 1];
  ll best = solve(pref[n - 1] / n);
  best = min(best, solve(pref[n - 1] / n + 1));
  for(int i = 0; i < n; i++) {
    best = min(best, solve(h[i]));
  }
  cout << best << endl;
  return 0;
}
