#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, m;
vector<vector<int>> mat;

int solve(vector<int>& v, int sub)
{
  unordered_map<int, int> st;
  for(int i = 0 ; i < sz(v) ; i++){
    if(v[i] - sub >= 0 &&  (v[i] - sub) % m == 0)
    {
      int idx = (v[i] - sub) / m;
      if(0 <= idx && idx < n)
        st[((i - idx) % n + n) % n]++;
    }
  }
  int best = n;
  for(int s = 0 ; s < n ; s++){
    int cur = s + (n - st[s]);
    best = min(best, cur);
  }
  return best;
}

int main()
{
  scanf("%d%d", &n, &m);
  mat.resize(m, vector<int>());
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      int a; scanf("%d", &a);
      mat[j].pb(a);
    }
  }
  int ans = 0;
  for(int j = 0 ; j < m ; j++)
    ans += solve(mat[j], j + 1);
  cout << ans << endl;
  return 0;
}
