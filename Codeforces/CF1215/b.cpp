#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, arr[N];

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
    arr[i] = arr[i] < 0;
  }
  int odd = 0, even = 1;
  int sum = 0;
  long long pos = 0, neg = 0;
  for(int i = 0 ; i < n ; i++){
    sum ^= arr[i];
    if(sum){
      neg += even;
      pos += odd;
      odd++;
    }else{
      neg += odd;
      pos += even;
      even++;
    }
  }
  cout << neg << " " << pos << endl;
  return 0;
}
