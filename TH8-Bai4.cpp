#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H
class NhanVien{
    protected:
        string manv;
        string hoten;
        int tuoi;
        string sdt;
        string email;
        double luongcb;
        static int dem;
    public:
        virtual ~NhanVien();
        NhanVien();
        NhanVien(string, string, int, string, string, double);
        NhanVien(const NhanVien&);
        NhanVien& operator=(const NhanVien&);
        string GetMaNV();
        string GetHoTen();
        int GetTuoi();
        string GetSDT();
        string GetEmail();
        double GetLuongCB();
        static int GetDem();
        void SetHoTen(string);
        void SetTuoi(int);
        void SetSDT(string);
        void SetEmail(string);
        void SetLuongCB(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual double TinhLuong()=0;
};
#endif
int NhanVien::dem=0;
NhanVien::~NhanVien(){
    cout<<"Da huy mot nhan vien"<<endl;
    --dem;
}
NhanVien::NhanVien():manv(""), hoten(""), tuoi(0), sdt(""), email(""), luongcb(0){
    ++dem;
}
NhanVien::NhanVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb):manv(manv), hoten(hoten), tuoi(tuoi), sdt(sdt), email(email), luongcb(luongcb){
    ++dem;
}
NhanVien::NhanVien(const NhanVien& nv){
    this->manv=nv.manv;
    this->hoten=nv.hoten;
    this->tuoi=nv.tuoi;
    this->sdt=nv.sdt;
    this->email=nv.email;
    this->luongcb=nv.luongcb;
    ++dem;
}
NhanVien& NhanVien::operator=(const NhanVien& nv){
    this->manv=nv.manv;
    this->hoten=nv.hoten;
    this->tuoi=nv.tuoi;
    this->sdt=nv.sdt;
    this->email=nv.email;
    this->luongcb=nv.luongcb;
    return *this;
}
string NhanVien::GetMaNV(){
    return this->manv;
}
string NhanVien::GetHoTen(){
    return this->hoten;
}
int NhanVien::GetTuoi(){
    return this->tuoi;
}
string NhanVien::GetSDT(){
    return this->sdt;
}
string NhanVien::GetEmail(){
    return this->email;
}
double NhanVien::GetLuongCB(){
    return this->luongcb;
}
int NhanVien::GetDem(){
    return dem;
}
void NhanVien::SetHoTen(string hoten){
    this->hoten=hoten;
}
void NhanVien::SetTuoi(int tuoi){
    while(tuoi<18){
        cout<<"Tuoi khong hop le! Moi ban nhap lai: ";
        cin>>tuoi;
    }
    this->tuoi=tuoi;
}
void NhanVien::SetSDT(string sdt){
    this->sdt=sdt;
}
void NhanVien::SetEmail(string email){
    this->email=email;
}
void NhanVien::SetLuongCB(double luongcb){
    while(luongcb<0){
        cout<<"Luong co ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
    this->luongcb=luongcb;
}
void NhanVien::Nhap(){
    cin.ignore();
    cout<<"Nhap ma nhan vien: "; getline(cin, manv);
    cout<<"Nhap ho ten nhan vien: "; getline(cin, hoten);
    cout<<"Nhap tuoi: "; cin>>tuoi;
    while(tuoi<18){
        cout<<"Tuoi khong hop le! Moi ban nhap lai: ";
        cin>>tuoi;
    }
    cin.ignore();
    cout<<"Nhap so dien thoai: "; getline(cin, sdt);
    cout<<"Nhap email: "; getline(cin, email);
    cout<<"Nhap luong co ban: "; cin>>luongcb;
    while(luongcb<0){
        cout<<"Luong co ban khong hop le! Moi ban nhap lai: ";
        cin>>luongcb;
    }
}
void NhanVien::Xuat(){
    cout<<"Ma nhan vien: "<<manv<<endl;
    cout<<"Ho ten nhan vien: "<<hoten<<endl;
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"So dien thoai: "<<sdt<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Luong co ban: "<<fixed<<setprecision(2)<<luongcb<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Tong luong: "<<fixed<<setprecision(2)<<TinhLuong()<<endl;
}
#pragma once
#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H
class LapTrinhVien : public NhanVien{
    private:
        int sogioot;
        static int dem;
    public:
        ~LapTrinhVien();
        LapTrinhVien();
        LapTrinhVien(string, string, int, string, string, double, int);
        LapTrinhVien(const LapTrinhVien&);
        LapTrinhVien& operator=(const LapTrinhVien&);
        int GetSoGioOT();
        static int GetDem();
        void SetSoGioOT(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        double TinhLuong();
};
#endif
int LapTrinhVien::dem=0;
LapTrinhVien::~LapTrinhVien(){
    cout<<"Da huy mot lap trinh vien"<<endl;
    --dem;
}
LapTrinhVien::LapTrinhVien():NhanVien(), sogioot(0){
    ++dem;
}
LapTrinhVien::LapTrinhVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb, int sogioot):NhanVien(manv, hoten, tuoi, sdt, email, luongcb), sogioot(sogioot){
    ++dem;
}
LapTrinhVien::LapTrinhVien(const LapTrinhVien& ltv):NhanVien(ltv){
    this->sogioot=ltv.sogioot;
    ++dem;
}
LapTrinhVien& LapTrinhVien::operator=(const LapTrinhVien& ltv){
    NhanVien::operator=(ltv);
    this->sogioot=ltv.sogioot;
    return *this;
}
int LapTrinhVien::GetSoGioOT(){
    return this->sogioot;
}
int LapTrinhVien::GetDem(){
    return dem;
}
void LapTrinhVien::SetSoGioOT(int sogioot){
    while(sogioot<0){
        cout<<"So gio overtime khong hop le! Moi ban nhap lai: ";
        cin>>sogioot;
    }
    this->sogioot=sogioot;
}
void LapTrinhVien::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so gio overtime: "; cin>>sogioot;
        if(sogioot<0) cout<<"So gio overtime khong hop le! Moi ban nhap lai"<<endl;
    }while(sogioot<0);
}
void LapTrinhVien::Xuat(){
    NhanVien::Xuat();
    cout<<"So gio overtime: "<<sogioot<<endl;
}
string LapTrinhVien::GetLoai(){
    return "Lap trinh vien";
}
double LapTrinhVien::TinhLuong(){
    return luongcb+sogioot*200000;
}
#pragma once
#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H
class KiemChungVien : public NhanVien{
    private:
        int soloi;
        static int dem;
    public:
        ~KiemChungVien();
        KiemChungVien();
        KiemChungVien(string, string, int, string, string, double, int);
        KiemChungVien(const KiemChungVien&);
        KiemChungVien& operator=(const KiemChungVien&);
        int GetSoLoi();
        static int GetDem();
        void SetSoLoi(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        double TinhLuong();
};
#endif
int KiemChungVien::dem=0;
KiemChungVien::~KiemChungVien(){
    cout<<"Da huy mot kiem chung vien"<<endl;
    --dem;
}
KiemChungVien::KiemChungVien():NhanVien(), soloi(0){
    ++dem;
}
KiemChungVien::KiemChungVien(string manv, string hoten, int tuoi, string sdt, string email, double luongcb, int soloi):NhanVien(manv, hoten, tuoi, sdt, email, luongcb), soloi(soloi){
    ++dem;
}
KiemChungVien::KiemChungVien(const KiemChungVien& kcv):NhanVien(kcv){
    this->soloi=kcv.soloi;
    ++dem;
}
KiemChungVien& KiemChungVien::operator=(const KiemChungVien& kcv){
    NhanVien::operator=(kcv);
    this->soloi=kcv.soloi;
    return *this;
}
int KiemChungVien::GetSoLoi(){
    return this->soloi;
}
int KiemChungVien::GetDem(){
    return dem;
}
void KiemChungVien::SetSoLoi(int soloi){
    while(soloi<0){
        cout<<"So loi khong hop le! Moi ban nhap lai: ";
        cin>>soloi;
    }
    this->soloi=soloi;
}
void KiemChungVien::Nhap(){
    NhanVien::Nhap();
    do{
        cout<<"Nhap so loi phat hien: "; cin>>soloi;
        if(soloi<0) cout<<"So loi khong hop le! Moi ban nhap lai"<<endl;
    }while(soloi<0);
}
void KiemChungVien::Xuat(){
    NhanVien::Xuat();
    cout<<"So loi phat hien: "<<soloi<<endl;
}
string KiemChungVien::GetLoai(){
    return "Kiem chung vien";
}
double KiemChungVien::TinhLuong(){
    return luongcb+soloi*50000;
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
        double LuongTBCuaNhanVien();
        void NVCoLuongThapHonTB();
        void NVCaoNhatLuong();
        void NVThapNhatLuong();
        void LTVCaoNhatLuong();
        void KCVCaoNhatLuong();
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
            if(nv[i]->GetLoai()=="Lap trinh vien")
                ct[i]=new LapTrinhVien(*(LapTrinhVien*)nv[i]);
            else
                ct[i]=new KiemChungVien(*(KiemChungVien*)nv[i]);
        }
    }
    ++dem;
}
CongTy::CongTy(const CongTy& other):sl(other.sl), ct(nullptr){
    if(sl>0&&other.ct!=nullptr){
        ct=new NhanVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.ct[i]->GetLoai()=="Lap trinh vien")
                ct[i]=new LapTrinhVien(*(LapTrinhVien*)other.ct[i]);
            else
                ct[i]=new KiemChungVien(*(KiemChungVien*)other.ct[i]);
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
                if(other.ct[i]->GetLoai()=="Lap trinh vien")
                    ct[i]=new LapTrinhVien(*(LapTrinhVien*)other.ct[i]);
                else
                    ct[i]=new KiemChungVien(*(KiemChungVien*)other.ct[i]);
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
            cout<<"Nhap loai (1: Lap trinh vien, 2: Kiem chung vien): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            ct[i]=new LapTrinhVien;
        else
            ct[i]=new KiemChungVien;
        ct[i]->Nhap();
    }
}
NhanVien* CongTy::Nhap1(){
    int loai;
    NhanVien* nv;
    do{
        cout<<"Nhap loai (1: Lap trinh vien, 2: Kiem chung vien): ";
        cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai nhan vien khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1)
        nv=new LapTrinhVien;
    else
        nv=new KiemChungVien;
    nv->Nhap();
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
double CongTy::LuongTBCuaNhanVien(){
    double sum=0;
    int dem=0;
    for(int i=0; i<sl; i++){
        sum+=ct[i]->TinhLuong();
        dem++;
    }
    return dem>0?sum/dem:0;
}
void CongTy::NVCoLuongThapHonTB(){
    double tb=LuongTBCuaNhanVien();
    int cnt=0;
    cout<<"\n=====NHAN VIEN CO LUONG THAP HON TRUNG BINH ("<<fixed<<setprecision(2)<<tb<<")=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()<tb){
            cout<<"---NHAN VIEN THU "<<cnt+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong co nhan vien nao co luong thap hon trung binh!"<<endl;
}
void CongTy::NVCaoNhatLuong(){
    double maxLuong=-1;
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()>maxLuong)
            maxLuong=ct[i]->TinhLuong();
    if(maxLuong==-1){
        cout<<"Cong ty khong co nhan vien"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN CO LUONG CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()==maxLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::NVThapNhatLuong(){
    double minLuong=1e9;
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()<minLuong)
            minLuong=ct[i]->TinhLuong();
    if(minLuong==1e9){
        cout<<"Cong ty khong co nhan vien"<<endl;
        return;
    }
    cout<<"\n=====NHAN VIEN CO LUONG THAP NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->TinhLuong()==minLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::LTVCaoNhatLuong(){
    double maxLuong=-1;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Lap trinh vien"&&ct[i]->TinhLuong()>maxLuong)
            maxLuong=ct[i]->TinhLuong();
    if(maxLuong==-1){
        cout<<"Cong ty khong co lap trinh vien"<<endl;
        return;
    }
    cout<<"\n=====LAP TRINH VIEN CO LUONG CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Lap trinh vien"&&ct[i]->TinhLuong()==maxLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
void CongTy::KCVCaoNhatLuong(){
    double minLuong=1e9;
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Kiem chung vien"&&ct[i]->TinhLuong()<minLuong)
            minLuong=ct[i]->TinhLuong();
    if(minLuong==1e9){
        cout<<"Cong ty khong co kiem chung vien"<<endl;
        return;
    }
    cout<<"\n=====KIEM CHUNG VIEN CO LUONG THAP NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(ct[i]->GetLoai()=="Kiem chung vien"&&ct[i]->TinhLuong()==minLuong){
            cout<<"---NHAN VIEN THU "<<i+1<<"---"<<endl;
            ct[i]->Xuat();
            cout<<endl;
        }
}
int main(){
    CongTy ct;
    cout<<"===== CHUONG TRINH QUAN LY CONG TY HOAN CAU =====\n\n";
    cout<<"1. Nhap danh sach nhan vien:\n";
    ct.Nhap();
    cout<<"Danh sach vua nhap:\n"; ct.Xuat();
    cout<<"\n2. Nhan vien co luong thap hon trung binh:\n";
    ct.NVCoLuongThapHonTB();
    cout<<"\n3. Nhan vien co luong cao nhat:\n";
    ct.NVCaoNhatLuong();
    cout<<"\n4. Nhan vien co luong thap nhat:\n";
    ct.NVThapNhatLuong();
    cout<<"\n5. Lap trinh vien co luong cao nhat:\n";
    ct.LTVCaoNhatLuong();
    cout<<"\n6. Kiem chung vien co luong thap nhat:\n";
    ct.KCVCaoNhatLuong();
    cout<<"\n7. Thong ke:\n";
    cout<<"So luong nhan vien: "<<NhanVien::GetDem()<<endl;
    cout<<"So luong lap trinh vien: "<<LapTrinhVien::GetDem()<<endl;
    cout<<"So luong kiem chung vien: "<<KiemChungVien::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}