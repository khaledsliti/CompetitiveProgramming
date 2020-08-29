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

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n;
int a[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, sum = 0;
  for(int i = n - 1; i >= 0; i--) {
    ans = (ans + 1LL * a[i] * sum % Mod) % Mod;
    sum = (sum + a[i]) % Mod;
  }
  cout << ans << endl;
  return 0;
}
