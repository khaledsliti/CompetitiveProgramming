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

const int N = 1e5 + 5;

int n, m;
int arr[N];
int d[N];

int g() {
  int r = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int last = -1;
      int cur = 0;
      for(int k = i; k <= j; k++) {
        if(last != arr[k]) {
          cur++;
        }
        last = arr[k];
      }
      r += cur;
    }
  }
  return r;
}

ll cost(int i) {
  if(!d[i]) {
    return 0;
  }
  return 1LL * (i + 1) * (n - i - 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < n - 1; i ++) {
    d[i] = arr[i] != arr[i + 1];
  }

  ll cur = 1LL * n * (n + 1) / 2;
  for(int i = 0; i + 1 < n; i++) {
    cur += cost(i);
  }

  while(m--) {
    int i, x;
    cin >> i >> x;
    --i;
    if (i > 0) {
      cur -= cost(i - 1);
    }
    if (i + 1 < n) {
      cur -= cost(i);
    }
    arr[i] = x;
    if(i > 0) {
      d[i - 1] = arr[i - 1] != arr[i];
      cur += cost(i - 1);
    }
    if(i + 1 < n) {
      d[i] = arr[i] != arr[i + 1];
      cur += cost(i);
    }
    cout << cur << endl;
  }
  return 0;
}
