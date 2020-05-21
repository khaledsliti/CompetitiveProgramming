// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1'050;

int n, k;
int arr[N];
int good[N];
int pro[N], test[N];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  for(int i = 0 ; i < k ; i++)
    pro[i] = -1;
  int index = 0;
  int total = 0;
  for(int i = 0 ; i < k && index < n ; i++) {
    pro[i] = index;
    test[index++] = 1;
  }
  for(int t = 1 ; t < 150'000; t++) {
    int q = round(100.0 * total / n);
    for(int i = 0 ; i < k ; i++) {
      if(~pro[i] && test[pro[i]] == q)
        good[pro[i]] = 1;
    }
    for(int i = 0 ; i < k ; i++) {
      if(~pro[i]) {
        if(test[pro[i]] == arr[pro[i]]) {
          total++;
          pro[i] = -1;
        } else {
          test[pro[i]]++;
        }
      }
      if(pro[i] == -1 && index < n) {
        pro[i] = index;
        test[index] = 1;
        index++;
      }
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    ans += good[i];
  cout << ans << endl;
  return 0;
}
