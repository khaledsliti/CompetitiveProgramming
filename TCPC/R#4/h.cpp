#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int V = 1e6 + 5;
const int MOD = 1e9 + 7;
const int BLOCK_SIZE = 317;

int fast_pow(long long a, int b)
{
  long long r = 1;
  while(b){
    if(b & 1) r = r * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}

int block_idx[N];

struct query{
  int l, r, idx;
  bool operator<(const query& other) const {
    if(block_idx[l] != block_idx[other.l])
      return l < other.l;
    return block_idx[l] ? r < other.r : r > other.r;
  }
};

int n, q;
int arr[N];
int ans[N];
int inv[N];
long long cur_ans;
query qr[N];

int total, occ[V];

void add(int idx)
{
  cur_ans = (cur_ans * ++total) % MOD;
  cur_ans = (cur_ans * inv[++occ[arr[idx]]]) % MOD;
}

void del(int idx)
{
  cur_ans = (cur_ans * occ[arr[idx]]--) % MOD;
  cur_ans = (cur_ans * inv[total--]) % MOD;
}

int main()
{
  for(int i = 0 ; i < N ; i++){
    inv[i] = fast_pow(i, MOD - 2);
    block_idx[i] = i / BLOCK_SIZE;
  }
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &n, &q);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      occ[arr[i]] = 0;
    }
    for(int i = 0 ; i < q ; i++){
      scanf("%d%d", &qr[i].l, &qr[i].r);
      qr[i].l--;
      qr[i].idx = i;
    }
    sort(qr, qr + q);
    int st = 0, en = 0;
    total = 0;
    cur_ans = 1;
    for(int i = 0 ; i < q ; i++){
      int l = qr[i].l, r = qr[i].r;
      while(st > l) add(--st);
      while(en < r) add(en++);
      while(st < l) del(st++);
      while(en > r) del(--en);
      ans[qr[i].idx] = cur_ans;
    }
    for(int i = 0 ; i < q ; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}
