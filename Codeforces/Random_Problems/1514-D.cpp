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

const int N = 3e5 + 5;
const int BLOCK_SIZE = 550;

int n, q;
int arr[N];
int ans[N];
int fr[N], freq_occ[N];
int max_pointer = 0;

struct query {
  int l, r, idx, block;
  bool operator<(const query& rhs) const {
    if(block != rhs.block) return l < rhs.l;
    return (block & 1) ? (r < rhs.r) : (r > rhs.r);
  }
} qr[N];

void add(int x) {
  freq_occ[fr[x]]--;
  fr[x]++;
  freq_occ[fr[x]]++;
  while(freq_occ[max_pointer + 1] != 0) {
    max_pointer++;
  }
}

void remove(int x) {
  freq_occ[fr[x]]--;
  fr[x]--;
  freq_occ[fr[x]]++;
  while(max_pointer > 0 && freq_occ[max_pointer] == 0) {
    max_pointer--;
  }
}

int get_answer() {
  return max_pointer;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for(int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    qr[i] = {l, r, i, l / BLOCK_SIZE};
  }
  sort(qr, qr + q);
  int cur_l = 0, cur_r = -1;
  for(int i = 0; i < q; i++) {
    int l = qr[i].l, r = qr[i].r;
    while(cur_l > l) {
      cur_l--;
      add(arr[cur_l]);
    }
    while(cur_l < l) {
      remove(arr[cur_l]);
      cur_l++;
    }
    while(cur_r < r) {
      cur_r++;
      add(arr[cur_r]);
    }
    while(cur_r > r) {
      remove(arr[cur_r]);
      cur_r--;
    }
    int mx = get_answer(), len = r - l + 1;
    bool ok = (len + 1) / 2 >= mx;
    int rem = len - mx;
    ans[qr[i].idx] = ok ? 1 : len - 2 * rem;
  }
  for(int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
