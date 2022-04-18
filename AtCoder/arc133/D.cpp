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


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int s = 0;
  for(int i = 1; i <= 20; i++) {
    s ^= i;
    cout << i << "\t" << s << endl;
  }

  long long L, R, V;
  cin >> L >> R >> V;
  return 0;
}
