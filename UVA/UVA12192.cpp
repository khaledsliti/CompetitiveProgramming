// Guess Who's Back
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

const int N = 507;
const int V = 1e5 + 1;

int n, m;
int arr[N][N];
int mn[N + N], mx[N + N];

void getLowPts(int low) {
  for(int i = 0; i < n + m; i++)
    mn[i] = -1;
  int i = n - 1;
  for(int j = 0; j < m; j++) {
    if(arr[i][j] < low) continue;
    while(i >= 0 && arr[i][j] >= low) {
      mn[i - j + m - 1] = i;
      i--;
    }
    i++;
  }
}

void getUpPts(int up) {
  for(int i = 0; i < n + m; i++)
    mx[i] = -1;
  int i = 0;
  for(int j = m - 1; j >= 0; j--) {
    if(arr[i][j] > up) continue;
    while(i < n && arr[i][j] <= up) {
      mx[i - j + m - 1] = i;
      i++;
    }
    i--;
  }
}

int solve(int low, int up) {
  getUpPts(up);
  getLowPts(low);
  int ans = 0;
  for(int idx = 0; idx < n + m; idx++) {
    if(mx[idx] != -1 && mn[idx] != -1) {
      ans = max(ans, mx[idx] - mn[idx] + 1);
    }
  }
  return ans;
}

int main()
{
  while(scanf("%d%d", &n, &m) && (n || m)) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("%d", &arr[i][j]);
      }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
      int low, up;
      scanf("%d%d", &low, &up);
      printf("%d\n", solve(low, up));
    }
    printf("-\n");
  }
  return 0;
}
