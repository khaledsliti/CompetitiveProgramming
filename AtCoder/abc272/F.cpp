// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

vector<int> SuffixArray(const char *s, int n, int charBound) {
  vector<int> head(charBound, -1), nxt(n);
  int len;
  for(len = 0; len <= n; len++) {
    nxt[len] = head[s[len]];
    head[s[len]] = len;
  }
  vector<int> rnk(len);
  vector<int> suff(len);
  vector<int> rnk_start(len);
  for(int i = 0, j = 0, cur_rnk = 0; i < charBound; i++) {
    if(head[i] != -1) {
      rnk_start[cur_rnk] = j;
      for(int k = head[i]; ~k; k = nxt[k]) {
        suff[j++] = k;
        rnk[k] = cur_rnk;
      }
      cur_rnk++;
    }
  }
  vector<int> t_suff(len), t_rnk(len, 0);
  t_suff[0] = suff[0];
  for(int width = 1; t_rnk[len - 1] != len - 1; width <<= 1) {
    for(int i = 0; i < len; i++) {
      int j = suff[i] - width;
      if(j < 0) continue;
      t_suff[rnk_start[rnk[j]]++] = j;
    }
    auto isSmaller = [&](int i, int j) -> bool {
      return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + width] < rnk[j + width]);
    };
    for(int i = 1; i < len; i++) {
      bool newRnk = isSmaller(t_suff[i - 1], t_suff[i]);
      t_rnk[i] = t_rnk[i - 1] + newRnk;
      if(newRnk) {
        rnk_start[t_rnk[i]] = i;
      }
    }
    for(int i = 0; i < len; i++) {
      suff[i] = t_suff[i];
      rnk[suff[i]] = t_rnk[i];
    }
  }
  return suff;
}

vector<int> BuildLcp(const char *s, const vector<int>& suff) {
  int n = (int) suff.size();
  vector<int> pos(n);
  for(int i = 0; i < n; i++) {
    pos[suff[i]] = i;
  }
  int len = 0;
  vector<int> lcp(n - 1, 0);
  for(int i = 0; i < n; i++) {
    len = max(len - 1, 0);
    if(pos[i] == n - 1) {
      len = 0;
    } else {
      int j = suff[pos[i] + 1];
      while(i + len < n - 1 && j + len < n - 1 && s[i + len] == s[j + len]) {
        len++;
      }
      lcp[pos[i]] = len;
    }
  }
  return lcp;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; cin >> n;
  string s, t; cin >> s >> t;
  auto w = s + s + t + t;
  auto str = w.c_str();
  auto suff = SuffixArray(str, w.size(), 128);
  auto lcp = BuildLcp(str, suff);

  int so_far = 0;
  long long ans = 0;
  for(int i = 0; i < sz(suff); i++) {
    int j = i;
    while(j < sz(lcp) && lcp[j] >= n) {
      j++;
    }
    for(int k = i; k <= j; k++) {
      if(suff[k] < n) {
        so_far++;
      }
    }
    for(int k = i; k <= j; k++) {
      if(suff[k] >= 2 * n && suff[k] < 3 * n) {
        ans += so_far;
      }
    }
    i = j;
  }
  cout << ans << endl;
  return 0;
}
