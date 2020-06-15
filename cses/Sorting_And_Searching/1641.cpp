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

const int N = 5003;

int n, x;
pair<int, int> a[N];

int main()
{
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for(int i = 0; i + 2 < n; i++) {
    int need = x - a[i].first;
    int j = i + 1, k = n - 1;
    while(j < k) {
      int cur = a[j].first + a[k].first;
      if(cur == need) {
        cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1 << endl;
        return 0;
      } else if(cur > need) {
        k--;
      } else {
        j++;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
