#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

const int N = 6e5 + 5;

int n, m;
int bit[N];
int mn[N], mx[N];
int last_pos[N];

void add(int idx, int v)
{
  for(int i = idx ; i < N ; i += i & -i)
    bit[i] += v;
}

int get(int idx)
{
  int res = 0;
  for(int i = idx ; i > 0 ; i -= i & -i)
    res += bit[i];
  return res;
}

int get(int a, int b)
{
  return get(b) - get(a - 1);
}

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 1 ; i <= n ; i++){
    mn[i] = mx[i] = i;
    add(n - i + 1, 1);
    last_pos[i] = n - i + 1;
  }
  for(int i = 0 ; i < m ; i++){
    int a; scanf("%d", &a);
    int new_pos = i + n + 1;
    int& pos = last_pos[a];
    mx[a] = max(mx[a], get(pos, new_pos));
    mn[a] = 1;
    add(pos, -1);
    add(new_pos, 1);
    pos = new_pos;
  }
  for(int i = 1 ; i <= n ; i++){
    mx[i] = max(mx[i], get(last_pos[i], m + n + 1));
  }
  for(int i = 1 ; i <= n ; i++)
    printf("%d %d\n", mn[i], mx[i]);
  return 0;
}
