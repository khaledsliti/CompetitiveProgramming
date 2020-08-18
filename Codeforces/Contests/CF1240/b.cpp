#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
int arr[N], ex[N];
vector<int> pos[N];
int nxt[N];

int check(int i, int j)
{
  if(!sz(pos[i]) || !sz(pos[j]))
    return true;
  return pos[i].back() < pos[j].front();
}

int main()
{
  int q;
  scanf("%d", &q);
  while(q--){
    scanf("%d", &n);
    for(int i = 0 ; i <= n ; i++)
      ex[i] = 0, pos[i].clear();
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      ex[arr[i]] = 1;
      pos[arr[i]].push_back(i);
    }
    vector<int> v;
    for(int i = 1 ; i <= n ; i++)
      if(ex[i])
        v.pb(i);
    nxt[sz(v) - 1] = sz(v) - 1;
    for(int i = sz(v) - 2 ; i >= 0 ; i--){
      if(check(v[i], v[i + 1]))
        nxt[i] = nxt[i + 1];
      else
        nxt[i] = i;
    }
    int best = 1e9;
    for(int i = 0 ; i < sz(v) ; i++){
      int cur = sz(v) - (nxt[i] - i + 1);
      best = min(best, cur);
    }
    printf("%d\n", best);
  }
  return 0;
}
