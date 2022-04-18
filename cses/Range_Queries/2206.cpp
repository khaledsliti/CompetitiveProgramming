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
const int S = 450;

int n, q;
int arr[N];
int bestLeft[N], bestRight[N];

void updateBlock(int st, int en) {
  int so_far = INT_MAX >> 1;
  for(int i = en - 1; i >= st; i--) {
    so_far = min(arr[i], so_far + 1);
  }
  bestLeft[st / S] = so_far;
  so_far = INT_MAX >> 1;
  for(int i = st; i < en; i++) {
    so_far = min(arr[i], so_far + 1);
  }
  bestRight[st / S] = so_far;
}

int get(int k) {
  int ans = INT_MAX >> 1;
  int b = k / S;
  int st = b * S;
  for(int i = st; i < min(n, st + S); i++) {
    ans = min(ans, abs(i - k) + arr[i]);
  }
  for(int i = st - 1, cur_b = b - 1; i >= 0; i -= S, cur_b--) {
    ans = min(ans, bestRight[cur_b] + abs(i - k));
  }
  for(int i = st + S, cur_b = b + 1; i < n; i += S, cur_b++) {
    ans = min(ans, bestLeft[cur_b] + abs(i - k));
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int st = 0; st < n; st += S) {
    int en = min(n, st + S);
    updateBlock(st, en);
  }

  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int k, x; cin >> k >> x;
      k--;
      arr[k] = x;
      int st = k / S * S;
      int en = min(n, st + S);
      updateBlock(st, en);
    } else {
      int k; cin >> k; k--;
      cout << get(k) << endl;
    }
  }
  return 0;
}
