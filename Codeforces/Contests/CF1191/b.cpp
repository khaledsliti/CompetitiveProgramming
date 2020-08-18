#include <bits/stdc++.h>
using namespace std;
  
int g[3][10];
 
int get(char c)
{
  if(c == 'm') return 0;
  if(c == 'p') return 1;
  return 2;
}
 
void add(string s)
{
  int a = s[0] - '0';
  int c = get(s[1]);
  g[c][a]++;
}
 
int main()
{
  for(int it = 0 ; it < 3 ; it++){
    string a;
    cin >> a;
    add(a);
  }
  int ans = 3;
  for(int i = 0 ; i < 3 ; i++){
    for(int j = 1 ; j < 10 ; j++)
      ans = min(ans, 3 - g[i][j]);
    for(int j = 1 ; j + 2 < 10 ; j++)
      ans = min(ans, 3 - ((g[i][j] > 0) + (g[i][j + 1] > 0) + (g[i][j + 2] > 0)));
  }
  cout << ans << endl;
  return 0;
}
