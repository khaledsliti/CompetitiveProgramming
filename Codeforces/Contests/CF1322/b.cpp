// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void debug() { cerr << endl; }

template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << " " << H;
  debug(T...);
}

const int N = 4e5 + 5;
const int B = 25;

struct node
{
  int nxt[2];
  int cnt;
  node(){
    nxt[0] = nxt[1] = -1;
    cnt = 0;
  }
};

int n;
int arr[N];
vector<node> trie;

void add(int x, int bit)
{
  int cur = 0;
  for(int i = bit ; i >= 0 ; i--) {
    int v = (x >> i) & 1;
    if(trie[cur].nxt[v] == -1){
      trie[cur].nxt[v] = sz(trie);
      trie.push_back(node());
    }
    cur = trie[cur].nxt[v];
    trie[cur].cnt++;
  }
}

int get_count(int cur)
{
  if(cur == -1)
    return 0;
  return trie[cur].cnt;
}

int calc_diff(int val, int cur, int bit)
{
  if(cur == -1 || bit == -1)
    return 0;
  int ith = (val >> bit) & 1;
  if(bit == 0)
    return ith == 1 ? 0 : get_count(cur);
  if(ith == 0) {
    return get_count(trie[cur].nxt[0]) + calc_diff(val, trie[cur].nxt[1], bit - 1);
  } else {
    return calc_diff(val, trie[cur].nxt[0], bit - 1);
  }
}

int calc_same(int val, int cur, int bit)
{
  if(cur == -1)
    return 0;
  int ith = (val >> bit) & 1;
  if(bit == 0)
    return ith == 0 ? 0 : get_count(trie[cur].nxt[1]);
  if(ith == 0) {
    return calc_same(val, trie[cur].nxt[1], bit - 1);
  } else {
    return get_count(trie[cur].nxt[1]) + calc_same(val, trie[cur].nxt[0], bit - 1);
  }
}

int calc(int val, int bit)
{
  int b = (val >> bit) & 1;
  int x = calc_same(val, trie[0].nxt[b], bit - 1);
  int y = calc_diff(val, trie[0].nxt[!b], bit - 1);
  // debug(val, bit, x, y);
  return x + y;
}

bool solve(int bit)
{
  trie.clear();
  trie.pb(node());
  long long cnt = 0;
  for(int i = 0 ; i < n ; i++) {
    cnt += calc(arr[i], bit);
    add(arr[i], bit);
  }
  return cnt & 1;
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  int ans = 0;
  for(int b = 0 ; b < 3 ; b++) {
    if(solve(b))
      ans |= (1 << b);
  }
  cout << ans << endl;
  return 0;
}
