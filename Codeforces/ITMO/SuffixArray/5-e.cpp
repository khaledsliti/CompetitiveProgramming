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


const int A = 11;
const int N = 150100;
const int L = 19;

int n, m;
int arr[N];
int suff[N], t_suff[N], rnk[N], rnk_start[N], t_rnk[N], lcp[N];
pair<int, int> dp[N][L];
int nxt_pos[N], last[N];

int* head = t_rnk, *nxt = lcp;

struct Comparator {
  int len;
  Comparator(int len): len(len) {}
  bool operator()(const int& i, const int& j) const {
    return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + len] < rnk[j + len]);
  }
};

void build_suff_array() {
  int len;
  memset(head, -1, A * sizeof(head));
  for(len = 0; len <= n; len++) {
    nxt[len] = head[arr[len]];
    head[arr[len]] = len;
  }
  int cur_rnk = 0, j = 0;
  for(int i = 0; i < A; i++) {
    if(head[i] != -1) {
      rnk_start[cur_rnk] = j;
      for(int k = head[i]; ~k; k = nxt[k]) {
        suff[j++] = k;
        rnk[k] = cur_rnk;
      }
      cur_rnk++;
    }
  }
  t_suff[0] = suff[0];
  t_rnk[0] = 0;
  for(int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    Comparator isSmaller(width);
    for(int i = 0; i < len; i++) {
      j = suff[i] - width;
      if(j < 0) continue;
      t_suff[rnk_start[rnk[j]]++] = j;
    }
    for(int i = 1; i < len; i++) {
      bool nw_rnk =  isSmaller(t_suff[i - 1], t_suff[i]);
      t_rnk[i] = t_rnk[i - 1] + nw_rnk;
      if(nw_rnk) rnk_start[t_rnk[i]] = i;
    }
    for(int i = 0; i < len; i++) {
      suff[i] = t_suff[i];
      rnk[suff[i]] = t_rnk[i];
    }
  }
}

void build_lcp() {
  lcp[0] = 0;
  for(int i = 0, len = 0; i < n; i++) {
    int j = suff[rnk[i] - 1];
    while(max(i + len, j + len) < n && arr[i + len] == arr[j + len]) len++;
    lcp[rnk[i]] = len;
    if(len) len--;
  }
}

void build_sparse() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < L; j++)
      dp[i][j] = {-1, -1};
  for(int i = 0; i < n; i++)
    dp[i][0] = {lcp[i + 1], i};
  for(int j = 1; j < L; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
}

pair<int, int> get_min(int l, int r) {
  int lg = 0;
  while(l + (1 << lg) - 1 <= r) lg++;
  lg--;
  return min(dp[l][lg], dp[r - (1 << lg) + 1][lg]);
}

ll best;
int st, len;
void solve(int l, int r) {
  if(l > r) return;
  // cout << l << " " << r << endl;
  auto mn = get_min(l, r);
  ll cur = 1LL * (r - l + 2) * mn.first;
  if(cur > best) {
    best = cur;
    st = suff[l];
    len = mn.first;
  }
  solve(l, mn.second - 1);
  l = mn.second + 1;
  for(int i = mn.second; i <= r; i = nxt_pos[i]) {
    solve(i + 1, min(r, nxt_pos[i] - 1));
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
  build_suff_array();
  build_lcp();
  int mx = 0;
  for(int i = 0; i < n; i++) {
    mx = max(mx, lcp[i + 1]);
  }
  build_sparse();
  for(int i = 0; i <= n; i++)
    last[i] = n;
  for(int i = n - 1; i >= 0; i--) {
    nxt_pos[i] = last[lcp[i + 1]];
    last[lcp[i + 1]] = i;
  }
  // for(int i = 0; i < n; i++)
  //   cout << lcp[i + 1] << " "; cout << endl;
  best = len = n;
  st = 0;
  solve(0, n - 1);
  printf("%lld\n%d\n", best, len);
  for(int i = 0; i < len; i++)
    printf("%d%c", arr[st + i], " \n"[i == len - 1]);
  return 0;
}
