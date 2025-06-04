#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H
class NhanVien{
protected:
    string hoten;
    string ngaysinh;
    double luong;
    static int dem;
public:
    virtual ~NhanVien();
    NhanVien();
    NhanVien(string, string);
    NhanVien(const NhanVien&);
    NhanVien& operator=(const NhanVien&);
    string GetHoTen();
    string GetNgaySinh();
    double GetLuong();
    static int GetDem();
    void SetHoTen(string);
    void SetNgaySinh(string);
    virtual void Nhap();
    virtual void Xuat();
    virtual string GetLoai()=0;
    virtual void TinhLuong()=0;
};
#endif
int NhanVien::dem=0;
NhanVien::~NhanVien(){
    cout<<"Da huy mot nhan vien"<<endl;
    --dem;
}
NhanVien::NhanVien():hoten(""), ngaysinh(""), luong(0){
    ++dem;
}
NhanVien::NhanVien(string hoten, string ngaysinh):hoten(hoten), ngaysinh(ngaysinh), luong(0){
    ++dem;
}
NhanVien::NhanVien(const NhanVien& nv){
    this->hoten=nv.hoten;
    this->ngaysinh=nv.ngaysinh;
    this->luong=nv.luong;
    ++dem;
}
NhanVien& NhanVien::operator=(const NhanVien& nv){
    this->hoten=nv.hoten;
    this->ngaysinh=nv.ngaysinh;
    this->luong=nv.luong;
    return *this;
}
string NhanVien::GetHoTen(){
    return this->hoten;
}
string NhanVien::GetNgaySinh(){
    return this->ngaysinh;
}
double NhanVien::GetLuong(){
    return this->luong;
}
int NhanVien::GetDem(){
    return dem;
}
void NhanVien::SetHoTen(string hoten){
    this->hoten=hoten;
}
void NhanVien::SetNgaySinh(string ngaysinh){
    this->ngaysinh=ngaysinh;
}
void NhanVien::Nhap(){
    cin.ignore();
    cout<<"Nhap ho ten nhan vien: "; getline(cin, hoten);
    cout<<"Nhap ngay sinh (dd/mm/yyyy): "; getline(cin, ngaysinh);
}
void NhanVien::Xuat(){
    cout<<"Ho ten nhan vien: "<<hoten<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Luong: "<<fixed<<setprecision(2)<<luong<<endl;
}
#pragma once
#ifndef VANPHONG_H
#define VANPHONG_H
class VanPhong : public NhanVien{
private:
    int songaylam;
    static int dem;
public:
    ~VanPhong();
    VanPhong();
    VanPhong(string, string, int);
    VanPhong(const VanPhong&);
    VanPhong& operator=(const VanPhong&);
    int GetSoNgayLam();
    static int GetDem();
    void SetSoNgayLam(int);
    void Nhap();
    void Xuat();
    string GetLoai();
    void TinhLuong();
};
#endif
int VanPhong::dem=0;
VanPhong::~VanPhong(){
    cout<<"Da huy mot nhan vien van phong"<<endl;
    --dem;
}
VanPhong::VanPhong():NhanVien(), songaylam(0){
    ++dem;
}
VanPhong::VanPhong(string hoten, string ngaysinh, int songaylam):NhanVien(hoten, ngaysinh), songaylam(songaylam){
    ++dem;
}
VanPhong::VanPhong(const VanPhong& vp):NhanVien(vp){
    this->songaylam=vp.songaylam;
    ++dem;
}
VanPhong& VanPhong::operator=(const VanPhong& vp){
    NhanVien::operator=(vp);
    this->songaylam=vp.songaylam;
    return *this;
}
int VanPhong::GetSoNgayLam(){
    return this->songaylam;
}
int VanPhong::GetDem(){
    return dem;
}
void VanPhong::SetSoNgayLam(int songaylam){
    while(songaylam<0){
        cout<<"So ngay lam khong hop le! Moi ban nhap lai: ";
        cin>>songaylam;
    }
    this->songaylam=songaylam;
}
void VanPhong::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so ngay lam viec: "; cin>>songaylam;
        if(songaylam<0) cout<<"So ngay lam khong hop le! Moi ban nhap lai"<<endl;
    }while(songaylam<0);
}
void VanPhong::Xuat(){
    NhanVien::Xuat();
    cout<<"So ngay lam: "<<songaylam<<endl;
}
string VanPhong::GetLoai(){
    return "Nhan vien van phong";
}
void VanPhong::TinhLuong(){
    luong=songaylam*100000;
}
#pragma once
#ifndef SANXUAT_H
#define SANXUAT_H
class SanXuat : public NhanVien{
private:
    double luongcb;
    int sosanpham;
    static int dem;
public:
    ~SanXuat();
    SanXuat();
    SanXuat(string, string, double, int);
    SanXuat(const SanXuat&);
    SanXuat& operator=(const SanXuat&);
    double GetLuongCB();
    int GetSoSanPham();
    static int GetDem();
    void SetLuongCB(double);
    void SetSoSanPham(int);
    void Nhap();
    void Xuat();
    string GetLoai();
    void TinhLuong();
};
#endif
int SanXuat::dem=0;
SanXuat::~SanXuat(){
    cout<<"Da huy mot nhan vien san xuat"<<endl;
    --dem;
}
SanXuat::SanXuat():NhanVien(), luongcb(0), sosanpham(0){
    ++dem;
}
SanXuat::SanXuat(string hoten, string ngaysinh, double luongcb, int sosanpham):NhanVien(hoten, ngaysinh), luongcb(luongcb), sosanpham(sosanpham){
    ++dem;
}
SanXuat::SanXuat(const SanXuat& sx):NhanVien(sx){
    this->luongcb=sx.luongcb;
    this->sosanpham=sx.sosanpham;
    ++dem;
}
SanXuat& SanXuat::operator=(const SanXuat& sx){
    NhanVien::operator=(sx);
    this->luongcb=sx.luongcb;
    this->sosanpham=sx.sosanpham;
    return *this;
}
double SanXuat::GetLuongCB(){
    return this->luongcb;
}
int SanXuat::GetSoSanPham(){
    return this->sosanpham;
}
int SanXuat::GetDem(){
    return dem;
}
void SanXuat::SetLuongCB(double luongcb){
    while(luongcb<0){
        cout<<"Luong can ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
    this->luongcb=luongcb;
}
void SanXuat::SetSoSanPham(int sosanpham){
    while(sosanpham<0){
        cout<<"So san pham khong hop le! Moi ban nhap lai: ";
        cin>>sosanpham;
    }
    this->sosanpham=sosanpham;
}
void SanXuat::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap luong can ban: "; cin>>luongcb;
        if(luongcb<0) cout<<"Luong can ban khong hop le! Moi ban nhap lai"<<endl;
    }while(luongcb<0);
    do{
        cout<<"Nhap so san pham: "; cin>>sosanpham;
        if(sosanpham<0) cout<<"So san pham khong hop le! Moi ban nhap lai"<<endl;
    }while(sosanpham<0);
}
void SanXuat::Xuat(){
    NhanVien::Xuat();
    cout<<"Luong can ban: "<<fixed<<setprecision(2)<<luongcb<<endl;
    cout<<"So san pham: "<<sosanpham<<endl;
}
string SanXuat::GetLoai(){
    return "Nhan vien san xuat";
}
void SanXuat::TinhLuong(){
    luong=luongcb+sosanpham*5000;
}
#pragma once
#ifndef CONGTY_H
#define CONGTY_H
class CongTy{
private:
    NhanVien** ct;
    int sl;
    static int dem;
public:
    ~CongTy();
    CongTy();
    CongTy(int);
    CongTy(int, NhanVien**);
    CongTy(const CongTy&);
    CongTy& operator=(const CongTy&);
    int GetSL();
    static int GetDem();
    void SetSL();
    void Nhap();
    NhanVien* Nhap1();
    void Xuat();
    double TongLuong();
    void NVSXLuongThapNhat();
    void NVVPTuoiCaoNhat();
};
#endif
int CongTy::dem=0;
CongTy::~CongTy(){
    if(ct!=nullptr){
        for(int i=0; i<sl; i++)
            delete ct[i];
        delete[] ct;
        ct=nullptr;
        sl=0;
    }
    --dem;
}
CongTy::CongTy():sl(0), ct(nullptr){
    ++dem;
}
CongTy::CongTy(int sl):sl(sl), ct(nullptr){
    if(sl>0){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++)
            ct[i]=nullptr;
    }
    ++dem;
}
CongTy::CongTy(int sl, NhanVien** nv):sl(sl), ct(nullptr){
    if(sl>0&&nv!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(nv[i]->GetLoai()=="Nhan vien van phong")
                ct[i]=new VanPhong(*(VanPhong*)nv[i]);
            else
                ct[i]=new SanXuat(*(SanXuat*)nv[i]);
        }
    }
    ++dem;
}
CongTy::CongTy(const CongTy& other):sl(other.sl), ct(nullptr){
    if(sl>0&&other.ct!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.ct[i]->GetLoai()=="Nhan vien van phong")
                ct[i]=new VanPhong(*(VanPhong*)other.ct[i]);
            else
                ct[i]=new SanXuat(*(SanXuat*)other.ct[i]);
        }
    }
    ++dem;
}
CongTy& CongTy::operator=(const CongTy& other){
    if(this!=&other){
        if(ct!=nullptr){
            for(int i=0; i<sl; i++)
                delete ct[i];
            delete[] ct;
        }
        sl=other.sl;
        if(sl>0&&other.ct!=nullptr){
            ct=new NhanVien*[sl];
            for(int i=0; i<sl; i++){
                if(other.ct[i]->GetLoai()=="Nhan vien van phong")
                    ct[i]=new VanPhong(*(VanPhong*)other.ct[i]);
                else
                    ct[i]=new SanXuat(*(SanXuat*)other.ct[i]);
            }
        }
        else ct=nullptr;
    }
    return *this;
}
int CongTy::GetSL(){
    return this->sl;
}
int CongTy::GetDem(){
    return dem;
}
void CongTy::SetSL(){
    while(sl<1){
        cout<<"So luong khong hop le! Moi ban nhap lai: ";
        cin>>sl;
    }
    this->sl=sl;
}
void CongTy::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong nhan vien: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(sl<1);
    ct=new NhanVien*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n===========================\n";
        cout<<"Nhap thong tin nhan vien thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Nhan vien van phong, 2: Nhan vien san xuat): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            ct[i]=new VanPhong;
        else
            ct[i]=new SanXuat;
        ct[i]->Nhap();
        ct[i]->TinhLuong();
    }
}
NhanVien* CongTy::Nhap1(){
    int loai;
    NhanVien* nv;
    do{
        cout<<"Nhap loai (1: Nhan vien van phong, 2: Nhan vien san xuat): ";
        cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1)
        nv=new VanPhong;
    else
        nv=new SanXuat;
    nv->Nhap();
    nv->TinhLuong();
    return nv;
}
void CongTy::Xuat(){
    if(ct==nullptr) cout<<"Danh sach nhan vien rong"<<endl;
    else{
        cout<<"\n=====THONG TIN NHAN VIEN======\n";
        for(int i=0; i<sl; i++){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
    }
}
double CongTy::TongLuong(){
    double sum=0;
    for(int i=0; i<sl; i++)
        sum+=ct[i]->GetLuong();
    return sum;
}
void CongTy::NVSXLuongThapNhat(){
    double minLuong=-1;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Nhan vien san xuat"&&(minLuong==-1||ct[i]->GetLuong()<minLuong))
            minLuong=ct[i]->GetLuong();
    if(minLuong==-1){
        cout<<"Khong co nhan vien san xuat"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN SAN XUAT CO LUONG THAP NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Nhan vien san xuat"&&ct[i]->GetLuong()==minLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::NVVPTuoiCaoNhat(){
    int maxNamSinh=9999;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Nhan vien van phong"){
            string ns=ct[i]->GetNgaySinh();
            int nam=stoi(ns.substr(6, 4));
            if(nam<maxNamSinh)
                maxNamSinh=nam;
        }
    if(maxNamSinh==9999){
        cout<<"Khong co nhan vien van phong"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN VAN PHONG CO TUOI CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Nhan vien van phong"){
            string ns=ct[i]->GetNgaySinh();
            int nam=stoi(ns.substr(6, 4));
            if(nam==maxNamSinh){
                cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
                ct[i]->Xuat();
                cout<<endl;
            }
        }
}
int main(){
    CongTy ct;
    cout<<"===== CHUONG TRINH QUAN LY CONG TY =====\n\n";
    cout<<"1. Nhap danh sach nhan vien:\n";
    ct.Nhap();
    cout<<"Danh sach vua nhap:\n"; ct.Xuat();
    cout<<"\n2. Tong luong cong ty phai tra: "<<fixed<<setprecision(2)<<ct.TongLuong()<<endl;
    cout<<"\n3. Nhan vien san xuat co luong thap nhat:\n";
    ct.NVSXLuongThapNhat();
    cout<<"\n4. Nhan vien van phong co tuoi cao nhat:\n";
    ct.NVVPTuoiCaoNhat();
    cout<<"\n5. Thong ke:\n";
    cout<<"So luong nhan vien: "<<NhanVien::GetDem()<<endl;
    cout<<"So luong nhan vien van phong: "<<VanPhong::GetDem()<<endl;
    cout<<"So luong nhan vien san xuat: "<<SanXuat::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}