#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int arr[11];

int main()
{
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0 ; i < n ; i++){
    int c = s[i];
    if(c == 'L'){
      for(int i = 0 ; i < 10; i++)
        if(!arr[i]){
          arr[i] = 1;
          break;
        }
    }else if(c == 'R'){
      for(int i = 9 ; i >= 0 ; i--)
        if(!arr[i]){
          arr[i] = 1;
          break;
        }
    }else{
      int x = c - '0';
      arr[x] = 0;
    }
  }
  for(int i = 0 ; i < 10 ; i++)
    cout << arr[i];
  cout << endl;
  return 0;
}
