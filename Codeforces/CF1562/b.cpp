#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 100;

int isP[N];

void sieve() {
  for(int i = 2; i < N; i++) {
    isP[i] = 1;
  }
  for(int i = 2; i < N; i++) {
    if(isP[i]) {
      for(int j = 2 * i; j < N; j += i) {
        isP[j] = 0;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  string s; cin >> s;
  for(char c: s) {
    if(!isP[c - '0']) {
      cout << 1 << endl;
      cout << c << endl;
      return;
    }
  }
  for(int i = 0; i < sz(s); i++) {
    for(int j = i + 1; j < sz(s); j++) {
      int cur = (s[i] - '0') * 10 + s[j] - '0';
      if(!isP[cur]) {
        cout << 2 << endl;
        cout << s[i] << s[j] << endl;
        return;
      }
    }
  }
  assert(false);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sieve();

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
