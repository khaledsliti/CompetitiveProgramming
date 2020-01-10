#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

//Constants
const int N = 1e5 + 5;
const int BLOCK_SIZE = 320; // 320

//DATA
int n, q, blocks;
int arr[N];
short len[BLOCK_SIZE];
int vals[BLOCK_SIZE][(BLOCK_SIZE << 1) + 5];
short freq[BLOCK_SIZE][N];

//Methods
void build()
{
  for(int b = 0 ; b < blocks ; b++){
    int st = b * BLOCK_SIZE;
    int en = min(n, st + BLOCK_SIZE);
    for(int i = st ; i < en ; i++){
      vals[b][len[b]++] = arr[i];
      freq[b][arr[i]]++;
    }
  }
}

void rebuild()
{
  int l = 0;
  for(int b = 0 ; b < blocks ; b++){
    for(int i = 0 ; i < len[b] ; i++)
      freq[b][vals[b][i]]--, arr[l++] = vals[b][i];
    len[b] = 0;
  }
  build();
}

int erase(int idx)
{
  for(int sum = 0, b = 0; b < blocks; b++){
    sum += len[b];
    if(idx < sum){
      int pos = idx - sum + len[b];
      int item = vals[b][pos];
      freq[b][item]--;
      for(int j = pos ; j + 1 < len[b] ; j++)
        vals[b][j] = vals[b][j + 1];
      len[b]--;
      return item;
    }
  }
  return -1;
}

void insert(int idx, int val)
{
  for(int sum = 0, b = 0; b < blocks; b++){
    sum += len[b];
    if(idx < sum){
      int pos = idx - sum + len[b];
      for(int j = len[b]; j > pos ; j--)
        vals[b][j] = vals[b][j - 1];
      vals[b][pos] = val;
      freq[b][val]++;
      len[b]++;
      return;
    }
  }
}

int solve(int cnt, int k)
{
  int ans = 0;
  for(int b = 0 ; b < blocks ; b++){
    if(len[b] <= cnt){
      ans += freq[b][k];
      cnt -= len[b];
    }else{
      for(int j = 0 ; j < cnt ; j++)
        if(vals[b][j] == k)
          ++ans;
      break;
    }
  }
  return ans;
}

int main()
{
  scanf("%d", &n);
  blocks = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  build();
  int last_ans = 0;
  scanf("%d", &q);
  int slot = 0;
  while(q--){
    int t, l, r, k;
    scanf("%d%d%d", &t, &l, &r);
    l = (l + last_ans - 1) % n + 1;
    r = (r + last_ans - 1) % n + 1;
    if(l > r) swap(l, r);
    if(t == 1){
      --l, --r;
      insert(l, erase(r));
      if(++slot == BLOCK_SIZE)
        rebuild(), slot = 0;
    }else{
      scanf("%d", &k);
      k = (k + last_ans - 1) % n + 1;
      last_ans = solve(r, k) - solve(l - 1, k);
      printf("%d\n", last_ans);
    }
  }
  return 0;
}
