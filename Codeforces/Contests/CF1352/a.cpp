// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int te = 1;
    vector<int> v;
    for(int i = 0 ; i < 5 ; i++) {
      if(n % 10) {
        v.push_back(te * (n % 10));
      }
      te *= 10;
      n /= 10;
    }
    cout << sz(v) << endl;
    for(int x : v)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}
