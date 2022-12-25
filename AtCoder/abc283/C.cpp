// RedStone
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
  string s;
  cin >> s;
  int ans = sz(s);
  for(int i = 0; i < sz(s) - 1; i++) {
    if(s[i] == '0' && s[i + 1] == '0') {
      ans--;
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
