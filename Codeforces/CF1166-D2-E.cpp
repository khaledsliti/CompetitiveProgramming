#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;

int n, m;
vector<int> s[N];

int main()
{
  scanf("%d%d", &m, &n);
  for(int i = 0 ; i < m ; i++){
    int k; scanf("%d", &k);
    while(k--){
      int a;
      scanf("%d", &a);
      s[i].push_back(a);
    }
  }
  for(int i = 0 ; i < m ; i++){
    for(int j = i + 1 ; j < m ; j++){
      unordered_set<int> ex;
      for(auto& x : s[i])
        ex.insert(x);
      bool intersection = false;
      for(auto& x : s[j]){
        if(ex.find(x) != ex.end()){
          intersection = true;
          break;
        }
      }
      if(!intersection){
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;
  return 0;
}
