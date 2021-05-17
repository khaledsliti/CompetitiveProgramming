#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int A = 26;

int n;
char s[N];
vector<int> pos[N];
int ex[A][N];
vector<char> chars;

void init() {
	for(int i = 0; i < A; i++)
		pos[i].clear();
	for(int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}
	for(int i = 0; i < A; i++) {
		ex[i][n] = 0;
		for(int j = n - 1; j >= 0; j--) {
			ex[i][j] = ex[i][j + 1];
			if(s[j] - 'a' == i) ex[i][j] = 1;
		}
	}
}

bool can(char candidate, int& start_pos) {
	vector<int>& positions = pos[candidate - 'a'];
	int idx = lower_bound(positions.begin(), positions.end(), start_pos) - positions.begin();
	if(idx < positions.size()) idx = positions[idx];
	else return false;
	bool ok = true;
	for(char c: chars) {
		if(c == candidate) continue;
		ok = ok && ex[c - 'a'][idx + 1];
	}
	if(ok) start_pos = idx + 1;
	return ok;
}

vector<char> delete_char(vector<char> cur, char c) {
	vector<char> rem;
	for(char a: cur)
		if(a != c)
			rem.push_back(a);
	return rem;
}

string build_solution() {
	string sol;
	int iterations = chars.size();
	int start_pos = 0;
	for(int it = 0; it < iterations; it++) {
		for(char candidate: chars) {
			if(can(candidate, start_pos)) {
				chars = delete_char(chars, candidate);
				sol += candidate;
				break;
			}
		}
	}
	return sol;
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	init();
	chars.clear();
	for(int i = 0; i < n; i++) {
		chars.push_back(s[i]);
	}
	sort(chars.begin(), chars.end());
	chars.resize(unique(chars.begin(), chars.end()) - chars.begin());
	reverse(chars.begin(), chars.end());
	string result = build_solution();
	cout << result << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}
