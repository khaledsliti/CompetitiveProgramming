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

int n;
int arr[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  sort(arr, arr + n);
  int cnt = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    cnt++;
    if(arr[i] <= cnt) {
      ans++;
      cnt = 0;
    }
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
