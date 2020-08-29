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

const int N = 1e6 + 5;

int n;
int a[N];
vector<int> d[N];
int cnt[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }

  cin >> n;
  int g = 0;
  int mn = 1e9;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    g = __gcd(g, a[i]);
    for(int di : d[a[i]]) {
      cnt[di]++;
    }
  }
  bool pairwise = true;
  for(int i = 2; i < N; i++) {
    if(cnt[i] > 1) {
      pairwise = false;
    }
  }
  if(pairwise) cout << "pairwise coprime" << endl;
  else if(g == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;
  return 0;
}
