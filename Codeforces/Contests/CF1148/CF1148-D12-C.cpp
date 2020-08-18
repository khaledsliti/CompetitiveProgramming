#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;

int n;
int per[N], pos[N];
vector<pair<int, int>> ans;

void mySwap(int a, int b)
{
  ans.pb({a, b});
  swap(pos[per[a]], pos[per[b]]);
  swap(per[a], per[b]);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &per[i]);
    per[i]--;
    pos[per[i]] = i;
  }
  for(int cur = 0 ; cur < n ; cur++){
    int idx = pos[cur];
    if(idx == cur)
      continue;
    if(abs(idx - cur) >= n / 2){
      mySwap(cur, pos[cur]);
    }else{
      int a = cur, b = pos[cur];
      int witha = a >= n / 2 ? 0 : n - 1;
      int withb = b >= n / 2 ? 0 : n - 1;
      if(withb == witha){
        mySwap(b, withb);
        mySwap(a, withb);
        mySwap(b, withb);
      }else{
        mySwap(witha, a);
        mySwap(withb, b);
        mySwap(witha, withb);
        mySwap(witha, a);
        mySwap(withb, b);
      }
    }
  }
  printf("%d\n", sz(ans));
  for(int i = 0 ; i < sz(ans) ; i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}