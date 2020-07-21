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

const int N = 1e4 + 5;

int fr[N];

int main()
{
  for(int x = 1; x * x <= N; x++) {
    for(int y = 1; y * y <= N; y++) {
      for(int z = 1; z * z <= N; z++) {
        int ans = x * x + y * y + z * z + x * y + x * z + y * z;
        if(ans < N)
          fr[ans]++;
      }
    }
  }
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cout << fr[i] << endl;
  }
  return 0;
}
