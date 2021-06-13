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



int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int a = min_element(all(arr)) - begin(arr);
    int b = max_element(all(arr)) - begin(arr);
    if(a > b) swap(a, b);
    cout << min(min(a + 1 + n - b, b + 1), n - a) << endl;
  }
  return 0;
}
