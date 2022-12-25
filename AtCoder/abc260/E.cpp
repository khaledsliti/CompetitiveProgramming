// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n, m;
int A[N], B[N];
vector<int> st[N];
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    st[A[i]].push_back(i);
  }

  int cur_end = -1, last_poss_start = 1e9;
  for(int i = 0; i < n; i++) {
    cur_end = max(cur_end, A[i]);
    last_poss_start = min(last_poss_start, B[i]);
  }

  for(int cur_start = 1; cur_start <= last_poss_start; cur_start++) {
    int length = cur_end - cur_start + 1;
    if(length >= 1) {
      ans[length]++;
      ans[m - cur_start + 2]--;
    }
    for(int i = 0; i < sz(st[cur_start]); i++) {
      cur_end = max(cur_end, B[st[cur_start][i]]);
    }
  }

  for(int i = 1; i <= m; i++) {
    ans[i] += ans[i - 1];
    cout << ans[i] << " ";
  }
  cout  << endl;

  return 0;
}
