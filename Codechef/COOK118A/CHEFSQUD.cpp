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


const int N = 100007;

int n;
int arr[N];
int bit[N];

void add(int idx, int val) {
	for(; idx < N ; idx += idx&-idx)
		bit[idx] += val;
}

int get(int idx) {
	int sum = 0;
	for(; idx ; idx -= idx&-idx)
		sum += bit[idx];
	return sum;
}

int get(int l, int r) {
  return get(r) - get(l - 1);
}

// return the number of segs with inversions count less than or equal to "inversions"
ll calc(ll inversions) {
  for(int i = 0; i <= n; i++)
    bit[i] = 0;
  int index = 0;
  ll res = 1, cur_inv = 0;
  add(arr[0] + 1, 1);
  for(int i = 1; i < n; i++) {
    if(arr[i] + 1 < n)
      cur_inv += get(arr[i] + 2, n);
    add(arr[i] + 1, 1);
    while(cur_inv > inversions) {
      if(arr[index] > 0) cur_inv -= get(1, arr[index]);
      add(arr[index] + 1, -1);
      index++;
    }
    res += i - index + 1;
  }
  return res;
}

void format() {
  map<int, int> id;
  for(int i = 0; i < n; i++) {
    id[arr[i]];
  }
  int idx = 0;
  for(auto& x : id) {
    x.second = idx++;
  }
  for(int i = 0; i < n; i++)
    arr[i] = id[arr[i]];
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
  format();
  ll seg_count = (1LL * n * (n + 1) / 2 + 1) / 2;
  ll l = 0, r = 1LL * n * (n - 1) / 2, ans = 0;
  while(l <= r) {
    ll mid = (l + r) >> 1;
    if(calc(mid) >= seg_count) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
