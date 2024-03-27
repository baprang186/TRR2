#include<bits/stdc++.h>
using namespace std;

#define MAX 50
#define true 1
#define false 0

int CBT[MAX][MAX], n, A[MAX][MAX], chuaxet[MAX], sc=0, QUEUE[MAX];

void Init(){
	ifstream fpi("maxtrix5-2.txt");
	fpi>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) fpi>>A[i][j];
	}
	for(int i=1;i<=n;i++) chuaxet[i]=true;
}

void TREE_BFS(int u){
	int dauQ=1, cuoiQ=1, v, p;
	QUEUE[dauQ]=u;
	chuaxet[u]=false;
	while(dauQ<=cuoiQ){
		v=QUEUE[dauQ];
		dauQ+=1;
		for(int p=1;p<=n;p++){
			if(chuaxet[p] &&  A[v][p] ){
				chuaxet[p]=false;
				sc++;
				CBT[sc][1]=v;
				CBT[sc][2]=p;
				cuoiQ++;
				QUEUE[cuoiQ]=p;
				if(sc==n-1) return;
			}
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
	TREE_BFS(i);
	if(sc<n-1) printf("Do thi khong lien thong!");
	else result();
}

