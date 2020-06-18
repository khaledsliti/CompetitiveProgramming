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

const int N = 2e5 + 5;

int n;
int arr[N];
int tmp[N], len = 0;

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  int best = 0;
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(tmp, tmp + len, arr[i]) - tmp;
    if(idx >= len) best = ++len;
    tmp[idx] = arr[i];
  }
  cout << best << endl;
  return 0;
}
