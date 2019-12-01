#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;
vector<int> val[N];

void output(int x, int y)
{
  cout << x << " " << y << endl;
  cout.flush();
}

void output(int x)
{
  cout << x << endl;
  cout.flush();
}

int main() {
  string line;
  cin >> n;
  getline(cin, line);
  for(int i = 1 ; i <= n ; i++){
    output(2 * i - 1, 2 * i);
    getline(cin, line);
    if(line == "MATCH")
      continue;
    if(line == "-1")
      exit(-1);
    stringstream ss(line);
    int a, b;
    ss >> a >> b;
    val[a].push_back(2 * i - 1);
    val[b].push_back(2 * i);
  }
  for(int i = 1 ; i <= n ; i++){
    if(val[i].size() > 0){
      output(val[i][0], val[i][1]);
      getline(cin, line);
      if(line != "MATCH")
        exit(-1);
    }
  }
  output(-1);
}