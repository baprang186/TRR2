#include <iostream>
#include <fstream>
using namespace std;
int n,u,a[100][100],chuaxet[100],x[100];

void in(){
	cout << "Chu Trinh Hamilton tai dinh thu " << u << " la: ";
	for(int i=1;i<=n;i++){
		cout << x[i] << " ";
	}
	cout << x[1] << endl;
}

void Hamilton(int k){
	for(int i=1;i<=n;i++){
		if(a[x[k-1]][i]==1){
			if(k==n+1 && i==u){
				in();
			}else if(!chuaxet[i]){
				x[k] = i;
				chuaxet[i] = 1;
				Hamilton(k+1);
				chuaxet[i] = 0;
			}
		}
	}
}

void Hamilton_Cycle(int u){
	x[1] = u;
	chuaxet[u] = 1;
	Hamilton(2);
}

main(){
	//Lay ma tran ke: (Do Thi Chac Chan Lien Thong!)
	ifstream mtk;
	mtk.open("Hamilton.in");
	mtk >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mtk >> a[i][j];
		}
	}
	mtk.close();
	//Tim Chu Trinh Hamilton cua dinh bat ky:
	cout << "Nhap dinh bat ki: ";
	cin >> u;
	Hamilton_Cycle(u);
}
