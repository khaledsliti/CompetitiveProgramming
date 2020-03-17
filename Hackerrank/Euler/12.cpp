#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int div_number(int x)
{
  int cnt = 0;
  for(int i = 1 ; i * i <= x ; i++){
    if(x % i == 0){
      cnt++;
      int d = x / i;
      if(d != i)
        cnt++;
    }
  }
  return cnt;
}

int main()
{
  long long n = 10000;
  cout << div_number(n * (n + 1) / 2) << endl;
  return 0;
}
