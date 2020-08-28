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

int n;
int arr[N], ans[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  int idx = 0;
  for(int i = 0 ; i < n ; i++) {
    int j = (i + 1) % n;
    if(arr[i] == arr[j]) {
      idx = j;
      break;
    }
  }
  int prv = -1;
  int cols = 0;
  for(int i = 0 ; i < n ; i++) {
    int j = (i + idx) % n;
    if(prv == -1 || arr[j] == arr[prv])
      ans[j] = 1;
    else
      ans[j] = ans[prv] == 1 ? 2 : 1;
    cols = max(cols, ans[j]);
    prv = j;
  }
  if(arr[0] != arr[n - 1] && ans[0] == ans[n - 1])
    ans[n - 1] = 3, cols = 3;
  cout << cols << endl;
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
