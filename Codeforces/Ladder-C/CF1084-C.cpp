// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
  string t, s = "";
  cin >> t;
  bool good = false;
  for(int i = 0 ; i < sz(t) ; i++){
    if(t[i] == 'a' || t[i] == 'b')
      s += t[i];
    good = good || t[i] == 'a';
  }
  if(!good)
    return cout << 0 << endl, 0;
  int ans = 1;
  for(int i = 0 ; i < sz(s) ; i++){
    if(s[i] == 'a'){
      int j = i;
      while(j < sz(s) && s[j] == 'a')
        ++j;
      ans = (1LL * ans * (j - i + 1)) % MOD;
      i = j - 1;
    }
  }
  cout << (ans + MOD - 1) % MOD << endl;
  return 0;
}
