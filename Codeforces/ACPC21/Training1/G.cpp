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

const int N = 1000001;

int phi[N];

void calc_phi() {
  for(int i = 1 ; i < N ; i++)
    phi[i] = i;
  for(int i = 2 ; i < N ; i++)
    if(phi[i] == i) {
      for(int j = i ; j < N ; j += i)
        phi[j] -= phi[j] / i;
    }
}

void solve() {
  int n;
  cin >> n;
  string a = to_string(n);
  string b = to_string(phi[n]);
  sort(all(a));
  sort(all(b));
  cout << (a == b ? "YES" : "NO") << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifndef LOCAL
  freopen("phi.in", "r", stdin);
#endif

  calc_phi();

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}