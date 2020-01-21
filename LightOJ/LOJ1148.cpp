#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    unordered_map<int, int> cnt;
    for(int i = 0 ; i < n ; i++){
      int a; scanf("%d", &a);
      cnt[++a]++;
    }
    int ans = 0;
    for(auto v : cnt){
      int s = v.first;
      int c = v.second;
      ans += (c + s - 1) / s * s;
    }
    printf("Case %d: %d\n", tc++, ans);
  }
  return 0;
}
