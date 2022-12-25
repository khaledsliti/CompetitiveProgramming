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

const int N = 1e5 + 5;

int n;
int arr[N];
vector<int> pr;
int isp[N];

void pre() {
  for(int i = 2; i < N; i++) {
    isp[i] = 1;
  }
  for(int i = 2; i < N; i++) {
    if(isp[i]) {
      for(int j = i + i; j < N; j += i) {
        isp[j] = 0;
      }
    }
  }
  for(int i = 2; i < 32000; i++) {
    if(isp[i]) {
      pr.push_back(i);
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> cnt(sz(pr), 0);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < sz(pr); j++) {
      if(arr[i] % pr[j] != 0) {
        continue;
      }
      if(cnt[j]) {
        cout << "YES" << endl;
        return;
      }
      while(arr[i] % pr[j] == 0) {
        arr[i] /= pr[j];
      }
      cnt[j] = 1;
    }
  }
  sort(arr, arr + n);
  for(int i = 1; i < n; i++) {
    if (arr[i] > 1 && arr[i] == arr[i - 1]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pre();

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
