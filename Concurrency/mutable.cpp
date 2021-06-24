// RedStone
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

class Test {
public:
  int x;
  mutable int y;
  Test() {
    x = 4;
    y = 10;
  }
};

int main()
{
  const Test t1;
  t1.y = 20;
  cout << t1.y << endl;
  return 0;
}
