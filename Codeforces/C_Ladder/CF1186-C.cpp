// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1000003;

int n, m;
char A[N], B[N];

int main()
{
  scanf("%s", A);
  scanf("%s", B);
  n = strlen(A);
  m = strlen(B);
  int cntb = 0;
  for(int i = 0 ; B[i] ; i++)
    cntb ^= B[i] == '1';
  int cnta = 0;
  for(int i = 0 ; i < m ; i++)
    cnta ^= A[i] == '1';
  int ans = cnta == cntb;
  for(int i = m ; i < n ; i++) {
    cnta ^= A[i] == '1';
    cnta ^= A[i - m] == '1';
    ans += cnta == cntb;
  }
  cout << ans << endl;
  return 0;
}
