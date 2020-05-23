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

const int N = 1e7;

int isp[N];
vector<int> pr;
vector<ll> prf;

int main()
{
  for(int i = 2; i < N ; i++)
    isp[i] = 1;
  for(int i = 2; i * i < N ; i++)
    if(isp[i])
      for(int j = i * i; j < N ; j += i)
        isp[j] = 0;
  for(int i = 2; i < N; i++) {
    if(isp[i]) {
      pr.push_back(i);
      if(i > 2) prf.push_back(i + prf.back());
      else prf.push_back(2);
    }
  }
  // cout << prf.back() << endl;
  // return 0;
  ll n;
  cin >> n;
  int len = 0; ll best = -1;
  for(int i = 1; i <= 100000; i++) {
    ll sum = pr[i];
    for(int j = i - 1; j >= 0; j--) {
      sum += pr[j];
      if(sum < N && isp[sum]) {
        if(len < i - j + 1) {
          len = i - j + 1;
          best = sum;
        }
      }
    }
  }
  cout << best << " " << len << endl;;
  return 0;
}
