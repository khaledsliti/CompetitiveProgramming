// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;
const int L = 17;

int n, y;
int arr[N];
long long dp[N];
int mx[N][L], mn[N][L], lg[N];

void add(int idx,int val)
{
	for(idx++ ; idx < N ; idx += idx & -idx)
		dp[idx] = (dp[idx] + val) % Mod;
}

long long query(int idx)
{
	long long sum = 0;
	for(idx++ ; idx > 0 ; idx -= idx & -idx)
		sum += dp[idx];
	return sum;
}

long long query(int a, int b) {
  return query(b) - query(a - 1);
}

int good(int i, int j) {
  int len = lg[j - i + 1];
  int a = max(mx[i][len], mx[j - (1 << len) + 1][len]);
  int b = min(mn[i][len], mn[j - (1 << len) + 1][len]);
  int dif = a - b;
  return dif <= y;
}


int main()
{
  lg[1] = 0;
  for(int i = 2 ; i < N ; i++)
    lg[i] = 1 + lg[i >> 1];
  scanf("%d%d", &n, &y);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  for(int i = 0 ; i < n ; i++) {
    mn[i][0] = arr[i];
    mx[i][0] = arr[i];
  }
  for(int j = 1 ; (1 << j) <= n ; j++) {
    for(int i = 0 ; i + (1 << j) <= n ; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }
  add(n, 1);
  for(int i = n - 1 ; i >= 0 ; i--) {
    int l = i, r = n - 1, j = i;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(good(i, mid)){
        j = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    long long sum = query(i + 1, j + 1) % Mod;
    add(i, sum);
  }
  cout << query(0) % Mod << endl;
  return 0;
}
