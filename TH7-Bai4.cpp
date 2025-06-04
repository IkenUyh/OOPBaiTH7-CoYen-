#pragma once
#ifndef GIAODICH_H
#define GIAODICH_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class GiaoDich{
protected:
    string MaGD;
    string NgayGD; 
    double DonGia;
    double DienTich;
    static int dem;
public:
    virtual ~GiaoDich();
    GiaoDich();
    GiaoDich(string, string, double, double);
    GiaoDich(const GiaoDich&);
    GiaoDich& operator=(const GiaoDich&);
    string GetMaGD();
    string GetNgayGD();
    double GetDonGia();
    double GetDienTich();
    static int GetDem();
    void SetMaGD(string);
    void SetNgayGD(string);
    void SetDonGia(double);
    void SetDienTich(double);
    virtual void Nhap();
    virtual void Xuat();
    virtual double ThanhTien()=0; 
};
#endif
int GiaoDich::dem=0;
GiaoDich::~GiaoDich(){
    --dem;
}
GiaoDich::GiaoDich():MaGD(""), NgayGD(""), DonGia(0), DienTich(0){
    ++dem;
}
GiaoDich::GiaoDich(string MaGD, string NgayGD, double DonGia, double DienTich) 
:MaGD(MaGD), NgayGD(NgayGD), DonGia(DonGia), DienTich(DienTich){
    ++dem;
}
GiaoDich::GiaoDich(const GiaoDich& gd) 
:MaGD(gd.MaGD), NgayGD(gd.NgayGD), DonGia(gd.DonGia), DienTich(gd.DienTich){
    ++dem;
}
GiaoDich& GiaoDich::operator=(const GiaoDich& gd){
    MaGD=gd.MaGD;
    NgayGD=gd.NgayGD;
    DonGia=gd.DonGia;
    DienTich=gd.DienTich;
    return *this;
}
string GiaoDich::GetMaGD(){ 
    return MaGD; 
}
string GiaoDich::GetNgayGD(){ 
    return NgayGD; 
}
double GiaoDich::GetDonGia(){ 
    return DonGia; 
}
double GiaoDich::GetDienTich(){ 
    return DienTich; 
}
int GiaoDich::GetDem(){ 
    return dem; 
}
void GiaoDich::SetMaGD(string MaGD){ 
    this->MaGD=MaGD; 
}
void GiaoDich::SetNgayGD(string NgayGD){ 
    this->NgayGD=NgayGD; 
}
void GiaoDich::SetDonGia(double DonGia){ 
    this->DonGia=DonGia; 
}
void GiaoDich::SetDienTich(double DienTich){ 
    this->DienTich=DienTich; 
}
void GiaoDich::Nhap(){
    cin.ignore();
    cout<<"Nhap ma giao dich: "; getline(cin, MaGD);
    cout<<"Nhap ngay giao dich (DD/MM/YYYY): "; getline(cin, NgayGD);
    cout<<"Nhap don gia: ";
    do{
        cin>>DonGia;
        if(DonGia<=0) cout<<"Don gia khong hop le! Nhap lai: ";
    }while(DonGia<=0);
    cout<<"Nhap dien tich: ";
    do{
        cin>>DienTich;
        if(DienTich<=0) cout<<"Dien tich khong hop le! Nhap lai: ";
    } while (DienTich<=0);
}
void GiaoDich::Xuat(){
    cout<<"Ma giao dich: "<<MaGD<<endl;
    cout<<"Ngay giao dich: "<<NgayGD<<endl;
    cout<<"Don gia: "<<fixed<<setprecision(2)<<DonGia<<endl;
    cout<<"Dien tich: "<<DienTich<<endl;
}
#ifndef GIAODICHCHUNGCU_H
#define GIAODICHCHUNGCU_H
class GiaoDichChungCu:public GiaoDich{
private:
    string MaCan;
    int ViTriTang;
    static int dem;
public:
    ~GiaoDichChungCu();
    GiaoDichChungCu();
    GiaoDichChungCu(string, string, double, double, string, int);
    GiaoDichChungCu(const GiaoDichChungCu&);
    GiaoDichChungCu& operator=(const GiaoDichChungCu&);
    string GetMaCan();
    int GetViTriTang();
    static int GetDem(); 
    void SetMaCan(string);
    void SetViTriTang(int);
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif
int GiaoDichChungCu::dem=0;
GiaoDichChungCu::~GiaoDichChungCu(){ 
    --dem; 
}
GiaoDichChungCu::GiaoDichChungCu():GiaoDich(), MaCan(""), ViTriTang(0){ 
    +dem; 
}
GiaoDichChungCu::GiaoDichChungCu(string MaGD, string NgayGD, double DonGia, double DienTich, string MaCan, int ViTriTang)
:GiaoDich(MaGD, NgayGD, DonGia, DienTich), MaCan(MaCan), ViTriTang(ViTriTang){ 
    ++dem; 
}
GiaoDichChungCu::GiaoDichChungCu(const GiaoDichChungCu& gdcc) 
:GiaoDich(gdcc), MaCan(gdcc.MaCan), ViTriTang(gdcc.ViTriTang){ 
    ++dem; 
}
GiaoDichChungCu& GiaoDichChungCu::operator=(const GiaoDichChungCu& gdcc){
    GiaoDich::operator=(gdcc);
    MaCan=gdcc.MaCan;
    ViTriTang=gdcc.ViTriTang;
    return *this;
}
string GiaoDichChungCu::GetMaCan(){ 
    return MaCan; 
}
int GiaoDichChungCu::GetViTriTang(){ 
    return ViTriTang; 
}
int GiaoDichChungCu::GetDem(){ 
    return dem; 
} 
void GiaoDichChungCu::SetMaCan(string MaCan){ 
    this->MaCan = MaCan; 
}
void GiaoDichChungCu::SetViTriTang(int ViTriTang){ 
    this->ViTriTang = ViTriTang; 
}
void GiaoDichChungCu::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout<<"Nhap ma can: "; getline(cin, MaCan);
    cout<<"Nhap vi tri tang: ";
    do{
        cin>>ViTriTang;
        if(ViTriTang<=0) cout<<"Vi tri tang khong hop le! Nhap lai: ";
    } while (ViTriTang<=0);
}
void GiaoDichChungCu::Xuat(){
    GiaoDich::Xuat();
    cout<<"Ma can: "<<MaCan<<endl;
    cout<<"Vi tri tang: "<<ViTriTang<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}
