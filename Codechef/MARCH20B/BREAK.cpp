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

int n;
int a[N], b[N];

int main()
{
  int T, S;
  scanf("%d%d", &T, &S);
  while(T--) {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
      scanf("%d", a + i);
    for(int i = 0 ; i < n ; i++)
      scanf("%d", b + i);
    if(S == 1) {
      sort(a, a + n);
      sort(b, b + n);
      bool ok = true;
      unordered_set<int> pr;
      for(int i = 0 ; i < n ; i++) {
        ok &= a[i] < b[i] && (i == 0 || pr.find(a[i]) != pr.end());
        pr.insert(a[i]);
        pr.insert(b[i]);
      }
      cout << (ok ? "YES" : "NO") << endl;
    } else {

    }
  }
  return 0;
}
