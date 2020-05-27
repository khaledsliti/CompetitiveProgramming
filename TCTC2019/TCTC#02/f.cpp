#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 3505;
const int A = 2e4 + 1;

int n;
int arr[N];
int par[N];
int root[N], szComp[N];

int fs(int x)
{
  return x == root[x] ? x : root[x] = fs(root[x]);
}

int build(int x)
{
  for(int i = 0 ; i < n ; i++)
    root[i] = i, szComp[i] = 1;
  for(int i = 1 ; i < n ; i++){
    if(arr[i] % x == 0 && arr[par[i]] % x == 0){
      int a = fs(i);
      int b = fs(par[i]);
      if(a != b){
        root[a] = b;
        szComp[b] += szComp[a];
      }
    }
  }
  int best = 0;
  for(int i = 0 ; i < n ; i++)
    if(root[i] == i && arr[i] %  x == 0)
      best = max(best, szComp[i]);
  return best;
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  par[0] = -1;
  for(int i = 1 ; i < n ; i++){
    cin >> par[i];
    par[i]--;
  }
  int ans = 0;
  int At;
  for(int x = 2 ; x < A ; x++){
    int cur = build(x);
    if(ans < cur){
      ans = cur;
      At = x;
    }
  }
  cout << At << " " << ans << endl;
  return 0;
}
