#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 2e5 + 5;

// O(Q + N log(Q))
namespace Solution1{

  struct segment{
    int color;
    int index;
    segment(int color, int index): color(color), index(index) {}
    bool operator<(const segment& rhs) const {
      return index > rhs.index;
    }
  };

  int n;
  vector<int> add[N], del[N];
  vector<segment> queries;

  void solve()
  {
    int q;
    scanf("%d%d", &n, &q);
    for(int it = 0 ; it < q ; it++){
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);
      queries.push_back(segment(c, it));
      add[--l].push_back(it);
      del[r].push_back(it);
    }
    set<segment> seg;
    for(int i = 0 ; i < n ; i++){
      for(int idx : add[i])
        seg.insert(queries[idx]);
      for(int idx : del[i])
        seg.erase(queries[idx]);
      // print(seg);
      int col = sz(seg) ? seg.begin()->color : 0;
      printf("%d\n", col);
    }
  }
}

// O(N + Q)
namespace Solution2{
  struct seg{
    int l, r, c;
  };

  int n, q;
  vector<seg> queries;
  int par[N], rank[N];
  int col[N];
  int endOf[N];

  int findSet(int i)
  {
    return i == par[i] ? i : par[i] = findSet(par[i]);
  }
  void unionSet(int a, int b)
  {
    a = findSet(a);
    b = findSet(b);
    if(a != b){
      endOf[a] = endOf[b];
      if(rank[a] < rank[b])
        swap(a, b);
      par[b] = a;
      rank[a] += rank[b];
    }
  }

  void solve()
  {
    scanf("%d%d", &n, &q);
    for(int i = 0 ; i < q ; i++){
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);
      queries.push_back({--l, r, c});
    }
    for(int i = 0 ; i <= n ; i++){
      rank[i] = 1;
      par[i] = i;
      endOf[i] = i;
    }
    for(int i = q - 1 ; i >= 0 ; i--){
      for(int cur = endOf[findSet(queries[i].l)] ; cur < queries[i].r ; cur = endOf[findSet(cur)]){
        col[cur] = queries[i].c;
        unionSet(cur, cur + 1);
      }
    }
    for(int i = 0 ; i < n ; i++)
      printf("%d\n", col[i]);
  }
}

int main()
{
  Solution2::solve();
  return 0;
}
