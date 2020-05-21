#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;
vector<int> sol;

void solve(int cur) {
  if(cur == 0)
    return;
  sol.push_back(n / cur);
  int l = 1, r = cur, best = cur;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(n / mid == n / cur){
      best = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  solve(best - 1);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    sol.clear();
    solve(n + 1);
    cout << sz(sol) << endl;
    for(int i = 0 ; i < sz(sol) ; i++)
      cout << sol[i] << " ";
    cout << endl;
  }
  return 0;
}
