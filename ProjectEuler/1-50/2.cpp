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
  int a = 0, b = 1;
  int sum = 0;
  while(b + a <= 4e6) {
    int c = b + a;
    if(c % 2 == 0) sum += c;
    a = b, b = c;
  }
  cout << sum << endl;
  return 0;
}
