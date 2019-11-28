#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;
//m la trong luong tui, n la tong so do vat
//	int m=10,n=6;
//	int v[]={12,1,8,1,10,3};
//	int w[]={6,3,3,7,4,3};
//	int m=19,n=6;
//	int v[100]={7,10,20,19,13,40};
//	int w[100]={3,4,5,7,6,9};
	int m=20,n=28;
	int v[100] = {4,2,10,12,11,17,9,11,4,19,4,7,10,13,9,4,3,6,1,19,4,2,10,12,11,14,4,15};
	int w[100] = {6,2,6,2,3,7,3,1,1,12,2,1,6,2,4,1,3,1,2,17,6,2,6,2,3,7,2,3};  	
	int daxet[100];
	int x[100];
	int vi;
	int wi;
	int vmax;
	int i;
void Init(){
	for (i=0;i<n;i++){
		daxet[i]=0;
		x[i]=0;
	}
}
void Xuat(int x[100]){
	cout<<"x[i] = 0 la khong duoc chon, x[i] = 1 la vat duoc chon"<<endl;
	cout<<"Nghiem cua bai toan cai tui theo giai thuat quay lui:"<<endl;
	for(i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl<<"Do vat duoc chon la: "<<endl;
	for(i=0;i<n;i++){
		if(x[i]==1)
			cout<<i+1<<"	";
	}
	cout<<endl<<"Gia tri lon nhat co the mang di la : "<<vmax<<endl;
}
void KiemTraCauHinh(){
	int k;
	for(k=0;k<n;k++){
		if(daxet[k]==1){
			wi=wi+w[k];
			if(wi<=m){
				vi=vi+v[k];
			}else{vi=0;
			break;
			}
		}
	}
	if((vi>vmax)&&(wi<=m)){
		vmax=vi;
		for(int k=0;k<n;k++)
			x[k]=daxet[k];		
		}
}
void Try(int i){
	int j;
	for(j=0;j<=1;j++){
		daxet[i]=j;
		vi=0;
		wi=0;
		if(i==n-1){
			KiemTraCauHinh();
		}else Try(i+1);
	}
}
void InDuLieu(){
	cout<<"STT\tGia tri\t   Trong luong\n";
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<"\t"<<v[i]<<"\t   "<<w[i]<< endl; 
	}
}
int main()
{
	cout<<"GIAI BAI TOAN CAI TUI THEO PHUONG PHAP QUAY LUI"<<endl;
	cout<<"Tong trong luong cai tui : "<<m<<endl;
	cout<<"Tong so luong do vat: "<<n<<endl;
	InDuLieu();
	clock_t start=clock();
	Init();
	vmax=0;
	Try(0);
	Xuat(x);
	clock_t end=clock();
	float time=(end-start)/CLOCKS_PER_SEC;
	cout<<"Run time : "<<fixed<<setprecision(3)<<time<<" (s)"<<endl;
 	return 0;	
}
