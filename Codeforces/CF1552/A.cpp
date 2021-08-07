// Guess Who's Back
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
    string s;
    cin >> n >> s;
    string p = s;
    sort(all(p));
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans += s[i] != p[i];
    }
    cout << ans << endl;
  }
  return 0;
}
