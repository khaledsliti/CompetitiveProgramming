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

int n;
int a[N];

int get_parity(int n, int k) {
  return (n | k) == n;
}

int main()
{
  cin >> n;
  int one = false;
  for(int i = 0 ; i < n ; i++) {
    char c; cin >> c;
    a[i] = c - '1';
    one |= a[i] == 1;
  }
  if(!one)
    for(int i = 0 ; i < n ; i++)
      a[i] >>= 1;
  int p = 0;
  for(int i = 0 ; i < n ; i++) {
    int cur = get_parity(n - 1, i);
    if(cur && a[i] == 1)
      p ^= 1;
  }
  if(p == 1) {
    if(one) cout << 1 << endl;
    else cout << 2 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
