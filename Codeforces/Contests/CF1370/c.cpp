// We only fail when we stop trying
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

int n;

void solve() {
  cin >> n;
  if(n == 1) {
    cout << "FastestFinger" << endl;
    return;
  }
  if(n == 2) {
    cout << "Ashishgup" << endl;
    return;
  }
  int cnt = 0;
  while(n % 2 == 0) {
    cnt++;
    n >>= 1;
  }
  if(!cnt) {
    cout << "Ashishgup" << endl;
    return;
  }
  if(cnt > 1) {
    if(n == 1) cout << "FastestFinger" << endl;
    else cout << "Ashishgup" << endl;
    return;
  }
  bool isPrime = true;
  for(int i = 2; i * i <= n && isPrime; i++)
    if(n % i == 0)
      isPrime = false;
  if(isPrime) cout << "FastestFinger" << endl;
  else cout << "Ashishgup" << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
