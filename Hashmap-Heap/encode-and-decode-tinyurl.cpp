
// Link : https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    unordered_map<string,string>mp;
    int n=1;
 
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string res="http://tinyurl.com/"+to_string(n);
        n++;
        mp[res]=longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};
