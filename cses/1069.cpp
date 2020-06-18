// We only fail when we stop trying
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



void solve() {
  string s; cin >> s;
  int best = 0;
  for(int i = 0; i <  sz(s); i++) {
    int j = i;
    while(j < sz(s) && s[j] == s[i]) j++;
    best = max(best, j - i);
    i = j - 1;
  }
  cout << best << endl;
}

int main()
{
  int T = 1;
  while(T--)
    solve();
  return 0;
}
