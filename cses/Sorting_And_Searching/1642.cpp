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

const int N = 1e6 + 5;

struct p {
  int value;
  int i, j;
  bool operator<(const p& other) const {
    if(value != other.value) return value < other.value;
    return i > other.i;
  }
};

int n, x;
int arr[N];
vector<p> pairs;

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++)
      pairs.push_back({arr[i] + arr[j], i, j});
  }
  sort(all(pairs));
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int need = x - arr[i] - arr[j];
      if(need > 0) {
        int idx = lower_bound(all(pairs), (p){need, n, n}) - begin(pairs);
        if(idx < sz(pairs) && pairs[idx].value == need && pairs[idx].i > j) {
          cout << i + 1 << " " << j + 1 << " " << pairs[idx].i + 1 << " " << pairs[idx].j + 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
