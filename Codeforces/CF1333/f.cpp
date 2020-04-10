// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5e5 + 5;

int n;
int arr[N];
int isp[N], d[N];

int main()
{
  for(int i = 1 ; i < N ;  i++)
    isp[i] = 1;
  for(int i = 2 ; i < N ; i++) {
    if(isp[i]) {
      for(int j = 2 * i ; j < N ; j += i)
        isp[j] = 0;
    }
  }
  for(int i = 2 ; i < N ; i++) {
    if(d[i] == 0)
      d[i] = 1;
    for(int j = 2 * i ; j < N ; j += i)
      d[j] = i;
  }
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    arr[i] = i + 1;
  sort(arr, arr + n, [&](int a, int b) {
    if(isp[a] && isp[b])
      return a < b;
    if(isp[a]) return true;
    if(isp[b]) return false;
    return d[a] < d[b];
  });
  for(int i = 1 ; i < n ; i++)
    cout << d[arr[i]] << " ";
  return 0;
}
