#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, k;


int main()
{
  scanf("%d%d", &n, &k);
  int a = 0;
  for(int i = 1 ; i < n ; i++){
    vector<int> v;
    for(int j = i ; j < n ; j += i)
      ++a;
  }
  cout << a << endl;
  // for(int i = 0 ; i < n ; i++){
  //   int a; scanf("%d", &a);
  // }
  return 0;
}
