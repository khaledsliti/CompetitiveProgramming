// Guess Who's Back
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
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    int a = n / 3;
    if(n % 3 == 1) a++;
    cout << a << " " << (n - a) / 2 << endl;
  }
  return 0;
}
