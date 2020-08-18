#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve(int n, int d)
{
  for(int x = 0 ; x <= 1e5 ; x++){
    if(x + (d + x) / (x + 1) <= n){
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    int n, d;
    cin >> n >> d;
    solve(n, d);
  }
  return 0;
}