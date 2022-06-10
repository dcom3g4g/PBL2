#include<iostream>
#include"QLHV.h"
#include<fstream>
#include<iomanip>
using namespace std ; 
QLHV::QLHV()
{
    n=0; 
}
QLHV::~QLHV() 
{
        delete[] p ; 
}
void QLHV::ISfromfile() 
{
    ifstream hv("D:\\VSCODE\\DA1\\hv.txt") ; 
    hv>> this->n ; 
    this->p= new HoiVien[this->n] ; 
    int m1;
    string m2 ;
    int m3 ;
    int m4 ;  
    int m5 ;
    for (int i=0;i<n;i++)
    {
        hv>>  m1 ;
        //fgets(m2,20,hv) ;
        hv.ignore();
        getline(hv,m2);  
        hv>> m3 ; 
        hv>> m4 ; 
        hv>>m5 ;
        (this->p+i)->SetMaHV(m1) ; 
        (this->p+i)->SetTen(m2) ; 
        (this->p+i)->Setsdt(m3) ;
        (this->p+i)->Setlevel(m4) ; 
        (this->p+i)->Settong(m5) ;
    }
}
void QLHV::Show() 

{   cout<<"                           DANH SACH HOI VIEN "<<endl;
    cout<<setw(10)<<left<<"Ma HV"<<"\t"<<setw(20)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"level"<<setw(15)<<left<<"Tong"<<  endl;
    for (int i=0;i<this->n;i++)
    (this->p+i)->Show() ; 
}
void QLHV::Endday()
{
    ofstream hv("D:\\VSCODE\\DA1\\hv.txt") ; 
    hv << this->n<<endl ; 
    for (int i=0;i<this->n;i++)
    {
    hv << (this->p+i)->GetMaHV()<<endl ; 
    hv << (this->p+i)->GetTen()<<endl ; 
    hv << (this->p+i)->Getsdt()<<endl ; 
    int a=0; 
    a=(this->p+i)->Gettong() ; 
    if(a>500000 && a<2000000)
    {
        (this->p+i)->Setlevel(1) ; 
        hv<< "1"  <<endl; 
    }
        
    if(a>2000000 && a<5000000)
    {
        (this->p+i)->Setlevel(2) ; 
        hv<< "2"  <<endl; 
    }
    if(a>5000000 && a<10000000)
    {
        (this->p+i)->Setlevel(3) ; 
        hv<< "3"  <<endl; 
    }
    if(a>10000000 && a<20000000)
    {
        (this->p+i)->Setlevel(4) ; 
        hv<< "4"  <<endl; 
    }
    if(a>20000000)
    {
        (this->p+i)->Setlevel(5) ; 
        hv<< "5"  <<endl; 
    }
    if(a>0 && a<500000)
    {
        (this->p+i)->Setlevel(0) ; 
        hv<< "0"  <<endl; 
    }
    hv << (this->p+i)->Gettong()<< endl; 
    }
}
void QLHV::Add() 
{
    HoiVien B ; 
    B.Nhap() ; 
    HoiVien *t= new HoiVien[this->n+1] ; 
        for (int i=0;i<this->n;i++)   
            {
            (t+i)->SetMaHV((this->p+i)->GetMaHV()) ; 
            (t+i)->SetTen((this->p+i)->GetTen()) ; 
            (t+i)->Setsdt((this->p+i)->Getsdt()) ; 
            (t+i)->Setlevel((this->p+i)->Getlevel()) ; 
            (t+i)->Settong((this->p+i)->Gettong()) ;
            
            }
        delete[] p; 
 
        this->p=new HoiVien[this->n+1] ;
        for (int i=0;i<this->n;i++)
            {
            (this->p+i)->SetMaHV((t+i)->GetMaHV()) ;  
            (this->p+i)->SetTen((t+i)->GetTen()) ; 
            (this->p+i)->Setsdt((t+i)->Getsdt()) ; 
            (this->p+i)->Setlevel((t+i)->Getlevel()) ; 
            (this->p+i)->Settong((t+i)->Gettong()) ; 
            }
        (this->p+this->n)->SetMaHV(B.GetMaHV()) ;  
        (this->p+this->n)->SetTen(B.GetTen()) ; 
        (this->p+this->n)->Setsdt(B.Getsdt()) ; 
        (this->p+this->n)->Setlevel(B.Getlevel()) ;
        (this->p+this->n)->Settong(B.Gettong()) ; 
        this->n++ ;
}
HoiVien* QLHV::Find(int x) 
{   
    for (int i=0;i<this->n;i++) 
    {
            if (x==(this->p+i)->GetMaHV())  return (this->p+i) ; 
    }
    return NULL ; 
}
void QLHV::FindMSV(const int x)
{
    int check=0; 
    for (int i=0;i<this->n;i++)
    {
        if( (this->p+i)->GetMaHV()==x) 
        {
            (this->p+i)->Show() ; 
            check=1; 
        }
    }   
    if (check==0) cout << "Khong tim thay nhan vien co Ma HV nhu tren "<<endl; 
}
void QLHV::Update()
{   
    string a;
    int b,c,d,e;  
    cout <<" Moi nhap Ma HV de tien hanh sua doi thong tin" << endl; 
    cin >> b ; 
    if (this->Find(b)==NULL)
    {
        cout<<"Cua Hang Khong Co Hoi Vien Nay"<< endl; 
    }
    else
    {
    cout<<"Thong tin hoi vien truoc khi chinh sua"<<endl;
    cout<<setw(10)<<left<<"Ma HV"<<"\t"<<setw(20)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"level"<<setw(10)<<"TongTien"<<endl;
    Find(b)->Show() ;
    cout << "Moi Nhap thong tin can hoi vien can update" << endl ; 
    Find(b)->Nhap1() ; 
    cout<<"Ban da update thanh cong."<<endl; 
    }
}
void QLHV::Delete(int x) 
{
    int check=0; 
    for (int i=0;i<this->n;i++)
    {
        if (x==(this->p+i)->GetMaHV()) 
        {x=i ; check=1;} 
    }
    if (check==0) 
    {
        cout << "Khong co MaHV nay trong danh sach" <<endl; 
    }
    else 
    {
    HoiVien *k= new HoiVien[this->n] ; 
        for (int i=0;i<this->n;i++)   
        {
            (k+i)->SetMaHV((this->p+i)->GetMaHV()) ; 
            (k+i)->SetTen((this->p+i)->GetTen()) ; 
            (k+i)->Setsdt((this->p+i)->Getsdt()) ; 
            (k+i)->Setlevel((this->p+i)->Getlevel()) ; 
        };
         delete[] p; 
        this->p=new HoiVien[this->n-1] ;
        int j=1 ; 
        for (int i=0;i<this->n-1;i++)
            { 
            if (i<x)
            {   
                (this->p+i)->SetMaHV((k+i)->GetMaHV()) ;  
                (this->p+i)->SetTen((k+i)->GetTen()) ; 
                (this->p+i)->Setsdt((k+i)->Getsdt()) ; 
                (this->p+i)->Setlevel((k+i)->Getlevel()) ; 
            }
            else 
            {   
                (this->p+i)->SetMaHV((k+x+j)->GetMaHV()-1) ;  
                (this->p+i)->SetTen((k+x+j)->GetTen()) ; 
                (this->p+i)->Setlevel((k+x+j)->Getlevel()) ; 
                (this->p+i)->Setsdt((k+x+j)->Getsdt()) ; 
                j++ ; 
            }
            }
        this->n--; 
        cout<<"Ban da xoa thanh cong"<<endl;
    }
}
void QLHV::Uudai(int x)
{
    switch (x)
    {
    case 1:
        {
            cout << "Ban dang o cap do uu dai 1 " << endl; 
            cout << "Danh sach cac uu dai cua ban la" << endl;
            cout << "Giam 2% tong gia tri hoa don" << endl; 
            cout << "Duoc tham gia vong quay thuong cuoi nam cho khach Vip 1"<< endl; 
            break;
        }
    case 2:
        {
            cout << "Ban dang o cap do uu dai 2 " << endl; 
            cout << "Danh sach cac uu dai cua ban la" << endl;
            cout << "Giam 4% tong gia tri hoa don" << endl; 
            cout << "Ban duoc tang kem 1 phu kien san pham bat ky duoi 50k khi hoa don tren 250k"<< endl; 
            cout << "Duoc tham gia vong quay thuong cuoi nam cho khach Vip 2"<< endl; 
            break;
        }
    case 3:
        {
            cout << "Ban dang o cap do uu dai 3 " << endl; 
            cout << "Danh sach cac uu dai cua ban la" << endl;
            cout << "Giam 6% tong gia tri hoa don" << endl; 
            cout << "Ban duoc tang kem 1 phu kien san pham bat ky duoi 100k khi hoa don tren 500k"<< endl; 
            cout << "Duoc dat hang truoc cac san pham hot cua cua hang"<<endl; 
            cout << "Duoc tham gia vong quay thuong cuoi nam cho khach Vip 3"<< endl; 
            break;
        }
    case 4:
        {
            cout << "Ban dang o cap do uu dai 4 " << endl; 
            cout << "Danh sach cac uu dai cua ban la" << endl;
            cout << "Giam 8% tong gia tri hoa don" << endl; 
            cout << "Ban duoc tang kem 1 phu kien san pham bat ky duoi 100k khi hoa don tren 500k"<< endl; 
            cout << "Duoc dat hang truoc cac san pham hot cua cua hang"<<endl; 
            cout << "Duoc tu van ho tro 24/24 qua tai khoan cua minh tren website cua cua hang"<<endl; 
            cout << "Duoc tham gia vong quay thuong cuoi nam cho khach Vip4"<< endl; 
            break;
        }
    case 5:
        {
            cout << "Ban dang o cap do uu dai 5 " << endl; 
            cout << "Danh sach cac uu dai cua ban la" << endl;
            cout << "Giam 10% tong gia tri hoa don" << endl; 
            cout << "Ban duoc tang kem 1 phu kien san pham bat ky duoi 100k khi hoa don tren 500k"<< endl; 
            cout << "Duoc dat hang truoc cac san pham hot cua cua hang"<<endl; 
            cout << "Ban duoc tham gia mua co phan cua cua hang kh qua 5%/nam/toida 15%"<< endl; 
            cout << "Duoc tu van ho tro 24/24 qua tai khoan cua minh tren website cua cua hang"<<endl; 
            cout << "Duoc tham gia vong quay thuong cuoi nam cho khach Vip5"<< endl; 
            break;
        }
    default:
        break;
    }
}