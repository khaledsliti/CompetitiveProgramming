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

const int N = 51;

int n;
int s[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> s[i];
    sort(s, s + n);
    int x = 100000;
    for(int i = 1; i < n; i++)
      x = min(x, s[i] - s[i - 1]);
    cout << x << endl;
  }
  return 0;
}
