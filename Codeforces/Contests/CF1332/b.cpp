// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1005;

int isp[N];
vector<int> pr;

void solve() {
  int n;
  cin >> n;
  map<int, vector<int>> g;
  for(int i = 0 ; i < n ; i++) {
    int a; cin >> a;
    for(int j = 0 ; j < sz(pr) ; j++)
      if(a % pr[j] == 0) {
        g[pr[j]].pb(i);
        break;
      }
  }
  vector<int> ans(n);
  int cur = 1;
  for(auto x : g){
    for(int idx : x.second)
      ans[idx] = cur;
    cur++;
  }
  cout << sz(g) << endl;
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
}

int main()
{
  for(int i = 2 ; i < N ; i++)
    isp[i] = 1;
  for(int i = 2 ; i < N ; i++) {
    if(isp[i]) {
      pr.pb(i);
      for(int j = 2 * i ; j < N ; j += i)
        isp[j] = 0;
    }
  }
  int t;
  cin >> t;
  while(t--)
   solve(); 
  return 0;
}
