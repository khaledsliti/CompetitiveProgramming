#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 4e5 + 5;

struct state{
  int pos;
  int type;
  int idx;
  bool operator<(const state& other) const {
    if(pos != other.pos)
      return pos < other.pos;
    return type < other.type;
  }
};

int n;
vector<pair<int, int>> seg;
vector<state> st;
int ans[N];

bool have_next(int i, int before)
{
  int j = i;
  // cout << before << endl;
  while(j < sz(st) && st[i].pos == st[j].pos){
    int t = st[j].type;
    // cout << t << endl;
    if(t == 1) before++;
    else before--;
    j++;
  }
  // cout << st[i].pos << "   -- - --   " << before << endl;
  return before > 0;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    st.clear(); seg.clear();
    for(int i = 0 ; i < n ; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      b *= 2;
      a *= 2;
      if(a == b) a--;
      seg.pb({a, b});
      st.pb({a, 1, i});
      st.pb({b, 0, i});
      ans[i] = 0;
    }
    sort(all(st));
    unordered_set<int> seg_idx;
    int before = 0;
    for(int i = 0 ; i < sz(st) ; i++){
      int j = i;
      int after = before;
      while(j < sz(st) && st[i].pos == st[j].pos){
        int idx = st[j].idx;
        int t = st[j].type;
        if(t == 1){
          after++;
          seg_idx.insert(idx);
        }else{
          after--;
          seg_idx.erase(idx);
        }
        j++;
      }
      if(before >= 1 && after == 1 && have_next(j, after)){
        int idx = *seg_idx.begin();
        ans[idx]++;
        // cout << idx + 1 << st[i].pos << endl;
      }
      before = after;
      i = j - 1;
    }
    int best = -1;
    for(int i = 0 ; i < sz(seg) ; i++)
      if(best == -1 || ans[i] > ans[best])
        best = i;
    vector<pair<int, int>> tmp;
    for(int i = 0 ; i < sz(seg) ; i++)
      if(i != best)
        tmp.pb(seg[i]);
    seg = tmp;
    sort(all(seg));
    int tot = 0;
    for(int i = 0 ; i < sz(seg) ; i++){
      int right = seg[i].second;
      int j = i;
      while(j < sz(seg) && seg[j].first <= right){
        right = max(right, seg[j].second);
        j++;
      }
      i = j - 1;
      tot++;
    }
    cout << tot << endl;
  }
  return 0;
}
