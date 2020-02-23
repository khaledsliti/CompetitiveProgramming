#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

map<string, vector<string>> nums;

int main()
{
  int t;
  cin >> t;
  while(t--){
    string name;
    int k;
    cin >> name >> k;
    while(k--){
      string number;
      cin >> number;
      nums[name].push_back(number);
    }
  }
  cout << sz(nums) << endl;
  for(auto x : nums) {
    cout << x.first << " ";
    vector<string>& s = x.second;
    sort(all(s), [](const string& a, const string& b){
      return a.size() > b.size();
    });
    unordered_set<string> exist;
    vector<string> sol;
    for(int i = 0 ; i < sz(s) ; i++){
      if(exist.find(s[i]) != exist.end())
        continue;
      sol.push_back(s[i]);
      for(int j = 0 ; j < sz(s[i]) ; j++){
        exist.insert(s[i].substr(j, sz(s[i]) - j));
      }
    }
    cout << sz(sol);
    for(int i = 0 ; i < sz(sol) ; i++)
      cout << " " << sol[i];
    cout << endl;
  }
  return 0;
}
