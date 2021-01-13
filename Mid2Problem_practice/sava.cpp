#include <bits/stdc++.h>
	using namespace std;

	int main(){
	    char str[15];
	    int i,j;
	    scanf("%s", &str);
	    char temp;
         int len;
        for(len=0; str[len]!=0; len++);
	    for(i=0, j=len-1; i<j; i++, j--){
             temp=str[i];
             str[i]=str[j];
             str[j]=temp;
         }
         printf("%s\n", str);
}

