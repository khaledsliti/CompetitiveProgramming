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

const int N = 3e5 + 5;
const int Inf = 1e9 + 7;

int n;
int a[N];
int g[N], l[N];
int dp[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  stack<int> st;
  st.push(n - 1);
  g[n - 1] = n;
  for(int i = n - 2; i >= 0; i--) {
    while(st.empty() == false && a[st.top()] <= a[i])
      st.pop();
    if(st.empty()) g[i] = n;
    else g[i] = st.top();
    st.push(i);
  }

  while(st.empty() == false) st.pop();

  st.push(n - 1);
  l[n - 1] = n;
  for(int i = n - 2; i >= 0; i--) {
    while(st.empty() == false && a[st.top()] >= a[i])
      st.pop();
    if(st.empty()) l[i] = n;
    else l[i] = st.top();
    st.push(i);
  }

  dp[n] = n + 1;
  dp[n - 1] = 0;
  for(int i = n - 2; i >= 0; i--) {
    dp[i] = n + 1;
    if(a[i] == a[i + 1]) {
      dp[i] = 1 + dp[i + 1];
    } else if(a[i] < a[i + 1]) {
      int cur = i + 1, last = -1;
      while(cur < n && (cur == i + 1 || a[last] > a[i])) {
        dp[i] = min(dp[i], 1 + dp[cur]);
        last = cur;
        cur = l[cur];
      }
    } else {
      int cur = i + 1, last = -1;
      while(cur < n && (cur == i + 1 || a[last] < a[i])) {
        dp[i] = min(dp[i], 1 + dp[cur]);
        last = cur;
        cur = g[cur];
      }
    }
  }
  
  printf("%d\n", dp[0]);
  return 0;
}
