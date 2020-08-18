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

const int N = 100001;

int n;
int x;
int arr[N];

void solve() {
  scanf("%d%d", &n, &x);
  int sum = 0;
  int f = -1, l = -1, a = 1;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
    a &= arr[i] % x == 0;
    if(arr[i] % x != 0) {
      if(f == -1) f = i;
      l = i;
    }
  }
  if(sum % x != 0) return void(cout << n << endl);
  else if(a) return void(cout << -1 << endl);
  cout << max(n - 1 - f, l) << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
