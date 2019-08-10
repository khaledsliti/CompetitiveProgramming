#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1005;

int bit[N][N];

void add(int i, int j, int val)
{
  for(int x = i; x < N; x += x & -x)
    for(int y = j; y < N; y += y & -y)
      bit[x][y] += val;
}

int get(int i, int j)
{
  int res = 0;
  for(int x = i; x > 0; x -= x & -x)
    for(int y = j; y > 0; y -= y & -y)
      res += bit[x][y];
  return res;
}

int get(int l, int r, int d, int u)
{
  return get(r, u) - get(l - 1, u) - get(r, d - 1) + get(l - 1, d - 1);
}

int index(int i, int j)
{
  return i * N + j;
}

pair<int, int> index(int idx)
{
  return { idx / N, idx % N };
}

int main()
{
  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    printf("Case %d:\n", tc++);
    int q;
    scanf("%d", &q);
    unordered_set<int> pts;
    while(q--){
      int t;
      scanf("%d", &t);
      if(t == 0){
        int x, y;
        scanf("%d%d", &x, &y);
        x++; y++;
        if(pts.find(index(x, y)) == pts.end()){
          add(x, y, 1);
          pts.insert(index(x, y));
        }
      }else{
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", get(++x1, ++x2, ++y1, ++y2));
      }
    }
    for(auto& idx : pts){
      pair<int, int> p = index(idx);
      add(p.first, p.second, -1);
    }
  }
  return 0;
}
