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

const int N = 31;

int n, k;
int a[N], b[N];

void solve() {
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  for(int i = 0 ; i < n ; i++)
    cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int best = 0;
  for(int i = 0; i <= k; i++) {
    int sum = 0;
    for(int j = 0; j < i; j++)
      sum += b[n - j - 1];
    for(int j = 0; j < n - i; j++)
      sum += a[n - j - 1];
    best = max(best, sum);
  }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
