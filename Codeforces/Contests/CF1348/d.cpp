#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sol;

bool check(long long have, int day) {
  long long sum = 0;
  for(int i = day ; i > 0 ; i--) {
    sum += have * i;
    have <<= 1;
  }

  return false;
}

int main()
{
  int T = 50;
  cin >> T;
  while(T--) {
    cin >> n;
    int d = 0, act = n - 1;
    int p = 2;
    while(act > 0) {
      d++;
      act -= p;
      p <<= 1;
    }
    cout << d << endl;
    
  }
  return 0;
}
