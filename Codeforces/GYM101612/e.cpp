#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;
const int oo = 1e9;

int n;
int arr[N];
int cnt[N], ans[N], op[N];

int main()
{
  freopen("equal.in", "r", stdin);
  freopen("equal.out", "w", stdout);
  while(~scanf("%d", &n)){
    memset(cnt, 0, sizeof cnt);
    for(int i = 0 ; i < n ; i++){
      scanf("%d", arr + i);
      cnt[arr[i]]++;
    }
    vector<int> v0, v1, v2;
    for(int i = 1 ; i < N ; i++){
      if(cnt[i]){
        bool has = false;
        for(int j = i * 2 ; j < N ; j += i){
          if(cnt[j]){
            has = true;
            break;
          }
        }
        if(has) v1.push_back(cnt[i]), v2.push_back(cnt[i]);
        else v0.push_back(cnt[i]);
      }
    }
    int diff = sz(v0) + sz(v1);
    for(int i = 0 ; i <= n ; i++)
      op[i] = oo, ans[i] = 0;
    op[diff] = 0;
    sort(all(v1));
    int choice1 = 0;
    for(int k = 1 ; k <= sz(v1) ; k++){
      choice1 += v1[k - 1];
      op[diff - k] = choice1;
    }
    sort(all(v0));
    for(int i = 2 ; i < sz(v0) ; i++)
      v2.push_back(v0[i]);
    sort(all(v2));
    if(sz(v0) >= 2){
      int choice2 = v0[0] + v0[1];
      for(int k = 1 ; k < diff ; k++){
        if(k > 1) choice2 += v2[k - 2];
        op[diff - k] = min(op[diff - k], choice2);
      }
    }
    for(int i = 1 ; i <= diff ; i++)
      ans[op[i]] = i;
    for(int i = 1 ; i <= n ; i++)
      if(ans[i] == 0)
        ans[i] = ans[i - 1];
    for(int i = 0 ; i <= n ; i++)
      printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}
