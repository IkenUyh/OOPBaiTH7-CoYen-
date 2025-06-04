#include<iostream>
#include<iomanip>
using namespace std;
#pragma once
#ifndef SINHVIEN_H
#define SINHVIEN_H
class SinhVien{
    protected:
        string mssv;
        string hoten;
        string khoa;
        double dtb;
        static int dem;
    public:
        virtual ~SinhVien();
        SinhVien();
        SinhVien(string, string, string, double);
        SinhVien(const SinhVien&);
        SinhVien& operator=(const SinhVien&);
        string GetMSSV();
        string GetHoTen();
        string GetKhoa();
        double GetDTB();
        static int GetDem();
        void SetHoTen(string);
        void SetKhoa(string);
        void SetDTB(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        virtual long NhanHocBong()=0;
};
#endif
int SinhVien::dem=0;
SinhVien::~SinhVien(){
    cout<<"Da huy mot sinh vien"<<endl;
    --dem;
}
SinhVien::SinhVien():mssv(""), hoten(""), khoa(""), dtb(0){
    ++dem;
}
SinhVien::SinhVien(string mssv, string hoten, string khoa, double dtb):mssv(mssv), hoten(hoten), khoa(khoa), dtb(dtb){
    ++dem;
}
SinhVien::SinhVien(const SinhVien& sv){
    this->mssv=sv.mssv;
    this->hoten=sv.hoten;
    this->khoa=sv.khoa;
    this->dtb=sv.dtb;
    ++dem;
}
SinhVien& SinhVien::operator=(const SinhVien& sv){
    this->mssv=sv.mssv;
    this->hoten=sv.hoten;
    this->khoa=sv.khoa;
    this->dtb=sv.dtb;
    return *this;
}
string SinhVien::GetMSSV(){
    return this->mssv;
}
string SinhVien::GetHoTen(){
    return this->hoten;
}
string SinhVien::GetKhoa(){
    return this->khoa;
}
double SinhVien::GetDTB(){
    return this->dtb;
}
int SinhVien::GetDem(){
    return dem;
}
void SinhVien::SetHoTen(string hoten){
    this->hoten=hoten;
}
void SinhVien::SetKhoa(string khoa){
    this->khoa=khoa;
}
void SinhVien::SetDTB(double dtb){
    while(dtb<0){
        cout<<"Diem trung binh khong hop le! Moi ban nhap lai: ";
        cin>>dtb;
    }
    this->dtb=dtb;
}
void SinhVien::Nhap(){
    cin.ignore();
    cout<<"Nhap ma so sinh vien: "; getline(cin, mssv);
    cout<<"Nhap ho ten sinh vien: "; getline(cin, hoten);
    cout<<"Nhap ten khoa: "; getline(cin, khoa);
    do{
        cout<<"Nhap diem trung binh: "; cin>>dtb;
        if(dtb<0) cout<<"Diem trung binh khong hop le! Moi ban nhap lai"<<endl;
    }while(dtb<0);
}
void SinhVien::Xuat(){
    cout<<"Ma so sinh vien: "<<mssv<<endl;
    cout<<"Ho ten sinh vien: "<<hoten<<endl;
    cout<<"Khoa: "<<khoa<<endl;
    cout<<"Diem trung binh: "<<fixed<<setprecision(2)<<dtb<<endl;
    cout<<"Loai: "<<GetLoai()<<endl;
    cout<<"Nhan hoc bong: "<<fixed<<setprecision(2)<<NhanHocBong()<<endl;
}
#pragma once
#ifndef CHINHQUY_H
#define CHINHQUY_H
class ChinhQuy : public SinhVien{
    private:
        int drl;
        static int dem;
    public: 
        ~ChinhQuy();
        ChinhQuy();
        ChinhQuy(string, string, string, double, int);
        ChinhQuy(const ChinhQuy&);
        ChinhQuy& operator=(const ChinhQuy&);
        int GetDRL();
        static int GetDem();
        void SetDRL(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        long NhanHocBong();
};
#endif
int ChinhQuy::dem=0;
ChinhQuy::~ChinhQuy(){
    cout<<"Da huy mot sinh vien chinh quy"<<endl;
    --dem;
}
ChinhQuy::ChinhQuy():SinhVien(), drl(0){
    ++dem;
}
ChinhQuy::ChinhQuy(string mssv, string hoten, string khoa, double dtb, int drl):SinhVien(mssv, hoten, khoa, dtb), drl(drl){
    ++dem;
}
ChinhQuy::ChinhQuy(const ChinhQuy& cq):SinhVien(cq){
    this->drl=cq.drl;
    ++dem;
}
ChinhQuy& ChinhQuy::operator=(const ChinhQuy& cq){
    SinhVien::operator=(cq);
    this->drl=cq.drl;
    return *this;
}
int ChinhQuy::GetDRL(){
    return this->drl;
}
int ChinhQuy::GetDem(){
    return dem;
}
void ChinhQuy::SetDRL(int drl){
    while(drl<0){
        cout<<"Diem ren luyen khong hop le! Moi ban nhap lai: ";
        cin>>drl;
    }
    this->drl=drl;
}
void ChinhQuy::Nhap(){
    SinhVien::Nhap();
    do{
        cout<<"Nhap diem ren luyen: "; cin>>drl;
        if(drl<0) cout<<"Diem ren luyen khong hop le! Moi ban nhap lai"<<endl;
    }while(drl<0);
}
void ChinhQuy::Xuat(){
    SinhVien::Xuat();
    cout<<"Diem ren luyen: "<<drl<<endl;
}
string ChinhQuy::GetLoai(){
    return "Sinh vien chinh quy";
}
long ChinhQuy::NhanHocBong(){
    long thuong=0;
    if(drl>=85){
        if(dtb>=9.5) thuong=1500000;
        else if(dtb>=8.5) thuong=1200000;
        else if(dtb>=7.5) thuong=1000000;
    }
    return thuong;
}
#pragma once
#ifndef LIENTHONG_H
#define LIENTHONG_H
class LienThong : public SinhVien{
    private:
        int sbv;
        static int dem;
    public:
        ~LienThong();
        LienThong();
        LienThong(string, string, string, double, int);
        LienThong(const LienThong&);
        LienThong& operator=(const LienThong&);
        int GetSBV();
        static int GetDem();
        void SetSBV(int);
        void Nhap();
        void Xuat();
        string GetLoai();
        long NhanHocBong();
};
#endif
int LienThong::dem=0;
LienThong::~LienThong(){
    cout<<"Da huy mot sinh vien lien thong "<<endl;
    --dem;
}
LienThong::LienThong():SinhVien(), sbv(0){
    ++dem;
}
LienThong::LienThong(string mssv, string hoten, string khoa, double dtb, int sbv):SinhVien(mssv, hoten, khoa, dtb), sbv(sbv){
    ++dem;
}
LienThong::LienThong(const LienThong& lt): SinhVien(lt){
    this->sbv=lt.sbv;
    ++dem;
}
LienThong& LienThong::operator=(const LienThong& lt){
    SinhVien::operator=(lt);
    this->sbv=lt.sbv;
    return *this;
}
int LienThong::GetSBV(){
    return this->sbv;
}
int LienThong::GetDem(){
    return dem;
}
void LienThong::SetSBV(int sbv){
    while(sbv<0){
        cout<<"So buoi vang khong hop le! Moi ban nhap lai: ";
        cin>>sbv;
    }
    this->sbv=sbv;
}
void LienThong::Nhap(){
    SinhVien::Nhap();
    do{
        cout<<"Nhap so buoi vang: "; cin>>sbv;
        if(sbv<0) cout<<"So buoi vang khong hop le! Moi ban nhap lai"<<endl;
    }while(sbv<0);
}
void LienThong::Xuat(){
    SinhVien::Xuat();
    cout<<"So buoi vang: "<<sbv<<endl;
}
string LienThong::GetLoai(){
    return "Sinh vien lien thong";
}
long LienThong::NhanHocBong(){
    long thuong=0;
    if(sbv<=3){
        if(dtb>=9) thuong=1500000;
        else if(dtb>=8) thuong=1200000;
        else if(dtb>=7) thuong=1000000;
    }
    return thuong;
}
#pragma once 
#ifndef TRUONGDH_H
#define TRUONGDH_H
class TruongDaiHoc{
    private:
        SinhVien** dh;
        int sl;
        static int dem;
    public:
        ~TruongDaiHoc();
        TruongDaiHoc();
        TruongDaiHoc(int);
        TruongDaiHoc(int, SinhVien**);
        TruongDaiHoc(const TruongDaiHoc&);
        TruongDaiHoc& operator=(const TruongDaiHoc&);
        int GetSL();
        static int GetDem();
        void SetSL();
        string DoiChuoiInHoa(string);
        string DoiChuoiInThuong(string);
        void Nhap();
        SinhVien* Nhap1();
        void Xuat();
        void SVCQCoDRL100();
        int DemSVLTDiHocDayDu();
        long TongHBCapChoSinhVien();
        double DTBCuaSinhVienCQDuocHB();
        bool KiemTraSVLTcoHBVaKhongVang();
        void TimSVCQcoDTBCaoNhat();
        void SapXepSVTangDanTheoMaSo();
        void ThemMotSinhVien(SinhVien*, int);
        int XoaMotSinhVien(string);
        void TimSinhVienTheoMaSo(string);
        void TimSinhVienTheoHoTen(string);
        void TimSinhVienTheoKhoa(string);
        void TimSinhVienTheoDTB(double);
        void TimSinhVienTheoHB(long);
};
#endif
int TruongDaiHoc::dem=0;
TruongDaiHoc::~TruongDaiHoc(){
    if(dh!=nullptr){
        for(int i=0; i<sl; i++)
            delete dh[i];
        delete[] dh;
        dh=nullptr;
        sl=0;
    }
    --dem;
}
TruongDaiHoc::TruongDaiHoc():sl(0), dh(nullptr){
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(int sl): sl(sl), dh(nullptr){
    if(sl>0){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++)
            dh[i]=nullptr;
    }
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(int sl, SinhVien** hs): sl(sl), dh(nullptr){
    if(sl>0&&hs!=nullptr){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++){
            if(hs[i]->GetLoai()=="Sinh vien chinh quy")
                dh[i]=new ChinhQuy(*(ChinhQuy*)hs[i]);
            else
                dh[i]=new LienThong(*(LienThong*)hs[i]);
        }
    }
    ++dem;
}
TruongDaiHoc::TruongDaiHoc(const TruongDaiHoc& other): sl(other.sl), dh(nullptr){
    if(sl>0&&other.dh!=nullptr){
        dh=new SinhVien*[sl];
        for(int i=0; i<sl; i++){
            if(other.dh[i]->GetLoai()=="Sinh vien chinh quy")
                dh[i]=new ChinhQuy(*(ChinhQuy*)other.dh[i]);
            else 
                dh[i]=new LienThong(*(LienThong*)other.dh[i]);
        }
    }
    ++dem;
}
TruongDaiHoc& TruongDaiHoc::operator=(const TruongDaiHoc& other){
    if(this!=&other){
        if(dh!=nullptr){
            for(int i=0; i<sl; i++)
                delete dh[i];
            delete[] dh;
        }
        sl=other.sl;
        if(sl>0&&other.dh!=nullptr){
            dh=new SinhVien*[sl];
            for(int i=0; i<sl; i++){
                if(other.dh[i]->GetLoai()=="Sinh vien chinh quy")
                    dh[i]=new ChinhQuy(*(ChinhQuy*)other.dh[i]);
                else 
                    dh[i]=new LienThong(*(LienThong*)other.dh[i]);
            }
        }
        else dh=nullptr;
    }
    return *this;
}
int TruongDaiHoc::GetSL(){
    return this->sl;
}
int TruongDaiHoc::GetDem(){
    return dem;
}
void TruongDaiHoc::SetSL(){
    while(sl<1){
        cout<<"So luong khong hop le! Moi ban nhap lai: ";
        cin>>sl;
    }
    this->sl=sl;
}
void TruongDaiHoc::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong sinh vien: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(sl<1);
    dh=new SinhVien*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n===========================\n";
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Sinh vien chinh quy, 2: Sinh vien lien thong): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai sinh vien khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            dh[i]=new ChinhQuy;
        else 
            dh[i]=new LienThong;
        dh[i]->Nhap();
    }
}
SinhVien* TruongDaiHoc::Nhap1(){
    int loai;
    SinhVien* hs;
    do{
        cout<<"Nhap loai (1: Sinh vien chinh quy, 2: Sinh vien lien thong): ";
        cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai sinh vien khong hop le! Moi ban nhap lai"<<endl; 
    }while(loai!=1&&loai!=2);
    if(loai==1)
        hs=new ChinhQuy;
    else
        hs=new LienThong;
    hs->Nhap();
    return hs; 
}
void TruongDaiHoc::Xuat(){
    if(dh==nullptr) cout<<"Danh sach sinh vien rong"<<endl;
    else{
        cout<<"\n=====THONG TIN SINH VIEN======\n";
        for(int i=0; i<sl; i++){
            cout<<"---SINH VIEN THU "<<i+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
        }
    }
}
void TruongDaiHoc::SVCQCoDRL100(){
    int cnt=0;
    cout<<"\n=====SINH VIEN CHINH QUY CO DIEM REN LUYEN 100=====\n";
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien chinh quy"&&((ChinhQuy*)dh[i])->GetDRL()==100){
            cout<<"---SINH VIEN THU "<<i+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong co sinh vien chinh quy nao dat duoc 100 diem ren luyen!"<<endl;
}
int TruongDaiHoc::DemSVLTDiHocDayDu(){
    int cnt=0;
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien lien thong"&&((LienThong*)dh[i])->GetSBV()==0)
            cnt++;
    return cnt;
}
long TruongDaiHoc::TongHBCapChoSinhVien(){
    long sum=0;
    for(int i=0; i<sl; i++)
        sum+=dh[i]->NhanHocBong();
    return sum;
}
double TruongDaiHoc::DTBCuaSinhVienCQDuocHB(){
    double sum=0;
    int cnt=0;
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien chinh quy"&&dh[i]->NhanHocBong()>0){
            sum+=dh[i]->GetDTB();
            cnt++;
        }
    return cnt>0?sum/cnt:0;
}
bool TruongDaiHoc::KiemTraSVLTcoHBVaKhongVang(){
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien lien thong"&&((LienThong*)dh[i])->GetSBV()==0&&dh[i]->NhanHocBong()>0){
            return true;
        }
    return false;
}
void TruongDaiHoc::TimSVCQcoDTBCaoNhat(){
    double maxDTB=-1;
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien chinh quy"&&dh[i]->GetDTB()>maxDTB)
            maxDTB=dh[i]->GetDTB();
    if(maxDTB==-1) {
        cout<<"Truong khong co sinh vien chinh quy"<<endl;
        return;
    }
    cout<<"\n=====SINH VIEN CHINH QUY CO DIEM TRUNG BINH CAO NHAT=====\n";
    for(int i=0; i<sl; i++)
        if(dh[i]->GetLoai()=="Sinh vien chinh quy"&&dh[i]->GetDTB()==maxDTB){
            cout<<"---SINH VIEN THU "<<i+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
        }
}
string TruongDaiHoc::DoiChuoiInHoa(string s){
    for(int i=0; i<s.size(); i++)
        s[i]=toupper(s[i]);
    return s;
}
string TruongDaiHoc::DoiChuoiInThuong(string s){
    for(int i=0; i<s.size(); i++)
        s[i]=tolower(s[i]);
    return s;
}
void TruongDaiHoc::SapXepSVTangDanTheoMaSo(){
    for(int i=0; i<sl-1; i++)
        for(int j=0; j<sl-i-1; j++)
            if(DoiChuoiInHoa(dh[j]->GetMSSV())>DoiChuoiInHoa(dh[j+1]->GetMSSV())){
                SinhVien* temp=dh[j];
                dh[j]=dh[j+1];
                dh[j+1]=temp;
            }
}
void TruongDaiHoc::ThemMotSinhVien(SinhVien* hs, int vt){
    if(vt<1 || vt>sl+1){
        cout<<"Vi tri khong hop le!"<<endl;
        return;
    }
    SinhVien** dhnew=new SinhVien*[sl+1];
    for(int i=0; i<vt-1; i++)
        dhnew[i]=dh[i];
    dhnew[vt-1]=hs;
    for(int i=vt; i<=sl; i++){
        dhnew[i]=dh[i-1];
    }
    delete[] dh;
    dh=dhnew;
    sl++;
}
int TruongDaiHoc::XoaMotSinhVien(string ms){
    int vt=-1;
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dh[i]->GetMSSV())==DoiChuoiInHoa(ms)){
            vt=i;
            break;
        }
    if(vt==-1){
        cout<<"Khong ton tai sinh vien voi ma so da cho"<<endl;
        return -1;
    }
    else{
        delete dh[vt];
        SinhVien** dhnew=new SinhVien*[sl-1];
        for(int i=0; i<vt; i++)
            dhnew[i]=dh[i];
        for(int i=vt+1; i<sl; i++)
            dhnew[i-1]=dh[i];
        delete[] dh;
        dh=dhnew;
        sl--;
        cout<<"Da xoa sinh vien co ma so: "<<ms<<endl;
    }
    return vt;
}
void TruongDaiHoc::TimSinhVienTheoMaSo(string ms){
    bool check=false;
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dh[i]->GetMSSV())==DoiChuoiInHoa(ms)){
            cout<<"---SINH VIEN TIM THAY---"<<endl;
            dh[i]->Xuat();
            check=true; break;
        }
    if(!check) cout<<"Khong ton tai ma so sinh vien da cho"<<endl;
}
void TruongDaiHoc::TimSinhVienTheoHoTen(string name){
    int cnt=0;
    cout<<"\n=====KET QUA TIM KIEM THEO HO TEN=====\n";
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dh[i]->GetHoTen())==DoiChuoiInHoa(name)){
            cout<<"---SINH VIEN THU "<<cnt+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong ton tai ho ten sinh vien da cho"<<endl;
}
void TruongDaiHoc::TimSinhVienTheoKhoa(string kh){
    int cnt=0;
    cout<<"\n=====KET QUA TIM KIEM THEO KHOA=====\n";
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dh[i]->GetKhoa())==DoiChuoiInHoa(kh)){
            cout<<"---SINH VIEN THU "<<cnt+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong ton tai sinh vien co khoa da cho"<<endl;
}
void TruongDaiHoc::TimSinhVienTheoDTB(double tb){
    int cnt=0;
    cout<<"\n=====KET QUA TIM KIEM THEO DIEM TRUNG BINH=====\n";
    for(int i=0; i<sl; i++)
        if(dh[i]->GetDTB()==tb){
            cout<<"---SINH VIEN THU "<<cnt+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong ton tai sinh vien co diem trung binh da cho"<<endl;
}
void TruongDaiHoc::TimSinhVienTheoHB(long hb){
    int cnt=0;
    cout<<"\n=====KET QUA TIM KIEM THEO HOC BONG=====\n";
    for(int i=0; i<sl; i++)
        if(dh[i]->NhanHocBong()==hb){
            cout<<"---SINH VIEN THU "<<cnt+1<<"---"<<endl;
            dh[i]->Xuat();
            cout<<endl;
            cnt++;
        }
    if(!cnt) cout<<"Khong ton tai sinh vien co hoc bong da cho"<<endl;
}
int main(){
    TruongDaiHoc dh;
    cout<<"===== CHUONG TRINH QUAN LY TRUONG DAI HOC =====\n\n";
    cout<<"1. Nhap danh sach sinh vien:\n";
    dh.Nhap();
    cout<<"Danh sach vua nhap:\n"; dh.Xuat();
    cout<<"\n2. Sinh vien chinh quy diem ren luyen 100:\n";
    dh.SVCQCoDRL100();
    cout<<"\n3. So sinh vien lien thong khong nghi buoi nao: "<<dh.DemSVLTDiHocDayDu()<<endl;
    cout<<"\n4. Tong hoc bong cap cho sinh vien: "<<fixed<<setprecision(2)<<dh.TongHBCapChoSinhVien()<<endl;
    cout<<"\n5. Diem trung binh sinh vien chinh quy duoc hoc bong: "<<fixed<<setprecision(2)<<dh.DTBCuaSinhVienCQDuocHB()<<endl;
    cout<<"\n6. Sinh vien lien thong co hoc bong va khong vang:\n";
    cout<<(dh.KiemTraSVLTcoHBVaKhongVang()?"Co":"Khong")<<endl;
    cout<<"\n7. Sinh vien chinh quy co diem trung binh cao nhat:\n";
    dh.TimSVCQcoDTBCaoNhat();
    cout<<"\n8. Sap xep sinh vien theo ma so:\n";
    dh.SapXepSVTangDanTheoMaSo();
    cout<<"Danh sach sau khi sap xep:\n"; dh.Xuat();
    cout<<"\n9. Them mot sinh vien:\n";
    SinhVien* sv=dh.Nhap1();
    int vt; cout<<"Vi tri them (1 -> "<<dh.GetSL()+1<<"): "; cin>>vt;
    dh.ThemMotSinhVien(sv, vt);
    cout<<"Danh sach sau khi them:\n"; dh.Xuat();
    string ms; cin.ignore();
    cout<<"\n10. Xoa sinh vien theo ma so:\n";
    cout<<"Nhap ma so: "; getline(cin, ms);
    dh.XoaMotSinhVien(ms);
    cout<<"Danh sach sau khi xoa:\n"; dh.Xuat();
    cout<<"\n11. Tim sinh vien theo ma so:\n";
    cout<<"Nhap ma so: "; getline(cin, ms);
    dh.TimSinhVienTheoMaSo(ms);
    string name;
    cout<<"\n12. Tim sinh vien theo ho ten:\n";
    cout<<"Nhap ho ten: "; getline(cin, name);
    dh.TimSinhVienTheoHoTen(name);
    string kh;
    cout<<"\n13. Tim sinh vien theo khoa:\n";
    cout<<"Nhap khoa: "; getline(cin, kh);
    dh.TimSinhVienTheoKhoa(kh);
    double dtb;
    cout<<"\n14. Tim sinh vien theo diem trung binh:\n";
    cout<<"Nhap diem trung binh: "; cin>>dtb;
    dh.TimSinhVienTheoDTB(dtb);
    long hb;
    cout<<"\n15. Tim sinh vien theo hoc bong:\n";
    cout<<"Nhap hoc bong: "; cin>>hb;
    dh.TimSinhVienTheoHB(hb);
    cout<<"\n16. Thong ke:\n";
    cout<<"So luong sinh vien: "<<SinhVien::GetDem()<<endl;
    cout<<"So luong sinh vien chinh quy: "<<ChinhQuy::GetDem()<<endl;
    cout<<"So luong sinh vien lien thong: "<<LienThong::GetDem()<<endl;
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}