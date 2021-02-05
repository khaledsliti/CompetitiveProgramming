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

int n;
string s;
int group[10], rep[10];
ll p[8][8], c[8][8];

void solve(int i, int g, int& cnt) {
  if(i == 8) {
    cnt++;
    return;
  }
  rep[g] = i;
  group[i] = g;
  solve(i + 1, g + 1, cnt);
  for(int k = 0; k < g; k++) {
    group[i] = k;
    solve(i + 1, g, cnt);
  }
}

ll solve(int cur, int mask) {
  
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++) {
    s[i] -= '1';
  }
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      cin >> p[i][j];
    }
  }
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      cin >> c[i][j];
    }
  }
  cout << solve(8, 0) << endl;
  return 0;
}
