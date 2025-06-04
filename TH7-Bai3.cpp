#pragma once
#ifndef GIAODICH_H
#define GIAODICH_H
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class GiaoDich{
    protected:
        string MaGD;
        string NgayGD;
        double DonGia;
        int SoLuong;
        static int dem;
    public:
        ~GiaoDich();
        GiaoDich();
        GiaoDich(string);
        GiaoDich(double);
        GiaoDich(int);
        GiaoDich(string, string);
        GiaoDich(string, string, double, int);
        GiaoDich(const GiaoDich&);
        GiaoDich& operator=(const GiaoDich&);
        string GetMaGD();
        string GetNgayGD();
        double GetDonGia();
        int GetSoLuong();
        static int GetDem();
        void SetMaGD(string);
        void SetNgayGD(string);
        void SetDonGia(double);
        void SetSoLuong(int);
        void Nhap();
        void Xuat();
        double ThanhTien();
};
#endif
int GiaoDich::dem=0;
GiaoDich::~GiaoDich(){
    --dem;
}
GiaoDich::GiaoDich():MaGD(""), NgayGD(""), DonGia(0), SoLuong(0){
    ++dem;
}
GiaoDich::GiaoDich(string MaGD):MaGD(MaGD), NgayGD(""), DonGia(0), SoLuong(0){
    ++dem;
}
GiaoDich::GiaoDich(string MaGD, string NgayGD):MaGD(MaGD), NgayGD(NgayGD), DonGia(0), SoLuong(0){
    ++dem;
}
GiaoDich::GiaoDich(double DonGia):MaGD(""), NgayGD(""), DonGia(DonGia), SoLuong(0){
    ++dem;
}
GiaoDich::GiaoDich(int SoLuong):MaGD(""), NgayGD(""), DonGia(0), SoLuong(SoLuong){
    ++dem;
}
GiaoDich::GiaoDich(string MaGD, string NgayGD, double DonGia, int SoLuong){
    this->MaGD=MaGD;
    this->NgayGD=NgayGD;
    this->DonGia=DonGia;
    this->SoLuong=SoLuong;
    ++dem;
}
GiaoDich::GiaoDich(const GiaoDich& gd){
    this->MaGD=gd.MaGD;
    this->NgayGD=gd.NgayGD;
    this->DonGia=gd.DonGia;
    this->SoLuong=gd.SoLuong;
    ++dem;
}
GiaoDich& GiaoDich::operator=(const GiaoDich& gd){
    this->MaGD=gd.MaGD;
    this->NgayGD=gd.NgayGD;
    this->DonGia=gd.DonGia;
    this->SoLuong=gd.SoLuong;
    return *this;
}
string GiaoDich::GetMaGD(){
    return this->MaGD;
}
string GiaoDich::GetNgayGD(){
    return this->NgayGD;
}
double GiaoDich::GetDonGia(){
    return this->DonGia;
}
int GiaoDich::GetSoLuong(){
    return this->SoLuong;
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
void GiaoDich::SetSoLuong(int SoLuong){
    this->SoLuong=SoLuong;
}
void GiaoDich::Nhap(){
    cin.ignore();
    cout<<"Nhap vao ma giao dich: "; getline(cin, MaGD);
    cout<<"Nhap vao ngay giao dich: "; getline(cin, NgayGD);
    cout<<"Nhap vao don gia can giao dich: "; 
    do{
        cin>>DonGia;
        if(DonGia<=0) cout<<"Don gia khong hop le! Moi ban nhap lai: ";
    }while(DonGia<=0);
    cout<<"Nhap vao so luong can giao dich: ";
    do{
        cin>>SoLuong;
        if(SoLuong<=0) cout<<"So luong khong hop le! Moi ban nhap lai: ";
    }while(SoLuong<=0);
}
void GiaoDich::Xuat(){
    cout<<"Ma giao dich: "<<MaGD<<endl;
    cout<<"Ngay giao dich: "<<NgayGD<<endl;
    cout<<"Don gia: "<<fixed<<setprecision(2)<<DonGia<<endl;
    cout<<"So luong: "<<SoLuong<<endl;
}
double GiaoDich::ThanhTien(){
    return SoLuong*DonGia;
}
#ifndef GIAODICHVANG_H
#define GIAODICHVANG_H
class GiaoDichVang : public GiaoDich{
    private:
        string LoaiVang;
        static int dem;
    public:
       ~GiaoDichVang();
       GiaoDichVang();
       GiaoDichVang(string);
       GiaoDichVang(string, string, double, int, string);
       GiaoDichVang(const GiaoDichVang&);
       GiaoDichVang& operator=(const GiaoDichVang&);
       string GetLoaiVang();
       static int GetDem();
       void SetLoaiVang(string);
       void Nhap();
       void Xuat();
       double ThanhTien();
};
#endif
int GiaoDichVang::dem=0;
GiaoDichVang::~GiaoDichVang(){
    --dem;
}
GiaoDichVang::GiaoDichVang(): GiaoDich(), LoaiVang(""){
    ++dem;
}
GiaoDichVang::GiaoDichVang(string LoaiVang): GiaoDich(), LoaiVang(LoaiVang){
    ++dem;
}
GiaoDichVang::GiaoDichVang(string MaGD, string NgayGD, double DonGia, int SoLuong, string LoaiVang)
:GiaoDich(MaGD, NgayGD, DonGia, SoLuong), LoaiVang(LoaiVang){
    ++dem;
}
GiaoDichVang::GiaoDichVang(const GiaoDichVang& gdv): GiaoDich(gdv), LoaiVang(gdv.LoaiVang){
    ++dem;
}
GiaoDichVang& GiaoDichVang::operator=(const GiaoDichVang& gdv){
    GiaoDich::operator=(gdv);
    this->LoaiVang=gdv.LoaiVang;
    return *this;
}
string GiaoDichVang::GetLoaiVang(){
    return this->LoaiVang;
}
int GiaoDichVang::GetDem(){
    return dem;
}
void GiaoDichVang::SetLoaiVang(string LoaiVang){
    this->LoaiVang=LoaiVang;
}
void GiaoDichVang::Nhap(){
    GiaoDich::Nhap();
    cout<<"Nhap vao loai vang can giao dich(9999/999/sjc): ";
    cin.ignore();
    do{
        getline(cin,LoaiVang);
        if(LoaiVang!="9999"&&LoaiVang!="999"&&LoaiVang!="sjc") 
            cout<<"Hien khong ho tro loai vang nay! Vui long nhap lai loai vang phu hop: "<<endl;
    }while(LoaiVang!="9999"&&LoaiVang!="999"&&LoaiVang!="sjc");
}
void GiaoDichVang::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai vang: "<<LoaiVang<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}
double GiaoDichVang::ThanhTien(){
    return GiaoDich::ThanhTien();
}
#ifndef GIAODICHTIEN_H
#define GIAODICHTIEN_H
class GiaoDichTien : public GiaoDich{
    private:
        string LoaiTien;
        double TyGia;
        static int dem;
    public:
       ~GiaoDichTien();
       GiaoDichTien();
       GiaoDichTien(string);
       GiaoDichTien(double);
       GiaoDichTien(string, double);
       GiaoDichTien(string, string, double, int, string, double);
       GiaoDichTien(const GiaoDichTien&);
       GiaoDichTien& operator=(const GiaoDichTien&);
       string GetLoaiTien();
       double GetTyGia();
       static int GetDem();
       void SetLoaiTien(string);
       void SetTyGia(double);
       void Nhap();
       void Xuat();
       double ThanhTien();
};
#endif
int GiaoDichTien::dem=0;
GiaoDichTien::~GiaoDichTien(){
    --dem;
}
GiaoDichTien::GiaoDichTien(): GiaoDich(), LoaiTien(""), TyGia(0){
    ++dem;
}
GiaoDichTien::GiaoDichTien(string LoaiTien): GiaoDich(), LoaiTien(LoaiTien), TyGia(0){
    ++dem;
}
GiaoDichTien::GiaoDichTien(double TyGia): GiaoDich(), LoaiTien(""), TyGia(TyGia){
    ++dem;
}
GiaoDichTien::GiaoDichTien(string LoaiTien, double TyGia): GiaoDich(), LoaiTien(LoaiTien), TyGia(TyGia){
    ++dem;
}
GiaoDichTien::GiaoDichTien(string MaGD, string NgayGD, double DonGia, int SoLuong, string LoaiTien, double TyGia)
:GiaoDich(MaGD, NgayGD, DonGia, SoLuong), LoaiTien(LoaiTien), TyGia(TyGia){
    ++dem;
}
GiaoDichTien::GiaoDichTien(const GiaoDichTien& gdt): GiaoDich(gdt), LoaiTien(gdt.LoaiTien), TyGia(gdt.TyGia){
    ++dem;
}
GiaoDichTien& GiaoDichTien::operator=(const GiaoDichTien& gdt){
    GiaoDich::operator=(gdt);
    this->LoaiTien=gdt.LoaiTien;
    this->TyGia=gdt.TyGia;
    return *this;
}
string GiaoDichTien::GetLoaiTien(){
    return this->LoaiTien;
}
double GiaoDichTien::GetTyGia(){
    return this->TyGia;
}
int GiaoDichTien::GetDem(){
    return dem;
}
void GiaoDichTien::SetLoaiTien(string LoaiTien){
    this->LoaiTien=LoaiTien;
}
void GiaoDichTien::SetTyGia(double TyGia){
    this->TyGia=TyGia;
}
void GiaoDichTien::Nhap(){
    GiaoDich::Nhap();
    cout<<"Nhap vao ty gia cua giao dich: ";
    do
    {
        cin>>TyGia;
        if(TyGia<=0) cout<<"Ty gia khong hop le! Vui long nhap lai: "<<endl;
    }while(TyGia<=0);
    cout<<"Nhap vao loai tien te can giao dich(Vnd/Usd/Euro): ";
    cin.ignore();
    do{
        getline(cin,LoaiTien);
        if(LoaiTien!="Vnd"&&LoaiTien!="Usd"&&LoaiTien!="Euro") 
            cout<<"Hien khong ho tro loai tien te nay! Vui long chon loai tien te phu hop: "<<endl;
    }while(LoaiTien!="Vnd"&&LoaiTien!="Usd"&&LoaiTien!="Euro");
}
void GiaoDichTien::Xuat(){
    GiaoDich::Xuat();
    cout<<"Loai tien te: "<<LoaiTien<<endl;
    cout<<"Ty gia: "<<TyGia<<endl;
    cout<<"Thanh tien: "<<fixed<<setprecision(2)<<ThanhTien()<<endl;
}
double GiaoDichTien::ThanhTien(){
    if(LoaiTien=="Usd"||LoaiTien=="Euro") return GiaoDich::ThanhTien()*TyGia;
    else if(LoaiTien=="Vnd") return GiaoDich::ThanhTien();
    return 0;
}
int main(){
    vector<GiaoDichVang> dsVang; vector<GiaoDichTien> dsTien; int choice;
    cout<<"===== CHUONG TRINH QUAN LY GIAO DICH CONG TY X =====\n\n";
    do{
        cout<<"\n========== MENU CHINH ==========\n";
        cout<<"1. Nhap danh sach giao dich vang\n2. Nhap danh sach giao dich ngoai te\n";
        cout<<"3. Tim giao dich vang co thanh tien cao nhat\n4. Tim giao dich Euro co gia tri thap nhat\n";
        cout<<"5. Xuat cac giao dich co thanh tien tren 1 ty dong\n6. Xuat tat ca giao dich vang\n";
        cout<<"7. Xuat tat ca giao dich tien te\n8. Thong ke so luong giao dich\n0. Thoat chuong trinh\n";
        cout<<"================================\nNhap lua chon cua ban: "; cin>>choice;
        switch(choice){
            case 1:{
                int n; cout<<"\n1. NHAP DANH SACH GIAO DICH VANG:\nNhap so luong: "; cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"\n--- Nhap thong tin giao dich vang thu "<<(i+1)<<" ---\n";
                    GiaoDichVang gv; gv.Nhap(); dsVang.push_back(gv);
                }
                cout<<"Da nhap thanh cong "<<n<<" giao dich vang!\n"; break;
            }
            case 2:{
                int n; cout<<"\n2. NHAP DANH SACH GIAO DICH NGOAI TE:\nNhap so luong: "; cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"\n--- Nhap thong tin giao dich ngoai te thu "<<(i+1)<<" ---\n";
                    GiaoDichTien gt; gt.Nhap(); dsTien.push_back(gt);
                }
                cout<<"Da nhap thanh cong "<<n<<" giao dich ngoai te!\n"; break;
            }
            case 3:{
                cout<<"\n3. GIAO DICH VANG CO THANH TIEN CAO NHAT:\n";
                if(dsVang.empty()) cout<<"Danh sach giao dich vang trong!\n";
                else{
                    int maxIndex=0; double maxTT=dsVang[0].ThanhTien();
                    for(int i=1;i<dsVang.size();i++) if(dsVang[i].ThanhTien()>maxTT){
                        maxTT=dsVang[i].ThanhTien(); maxIndex=i;
                    }
                    cout<<"--- Giao dich vang co thanh tien cao nhat ---\n"; dsVang[maxIndex].Xuat();
                }
                break;
            }
            case 4:{
                cout<<"\n4. GIAO DICH EURO CO GIA TRI THAP NHAT:\n";
                if(dsTien.empty()) cout<<"Danh sach giao dich ngoai te trong!\n";
                else{
                    int minIndex=-1; double minTT=0; bool found=false;
                    for(int i=0;i<dsTien.size();i++)
                        if(dsTien[i].GetLoaiTien()=="Euro")
                            if(!found||dsTien[i].ThanhTien()<minTT){
                                minTT=dsTien[i].ThanhTien(); minIndex=i; found=true;
                            }
                    if(found){ 
                        cout<<"--- Giao dich Euro co gia tri thap nhat ---\n"; dsTien[minIndex].Xuat(); 
                    }
                    else cout<<"Khong tim thay giao dich Euro nao!\n";
                }
                break;
            }
            case 5:{
                cout<<"\n5. CAC GIAO DICH CO THANH TIEN TREN 1 TY DONG:\n"; bool found=false;
                double billion=1e9;
                cout<<"--- Giao dich vang co thanh tien > 1 ty ---\n";
                for(int i=0;i<dsVang.size();i++) if(dsVang[i].ThanhTien()>billion){
                    cout<<"Giao dich vang "<<(i+1)<<":\n"; dsVang[i].Xuat(); 
                    cout<<"------------------------\n"; found=true;
                }
                cout<<"\n--- Giao dich ngoai te co thanh tien > 1 ty ---\n";
                for(int i=0;i<dsTien.size();i++) if(dsTien[i].ThanhTien()>billion){
                    cout<<"Giao dich ngoai te "<<(i+1)<<":\n"; dsTien[i].Xuat(); 
                    cout<<"------------------------\n"; found=true;
                }
                if(!found) cout<<"Khong co giao dich nao co thanh tien tren 1 ty dong!\n";
                break;
            }
            case 6:{
                cout<<"\n6. DANH SACH TAT CA GIAO DICH VANG:\n";
                if(dsVang.empty()) cout<<"Danh sach giao dich vang trong!\n";
                else for(int i=0;i<dsVang.size();i++){
                    cout<<"--- Giao dich vang "<<(i+1)<<" ---\n"; dsVang[i].Xuat(); 
                    cout<<"------------------------\n";
                }
                break;
            }
            case 7:{
                cout<<"\n7. DANH SACH TAT CA GIAO DICH TIEN TE:\n";
                if(dsTien.empty()) cout<<"Danh sach giao dich ngoai te trong!\n";
                else for(int i=0;i<dsTien.size();i++){
                    cout<<"--- Giao dich ngoai te "<<(i+1)<<" ---\n"; dsTien[i].Xuat(); 
                    cout<<"------------------------\n";
                }
                break;
            }
            case 8:{
                cout<<"\n8. THONG KE SO LUONG GIAO DICH:\n";
                cout<<"- So luong giao dich vang: "<<dsVang.size()<<endl;
                cout<<"- So luong giao dich ngoai te: "<<dsTien.size()<<endl;
                cout<<"- Tong so giao dich: "<<(dsVang.size()+dsTien.size())<<endl;
                cout<<"- So luong doi tuong GiaoDich: "<<GiaoDich::GetDem()<<endl;
                cout<<"- So luong doi tuong GiaoDichVang: "<<GiaoDichVang::GetDem()<<endl;
                cout<<"- So luong doi tuong GiaoDichTien: "<<GiaoDichTien::GetDem()<<endl;
                break;
            }
            case 0: cout<<"\n=== CAM ON BAN DA SU DUNG CHUONG TRINH ===\n"; break;
            default: cout<<"Lua chon khong hop le! Vui long chon lai.\n";
        }
    }while(choice!=0);
    return 0;
}