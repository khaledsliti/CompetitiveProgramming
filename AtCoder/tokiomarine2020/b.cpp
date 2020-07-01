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

int main()
{
  ll A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  if(A > B) swap(A, B);
  ll x = A + V * T;
  ll y = B + W * T;
  if(x >= y) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
