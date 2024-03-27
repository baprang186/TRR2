#include <iostream>
#include <fstream>
using namespace std;
int n,u,a[100][100],chuaxet[100],x[100],xopt[100],fopt = INT_MAX;

int TongPhuongAn(){
	int t = 0;
	for(int i=1;i<n;i++){
		t = t + a[x[i]][x[i+1]];
	}
	t = t + a[x[n]][x[1]];
	return t;
}

void CapNhat(int sum){
	fopt = sum; // cap nhat gia tri toi uu;
	for(int i=1;i<=n;i++){ // cap nhat phuong an toi uu
		xopt[i] = x[i];
	}
	xopt[n+1] = x[1];
}

void Hamilton(int k){
	for(int i=1;i<=n;i++){ // Duyet tung canh cua dinh x[k-1];
		if(a[x[k-1]][i] > 0){ 
			if(k==n+1 && i==u){ // Neu quay tro lai duoc dinh u (de tao thanh chu trinh);
				int sum = TongPhuongAn(); // Tinh tong cua phuong an;
				if(sum < fopt) CapNhat(sum); // Neu tong nho hon gia tri toi uu (hien tai) thi cap nhat;
			}else if(!chuaxet[i]){
				x[k] = i; // Neu chua xet dinh i thi cap nhat x[k];
				chuaxet[i] = 1; // Danh dau dinh da xet;
				Hamilton(k+1);
				chuaxet[i] = 0; // Sau khi da su dung xong;
			}
		}
	}
}

void Hamilton_Cycle(int u){
	x[1] = u; // dinh u la dinh dau tien
	chuaxet[u] = 1; // danh dau dinh u da su dung
	Hamilton(2); // duyet cac dinh tiep theo
}

void in(){
	cout << "Duong di tot nhat: ";
	for(int i=1;i<=n;i++){
		cout << xopt[i] << "->";
	}
	cout << xopt[n+1] << endl;
	cout << "Chi phi re nhat: " << fopt;
}

main(){
	//Lay ma tran ke:
	ifstream mtk;
	mtk.open("NguoiDuLich.in");
	mtk >> n; // Lay so canh;
	for(int i=1;i<=n;i++){ // Lay ma tran ke;
		for(int j=1;j<=n;j++){
			mtk >> a[i][j];
		}
	}
	mtk.close();
	//Tim Chu Trinh Hamilton tai dinh u:
	cout << "Nhap thanh pho xuat phat: ";
	cin >> u;
	Hamilton_Cycle(u);
	in();
}
