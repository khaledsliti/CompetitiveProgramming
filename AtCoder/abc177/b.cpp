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



int main()
{
  string s, t;
  cin >> s >> t;
  int best = 1e9;
  for(int i = 0; i + sz(t) <= sz(s); i++) {
    int cur = 0;
    for(int j = 0; j < sz(t); j++) {
      cur += t[j] != s[i + j];
    }
    best = min(best, cur);
  }
  cout << best << endl;
  return 0;
}
