#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

const int N = 2e5 + 5;

int n, k;

int main()
{
  while(cin >> n >> k){
    if(n == 1 && k == 1){
      puts("-1");
    }else if(k == 0){
      for(int i = 0 ; i < (1 << n) ; i++){
        if(i) cout << " ";
        cout << i << " " << i;
      }
      cout << endl;
    }else if(k < (1 << n)){
      vector<int> v;
      v.push_back(k);
      for(int i = 0 ; i < (1 << n) ; i++)
        if(i != k)
          v.push_back(i);
      v.push_back(k);
      for(int i = (1 << n) - 1 ; i >= 0 ; i--)
        if(i != k)
          v.push_back(i);
      for(auto& x : v)
        cout << x << " ";
      cout << endl;
    }else{
      puts("-1");
    }
  } 
  return 0;
}