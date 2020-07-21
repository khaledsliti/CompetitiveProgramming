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

const int N = 1000001;
const int Mod = 1e9 + 7;

char s[N];
int cnt[26];
ll fact[N];

ll po(ll a, ll b) {
  ll r = 1;
  while(b > 0) {
    if(b & 1) r = (r * a) % Mod;
    a = (a * a) % Mod;
    b >>= 1;
  }
  return r;
}

ll C(ll n, ll k) {
  return fact[n] * po(fact[k], Mod - 2) % Mod * po(fact[n - k], Mod - 2) % Mod;
}

int main()
{
  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % Mod;
  }
  scanf("%s", s);
  for(int i = 0; s[i]; i++){ 
    cnt[s[i] - 'a']++;
  }

  int have = strlen(s);

  ll ans = 1;
  
  for(int i = 0; i < 26; i++) {
    ans = (ans * C(have, cnt[i])) % Mod;
    have -= cnt[i];
  }

  cout << ans << endl;

  return 0;
}
