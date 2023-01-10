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

const int N = 3e5 + 6;

int n;
int a[N], b[N];
int arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    --b[i];
  }

  for(int i = 0; i < n; i++) {
    arr[a[i]] = b[i];
  }

  vector<int> tmp;
  for(int i = 0; i < n; i++) {
    int idx = lower_bound(all(tmp), arr[i]) - begin(tmp);
    if(idx >= sz(tmp)) tmp.push_back(arr[i]);
    else tmp[idx] = arr[i];
  }

  cout << n + sz(tmp) << endl;

  return 0;
}
