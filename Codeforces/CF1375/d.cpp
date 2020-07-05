// We only fail when we stop trying
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

const int N = 1001;

int n;
int arr[N];

int getMex() {
  vector<int> cnt(n + 1, 0);
  for(int i = 0; i < n; i++) {
    cnt[arr[i]] = 1;
  }
  for(int i = 0; i <= n; i++)
    if(!cnt[i])
      return i;
  return -1;
}

void print() {
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> sol;
  while(true) {
    int idx = -1;
    set<int> ex;
    for(int i = 0; i < n; i++) {
      if(ex.find(arr[i]) != ex.end()) {
        idx = i;
        break;
      }
      ex.insert(arr[i]);
    }
    if(idx == -1) break;
    int v = getMex();
    sol.push_back(idx + 1);
    arr[idx] = v;
  }
  
  while(true) {
    int m = getMex();
    if(m == n) {
      int idx = -1;
      for(int i = 0; i < n && idx == -1; i++)
        if(arr[i] != i)
          idx = i;
      if(idx == -1)
        break;
      sol.push_back(idx + 1);
      arr[idx] = m;
    } else {
      sol.push_back(m + 1);
      arr[m] = m;
    }
  }

  cout << sz(sol) << endl;
  for(int i: sol)
    cout << i << " ";
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
