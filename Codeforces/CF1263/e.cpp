#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define L(x) (2 * (x) + 1)
#define R(x) (2 * (x) + 2)

const int N = 1e6 + 5;

struct node{
  int mn, mx;
  int lz;
};

int n;
node st[4 * N];
char v[N];

node merge(node a, node b)
{
  return { min(a.mn, b.mn), max(a.mx, b.mx), 0 };
}

void pushDown(int cur, int s, int e)
{
  if(!st[cur].lz)
    return;
  st[cur].mn += st[cur].lz;
  st[cur].mx += st[cur].lz;
  if(s != e){
    int l = L(cur);
    int r = R(cur);
    st[l].lz += st[cur].lz;
    st[r].lz += st[cur].lz;
  }
  st[cur].lz = 0;
}

void update(int cur, int s, int e, int i, int j, int val)
{
  pushDown(cur, s, e);
  if(s > j || e < i)
    return;
  if(s >= i && e <= j){
    st[cur].lz += val;
    pushDown(cur, s, e);
    return;
  }
  int l = L(cur);
  int r = R(cur);
  int mid = (s + e) / 2;
  update(l, s, mid, i, j, val);
  update(r, mid + 1, e, i, j, val);
  st[cur] = merge(st[l], st[r]);
}

void update(int idx, int val)
{
  // cout << "update --- " << idx << " ---- " << val << endl;
  update(0, 0, N - 1, idx, N - 1, val);
}

node query(int cur, int s, int e, int i, int j)
{
  pushDown(cur, s, e);
  if(s > j || e < i)
    return {0, 0, 0};
  if(s >= i && e <= j)
    return st[cur];
  int l = L(cur);
  int r = R(cur);
  int mid = (s + e) / 2;
  return merge(query(l, s, mid, i, j), query(r, mid + 1, e, i, j));
}

int query(int sum)
{
  if(sum != 0)
    return -1;
  node ans = query(0, 0, N - 1, 0, N - 1);
  if(ans.mn >= 0)
    return ans.mx;
  return -1;
}

int main()
{
  memset(v, 0, sizeof v);
  int q;
  scanf("%d", &q);
  int idx = 0;
  int sum = 0;
  while(q--){
    char c;
    scanf(" %c", &c);
    if(c == 'R') idx++;
    else if(c == 'L') idx = max(0, --idx);
    else{
      int add = 0;
      if(c == '('){
        if(v[idx] == '(') add = 0;
        else if(v[idx] == ')') add = 2, sum += 2;
        else add = 1, sum += 1;
        v[idx] = '(';
      } else if(c == ')'){
        if(v[idx] == '(') add = -2, sum -= 2;
        else if(v[idx] == ')') add = 0;
        else add = -1, sum -= 1;
        v[idx] = ')';
      }else{
        if(v[idx] == '(') add = -1, sum -= 1;
        else if(v[idx] == ')') add = 1, sum += 1;
        else add = 0;
        v[idx] = 0;
      }
      if(add)
        update(idx, add);
    }
    printf("%d ", query(sum));
  }
  return 0;
}
