// RedStone
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

int n, k;
int a[N], t[N];
int suf[N], sum[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> t[i];
    if(t[i]) {
      suf[i] = a[i];
    }
  }

  for(int i = 0; i < n; i++) {
    sum[i] = a[i] + (i > 0 ? sum[i - 1] : 0);
  }

  for(int i = n - 2; i >= 0; i--) {
    suf[i] += suf[i + 1];
  }

  int best = 0, acc = 0;
  for(int i = 0; i <= n - k; i++) {
    int cur = acc + suf[i + k] + sum[i + k - 1] - (i > 0 ? sum[i - 1] : 0);
    best = max(best, cur);
    if(t[i]) {
      acc += a[i];
    }
  }
  cout << best << endl;
  return 0;
}
