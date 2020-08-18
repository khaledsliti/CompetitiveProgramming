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

const int N = 501;

int n;
int a[N], b[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", a + i);
  for(int i = 0; i < n; i++)
    scanf("%d", b + i);
  if((n & 1) && a[n / 2] != b[n / 2]) {
    cout << "No" << endl;
    return;
  }
  vector<pair<int, int>> x, y;
  for(int i = 0; i < n / 2; i++) {
    int aa = a[i], bb = a[n - 1 - i];
    x.push_back({min(aa, bb), max(aa, bb)});
  }
  for(int i = 0; i < n / 2; i++) {
    int aa = b[i], bb = b[n - 1 - i];
    y.push_back({min(aa, bb), max(aa, bb)});
  }
  sort(all(x));
  sort(all(y));
  bool good = true;
  for(int i = 0; i < sz(x); i++)
    good &= x[i] == y[i];
  cout << (good ? "Yes" : "No") << endl;
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
