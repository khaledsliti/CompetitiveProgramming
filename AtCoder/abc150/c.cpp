#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

//Constants
const int N = 9;

//Data
int n;
int p[N], q[N];
vector<vector<int>> per;

//Methods
void pre()
{
  vector<int> v(n);
  for(int i = 0 ; i < n;  i++)
    v[i] = i + 1;
  do{
    per.push_back(v);
  }while(next_permutation(all(v)));
}

int get(int* arr)
{
  for(int i = 0 ; i < sz(per) ; i++){
    bool eq = true;
    for(int j = 0 ; j < n && eq ; j++)
      if(per[i][j] != arr[j])
        eq = false;
    if(eq)
      return i;
  }
  assert(false);
  return -1;
}

int main()
{
  cin >> n;
  pre();
  for(int i = 0 ; i < n ;i++)
    cin >> p[i];
  for(int i = 0 ; i < n ; i++)
    cin >> q[i];
  cout << abs(get(p) - get(q)) << endl;
  return 0;
}
