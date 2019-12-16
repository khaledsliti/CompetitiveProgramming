#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 2e5 + 5;

int n, q;
char s[N];
int arr[N];
int par[N];
int cnt[3];

int fs(int x)
{
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  for(int i = 0 ; i < n ; i++){
    if(s[i] == 'W') arr[i] = 0;
    if(s[i] == 'B') arr[i] = 1;
    if(s[i] == 'G') arr[i] = 2;
    cnt[arr[i]]++;
  }
  for(int i = 0 ; i <= n ; i++){
    par[i] = i;
  }
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    // cout << l << " " << r << endl;
    for(int idx = fs(--l) ; idx < r ; idx = fs(idx)){
      int act = arr[idx];
      cnt[act]--;
      cnt[(act + 1) % 3]++;
      par[idx] = fs(idx + 1);
    }
    printf("%d %d %d\n", cnt[0], cnt[2], cnt[1]);
  }
  return 0;
}
