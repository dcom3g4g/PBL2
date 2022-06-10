#include<iostream>
#include"QLNV.h"
#include<fstream>
#include<iomanip>
using namespace std ; 
QLNV::QLNV()
{
    n=0; 
}
QLNV::~QLNV() 
{
        delete[] p ; 
}
void QLNV::ISfromfile() 
{
    ifstream nv("D:\\VSCODE\\DA1\\nv.txt") ; 
    nv>> this->n ; 
    this->p= new NhanVien[this->n] ; 
    int m1;
    string m2 ;
    int m3 ;
    int m4 ;  
    for (int i=0;i<n;i++)
    {
        nv>>  m1 ;
        //fgets(m2,20,nv) ; 
        // fflush(stdin);
        nv.ignore();
        getline(nv,m2);  
        nv>> m3 ; 
        nv>> m4 ; 
        (this->p+i)->SetMaNV(m1) ; 
        (this->p+i)->SetTen(m2) ; 
        (this->p+i)->Setsdt(m3) ;
        (this->p+i)->SetSoluongban(m4) ; 
    }
}
void QLNV::Show() 
{   cout<<"                           DANH SACH NHAN VIEN "<<endl;
    cout<<setw(10)<<left<<"Ma NV"<<"\t"<<setw(18)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"KPI"<<endl;
    for (int i=0;i<this->n;i++)
    (this->p+i)->Show() ; 
}
void QLNV::luongall()
{   cout<<setw(10)<<left<<"Ma NV"<<"\t"<<setw(10)<<left<<"Tien Luong"<<endl;
    cout<<""<<endl;
    for (int i=0;i<n;i++)
    {  
        cout << (this->p+i)->GetMaNV() ;  
        cout << setw(10)<<left<<"\t"<< 3000000+(this->p+i)->GetSoluongban()*5000  ;
        
        cout<<endl;
    }
}
void QLNV::Sosanh() 
{
    int sum=0;
    int a[this->n] ;    
    cout <<"           Bang so sanh doanh so ban hang cua cac nhan vien"<< endl; 
    for (int i=0;i<this->n;i++)
    {
        sum=sum+ (this->p+i)->GetSoluongban() ;  
    }
    for (int j=0;j<this->n;j++)
    {
    a[j]= 10*(this->p+j)->GetSoluongban()/sum ; 
    }
    cout<<"Ten NV:      Ty le   Doanh so thuc"<< endl; 
    for (int i=0; i<this->n; i++) 
    {   
        cout << "Ma NV" <<(this->p+i)->GetMaNV()<<"      "  ; 
        for (int j=0;j<a[i];j++)
        {
            cout <<"|" ; 
            if (j==a[i]-1) cout <<setw(10-a[i])<<(this->p+i)->GetSoluongban()<<  endl; 
        }
    }
}
void QLNV::Endday()
{
    ofstream nv("D:\\VSCODE\\DA1\\nv.txt") ; 
    nv << this->n<<endl ; 
    for (int i=0;i<this->n;i++)
    {
    nv << (this->p+i)->GetMaNV()<<endl ; 
    nv << (this->p+i)->GetTen()<<endl ; 
    nv << (this->p+i)->Getsdt()<<endl ; 
    nv << (this->p+i)->GetSoluongban()<<endl ; 
    }
}
void QLNV::Add() 
{
    NhanVien B ; 
    B.Nhap() ; 
    NhanVien *t= new NhanVien[this->n+1] ; 
        for (int i=0;i<this->n;i++)   
            {
            (t+i)->SetMaNV((this->p+i)->GetMaNV()) ; 
            (t+i)->SetTen((this->p+i)->GetTen()) ; 
            (t+i)->Setsdt((this->p+i)->Getsdt()) ; 
            (t+i)->SetSoluongban((this->p+i)->GetSoluongban()) ; 
            
            }
        delete[] p; 
 
        this->p=new NhanVien[this->n+1] ;
        for (int i=0;i<this->n;i++)
            {
            (this->p+i)->SetMaNV((t+i)->GetMaNV()) ;  
            (this->p+i)->SetTen((t+i)->GetTen()) ; 
            (this->p+i)->Setsdt((t+i)->Getsdt()) ; 
             (this->p+i)->SetSoluongban((t+i)->GetSoluongban()) ; 
 
            }
        (this->p+this->n)->SetMaNV(B.GetMaNV()) ;  
        (this->p+this->n)->SetTen(B.GetTen()) ; 
        (this->p+this->n)->Setsdt(B.Getsdt()) ; 
        (this->p+this->n)->SetSoluongban(B.GetSoluongban()) ; 
        this->n++ ;
}
NhanVien* QLNV::Find(int x ) 
{    
    for (int i=0;i<this->n;i++) 
    {
        if (x==(this->p+i)->GetMaNV()) return (this->p+i) ; 
    }
    return NULL ; 
}
void QLNV::FindMSV(const int x)
{
    int check=0; 
    for (int i=0;i<this->n;i++)
    {
        if( (this->p+i)->GetMaNV()==x) 
        {
            (this->p+i)->Show() ; 
            check=1; 
        }
    }   
    if (check==0) cout << "Khong tim thay nhan vien co Ma NV nhu tren "<<endl; 
}
void QLNV::Update()
{   
    string a;
    int b,c,d,e;  
    cout <<" Moi nhap Ma NV de tien hanh sua doi thong tin" << endl; 
    cin >> b ; 
    if (this->Find(b)==NULL)
        cout<<"Cua Hang Khong Co Nhan Vien Nay" << endl; 
    else
    {
    cout<<"Thong tin nhan vien truoc khi update "<<endl;
    cout<<setw(10)<<left<<"Ma NV"<<"\t"<<setw(20)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"KPI"<<endl;
    Find(b)->Show();
    cout << "Moi Nhap thong tin can nhan vien can update" << endl ; 
    Find(b)->Nhap1() ; 
    }
}
void QLNV::Delete(int x) 
{
    int check=0; 
    for (int i=0;i<this->n;i++)
    {
        if (x==(this->p+i)->GetMaNV()) 
        {x=i ; check=1;} 
    }
    if (check==0) 
    {
        cout << "Khong co MaNV nay trong danh sach" <<endl; 
    }
    else 
    {
    NhanVien *k= new NhanVien[this->n] ; 
        for (int i=0;i<this->n;i++)   
        {
            (k+i)->SetMaNV((this->p+i)->GetMaNV()) ; 
            (k+i)->SetTen((this->p+i)->GetTen()) ; 
            (k+i)->Setsdt((this->p+i)->Getsdt()) ; 
            (k+i)->SetSoluongban((this->p+i)->GetSoluongban()) ; 
        };
         delete[] p; 
        this->p=new NhanVien[this->n-1] ;
        int j=1 ; 
        for (int i=0;i<this->n-1;i++)
            { 
            if (i<x)
            {   
                (this->p+i)->SetMaNV((k+i)->GetMaNV()) ;  
                (this->p+i)->SetTen((k+i)->GetTen()) ; 
                (this->p+i)->Setsdt((k+i)->Getsdt()) ; 
                (this->p+i)->SetSoluongban((k+i)->GetSoluongban()) ; 
            }
            else 
            {   
                (this->p+i)->SetMaNV((k+x+j)->GetMaNV()-1) ;  
                (this->p+i)->SetTen((k+x+j)->GetTen()) ; 
                (this->p+i)->SetSoluongban((k+x+j)->GetSoluongban()) ; 
                (this->p+i)->Setsdt((k+x+j)->Getsdt()) ; 
                j++ ; 
            }
            }
        this->n--; 
        cout<<"Ban Da Xoa Thanh Cong"<< endl; 
    }
}