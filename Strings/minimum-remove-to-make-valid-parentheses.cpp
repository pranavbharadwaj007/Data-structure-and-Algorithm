// Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		int cnt = 0;
		string ans = "";
		for (auto x : s) {
			if (x == '(') {
				ans += x;
				cnt++;
			}
			else if (x == ')') {
				if (cnt > 0) {
					ans += x;
					cnt--;
				}

			}
			else {
				ans += x;
			}
		}
		cout << ans << endl;
		cnt = 0;
		string res = "";
		int n = ans.length();
		if (n == 0)return "";
		for (int i = n - 1; i >= 0; i--) {
			if (ans[i] == ')') {
				res += ans[i];
				cnt++;
			} else if (ans[i] == '(') {
				if (cnt > 0) {
					res += ans[i];
					cnt--;
				}
			} else {
				res += ans[i];
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
