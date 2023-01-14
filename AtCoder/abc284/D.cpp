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

const int N = 3e6 + 4;

int isp[N];
vector<long long> pr;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 2; i < N; i++) {
    isp[i] = 1;
  }
  for(int i = 2; i < N; i++) {
    if(!isp[i]) {
      continue;
    }
    for(int j = i + i; j < N; j += i) {
      isp[j] = 0;
    }
  }
  for(int i = 2; i < N; i++) {
    if(isp[i]) {
      pr.push_back(i);
    }
  }

  int T;
  cin >> T;
  while(T--) {
    long long n;
    cin >> n;
    for(auto x : pr) {
      if (n % x != 0) {
        continue;
      }
      if (n % (x * x) == 0) {
        cout << x << " " << n / x / x << endl;
        break;
      }
      cout << (long long)sqrt(n / x) << " " << x << endl;
      break;
    }
  }
  return 0;
}
