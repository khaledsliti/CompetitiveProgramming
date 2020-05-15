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

const int N = 2e6;

int np[N];

int main()
{
  long long sum = 0;
  for(int i = 2; i < N; i++) {
    if(!np[i]) {
      sum += i;
      for(int j = i * 2; j < N; j += i)
        np[j] = 1;
    }
  }
  cout << sum << endl;
  return 0;
}
