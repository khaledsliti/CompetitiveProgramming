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

const int N = 2e5 + 5;

int n;
int arr[N];
int p[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    p[i] = arr[i] == i + 1;
  }
  int f = -1, l = -1;
  for(int i = 0; i < n; i++)
    if(!p[i]) {
      if(f == -1) f = i;
      l = i;
    }
  if(f == -1) cout << 0 << endl;
  else {
    int same = 1;
    for(int i = f; i <= l; i++)
      same &= p[i] == 0;
    if(same) cout << 1 << endl;
    else cout << 2 << endl;
  }

}

int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--)
    solve();
  return 0;
}
