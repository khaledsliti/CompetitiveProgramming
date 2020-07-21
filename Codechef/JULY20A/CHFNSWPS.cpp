// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int a[N], b[N];

ll solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a + i);
  for(int i = 0; i < n; i++)
    scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + n);
  map<int, int> cnt;
  for(int i = 0; i < n; i++) {
    cnt[a[i]]++;
    cnt[b[i]]--;
  }
  vector<int> values;
  for(auto x: cnt) {
    int fr = x.second;
    if(fr % 2 != 0)
      return -1;
    fr = abs(fr) / 2;
    while(fr--)
      values.push_back(x.first);
  }
  assert(sz(values) % 2 == 0);
  sort(all(values));
  int tmp = 2 * min(a[0], b[0]);
  ll ans = 0;
  for(int i = 0; i < sz(values) / 2; i++) {
    ans += min(tmp, values[i]);
  }
  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    cout << solve() << endl;
  return 0;
}
