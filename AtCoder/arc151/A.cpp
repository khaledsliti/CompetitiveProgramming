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

const int N = 2e5 + 4;

int n;
string s, t;
int sol[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s >> t;
  
  vector<int> pos;
  for(int i = 0; i < n; i++) {
    if(s[i] == t[i]) {
      sol[i] = 0;
    } else {
      pos.push_back(i);
    }
  }
  if(sz(pos) & 1) {
    cout << -1 << endl;
    return 0;
  }
  int rem = sz(pos) - 1;
  int diff = 0;
  for(int i = 0; i < sz(pos); i++) {
    int idx = pos[i];
    int nw_diff = diff + (s[idx] == '1') - (s[idx] == '0');
    if(abs(nw_diff) <= rem) {
      sol[idx] = 0;
      diff += (s[idx] == '1') - (s[idx] == '0');
    } else {
      sol[idx] = 1;
      diff -= (s[idx] == '1') - (s[idx] == '0');
    }
    rem--;
  }
  for(int i = 0; i < n; i++) {
    cout << sol[i];
  }
  cout << endl;
  return 0;
}
