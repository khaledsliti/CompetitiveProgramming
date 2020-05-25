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

const int N = 101;

int n, m;
ll arr[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      arr[i] = 0;
      for(int j = 0; j < m; j++)
        arr[i] = (arr[i] << 1) | (s[j] == '1');
    }
    sort(arr, arr + n);
    ll index = ((1LL << m) - 1) >> 1;
    ll k = ((1LL << m) - n - 1) >> 1;
    for(ll cur = max(0LL, index - 200); cur <= index + 200; cur++) {
      int j = lower_bound(arr, arr + n, cur) - arr;
      if(j < n && arr[j] == cur) continue;
      ll res = cur - j;
      if(res == k) {
        for(int i = m - 1; i >= 0; i--)
          cout << ((cur >> i) & 1);
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
