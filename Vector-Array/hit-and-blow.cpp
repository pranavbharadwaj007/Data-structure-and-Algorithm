#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e7 + 7;
 
	int n;
	cin >> n;
	vector<int>vec1, vec2;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		vec1.push_back(p);
 
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		vec2.push_back(p);
 
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int pp = vec1[i];
		for (int j = 0; j < n; j++) {
			if (pp == vec2[j] && i == j) {
				cnt1++;
			} else if (pp == vec2[j] && i != j) {
				cnt2++;
			}
		}
	}
	cout << cnt1 << endl;
	cout << cnt2 << endl;
 
	return 0;
}
