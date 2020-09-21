/* Truong hoc can trao thuong cho sinh vien xuat sac va giang vien co nhieu cong trinh khoa hoc duoc cong bo tren tap tri
	Cu the can  quan ly nhu sau:
		- Giang vien: Ma, Ho ten, So bai bao.
			+So bai bao duoc khen thuong theo quy dinh: So bai bao > 5 duoc khen thuong;
		- Sinh vien: Ma, Ho ten, Diem trung binh.
			+ Duoc khen thuong theo quy dinh: Diem trung binh > 9 duoc khen thuong;
	a, Hay xay dung cac lop giai quyet de bai;
	b, Viet chuong trinh: + Nhap vao danh sach gom Giang vien, Sinh vien
						  + Xuat thong tin va khen thuong (neu co) cua cac Giang vien va Sinh Vien o danh sach tren;
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nguoi{
	protected:
		string Ma,HoTen;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual int KhenThuong()=0;
	
};

void Nguoi:: Nhap(){
	fflush(stdin);
	cout<< " Ma: ";
	getline(cin,Ma);
	cout<<" Ho ten: ";
	getline(cin,HoTen);
}

void Nguoi::Xuat(){
	cout<<" Ma: "<<Ma<<" --- Ho ten: ";
}
	
class SinhVien:public Nguoi{
	private:
		float DTB;
	public:
		void Nhap();
		void Xuat();
		int KhenThuong();
};
void SinhVien::Nhap(){
	Nguoi::Nhap();
	cout<< " Nhap diem trung binh: ";
	cin>>DTB;
	}
void SinhVien::Xuat(){
	Nguoi::Xuat();
	cout<<" --- Diem trung binh: "<<DTB<<endl;
	}
int SinhVien::KhenThuong(){
		if(DTB>7){
			return true;
		}else{
			return false;
		}
}
class GiangVien:public Nguoi{
	private:
		int SoBaiBao;
	public:
		void Nhap();
		void Xuat();
		int KhenThuong();
};

void GiangVien::Nhap(){
	Nguoi::Nhap();
	cout<< " So bai bao: ";
	cin>>SoBaiBao;
	}
	
void GiangVien::Xuat(){
	Nguoi::Xuat();
	cout<<" --- So bai bao: "<<SoBaiBao<<endl;
	}
	
int GiangVien::KhenThuong(){
		if(SoBaiBao>7){
			return true;
		}else{
			return false;
		}
	}
class QuanLy{
	private:
		vector<Nguoi*> danhsach;
	public:
		void Nhap();
		void Xuat();
		int getKhenThuong();
		
};
void QuanLy::Nhap(){
	Nguoi *nguoi;
	int chon;
	do{
		system("cls");
		cout<<"1. Nhap danh sach giang vien\n";
		cout<<"2. Nhap danh sach sinh vien\n";
		cout<<"3. Thoat\n";
		cout<<"Moi ban chon:";
		cin>>chon;
		switch(chon){
			case 1: 
				{
					nguoi=new GiangVien();
					nguoi->Nhap();
					danhsach.push_back(nguoi);
				break;
				}
			case 2:
				{
					nguoi=new SinhVien();				
					nguoi->Nhap();
					danhsach.push_back(nguoi);
				break;
				}
					
			case 3: 
				break;	
			default:
				break;
		}
	}while(chon!=3);
}
void QuanLy::Xuat(){
	for(int i=0;i<danhsach.size();i++){
		danhsach[i]->Xuat();
	}
}

int QuanLy::getKhenThuong(){
	for(int i=0;i<danhsach.size();i++){
		if(danhsach[i]->KhenThuong()==true){
			cout<< "Danh sach duoc khen thuong la:";
			danhsach[i]->Xuat();
		}
	}
}
int main(){
	QuanLy *ql=new QuanLy;
	int chon;
	do{
		system("cls");
		cout<<" 1. Nhap danh sach\n";
		cout<<" 2. Xuat danh sach\n";
		cout<<" 3. Xuat ra danh sach duoc khen thuong\n";
		cout<<" 4. Thoat!\n";
		cout<<" Moi ban chon:";
		cin>>chon;
		cout<<endl;
		switch(chon){
			case 1:
				ql->Nhap();	
				break;
			case 2:
				ql->Xuat();
				system("pause");
				break;
			case 3:
				{
					ql->getKhenThuong();
					system("pause");
					break;
				}
			case 4:
				system("pause");
			break;
		default:
			system("pause");
			break;
		}
			
	}while(chon!=4);
}		
