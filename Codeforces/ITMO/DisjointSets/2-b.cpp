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

const int N = 2 * 300007;

int n;
int nxt[N];

int fs(int x) {
  return nxt[x] == x ? x : nxt[x] = fs(nxt[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i <= n * 2; i++) {
    nxt[i] = i;
  }

  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    --x;
    int y = fs(x);
    y %= n;
    cout << y + 1 << " ";
    nxt[y] = fs(y + 1);
    nxt[y + n] = fs(y + n + 1);
  }
  cout << endl;
  return 0;
}
