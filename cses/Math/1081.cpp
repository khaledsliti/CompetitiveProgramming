// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e6 + 1;

int a[N];

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n;i ++) {
    int x; cin >> x;
    a[x]++;
  }
  int best = 1;
  for(int i = N - 1; i > 1; i--) {
    int cnt = 0;
    for(int j = i; j < N; j += i)
      cnt += a[j];
    if(cnt > 1) {
      best = i;
      break;
    }
  }
  cout << best << endl;
  return 0;
}
