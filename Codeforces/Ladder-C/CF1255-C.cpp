// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int arr[N][3];
vector<int> rows[N];
vector<int> cnt, ans;

void add(int val, int& flag, int& l, int& r) {
  if(!flag) ans[l++] = val;
  else ans[r--] = val;
  flag ^= 1;
}

int main()
{
  cin >> n;
  cnt.resize(n); ans.resize(n);
  for(int i = 0 ; i < n - 2 ; i ++) {
    for(int j = 0 ; j < 3 ; j++) {
      cin >> arr[i][j]; --arr[i][j];
      cnt[arr[i][j]]++;
      rows[arr[i][j]].push_back(i);
    }
  }
  for(int i = 0 ; i < n ; i++)
    if(cnt[i] == 1) {
      for(int j = 0 ; j < 3 ; j++) {
        int cur = arr[rows[i][0]][j];
        if(cnt[cur] == 1)
          ans[n - 1] = cur, cnt[cur] = 0;
        else if(cnt[cur] == 2)
          ans[n - 2] = cur, cnt[cur] = 0;
      }
      break;
    }
  queue<int> q;
  for(int i = 0 ; i < n ; i++)
    if(cnt[i] == 1)
      q.push(i);
  int idx = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    ans[idx++] = cur;
    for(int r : rows[cur])
      for(int j = 0 ; j < 3 ; j++) {
        int nxt = arr[r][j];
        if(cnt[nxt] > 0 && --cnt[nxt] == 1)
          q.push(nxt);
      }
  }
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] + 1 << " ";
  cout << endl;

  return 0;
}
