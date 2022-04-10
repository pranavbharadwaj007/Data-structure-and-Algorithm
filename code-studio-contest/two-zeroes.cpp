
// Link : codingninjas.com/codestudio/contests/codestudio-weekend-contest-16/problems/19066

int countInteresting(int l, int r) {
        int ans=0;
	for(int i=0;i<31;i++){
		for(int j=0;j<i-1;j++){
			for(int k=j+1;k<i-1;k++){
				int num=((1<<(i))-1)^(1<<j)^(1<<k);
				if(num>=l && num<=r){
					ans++;
				}
			}
		}
	}
	return ans;
}
