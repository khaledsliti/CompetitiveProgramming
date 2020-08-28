#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, x;
string s;

void solve()
{
  int p = x;
  bool found = false;
  for(int i = 0 ; i <= n ; i++){
    if(p == 0)
      found = true;
    if(i < n)
      p -= (s[i] == '0') - (s[i] == '1');
  }
  int b = x - p;
  if(b == 0){
    cout << (found ? -1 : 0) << endl;
    return;
  }
  unordered_set<int> sol;
  p = x;
  for(int i = 0 ; i <= n ; i++){
    if(p == 0) sol.insert(i);
    else if(p % b == 0) {
      int q = p / b;
      if(q >= 0)
       sol.insert(n * q + i);
    }
    if(i < n)
      p -= (s[i] == '0') - (s[i] == '1');
  }
  cout << sol.size() << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n >> x >> s;
    solve();
  }
  return 0;
}
