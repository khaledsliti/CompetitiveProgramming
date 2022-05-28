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

int n, k;
string s;
int ans[N];

void solve() {
  cin >> n >> k >> s;
  for(int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  if(k & 1) {
    bool ok = false;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1') {
        ok = true;
        ans[i]++;
        for(int j = 0; j < n; j++) {
          if(j != i) {
            s[j] ^= 1;
          }
        }
        break;
      }
    }
    if(!ok) {
      ans[n - 1]++;
      for(int i = 0; i < n - 1; i++) {
        s[i] = '1';
      }
    }
    k--;
  }
  queue<int> q;
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
      q.push(i);
    }
  }
  while(q.size() >= 2 && k >= 2) {
    int a = q.front(); q.pop();
    int b = q.front(); q.pop();
    s[a] = s[b] = '1';
    ans[a]++, ans[b]++;
    k -= 2;
  }
  while(q.size()) q.pop();
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '1') {
      q.push(i);
    }
  }
  for(int i = 0; i < n; i++) {
    if(k >= 2 && q.size() > 0 && s[i] == '0' && q.front() > i) {
      k -= 2;
      int j = q.front(); q.pop();
      swap(s[i], s[j]);
      ans[i]++, ans[j]++;
    }
  }

  if(k > 0) {
    ans[0] += k;
  }
  
  cout << s << endl;
  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
