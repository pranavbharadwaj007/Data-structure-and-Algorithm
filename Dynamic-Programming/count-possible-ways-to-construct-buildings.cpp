
// Link : https://practice.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1#

int TotalWays(int n)
	{
	    int mod=1000000007;
	    int os=1;
	    int ob=1;
	    for(int i=2;i<=n;i++){
	        int nb=os;
	        int ns=(ob+os)%mod;
	        os=ns;
	        ob=nb;
	    }
	    long long total=(os+ob)%mod;
	    total=((total%mod)*(total%mod)%mod);
	    return total;
	}
