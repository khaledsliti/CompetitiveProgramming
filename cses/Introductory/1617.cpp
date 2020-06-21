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

const int Mod = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  int ans = 1;
  for(int i = 1; i <= n; i++)
    ans = (ans * 2) % Mod;
  cout << ans << endl;
  return 0;
}
