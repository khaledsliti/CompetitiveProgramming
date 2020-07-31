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

const int N = 1000001;

int n, m, k;
int a[N];
int pref[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    a[x]++;
  }
  for(int i = 1; i < N; i++)
    pref[i] = a[i] + pref[i - 1];
  int ans = 0, sum = 0;
  for(int i = 1, j = 1; i < N; i++) {
    if(a[i] > 0) {
      sum += a[i];
      while(!a[j] || i - j + 1 > m) {
        sum -= a[j];
        j++;
      }
      while(sum >= k) {
        sum--;
        
      }
    }
  }
  cout << ans << endl;
  return 0;
}
