// We only fail when we stop trying
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
  long long p = 1;
  for(int i = 0 ; i < 30 ; i++)
    p *= 3;
  cout << p << endl;
  return 0;
}
