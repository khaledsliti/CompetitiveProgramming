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
const int L = 18;

int n, q;
int x[N];
long long pref[N];
int nxt[N][L];
long long cost[N][L];

long long sum(int i, int j) {
  return pref[j] - (i > 0 ? pref[i - 1] : 0);
}

void buildNxt() {
  stack<int> st;
  for(int i = n - 1; i >= 0; i--) {
    while(st.size() && x[i] >= x[st.top()]) {
      st.pop();
    }
    if(st.empty()) {
      nxt[i][0] = n;
    } else {
      nxt[i][0] = st.top();
    }
    cost[i][0] = 1LL * (nxt[i][0] - i) * x[i];
    st.push(i);
  }

  nxt[n][0] = n;
  cost[n][0] = 0;
  for(int j = 1; j < L; j++) {
    for(int i = 0; i <= n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      cost[i][j] = cost[i][j - 1] + cost[nxt[i][j - 1]][j - 1];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for(int i = 0; i < n; i++) {
    pref[i] = x[i];
    if (i > 0) {
      pref[i] += pref[i - 1];
    }
  }

  buildNxt();

  while(q--) {
    int l, r; cin >> l >> r; l--, r--;
    long long ans = -sum(l, r);
    for(int i = L - 1; i >= 0; i--) {
      if(nxt[l][i] <= r) {
        ans += cost[l][i];
        l = nxt[l][i];
      }
    }
    ans += 1LL * x[l] * (r - l + 1);
    cout << ans << endl;
  }

  return 0;
}
