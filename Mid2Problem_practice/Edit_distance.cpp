cahr s1[];
cahr s2[];
int l1,l2;
int dp[l1][];
f(int p1,int p2){


	if(p1==l1)return (l2-p2);
	if(p2==l2)return (l1-p1);
	if(dp[p1][p2]!=-1)return dp[p1][p2];
	if(s1[p1]==s2[p2]){
	return f(p1+1,p2 + 1);
        }
	int rep = 1 + f(p1+1,p2 + 1);
	int del = 1 + f(p1 + 1, p2);
	int ins = 1 + f(p1 , p2 + 1);

	return dp[p1][p2] = min(min(rep,del),ins);

}
