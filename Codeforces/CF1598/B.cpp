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

const int N = 1007;
const int D = 5;

int n;
int ok[N][D];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < D; j++) {
      cin >> ok[i][j];
    }
  }
  for(int i = 0; i < D; i++) {
    for(int j = 0; j < D; j++) {
      if(i == j) continue;
      int first = 0, second = 0, both = 0;
      for(int s = 0; s < n; s++) {
        if(ok[s][i] && !ok[s][j]) {
          first++;
        } else if(!ok[s][i] && ok[s][j]) {
          second++;
        } else if(ok[s][i] && ok[s][j]) {
          both++;
        }
      }
      if(first + second + both < n || first > n / 2 || second > n / 2) {
        continue;
      }
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
