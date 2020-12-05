#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<map>

using namespace std;

typedef pair<int, string> PIS;
string start, s, c;
char p[4] = {'l', 'r', 'u', 'd'};
int dx[4] = {0, 0, -1, 1}; // 对应上下左右移动
int dy[4] = {-1, 1, 0, 0};

int f(string s) {
	int ans = 0;
	for(int i = 0; i < 9; i++){
		if(s[i] != 'x'){
			int t = s[i] - '1';
			ans += abs(i /3 - t / 3) + abs(i % 3 - t % 3);
		}
	}
	return ans;
}

string bfs() {
	priority_queue<PIS, vector<PIS>, greater<PIS> > q;
	map<string, int> dis;   // 考察点的深度.
	map<string, bool> vis;	// 标记已经考察过的点

	map<string, pair<string, char> > pre; // 前向节点, 保存答案.

	q.push({f(start), start});

	dis[start] = 0;
	while(q.size()){
		PIS t = q.top();
		q.pop();
		string stare = t.second;
		if(stare == "12345678x") break;
		if(vis[stare]) continue;
		vis[stare] = true;
		int x, y;
		for(int i = 0; i < 9; i++){
			if(stare[i] == 'x'){
				x = i / 3;
				y = i % 3;
				break;
			}
		}
		int step = dis[stare];
		string raw = stare;
		for(int i = 0; i < 4; i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3){
				stare = raw;
				swap(stare[x * 3 + y], stare[a * 3 + b]);
				if(!dis.count(stare) || dis[stare] > step + 1){
					dis[stare] = step + 1;
					pre[stare] = {raw, p[i]};
					q.push({f(stare) + dis[stare], stare});
				}
			} 
		}	
	}
	string ans, end = "12345678x";
	while(end != start){
		ans += pre[end].second;
		end = pre[end].first;
	}	
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	for(int i = 0; i < 9; i++){
		cin >> c;
		start += c;
		if(c != "x") s += c;
	}
	int sum = 0;
	for(int i = 0; i < 8; i++)
		for(int j = i + 1; j < 8; j++)
			if(s[i] > s[j]) sum++;
	if(sum & 1) cout << "unsolvable" << endl;
	else cout << bfs() << endl;		

	return 0;
}