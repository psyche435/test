#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
const int Maxn=10000+10;

int n,m,k,A,B;
int a[Maxn],b[Maxn];

inline int Getint(){
	register int n=0;
	register bool f=0;
	register char ch=getchar();

	while(ch<'0' || ch>'9'){
		f = ch=='-' ? 1 : 0 ;
		ch=getchar();
	}

1	while(ch>='0' && ch<='9'){
		n=n*10+ch-'0';
		ch=getchar();
	}

	return f ? -n : n ;
}

int main(){
	n=Getint();
	m=Getint();
	k=Getint();
	for(int i=1;i<=m;++i)a[i]=Getint();
	for(int i=1;i<=k;++i)b[i]=Getint();
	for(int i=1;i<=n;++i){
		int s,t;
		if(i%m==0)s=a[m];
		else s=a[i%m];
		if(i%k==0)t=b[k];
		else t=b[i%k];
		if(s==t)continue;
		if(s==0){
			if(t==1)B++;
			if(t==2)A++;
			if(t==3)A++;
			if(t==4)B++;
		}
		if(s==1){
			if(t==0)A++;
			if(t==2)B++;
			if(t==3)A++;
			if(t==4)B++;
		}
		if(s==2){
			if(t==0)B++;
			if(t==1)A++;
			if(t==3)B++;
			if(t==4)A++;
		}
		if(s==3){
			if(t==0)B++;
			if(t==1)B++;
			if(t==2)A++;
			if(t==4)A++;
		}
		if(s==4){
			if(t==0)A++;
			if(t==1)A++;
			if(t==2)B++;
			if(t==3)B++;
		}
	}
	printf("%d %d\n",A,B);
	return 0;
}