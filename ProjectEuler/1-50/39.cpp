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

const int N = 1001;

int fr[N];

int main()
{
  for(int a = 1; a < 1000; a++) {
    for(int b = a; a + b < 1000; b++) {
      int c2 = a * a + b * b;
      int c = sqrt(c2);
      if(c * c == c2 && a + b + c <= 1000) {
        fr[a + b + c]++;
      }
    }
  }
  int best = 0;
  for(int i = 1; i <= 1000; i++)
    if(fr[best] < fr[i])
      best = i;
  cout << best << endl;
  return 0;
}
