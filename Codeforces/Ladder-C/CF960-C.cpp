// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  long long X, d;
  cin >> X >> d;
  long long cur = 1;
  vector<long long> sol;
  while(X > 0) {
    X++;
    for(int i = 30 ; i >= 0 ; i--)
      if(X & (1 << i)) {
        for(int j = 0 ; j < i ; j++)
          sol.push_back(cur);
        X -= (1 << i);
        break;
      }
    cur += d;
  }
  cout << sz(sol) << endl;
  for(auto x : sol)
    cout << x << " ";
  cout << endl;
  return 0;
}
