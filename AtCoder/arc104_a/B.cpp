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

string s;

int main()
{
  int n; cin >> n;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < sz(s); i++) {
    int a = 0, b = 0;
    for(int j = i; j < sz(s); j++) {
      a += (s[j] == 'A') - (s[j] == 'T');
      b += (s[j] == 'C') - (s[j] == 'G');
      if(!a && !b) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
