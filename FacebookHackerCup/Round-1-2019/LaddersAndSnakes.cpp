/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.facebook.com/hackercup/problem/448364075989193/

  Idea:
    Minimum-Cut problem.
    Ladders are nodes, floor is source and ceiling is sink.
    The flow between ladder i and ladder j is the length of horizontally visible part of ladder j from ladder i.

  Compexity:
    Time: O(N ^ 4)
    Memory: O(N ^ 2)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

const int N = 55;
const int oo = 1e9;

struct segment{
  int a, b, x;
  int idx;
};

bool overlap(segment& s1, segment& s2) {
  return !(s1.a > s2.b || s2.a > s1.b);
}

int nin, h, n;
segment seg[N];
int src, dst;
int g[N][N];

vector<segment> merge(vector<segment> seg) {
  vector<segment> res;
  sort(seg.begin(), seg.end(), [](segment& s, segment& t){
    return s.a < t.a;
  });
  for(int i = 0 ; i < sz(seg) ; i++){
    int left = seg[i].a;
    int right = seg[i].b;
    int j = i;
    while(j < sz(seg) && seg[j].a <= right)
      right = max(right, seg[j++].b);
    i = j - 1;
    res.push_back({left, right});
  }
  return res;
}

vector<segment> rev(vector<segment> seg) {
  if(!sz(seg))
    return { {0, h} };
  sort(seg.begin(), seg.end(), [](segment& s, segment& t){
    return s.a < t.a;
  });
  vector<segment> res;
  if(seg[0].a > 0)
    res.push_back({0, seg[0].a});
  for(int i = 0 ; i + 1 < sz(seg) ; i++) {
    res.push_back({ seg[i].b, seg[i + 1].a });
  }
  if(seg.back().b < h)
    res.push_back({seg.back().b, h});
  return res;
}

vector<segment> intersect(vector<segment> seg, segment cur) {
  vector<segment> res;
  for(int i = 0 ; i < sz(seg) ; i++){
    if(!overlap(seg[i], cur))
      continue;
    res.push_back({ max(seg[i].a, cur.a), min(seg[i].b, cur.b) });
  }
  return res;
}

void connect(vector<segment> mid, segment source, segment sink) {
  mid = merge(mid);
  mid = rev(mid);
  mid = intersect(mid, sink);
  mid = intersect(mid, source);
  int flow = 0;
  for(int i = 0 ; i < sz(mid) ; i++)
    flow += mid[i].b - mid[i].a;
  g[source.idx + 1][sink.idx + 1] = flow;
}

void connect(vector<segment>& seg, segment source) {
  vector<segment> mid;
  for(int i = 0 ; i < sz(seg) ; i++){
    connect(mid, source, seg[i]);
    mid.push_back(seg[i]);
  }
}

void build_graph()
{
  n = nin + 2;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      g[i][j] = 0;
  src = 0;
  dst = n - 1;
  for(int i = 0 ; i < nin ; i++){
    vector<segment> left, right;
    for(int j = 0 ; j < nin ; j++){
      if(seg[j].x < seg[i].x)
        left.push_back(seg[j]);
      else if(seg[j].x > seg[i].x)
        right.push_back(seg[j]);
    }
    // build left
    sort(left.begin(), left.end(), [](segment& a, segment& b){
      return a.x > b.x;
    });
    connect(left, seg[i]);
    // build right
    sort(right.begin(), right.end(), [](segment& a, segment& b){
      return a.x < b.x;
    });
    connect(right, seg[i]);
    if(seg[i].a == 0)
      g[src][seg[i].idx + 1] = oo;
    if(seg[i].b == h)
      g[seg[i].idx + 1][dst] = oo;
  }
}

//---------------
int ID;
int vis[N];

int dfs(int cur, int snk, int MX)
{
  if(vis[cur] == ID || MX == 0) return 0;
  vis[cur] = ID;
  if(cur == snk) return MX;
  for(int nxt = 0 ; nxt < n ; nxt++){
    if(g[cur][nxt] <= 0) continue;
    int f = dfs(nxt, snk, min(MX, g[cur][nxt]));
    if(!f) continue;
    g[cur][nxt] -= f;
    g[nxt][cur] += f;
    return f;
  }
  return 0;
}

int max_flow()
{
  int ret = 0;
  int f;
  for(ID++; (f = dfs(src, dst, oo)); ID++){
    ret += f;
  }
  return ret;
}

int main()
{
  int T, tc(1);
  cin >> T;
  while(T--){
    cin >> nin >> h;
    for(int i = 0 ; i < nin ; i++){
      cin >> seg[i].x >> seg[i].a >> seg[i].b;
      seg[i].idx = i;
    }
    build_graph();
    int mxf = max_flow();
    if(mxf >= oo) mxf = -1;
    cout << "Case #" << tc++ << ": " << mxf << endl;
  }
  return 0;
}
