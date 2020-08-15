#pragma once
#ifndef __HEAD__H__
#define __HEAD__H__
#define MAX 23
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#pragma warning(disable:4996)
using namespace std;

struct ThePhat
{
	int TheVang;
	int TheDo;
};
struct KyNang
{
	int SoAo;
	string ViTri;
	string ChanThuan;
	int SoBan;
	ThePhat The;
};
struct SucKhoe
{
	bool RaSan;
	float PhongDo;
};
class ConNguoi
{
public:
	string HoTen;
	int NamSinh;
	string DiaChi;
	string TenCha;
	string TenMe;
public:
	void Nhap();
};
class CauThu : public ConNguoi
{
public:
	KyNang Kynang;
	SucKhoe Suckhoe;
public:
	void NhapThongTin();
	CauThu GetCauThu();
	void XuatThongTin();
	CauThu NhapVaLuuThongTin();
	
};
struct NODE
{
	CauThu Data;
	NODE* pNext;
};
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
CauThu DocThongTin(string TenTepTin);
NODE* GetNode(CauThu X);
void XuatDanhSach(LIST l);
void KhoiTao(LIST &l);
void ThemCuoi(LIST &l, NODE *p);
void HuyDanhSach(LIST &l);
ostream& operator << (ostream& outdev, CauThu &A);
void HoanViCauThu(CauThu &X, CauThu &Y);
void SapXepTheoPhongDo(LIST l);
LIST TaoSoDo(LIST &l, int SLuongHauVe, int SLuongTienVe, int SLuongTienDao);
void DocDanhSachCauThu(LIST &l);
void LuaChon();
void chuanHoaChuoiString(string &str);
bool KiemTraTepTinCoTonTai(string& TenTepTin);
#endif
