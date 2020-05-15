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

int get(int n) {
  int a = 1;
  int rem[n];
  for(int i = 0; i < n; i++)
    rem[i] = -1;
  for(int i = 1; ; i++) {
    if(rem[a] != -1)
      return i - rem[a];
    rem[a] = i;
    a = a * 10 % n;
  }
  return -1;
}

int main()
{
  int best = 0, At = 0;
  for(int i = 2; i < 1000; i++) {
    int len = get(i);
    if(len > best) {
      best = len;
      At = i;
    }
  }
  cout << best << " " << At << endl;
  return 0;
}
