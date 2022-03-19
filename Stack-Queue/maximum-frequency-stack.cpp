// Link : https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>m;
    int maxfreq=0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        m[freq[x]].push(x);
    }

    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        if (!m[freq[x]--].size()) maxfreq--;
        return x;
    }
};
