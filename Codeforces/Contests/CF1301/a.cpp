#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string a, b, c;

int solve()
{
  for(int i = 0 ; i < sz(a) ; i++){
    if(c[i] != a[i] && c[i] != b[i])
      return false;
  }
  return true;
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> a >> b >> c;
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity