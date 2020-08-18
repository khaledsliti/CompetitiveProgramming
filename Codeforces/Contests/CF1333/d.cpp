// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3005;

int n, k;
char s[N];

int main()
{
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int r = 0;
  long long mx = 0;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] == 'L') mx += r;
    else r++;
  }
  if(mx < k) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> pos;
  for(int i = 0 ; i + 1 < n ; i++)
    if(s[i] == 'R' && s[i + 1] == 'L')
      pos.push_back(i);
  vector<vector<int>> sol;
  while(k > 0) {
    int rem = mx - k;
    if(!rem)
      break;
    int taken = 0;
    sol.push_back(vector<int>());
    vector<int> tmp;
    for(int i = 0 ; i < sz(pos) ; i++) {
      if(taken < rem + 1) {
        int idx = pos[i];
        swap(s[idx], s[idx + 1]);
        sol.back().push_back(idx + 1);
        taken++;
        if(idx > 0 && s[idx - 1] == 'R')
          tmp.push_back(idx - 1);
        if(idx + 2 < n && s[idx + 2] == 'L')
          tmp.push_back(idx + 1);
      } else {
        tmp.push_back(pos[i]);
      }
    }
    pos = tmp;
    mx -= taken;
    k--;
  }
  if(mx > k) {
    cout << -1 << endl;
    return 0;
  }
  while(mx > 0) {
    int idx = pos.back();
    pos.pop_back();
    swap(s[idx], s[idx + 1]);
    sol.push_back({idx + 1});
    if(idx > 0 && s[idx - 1] == 'R')
      pos.push_back(idx - 1);
    if(idx + 2 < n && s[idx + 2] == 'L')
      pos.push_back(idx + 1);
    mx--;
  }
  for(int i = 0 ; i < sz(sol) ; i++) {
    printf("%d", sz(sol[i]));
    for(int& x : sol[i])
      printf(" %d", x);
    printf("\n");
  }
  return 0;
}
