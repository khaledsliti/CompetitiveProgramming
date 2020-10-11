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



int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int s = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
    }
    sort(all(v));
    if(s == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if(s > 0) reverse(all(v));
      for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
