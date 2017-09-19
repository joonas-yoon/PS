#include <bits/stdc++.h>
using namespace std;

struct Dir {
	string name;
	map<string, Dir*> has;
	set<pair<string, Dir*>> children;
};

void trace(Dir* root, int dep = 0) {
	if (dep > 0) {
		for (int i = 1; i < dep; ++i) printf("--");
		puts(root->name.c_str());
	}
	for (auto& child : root->children) {
		trace(child.second, dep + 1);
	}
}

int main() {
	int T;
	scanf("%d", &T);

	Dir *root = new Dir();
	root->name = "root";

	while (T--) {
		int n;
		scanf("%d", &n);
		Dir *parent = root;
		for (int i = 1; i <= n; ++i) {
			char room[20];
			scanf("%s ", room);

			Dir *newDir = NULL;
			auto it = parent->has.find(room);
			if (it == parent->has.end()) {
				newDir = new Dir();
				newDir->name = room;
				parent->has[room] = newDir;
			}
			else {
				newDir = it->second;
			}
			parent->children.insert({ room, newDir });
			parent = newDir;
		}
	}

	trace(root);

	return 0;
}