#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 21;

int n;
struct P{
  int a, b;
} pr[N];

int main()
{
  while(cin >> n){
    for(int i = 0 ; i < n ; i++)
      cin >> pr[i].a;
    for(int i = 0 ; i < n ; i++)
      cin >> pr[i].b;
    sort(pr, pr + n, [](const P& x, const P& y){
      int a1 = x.a, b1 = x.b;
      int a2 = y.a, b2 = y.b;
      int t1 = a1 + max(a2, b1) + b2;
      int t2 = a2 + max(a1, b2) + b1;
      return t1 < t2;
    });
    int t1 = 0, t2 = 0;
    for(int i = 0 ; i < n ; i++){
      int a = pr[i].a;
      int b = pr[i].b;
      t1 += a;
      t2 = max(t1, t2) + b;
    }
    cout << t2 << endl;
  }
  return 0;
}
