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
 
const int A = 128;
const int N = 400005;
 
int n;
char s[N];
int suff[N], t_suff[N], rnk[N], rnk_start[N], t_rnk[N];
int lcp[N];
int* head = t_rnk, *nxt = lcp;
int nxt_pos[N], prv_pos[N];
 
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
  for(len = 0; !len || s[len - 1]; len++) {
    nxt[len] = head[s[len]];
    head[s[len]] = len;
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
  for(int i = 0, len = 0; i < n; i++) {
    int j = suff[rnk[i] - 1];
    while(s[i + len] == s[j + len]) len++;
    lcp[rnk[i]] = len;
    if(len) len--;
  }
}

int main()
{
  scanf("%s", s);
  n = strlen(s);
  build_suff_array();
  build_lcp();


  stack<pair<int, int>> st;
  st.push({-1, n + 1});
  for(int i = n; i > 0; i--) {
    while(st.empty() == false && st.top().first >= lcp[i])
      st.pop();
    nxt_pos[i] = st.top().second;
    st.push({lcp[i], i});
  }
  while(st.empty() == false)
    st.pop();
  st.push({-1, 0});
  for(int i = 1; i <= n; i++) {
    while(st.empty() == false && st.top().first > lcp[i])
      st.pop();
    prv_pos[i] = st.top().second;
    st.push({lcp[i], i});
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    int l = prv_pos[i] + 1;
    int r = nxt_pos[i] - 1;
    ans += 1LL * lcp[i] * (i - l + 1) * (r - i + 1);
  }
  ans += 1LL * n * (n + 1) / 2;
  cout << ans << endl;
  return 0;
}