double GiaoDichChungCu::ThanhTien(){
    if (ViTriTang==1) return GetDienTich()*GetDonGia()*2;
    if (ViTriTang>=15) return GetDienTich()*GetDonGia()*1.2;
    return GetDienTich()*GetDonGia();
}
#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H
class GiaoDichDat:public GiaoDich{
private:
    string LoaiDat;
    static int dem;
public:
    ~GiaoDichDat();
    GiaoDichDat();
    GiaoDichDat(string, string, double, double, string);
    GiaoDichDat(const GiaoDichDat&);
    GiaoDichDat& operator=(const GiaoDichDat&);
    string GetLoaiDat();
    static int GetDem();
    void SetLoaiDat(string);
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif
int GiaoDichDat::dem=0;
GiaoDichDat::~GiaoDichDat(){ 
    --dem; 
}
GiaoDichDat::GiaoDichDat():GiaoDich(), LoaiDat(""){ 
    ++dem; 
}
GiaoDichDat::GiaoDichDat(string MaGD, string NgayGD, double DonGia, double DienTich, string LoaiDat)
:GiaoDich(MaGD, NgayGD, DonGia, DienTich), LoaiDat(LoaiDat){ 
    ++dem; 
}
GiaoDichDat::GiaoDichDat(const GiaoDichDat& gdd) 
:GiaoDich(gdd), LoaiDat(gdd.LoaiDat){ 
    ++dem; 
}
GiaoDichDat& GiaoDichDat::operator=(const GiaoDichDat& gdd){
    GiaoDich::operator=(gdd);
    LoaiDat=gdd.LoaiDat;
    return *this;
}
string GiaoDichDat::GetLoaiDat(){ 
    return LoaiDat; 
}
int GiaoDichDat::GetDem(){ 
    return dem; 
} 
void GiaoDichDat::SetLoaiDat(string LoaiDat){ 
    this->LoaiDat=LoaiDat; 
}
void GiaoDichDat::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout<<"Nhap loai dat (A/B/C): ";
    do{
        getline(cin, LoaiDat);
        if(LoaiDat!="A"&&LoaiDat!="B"&&LoaiDat!="C")
            cout<<"Loai dat khong hop le! Nhap lai (A/B/C): ";
    }while(LoaiDat!="A"&&LoaiDat!="B"&&LoaiDat != "C");
}
void GiaoDichDat::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai dat: "<<LoaiDat<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}
double GiaoDichDat::ThanhTien(){
    if(LoaiDat=="A") return GetDienTich()*GetDonGia()*1.5;
    return GetDienTich()*GetDonGia();
}
#ifndef GIAODICHNHA_H
#define GIAODICHNHA_H
class GiaoDichNha:public GiaoDich{
private:
    string LoaiNha;
    string DiaChi;
    static int dem;
public:
    ~GiaoDichNha();
    GiaoDichNha();
    GiaoDichNha(string, string, double, double, string, string);
    GiaoDichNha(const GiaoDichNha&);
    GiaoDichNha& operator=(const GiaoDichNha&);
    string GetLoaiNha();
    string GetDiaChi();
    static int GetDem(); 
    void SetLoaiNha(string);
    void SetDiaChi(string);
    void Nhap();
    void Xuat();
    double ThanhTien();
};
#endif
int GiaoDichNha::dem=0;
GiaoDichNha::~GiaoDichNha(){ 
    --dem; 
}
GiaoDichNha::GiaoDichNha():GiaoDich(), LoaiNha(""), DiaChi(""){ 
    ++dem; 
}
GiaoDichNha::GiaoDichNha(string MaGD, string NgayGD, double DonGia, double DienTich, string LoaiNha, string DiaChi)
:GiaoDich(MaGD, NgayGD, DonGia, DienTich), LoaiNha(LoaiNha), DiaChi(DiaChi){ 
    ++dem; 
}
GiaoDichNha::GiaoDichNha(const GiaoDichNha& gdn):GiaoDich(gdn), LoaiNha(gdn.LoaiNha), DiaChi(gdn.DiaChi){ 
    ++dem; 
}
GiaoDichNha& GiaoDichNha::operator=(const GiaoDichNha& gdn){
    GiaoDich::operator=(gdn);
    LoaiNha=gdn.LoaiNha;
    DiaChi=gdn.DiaChi;
    return *this;
}
string GiaoDichNha::GetLoaiNha(){ 
    return LoaiNha; 
}
string GiaoDichNha::GetDiaChi(){ 
    return DiaChi; 
}
int GiaoDichNha::GetDem(){ 
    return dem; 
} 
void GiaoDichNha::SetLoaiNha(string LoaiNha){ 
    this->LoaiNha=LoaiNha; 
}
void GiaoDichNha::SetDiaChi(string DiaChi){ 
    this->DiaChi=DiaChi; 
}
void GiaoDichNha::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout<<"Nhap loai nha (cao cap/thuong): ";
    do{
        getline(cin, LoaiNha);
        if(LoaiNha!="cao cap"&&LoaiNha!="thuong")
            cout<<"Loai nha khong hop le! Nhap lai (cao cap/thuong): ";
    }while(LoaiNha!="cao cap"&&LoaiNha!="thuong");
    cout<<"Nhap dia chi: ";
    getline(cin, DiaChi);
}
void GiaoDichNha::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai nha: "<<LoaiNha<<endl;
    cout<<"Dia chi: "<<DiaChi<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}
