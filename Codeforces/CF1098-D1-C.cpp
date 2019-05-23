#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, b, par_so_far;
long long s;
int cnt[N];
int par[N];

bool check(long long rem_sum, int prv, int rem_nodes, int lev, int br)
{
  if(br == 1)
    return 1LL * rem_nodes * (lev + lev + rem_nodes) / 2 == rem_sum;
  long long res = 0;
  for(long long i = 1LL * prv * br ; rem_nodes > 0 ; i *= br, lev++){
    long long take = min(1LL * rem_nodes, i);
    res += take * lev;
    rem_nodes -= take;
  }
  return res <= rem_sum;
}

void solve(long long rem_sum, int cur_node, int prv, int lev)
{
  if(cur_node > n)
    return;
  int rem_nodes = n - cur_node + 1;
  int l = 1, r = min(1LL * rem_nodes, min(1LL * prv * b, rem_sum / lev));
  int best = -1;
  while(l <= r){
    int take = (l + r) / 2;
    if(check(rem_sum - 1LL * take * lev, take, rem_nodes - take, lev + 1, b)){
      best = take;
      r = take - 1;
    }else{
      l = take + 1;
    }
  }
  assert(best != -1);
  for(int i = cur_node ; i < cur_node + best ; i++){
    par[i] = par_so_far;
    if(++cnt[par_so_far] == b)
      par_so_far++;
  }
  par_so_far = cur_node;
  solve(rem_sum - 1LL * best * lev, cur_node + best, best, lev + 1);
}

int main()
{
  cin >> n >> s;
  if(s > 1LL * n * (n + 1) / 2LL || s < 2LL * n - 1)
    return puts("No"), 0;
  int l = 1, r = n;
  b = n;
  while(l <= r){
    int mid = (l + r) / 2;
    if(check(s - 1, 1, n - 1, 2, mid)){
      b = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  if(b == 1){
    printf("Yes\n");
    for(int i = 2 ; i <= n ; i++)
      cout << i - 1 << " ";
    cout << endl;
    return 0;
  }
  par_so_far = 1;
  solve(s - 1, 2, 1, 2);
  puts("Yes");
  for(int i = 2 ; i <= n ; i++)
    printf("%d ", par[i]);
  printf("\n");
  return 0;
}
