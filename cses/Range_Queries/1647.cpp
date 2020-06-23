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

const int N = 2e5 + 5;
const int L = 18;

int n, q;
int arr[N];
int mn[N][L], lg[N];

int main()
{
  for(int i = 2; i < N; i++)
    lg[i] = 1 + lg[i >> 1];
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> mn[i][0];
  for(int l = 1; l < L; l++) {
    for(int i = 0; i + (1 << l) <= n; i++) {
      int mid = i + (1 << (l - 1));
      mn[i][l] = min(mn[i][l - 1], mn[mid][l - 1]);
    }
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int k = lg[r - l + 1];
    int ans = min(mn[l][k], mn[r - (1 << k) + 1][k]);
    cout << ans << endl;
  }
  return 0;
}