double GiaoDichNha::ThanhTien() {
    if(LoaiNha=="thuong") return GetDienTich()*GetDonGia()*0.9;
    return GetDienTich()*GetDonGia();
}
int main(){
    vector<GiaoDichDat> dsDat; vector<GiaoDichNha> dsNha; vector<GiaoDichChungCu> dsChungCu;
    int choice;
    cout<<"===== CHUONG TRINH QUAN LY GIAO DICH BAT DONG SAN VAKALAND =====\n\n";
    do{
        cout<<"\n========== MENU CHINH ==========\n";
        cout<<"1. Nhap giao dich Dat\n";
        cout<<"2. Nhap giao dich Nha pho\n";
        cout<<"3. Nhap giao dich Chung cu\n";
        cout<<"4. Tong so luong tung loai\n";
        cout<<"5. TB thanh tien Chung cu\n";
        cout<<"6. Nha pho co GT cao nhat\n";
        cout<<"7. Giao dich 12/2024\n";
        cout<<"8. Xuat tat ca\n";
        cout<<"0. Thoat\n";
        cout<<"Nhap lua chon: ";
        cin>>choice;
        switch(choice){
            case 1:{
                int n; cout<<"Nhap so luong GD Dat: "; cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"-- GD Dat "<<(i+1)<<":\n";
                    GiaoDichDat gd;gd.Nhap();
                    dsDat.push_back(gd);
                }
                cout<<"Da nhap "<<n<<" giao dich dat!\n"; 
                break;
            }
            case 2:{
                int n; cout<<"Nhap so luong GD Nha pho: "; cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"-- GD Nha pho "<<(i+1)<<":\n";
                    GiaoDichNha gn;gn.Nhap();
                    dsNha.push_back(gn);
                }
                cout<<"Da nhap "<<n<<" giao dich nha pho!\n"; 
                break;
            }
            case 3:{
                int n; cout<<"Nhap so luong GD Chung cu: "; cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"-- GD Chung cu "<<(i+1)<<":\n";
                    GiaoDichChungCu gcc;gcc.Nhap();
                    dsChungCu.push_back(gcc);
                }
                cout<<"Da nhap "<<n<<" giao dich can ho!\n"; 
                break;
            }
            case 4:{
                cout<<"So GD Dat: "<<GiaoDichDat::GetDem()
                <<"\nSo GD Nha: "<<GiaoDichNha::GetDem()
                <<"\nSo GD Chung cu: "<<GiaoDichChungCu::GetDem()
                <<"\nTong: "<<GiaoDich::GetDem()<<endl;
                break;
            }
            case 5:{
                if(dsChungCu.empty()) cout<<"Danh sach trong!\n";
                else{
                    double total=0;
                    for(auto& gcc:dsChungCu) total+=gcc.ThanhTien();
                    cout<<"TB thanh tien: "<<fixed<<setprecision(2)
                    <<total/dsChungCu.size()<<endl;
                } 
                break;
            }
            case 6:{
                if(dsNha.empty()) cout<<"Danh sach trong!\n";
                else{
                    int maxI=0; double maxTT=dsNha[0].ThanhTien();
                    for(int i=1;i<dsNha.size();i++)
                        if(dsNha[i].ThanhTien()>maxTT){
                            maxTT=dsNha[i].ThanhTien(); maxI=i;
                        }
                    cout<<"-- GD Nha pho cao nhat:\n"; 
                    dsNha[maxI].Xuat();
                } 
                break;
            }
            case 7:{
                bool found=0;
                cout<<"-- GD Dat:\n";
                for(int i=0;i<dsDat.size();i++)
                    if(dsDat[i].GetNgayGD().substr(3)=="12/2024"){
                        cout<<"GD "<<(i+1)<<":\n";
                        dsDat[i].Xuat();
                        found=1;
                    }
                cout<<"-- GD Nha:\n";
                for(int i=0;i<dsNha.size();i++)
                    if(dsNha[i].GetNgayGD().substr(3)=="12/2024"){
                        cout<<"GD "<<(i+1)<<":\n";
                        dsNha[i].Xuat();found=1;
                    }
                cout<<"-- GD Chung cu:\n";
                for(int i=0;i<dsChungCu.size();i++)
                    if(dsChungCu[i].GetNgayGD().substr(3)=="12/2024"){
                        cout<<"GD "<<(i+1)<<":\n";
                        dsChungCu[i].Xuat();
                        found=1;
                    }
                if(!found) cout<<"Khong co GD nao thang 12/2024!\n";
                break;
            }
            case 8:{
                if(dsDat.empty()&&dsNha.empty()&&dsChungCu.empty()) 
                    cout<<"Chua co giao dich nao!\n";
                else{
                    if(!dsDat.empty()){
                        cout<<"-- GD Dat:\n";
                        for(int i=0;i<dsDat.size();i++){
                            cout<<"GD "<<(i+1)<<":\n";
                            dsDat[i].Xuat();
                        }
                    }
                    if(!dsNha.empty()){
                        cout<<"-- GD Nha pho:\n";
                        for(int i=0;i<dsNha.size();i++){
                            cout<<"GD "<<(i+1)<<":\n";
                            dsNha[i].Xuat();
                        }
                    }
                    if(!dsChungCu.empty()){
                        cout<<"-- GD Chung cu:\n";
                        for(int i=0;i<dsChungCu.size();i++){
                            cout<<"GD "<<(i+1)<<":\n";
                            dsChungCu[i].Xuat();
                        }
                    }
                } 
                break;
            }
            case 0: 
                cout<<"Cam on da su dung chuong trinh!\n"; 
                break;
            default: cout<<"Lua chon khong hop le!\n";
        }
    }while(choice!=0);
    return 0;
}