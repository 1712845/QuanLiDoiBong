#include"CauThu.h"
void chuanHoaChuoiString(string &str)
{
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0); // xóa kí tự tại vị trí 0
	}

	// Bước 2: Xóa hết tất cả các kí tự khoảng trắng thừa ở cuối chuỗi
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); // xóa kí tự tại vị trí cuối của chuỗi
	}
	strlwr((char *)str.c_str()); // hàm chuyển chuỗi str về chuỗi in thường
	// Bước 2: viết hoa kí tự đầu của mỗi từ
	if (str[0] != ' ')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] -= 32;
		}

	}
	// Xoa khoang trang giua cac tu
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// kí tự tại vị trí i là khoảng trắng, i + i khác khoảng trắng thì kí tự tại vị trí i + 1 chính là kí tự đầu tiên của mỗi từ
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				// - 32 là chuyển kí tự in thường về in hoa
				str[i + 1] -= 32; // <=> str[i + 1] = str[i + 1] - 32;
			}
		}
	}
}
void ConNguoi::Nhap()
{
	cout << "Nhap ho va ten: ";
	getline(cin,HoTen);
	chuanHoaChuoiString(HoTen);
	cout << "Nhap nam sinh: ";
	cin >> NamSinh; cin.ignore(1);
	cout << "Nhap dia chi: ";
	getline(cin, DiaChi);
	cout << "Nhap ten cha: ";
	getline(cin, TenCha);
	chuanHoaChuoiString(TenCha);
	cout << "Nhap ten me: ";
	getline(cin, TenMe);
	chuanHoaChuoiString(TenMe);
}
void CauThu::NhapThongTin()
{
	Nhap();
	cout << "Nhap so ao cua cau thu: ";
	cin >> Kynang.SoAo; cin.ignore(1);
	cout << "Nhap vi tri so truong: ";
	getline(cin, Kynang.ViTri);
	chuanHoaChuoiString(Kynang.ViTri);
	cout << "Nhap chan thuan: ";
	getline(cin, Kynang.ChanThuan);
	cout << "Nhap so ban thang: ";
	cin >> Kynang.SoBan; cin.ignore(1);
	cout << "Nhap so the vang: ";
	cin >> Kynang.The.TheVang;
	cout << "Nhap so the do: ";
	cin >> Kynang.The.TheDo;
	cin.ignore(1);
	cout << "Cau thu co the ra san khong ( true  = 1 , false = 0) : ";
	cin>> Suckhoe.RaSan;
	cout << "Phong do cua cau thu: ";
	cin >> Suckhoe.PhongDo; cin.ignore(1);
}
CauThu CauThu::GetCauThu()
{
	CauThu A;
	A.NhapThongTin();
	return A;
}
void CauThu::XuatThongTin()
{
	cout << "----------THONG--TIN--CAU--THU------------" << endl;

	cout << "Ho va ten: " << HoTen << endl;

	cout << "Nam sinh: " << NamSinh << endl;
	cout << "Dia chi: " << DiaChi << endl;
	cout << "Ten cha: " << TenCha << endl;
	cout << "Ten me: " << TenMe << endl;
	cout << "So ao : " << Kynang.SoAo << endl;
	cout << "Vi tri so truong(VD : Hau ve (Phai theo font)): " << Kynang.ViTri << endl;
	cout << "Chan thuan: " << Kynang.ChanThuan << endl;
	cout << "So ban thang: " << Kynang.SoBan << endl;
	cout << "So the vang: " << Kynang.The.TheVang << endl;
	cout << "So the do: " << Kynang.The.TheDo << endl;
	cout << "Cau thu co the ra san khong(CO = 1 ,KHONG = 0): " <<Suckhoe.RaSan<< endl;
	cout << "Phong do cua cau thu: "<<Suckhoe.PhongDo<<endl<<endl;
}
CauThu  CauThu::NhapVaLuuThongTin()
{
	CauThu B;
	fstream outfile;
	string TenTepTin;
	stringstream ss;
	B.NhapThongTin();
	ss << B.Kynang.SoAo;
	TenTepTin = ss.str()+".txt";
	outfile.open(TenTepTin, ios::out);
	if (outfile.fail())
	{
		cout << "Mo tep that bai!\n ";
		exit(0);
	}
	else
	{
		outfile << B.HoTen << endl;
		outfile << B.NamSinh << endl;
		outfile << B.DiaChi << endl;
		outfile << B.TenCha << endl;
		outfile << B.TenMe << endl;
		outfile << B.Kynang.SoAo << endl;
		outfile << B.Kynang.ViTri<<endl;
		outfile << B.Kynang.ChanThuan<<endl;
		outfile << B.Kynang.SoBan<<endl;
		outfile << B.Kynang.The.TheVang<<endl;
		outfile << B.Kynang.The.TheDo<<endl;
		outfile << B.Suckhoe.RaSan << endl;
		outfile << B.Suckhoe.PhongDo << endl;
	}
	outfile.close();
	return B;
}
CauThu DocThongTin(string TenTepTin)
{
	fstream filein;
	CauThu A;
	char temp[255];
	filein.open(TenTepTin, ios::in);
	if (filein.fail())
	{
		cout << "khong mo dc tep\n";
	}
	else {
		filein.getline(temp, 255);
		A.HoTen = temp;
		chuanHoaChuoiString(A.HoTen);
		filein.getline(temp, 255);
		A.NamSinh = atoi(temp);
		filein.getline(temp, 255);
		A.DiaChi = temp;
		filein.getline(temp, 255);
		A.TenCha = temp;
		chuanHoaChuoiString(A.TenCha);
		filein.getline(temp, 255);
		A.TenMe = temp;
		chuanHoaChuoiString(A.TenMe);
		filein.getline(temp, 255);
		A.Kynang.SoAo = atoi(temp);
		filein.getline(temp, 255);
		A.Kynang.ViTri = temp;
		chuanHoaChuoiString(A.Kynang.ViTri);
		filein.getline(temp, 255);
		A.Kynang.ChanThuan = temp;
		filein.getline(temp, 255);
		A.Kynang.SoBan = atoi(temp);
		filein.getline(temp, 255);
		A.Kynang.The.TheVang = atoi(temp);
		filein.getline(temp, 255);
		A.Kynang.The.TheDo = atoi(temp);
		filein.getline(temp, 255);
		A.Suckhoe.RaSan = atoi(temp);
		filein.getline(temp, 255);
		A.Suckhoe.PhongDo = atof(temp);
		return A;
	}
}
ostream& operator << (ostream& outdev, CauThu &A)
{
	A.XuatThongTin();
	return outdev;
}
void KhoiTao(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* GetNode(CauThu X)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Cap phat that bai!\n";
	}
	else
	{
		p->Data = X;
		p->pNext = NULL;
	}

	return p;
}
void ThemCuoi(LIST &l,NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void HuyDanhSach(LIST &l)
{
	NODE *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}
void XuatDanhSach(LIST l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data;
	}
}
void HoanViCauThu(CauThu &X, CauThu &Y)
{
	CauThu temp = X;
	X = Y;
	Y = temp;
}
void SapXepTheoPhongDo(LIST l)
{
	NODE* i;
	NODE* j;
	for ( i= l.pHead; i != NULL; i = i->pNext)
	{
		for (j = l.pHead->pNext; j != NULL; j = j->pNext)
		{
				if (i->Data.Suckhoe.PhongDo > j->Data.Suckhoe.PhongDo)
				{
					HoanViCauThu(i->Data, j->Data);
				}
		}
	}
}
LIST TaoSoDo(LIST& l, int SLuongHauVe, int SLuongTienVe, int SLuongTienDao)
{
	LIST k;
	int q = 0;
	NODE * temp;
	KhoiTao(k);
	SapXepTheoPhongDo(l);
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->Data.Kynang.ViTri == "Thu Mon" && i->Data.Suckhoe.RaSan == 1)
		{
			temp = GetNode(i->Data);
			ThemCuoi(k, temp);
			break;
		}
	}
	q = 0;
	for (NODE*i = l.pHead; i != NULL, q < SLuongHauVe; i = i->pNext)
	{
		if (i->Data.Kynang.ViTri == "Hau Ve" && i->Data.Suckhoe.RaSan == 1)
		{
			temp = GetNode(i->Data);
			ThemCuoi(k, temp);
			q++;
		}
	}
	q = 0;
	for (NODE *i = l.pHead; i != NULL, q < SLuongTienVe; i = i->pNext)
	{
		if (i->Data.Kynang.ViTri == "Tien Ve"&& i->Data.Suckhoe.RaSan == 1)
		{
			temp = GetNode(i->Data);
			ThemCuoi(k, temp);
			q++;
		}
	}
	q = 0;
	for (NODE* i = l.pHead; i != NULL, q < SLuongTienDao;i = i->pNext)
	{
		if (i->Data.Kynang.ViTri == "Tien Dao" && i->Data.Suckhoe.RaSan == 1)
		{
			temp = GetNode(i->Data);
			ThemCuoi(k, temp);
			q++;
		}
	}
	return k;
}
void DocDanhSachCauThu(LIST &l)
{
	NODE* p;

	string TenTepTin;
	stringstream ss[100];
	for (int i = 1; i <= 99; i++)
	{
		ss[i] << i;
		TenTepTin = ss[i].str() + ".txt";
		if (KiemTraTepTinCoTonTai(TenTepTin) == true)
		{
			p = GetNode(DocThongTin(TenTepTin));
			ThemCuoi(l, p);
		}
	}
}
void LuaChon()
{
	CauThu A;
	NODE* p;
	LIST l, k;
	int SLuongHauVe, SLuongTienVe, SLuongTienDao;
	int Luachon;
	cout << "Nhap lua chon cua ban: " ;
	cin >> Luachon; cin.ignore(1);
	switch (Luachon)
	{
	case 1: 
		KhoiTao(l);
		for (int i = 0; i < MAX; i++)
		{
			p = GetNode(A.GetCauThu());
			ThemCuoi(l, p);
			
		}
		cout << "Nhap so do chien thuat:"; cin >> SLuongHauVe >> SLuongTienVe >> SLuongTienDao;
		k = TaoSoDo(l, SLuongHauVe, SLuongTienVe, SLuongTienDao);
		XuatDanhSach(l);
		HuyDanhSach(l);
		break;
	case 2:
		KhoiTao(l);
		for (int i = 0; i < MAX; i++)
		{
			p = GetNode(A.NhapVaLuuThongTin());
			ThemCuoi(l, p);
		}
		cout << "Nhap so do chien thuat:"; cin >> SLuongHauVe >> SLuongTienVe >> SLuongTienDao;
		k = TaoSoDo(l, SLuongHauVe, SLuongTienVe, SLuongTienDao);
		XuatDanhSach(l);
		HuyDanhSach(l);
	case 3:
		KhoiTao(l);
		DocDanhSachCauThu(l);
		cout << "Nhap so do chien thuat:"; cin >> SLuongHauVe >> SLuongTienVe >> SLuongTienDao;
		k = TaoSoDo(l, SLuongHauVe, SLuongTienVe, SLuongTienDao);
		cout << "------DOI---HINH---RA---SAN--------" << endl;
		XuatDanhSach(k);
		HuyDanhSach(l);
		HuyDanhSach(k);
		system("pause");
		break;
	default: exit(0);
	}
}
bool KiemTraTepTinCoTonTai(string& TenTepTin)
{
	fstream filein;
	string temp;
	stringstream ss[100];
	for (int i = 1; i <= 99; i++)
	{
		ss[i] << i;
		temp = ss[i].str() + ".txt";
		filein.open(temp, ios::in);
		if (filein.fail())
		{
			continue;
		}
		else
		{
			if (TenTepTin == temp)
			{
				return true;
			}
		}
		filein.close();
	}
}

