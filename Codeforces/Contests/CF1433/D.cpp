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

const int N = 5001;

int n;
pair<int, int> a[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  if(a[0].first == a[n - 1].first) {
    cout << "NO" << endl;
    return;
  }
  int st = 0;
  while(a[st].first == a[0].first) st++;
  cout << "YES" << endl;
  for(int i = st; i < n; i++) {
    cout << a[0].second + 1 << " " << a[i].second + 1 << endl;
  }
  for(int i = 1; i < st; i++) {
    cout << a[i].second + 1 << " " << a[st].second + 1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
