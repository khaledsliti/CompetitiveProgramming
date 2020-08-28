#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
int f[3][3];

bool check(int* per)
{
  int a = per[0];
  int b = per[1];
  int c = per[2];
  if(!f[a][b] && !f[b][c] && (n == 1 || !f[c][a])){
    printf("YES\n");
    for(int i = 0 ; i < n ; i++)
      printf("%c%c%c", a + 'a', b + 'a', c + 'a');
    printf("\n");
    return true;
  }
  if(!f[a][a] && !f[a][b] && !f[b][b] && !f[b][c] && !f[c][c]){
    printf("YES\n");
    for(auto x : {a, b, c})
      for(int i = 0 ; i < n ; i++)
        printf("%c", x + 'a');
    printf("\n");
    return true;
  }
  return false;
}

int main()
{
  cin >> n;
  for(int it = 0 ; it < 2 ; it++){
    char a, b;
    cin >> a >> b;
    a -= 'a';
    b -= 'a';
    f[a][b] = 1;
  }
  int p[3] = {0, 1, 2};
  do{
    if(check(p))
      return 0;
  }while(next_permutation(p, p + 3));
  assert(false);
  return 0;
}
