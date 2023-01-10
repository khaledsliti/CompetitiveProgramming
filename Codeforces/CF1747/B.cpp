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

const int N = 103;

int n;

void solve() {
  cin >> n;
  cout << (n + 1) / 2 << endl;
  for(int i = 0; i < (n + 1) / 2; i++) {
    int j = n - 1 - i;
    cout << 3 * i + 1 << " " << 3 * j + 2 << endl;
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
