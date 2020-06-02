// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s;
  cin >> s;
  int best = sz(s);
  for(int i = 0; i <= sz(s); i++) {
    int a = count_if(begin(s), begin(s) + i, [](char c){ return c == '1'; }) + count_if(begin(s) + i, end(s), [](char c){ return c == '0'; });
    int b = count_if(begin(s), begin(s) + i, [](char c){ return c == '0'; }) + count_if(begin(s) + i, end(s), [](char c){ return c == '1'; });
    best = min(best, min(a, b));
  }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
