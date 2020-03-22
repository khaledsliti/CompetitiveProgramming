// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

int n;
int pos[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> pos[i];
  long long ans = 1;
  int cnt = 0;
  for(int i = 0 ; i < n ; i++) {
    ans = (ans * (cnt + 1)) % Mod;
    int last = 2 * cnt - 1;
    if(pos[i] == last + 1) {
      cnt--;
    }
    cnt++;
  }
  cout << ans << endl;
  return 0;
}
