#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int col[N];

int main()
{
  cin >> n;
  int cur = 1;
  for(int i = 2 ; i <= n ; i++){
    if(col[i] == 0){
      for(int j = i ; j <= n ; j += i)
        if(!col[j])
          col[j] = cur;
      cur++;
    }
  }
  for(int i = 2 ; i <= n ; i++)
    cout << col[i] << " ";
  return 0;
}
