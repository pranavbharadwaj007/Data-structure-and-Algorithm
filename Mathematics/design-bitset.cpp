class Bitset {
    private:
    vector<int>bits;
    int cnt=0;
    bool flipi=false;
public:
    Bitset(int size) {
        bits.resize(size);
    }
    
    void fix(int idx) {
        if(!flipi){
            if(bits[idx]==0){
                bits[idx]=1;
                cnt++;
            }
        }else{
            if(bits[idx]==1){
                bits[idx]=0;
                cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if(!flipi){
            if(bits[idx]==1){
                bits[idx]=0;
                cnt--;
            }
        }else{
            if(bits[idx]==0){
                bits[idx]=1;
                cnt--;
            }
        }
    }
    
    void flip() {
        flipi=!flipi;
        cnt=bits.size()-cnt;
    }
    
    bool all() {
        return cnt==bits.size();
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string str="";
        if(!flipi){
            for(auto it:bits){
                if(it==0){
                    str+="0";
                }else{
                    str+="1";
                }
            }
        }else{
            for(auto it:bits){
                if(it==1){
                    str+="0";
                }else{
                    str+="1";
                }
            }
        }
        return str;
    }
};
