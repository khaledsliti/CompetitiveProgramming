#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 50006;

int n, q;
int a[N], nxt[N];

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", a + i);
  stack<pair<int, int>> st;
  st.push({1e9 + 1, n});
  for(int i = n - 1 ; i >= 0 ; i--){
    while(st.top().first <= a[i])
      st.pop();
    nxt[i] = st.top().second;
    st.push({a[i], i});
  }
  int ans = 0;
  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    ans += nxt[--a] >= --b;
  }
  printf("%d\n", ans);
  return 0;
}
