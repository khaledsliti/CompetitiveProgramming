#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--){
    int n; string p;
    cin >> n >> p;
    int alice = p[0] == 'A';
    bool aliceWin = alice && (n % 3 != 1) || !alice && (n % 3 == 0);
    printf("Case %d: %s\n", tc++, aliceWin ? "Alice" : "Bob");
  }
  return 0;
}
