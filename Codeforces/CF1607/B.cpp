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
  long long x, n;
  cin >> x >> n;
  if(x % 2 == 0) {
    if(n % 4 == 0) cout << x << endl;
    else if(n % 4 == 1) cout << x - n << endl;
    else if(n % 4 == 2) cout << x + 1 << endl;
    else cout << x + n + 1 << endl;
  } else {
    if(n % 4 == 0) cout << x << endl;
    else if(n % 4 == 1) cout << x + n << endl;
    else if(n % 4 == 2) cout << x - 1 << endl;
    else cout << x - n - 1 << endl;
  }
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

x even:
x -> x-1 -> x+1 -> x+4 ->
x -> x-5 -> x+1 -> x+8 ->
x -> x-9 -> x+1 -> x+12 ->

x odd:
x -> x+1 -> x-1 -> x-4 ->
x -> 


10 -> 9 -> 11 -> 
*/