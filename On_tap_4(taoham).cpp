#include <iostream>
using namespace std;

class TaiLieu
{
private:
	string ma_tai_lieu;
	string ten_tai_lieu;

public:
	void Nhap()
	{
		cout << "Nhap ma_tai_lieu: ";
		getline(cin, ma_tai_lieu);  
		cout << "\nNhap Ten_tai_lieu: ";
		getline(cin, ten_tai_lieu); 
	}
	void Xuat()
	{
		cout <<"Ma Tai Lieu : "<<ma_tai_lieu<<"\t" <<"Ten Tai Lieu: "<< ten_tai_lieu << endl;
	}
	bool operator >(TaiLieu x)
	{
		return ten_tai_lieu > x.ten_tai_lieu;
	}
	virtual string timkiem()
	{
		return "";
	}
	virtual int namphathanh()
	{
		return -1;
	}
	string get_ma_tai_lieu()
	{
		return ma_tai_lieu;
	}
	string get_ten_tai_lieu()
	{
		return ten_tai_lieu;
	}
};

class Sach : public TaiLieu
{
private:
	string ten_tac_gia;
	string ten_nha_xuatban;
	int so_trang;

public:
	void Nhap()
	{
		TaiLieu::Nhap();
		cout << endl;
		cout << "Nhap ten_tac_gia: ";
		getline(cin, ten_tac_gia);
		cout << "\nNhap Ten_nha_xuatban: ";
		getline(cin, ten_nha_xuatban);
		cout << "\n so_trang: ";
		cin >> so_trang;
		cin.ignore();
	}
	void Xuat()
	{
		TaiLieu::Xuat();
		cout << "\t ";
		cout << ten_tac_gia << "\t" << ten_nha_xuatban << "\t" << so_trang << endl;
	}
	string timkiem() // tai dinh nghia ham ao(virtual) overider
	{
		return "sach";
	}
};

class Tapchi : public TaiLieu
{
private:
	int nam_phat_hanh;
	string ma_phat_hanh;

public:
	void Nhap()
	{
		TaiLieu::Nhap();
		cout << endl;
		cout << "Nhap nam_phat_hanh: ";
		cin >> nam_phat_hanh;
		cout << "\nNhap ma_phat_hanh: ";
		cin.ignore();
		getline(cin, ma_phat_hanh);
		cin.ignore();
	}
	void Xuat()
	{
		TaiLieu::Xuat();
		cout << "\t ";
		cout << nam_phat_hanh << "\t" << ma_phat_hanh << endl;
	}
	string timkiem() // tai dinh nghia ham ao (virtual)
	{
		return "tapchi";
	}
	int namphathanh()
	{
		return nam_phat_hanh;
	}
};

class Quanly
{
private:
	int n;
	TaiLieu *a[100];

public:
	Quanly(){};
void _swap(TaiLieu* x, TaiLieu* y)
{
    TaiLieu temp = *x;
    *x = *y;
    *y = temp;
}
	void Nhap()
	{
		// bo sung kiem tra n
		cout << "Nhap so luong N: ";
		cin >> n;
		int tl; // tra loi

		for (int i = 0; i < n; i++)
		{
			cout << "Nhap sach(1) || tapchi(2) \n";
			cin >> tl;
			if (tl == 1)
			{
				cin.ignore();
				Sach *p = new Sach;
				p->Nhap();
				a[i] = p;
			}
			else if (tl == 2)
			{
				cin.ignore();
				Tapchi *p = new Tapchi;
				p->Nhap();
				a[i] = p;
			}
		}
	}

	void deletatailieu(string k)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i]->get_ma_tai_lieu() == k)
			{
				for (int j = i; j < n - 1; j++)
				{
					a[j] = a[j + 1];
				}
				n--;
				i--;
			}
		}
	}
	bool check(string cum1, string cum2)
	{
		int sizecheck = cum2.size();
		bool ktra[cum2.size()] = {0};
		string k = ""; // buoc di den cuoi cung cua chuoi cum2
		for (int i = 0; i < cum2.size(); i++)
		{
			for (int j = 0; j < cum1.size(); j++)
			{
				if (cum2[i] == cum1[j] && ktra[i] == 0)
				{
					k += cum1[j];
					ktra[i] = 1;
				}
			}
		}
		if (k == cum2)
		{
			return true;
		}
		return false;
	}
	void xuatsachcumtu(string tieude)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i]->timkiem() == "sach" && check(a[i]->get_ten_tai_lieu(), tieude) == true) // a[i]->get_ten_tai_lieu().find(tieude) != string::npos
			{
				a[i]->Xuat();
			}
		}
	}
	void sapXepTangDanTheoTen()
	{
		for (int i = 0; i < n - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < a[min])
				{
					min = j;
				}
				_swap(a[i],a[min]);
			}
		}
	}
	void Timtapchitheonam(int nam)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i]->timkiem() == "tapchi" && a[i]->namphathanh() == nam)
			{
				a[i]->Xuat();
			}
		}
	}
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			a[i]->Xuat();
		}
		
	}
};
int main()
{
	Quanly otp;
	otp.Nhap();
	otp.sapXepTangDanTheoTen();
	cout<<"sap xep theo ten: "<<endl;
	otp.Xuat();
	
	return 0;
}
