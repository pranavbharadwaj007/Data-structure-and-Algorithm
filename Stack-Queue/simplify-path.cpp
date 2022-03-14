// Link : https://leetcode.com/problems/simplify-path/

class Solution {
public:
	string simplifyPath(string path) {
		path += '/';
		string str = "";
		vector<string>st;
		for (auto x : path) {
			if (x == '/') {
				if (str == ".." ) {
					if (st.size() > 0) {
						st.pop_back();
					}
				} else if (str != "." && str != "")
					st.push_back(str);
				str = "";
			} else {
				str += x;
			}
		}
		str = "/";
		for (int i = 0; i < st.size(); i++) {
			str += st[i];
			if (i != st.size() - 1) {
				str += '/';
			}
		}
		return str;
	}
};
