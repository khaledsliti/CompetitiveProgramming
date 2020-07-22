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

const int N = 300005;
const int A = 128;

char s[N], p[N];
int suff[N], t_suff[N], rnk[N], rnk_start[N], t_rnk[N];
int lcp[N];

int* head = t_rnk, *nxt = lcp;

struct Comparator {
  int len;
  Comparator(int len): len(len) {}
  bool operator()(const int& a, const int& b) {
    return rnk[a] < rnk[b] || rnk[a] == rnk[b] && rnk[a + len] < rnk[b + len];
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

int main()
{
  scanf("%s", s);
  int len = strlen(s);
  build_suff_array();
  int q;
  scanf("%d", &q);
  while(q--) {
    scanf("%s", p);
    int start = 1, end = len;
    for(int i = 0; p[i] && start <= len; i++) {
      char target = p[i];
      int lo = start, hi = end, new_start = -1;
      while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(s[suff[mid] + i] >= target) {
          new_start = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if(new_start == -1 || s[suff[new_start] + i] != target) {
        start = len + 1;
        break;
      }
      lo = new_start, hi = end;
      int new_end;
      while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(s[suff[mid] + i] == target) {
          new_end = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      start = new_start;
      end = new_end;
    }
    int ans = max(0, end - start + 1);
    printf("%d\n", ans);
  }
  return 0;
}
