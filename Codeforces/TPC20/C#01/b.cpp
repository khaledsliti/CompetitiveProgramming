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
const int Mod = 1e9 + 7;

int n;
int fact[N];

int main()
{
  fact[0] = 1;
  for(int i = 1 ; i < N ; i++)
    fact[i] = (1LL * fact[i - 1] * i) % Mod;
  cin >> n;
  int even = n / 2;
  int odd = n - even;
  int ans = 1LL * fact[even] * fact[odd] % Mod;
  if(n & 1){
    cout << (2 * ans) % Mod << " " << ans << endl;
  }else{
    cout << (2 * ans) % Mod << " " << (2 * ans) % Mod << endl;
  }
  return 0;
}
