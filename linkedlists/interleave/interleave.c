//interleaving of two strings
//#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//using namespace std;

void interleave(char* s,char* w,int len,char* s1)
{
	if(s[0]=='\0' && w[0]=='\0')
	{
		printf("%d  %s\n", strlen(s1-len), s1-len);
	}
	if(s[0]!='\0'){
		s1[0]=s[0];
		interleave(s+1,w,len,s1+1);
	}
	if(w[0]!='\0'){
	 s1[0]=w[0];
	 interleave(s,w+1,len,s1+1);
	}
}

int main(){
char *s="ab";
char *w="cd";
int m=strlen(s);
int n=strlen(w);
int len=m+n;
char *s1=(char*)malloc(len+1);
//s1[len]='\0';//bug
interleave(s,w,len,s1);
return 0;
}
