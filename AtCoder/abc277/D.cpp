// RedStone
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

const int N = 2e5 + 5;

int n, m;
int arr[N];
int par[N];
long long sum[N];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long s = 0;
  for(int i = 0; i < n; i++) {
    par[i] = i;
    sum[i] = arr[i];
    s += arr[i];
  }
  for(int i = 0; i < n; i++) {
    int j = i + 1;
    if(j == n) {
      j = 0;
    }
    if (i == j) continue;
    if(arr[j] == arr[i] || arr[i] + 1 == arr[j] || arr[i] == m - 1 && arr[j] == 0) {
      int a = find(i);
      int b = find(j);
      if (a != b) {
        sum[b] += sum[a];
        par[a] = b;
      }
    }
  }
  // for(int i = 0; i < n; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;
  // for(int i = 0 ; i < n; i++) {
  //   cout << find(i) << " ";
  // }
  // cout << endl;
  // for(int i = 0; i < n; i++) {
  //   cout << find(i) << " " << sum[find(i)] << endl;
  // }

  long long ans = 0;
  for(int i = 0 ; i < n; i++) {
    if(find(i) == i) {
      ans = max(ans, sum[find(i)]);
    }
  }
  cout << s - ans << endl;
  return 0;
}
