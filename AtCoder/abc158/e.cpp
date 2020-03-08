// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int P = 10000;

int n, p;
string s;
int fr[P];

int main()
{
  cin >> n >> p >> s;
  long long ans = 0;
  if(p == 2 || p == 5){
    for(int i = 0 ; i < n ; i++) {
      if((s[i] - '0') % p == 0)
        ans += i + 1;
    }
  } else {
    fr[0]++;
    int v = 0, po = 1;
    for(int i = n - 1 ; i >= 0 ; i--){
      int cur = s[i] - '0';
      v = (v + po * cur) % p;
      ans += fr[v];
      fr[v]++;
      po = (po * 10) % p;
    }
  }
  cout << ans << endl;
  return 0;
}
