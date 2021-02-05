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

const int N = 200;

int n;
int arr[N][N];
int isp[N];

void solve() {
  cin >> n;
  int p = n - 1;
  while(!isp[p] || isp[p - n + 1]) {
    p++;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        cout << p - n + 1 << " ";
      } else {
        cout << 1 << " ";
      }
    }
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 2; i < N; i++) {
    isp[i] = 1;
  }

  for(int i = 2; i < N; i++) {
    if(isp[i]) {
      for(int j = i * 2; j < N; j += i) {
        isp[j] = 0;
      }
    }
  }
  
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
