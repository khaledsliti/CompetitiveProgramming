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
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  vector<int> ans;
  while(sz(p) >= 2) {
    int a = p.back(); p.pop_back();
    int b = p.back(); p.pop_back();
    ans.push_back(b);
    ans.push_back(a);
  }
  if(sz(p)) {
    ans.push_back(p.back());
  }
  reverse(all(ans));
  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
/*
1 2 3
1 3 2
*/