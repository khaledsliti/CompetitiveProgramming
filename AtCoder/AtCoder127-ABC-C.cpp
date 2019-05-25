#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
int cnt[N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++){
    int l, r;
    cin >> l >> r;
    cnt[l]++;
    cnt[r + 1]--;
  }
  int ans = 0;
  for(int i = 1 ; i <= n ; i++){
    cnt[i] += cnt[i - 1];
    ans += cnt[i] == m;
  }
  cout << ans << endl;
  return 0;
}