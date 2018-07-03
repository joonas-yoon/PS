#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

int group[100001];
int gsize[100001];

int _find(int x) {
	if (x == group[x]) return x;
	return (group[x] = _find(group[x]));
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &gsize[i]), group[i] = i;
	while (m--) {
		int o, p, q;
		scanf("%d %d %d", &o, &p, &q);
		p = _find(p - 1);
		q = _find(q - 1);

		if (o == 1) {
			// unificate
			group[p] = q;
			gsize[q] += gsize[p];
		}
		else {
			// war
			int ps = gsize[p], qs = gsize[q];
			if (ps == qs) {
				group[p] = p;
				group[q] = q;
				gsize[p] = gsize[q] = 0;
			}
			else if (ps < qs) {
				group[p] = q;
				gsize[q] -= ps;
			}
			else {
				group[q] = p;
				gsize[p] -= qs;
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (i == _find(i) && gsize[i] > 0) {
			v.push_back(gsize[i]);
		}
	}
	sort(all(v));

	printf("%d\n", v.size());
	for (auto& x : v) printf("%d ", x);
	return 0;
}