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

int main()
{
  int n;
  cin >> n;
  map<int, int> last;
  int left = 0, best = 0;
  for(int i = 0; i < n; i++) {
    int a; 
    cin >> a;
    if(last.count(a)) {
      left = max(left, last[a] + 1);
    }
    best = max(best, i - left + 1);
    last[a] = i;
  }
  cout << best << endl;
  return 0;
}
