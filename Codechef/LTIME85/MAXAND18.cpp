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

const int N = 2e5 + 5, L = 30;

int n, k;
int arr[N];
int cnt[L];

void solve() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < L; i++)
    cnt[i] = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    for(int j = 0; j < L; j++)
      if(arr[i] & (1 << j))
        cnt[j]++;
  }
  vector<pair<ll, int>> bits;
  for(int i = 0; i < L; i++)
    bits.push_back({-1LL * cnt[i] * (1 << i), i});
  sort(all(bits));

  int x = 0;
  for(int i = 0; i < k; i++) {
    int idx = bits[i].second;
    x |= (1 << idx);
  }

  cout << x << endl;
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
