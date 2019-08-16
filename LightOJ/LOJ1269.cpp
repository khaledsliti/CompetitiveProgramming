#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e4 + 5;
const int L = 31;

struct node{
  int nxt[2];
  node(){
    nxt[0] = nxt[1] = -1;
  }
};

int n;
int arr[N];
vector<node> trie;

void add(int v)
{
  int cur = 0;
  for(int i = L - 1 ; i >= 0 ; i--){
    int d = (v >> i) & 1;
    if(trie[cur].nxt[d] == -1){
      trie[cur].nxt[d] = trie.size();
      trie.push_back(node());
    }
    cur = trie[cur].nxt[d];
  }
}

int solve(int val, int rev)
{
  int ans = 0;
  int cur = 0;
  for(int i = L - 1 ; i >= 0 ; i--){
    int need = (val >> i) & 1;
    if(rev) need = !need;
    if(trie[cur].nxt[need] == -1)
      need = !need;
    if(need)
      ans |= (1 << i);
    cur = trie[cur].nxt[need];
  }
  return ans ^ val;
}

int main()
{
  int T, tc(1);
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
      scanf("%d", arr + i);
    trie.clear();
    trie.push_back(node());
    add(0);
    int mx = 0, mn = (1LL << 31) - 1;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      sum ^= arr[i];
      mx = max(mx, solve(sum, 1));
      mn = min(mn, solve(sum, 0));
      add(sum);
    }
    printf("Case %d: %d %d\n", tc++, mx, mn);
  }
  return 0;
}
