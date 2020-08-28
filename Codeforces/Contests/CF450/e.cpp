#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n;
int isp[N];
int picked[N];

void pick(vector<pair<int, int>>& sol, vector<int>& v)
{
  int a = v.back(); v.pop_back();
  int b = v.back(); v.pop_back();
  picked[a] = picked[b] = 1;
  sol.pb({a, b});
}

int main()
{
  cin >> n;
  for(int i = 2 ; i <= n ; i++)
    isp[i] = 1, picked[i] = 0;
  for(int i = 2 ; i <= n ; i++){
    if(isp[i])
      for(int j = 2 * i ; j <= n ; j += i)
        isp[j] = 0;
  }
  vector<pair<int, int>> sol;
  for(int i = 3 ; 2 * i <= n ; i++)
    if(isp[i]){
      vector<int> v;
      for(int j = i ; j <= n ; j += i)
        if(!picked[j])
          v.push_back(j);
      swap(v[0], v[1]);
      while(sz(v) >= 2)
        pick(sol, v);
    }
  vector<int> v;
  for(int j = 2 ; j <= n ; j += 2)
    if(!picked[j])
      v.pb(j);
  while(sz(v) >= 2)
    pick(sol, v);
  cout << sz(sol) << endl;
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i].first << " " << sol[i].second << endl;
  return 0;
}
