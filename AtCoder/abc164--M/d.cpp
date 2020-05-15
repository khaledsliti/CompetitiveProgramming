// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 200001;
const int M = 2019;

string s;
int fr[M];

int main()
{
  ios::sync_with_stdio(false);
  cin >> s;
  long long ans = 0;
  int p = 1;
  int r = 0;
  fr[0]++;
  for(int i = sz(s) - 1; i >=0 ; i--) {
    int cur = s[i] - '0';
    r = (r + cur * p) % M;
    ans += fr[r];
    fr[r]++;
    p = (p * 10) % M;
  }
  cout << ans << endl;
  return 0;
}
