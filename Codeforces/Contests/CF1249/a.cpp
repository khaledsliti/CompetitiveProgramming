#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int q;
  cin >> q;
  while(q--){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
      cin >> v[i];
    sort(all(v));
    bool two = false;
    for(int i = 0 ; i < sz(v) - 1 && !two ; i++)
      if(v[i] + 1 == v[i + 1])
        two = true;
    cout << (1 + two) << endl;
  }
  return 0;
}
