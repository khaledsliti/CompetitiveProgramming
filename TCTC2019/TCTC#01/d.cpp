#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e3 + 4;

int n;
pair<pair<string, string>, int> input[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> input[i].first.first >> input[i].first.second >> input[i].second;
  }
  string cur;
  cin >> cur;
  int sum = 0;
  for(int i = 0 ; i < n ; i++){
    if(input[i].first.second != cur)
      continue;
    if(input[i].first.first == "Deposit")
      sum += input[i].second;
    else if(sum >= input[i].second)
      sum -= input[i].second;
  }
  cout << sum << endl;
  return 0;
}
