#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void print(vector<int>& v)
{
  for(int i = 0 ; i < sz(v) ; i++)
    cout << v[i] << " ";
  cout << endl;
}

int f(vector<int>& p, int s, int e)
{
  if(s > e) return 0;
  int m = s;
  for(int i = s ; i <= e ; i++){
    if(p[m] > p[i])
      m = i;
  }
  return f(p, s, m - 1) + p[m] * (m - s + 1) * (e - m + 1) + f(p, m + 1, e);
}

void solve(int n)
{
  int best = 0;
  vector<int> p;
  vector<vector<int>> sol;
  for(int i = 0 ; i < n ; i++)
    p.pb(i + 1);
  do{
    int cur = f(p, 0, n - 1);
    if(cur > best){
      sol.clear();
      sol.pb(p);
      best = cur;
    }else if(cur == best){
      sol.pb(p);
    }
  }while(next_permutation(all(p)));
  cout << n << " " << best << endl;
  for(int i = 0 ; i < sz(sol) ; i++)
    print(sol[i]);
  cout << "-------\n";
}

int ans[55];

void solve(int cur, int s, int e, long long comp, long long mth)
{
  if(s == e){
    ans[s] = cur;
    return;
  }
  if(mth <= comp){
    ans[s] = cur;
    solve(cur + 1, s + 1, e, comp >> 1, mth);
  }else{
    ans[e] = cur;
    solve(cur + 1, s, e - 1, comp >> 1, mth - comp);
  }
}

int main()
{
  int n;
  long long m;
  cin >> n >> m;
  solve(1, 0, n - 1, (1LL << (n - 2)), m);
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
