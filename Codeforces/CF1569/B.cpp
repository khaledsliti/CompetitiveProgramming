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

const int N = 55;

int n;
string s;
int sol[N][N];

char getChar(int v) {
  if(v == 0) return '=';
  if(v > 0) return '+';
  return '-';
}

void solve() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      sol[i][j] = 0;
    }
  }
  vector<int> v;
  for(int i = 0; i < n; i++) {
    if(s[i] == '2') {
      v.push_back(i);
    }
  }
  if(sz(v) == 1 || sz(v) == 2) {
    cout << "NO" << endl;
    return;
  }
  for(int i = 0; i < sz(v); i++) {
    int a = v[i];
    int b = v[(i + 1) % sz(v)];
    sol[a][b] = 1;
    sol[b][a] = -1;
  }
  cout << "YES" << endl;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) cout << "X";
      else cout << getChar(sol[i][j]);
    }
    cout << endl;
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
