#include<bits/stdc++.h>
using namespace std;

#define MAX 50
#define true 1
#define false 0

int CBT[MAX][MAX], n, A[MAX][MAX], chuaxet[MAX], sc=0;

void Init(){
	ifstream fpi("maxtrix5-2.txt");
	fpi>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) fpi>>A[i][j];
	}
	for(int i=1;i<=n;i++) chuaxet[i]=true;
}

void TREE_DFS(int i){
	int j;
	chuaxet[i]=false;
	if(sc==n-1) return;
	for(j=1;j<=n;j++){
		if(chuaxet[j] && A[i][j]){
			sc++;
			chuaxet[j]=false;
			CBT[sc][1]=i;
			CBT[sc][2]=j;
			if(sc==n-1) return;
			TREE_DFS(j);
		}
	}
}

void result(){
	int i,j;
	for(int i=1;i<=sc;i++){
		printf("\n Canh %d: ", i);
		for(int j=1;j<=2;j++) printf("%3d", CBT[i][j]);
	}
}


int main(){
	int i;
	cin>>i;
	Init();
	TREE_DFS(i);
	if(sc<n-1) printf("Do thi khong lien thong!");
	else result();
}






