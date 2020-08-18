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
int cnt[N];

void solve() {
  scanf("%d", &n);
  memset(cnt, 0, n * sizeof(cnt[0]));
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &arr[i]);
    arr[i] += i;
    arr[i] = (arr[i] % n + n) % n;
    cnt[arr[i]]++;
  }
  bool yes = true;
  for(int i = 0 ; i < n ; i++)
    yes &= cnt[i] == 1;
  cout << (yes ? "YES" : "NO") << endl;
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
