#include <bits/stdc++.h>
using namespace std;

int n;
int ans[200006];

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> n;
    int half = n >> 1;
    if(half & 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<int> a, b;
      long long sum = 0;
      for(int i = 2 ; i <= n ; i += 2) {
        a.push_back(i);
        sum += i;
      }
      for(int i = 1 ; i < n - 1 ; i += 2) {
        b.push_back(i);
        sum -= i;
      }
      b.push_back(sum); 
      for(auto x : a) cout << x << " ";
      for(auto x : b) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}