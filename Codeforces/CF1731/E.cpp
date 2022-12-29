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

const int N = 1e6 + 6;

int n;
long long m;
int phi[N];
long long gcdCnt[N];

void calc_phi() {
  for (int i = 2; i < N; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i <= n; i++) {
    gcdCnt[i] = 0;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i, q = 1; j <= n; j += i, q++) {
      gcdCnt[i] += phi[q];
    }
  }

  long long rem = m;
  long long sol = 0;
  for(int i = n; i >= 2; i--) {
    long long q = min(rem, gcdCnt[i]) / (i - 1);
    rem -= q * (i - 1);
    sol += q * i;
  }
  if(rem > 0) {
    cout << -1 << endl;
    return;
  }
  cout << sol << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  calc_phi();

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
