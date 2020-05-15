#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    set<int> s;
    for(int i = 0 ; i < n ; i++) {
      cin >> arr[i];
      s.insert(arr[i]);
    }
    vector<int> v;
    for(auto x : s)
      v.push_back(x);
    if((int)v.size() > k) {
      cout << -1 << endl;
      continue;
    }
    cout << n * k << endl;
    for(int i = 0 ; i < n ; i++) {
      for(int j = 0 ; j < k ; j++)
        cout << v[j % (int)v.size()] << " ";
    }
    cout << endl;
  }
  return 0;
}
