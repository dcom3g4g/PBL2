#include"NhanVien.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std ; 
NhanVien::NhanVien()
{
    MaNV=0; 
    sdt=0;
    KPI=0; 
}
NhanVien::~NhanVien() 
{

}

void NhanVien::Show()
{
//   cout<<setw(10)<<left<<"Ma NV"<<"\t"<<setw(30)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"KPI"<<endl;
    
    cout <<setw(10)<<left << this->MaNV  <<"\t";
    cout << setw(20)<<left << this->Ten <<"\t"; 
    cout <<"0"<< this ->sdt<<"\t";
    cout <<setw(10)<<left<< this->KPI <<"\t"; 
    cout <<endl;
}
int NhanVien::GetMaNV() 
{
    return this->MaNV ; 
}
void NhanVien::SetMaNV(int a) 
{
    this->MaNV=a ; 
} 
string NhanVien::GetTen() 
{
    return this->Ten ; 
}
void NhanVien::SetTen(string a) 
{
    this->Ten=a ; 
}
int NhanVien::Getsdt() 
{
    return this->sdt ; 
}
void NhanVien::Setsdt(int a ) 
{
    this->sdt=a ; 
}
int NhanVien::GetSoluongban() 
{
    return this->KPI ; 
}
void NhanVien::SetSoluongban(int a) 
{
    this->KPI=a ; 
} 
void NhanVien::Nhap()
{   
    int a; 
    ifstream sn("D:\\VSCODE\\DA1\\nv.txt") ; 
    sn>> a ;
    if (a>1000) a=0; 
    this->MaNV=++a ; 
    fflush(stdin) ; 
    cout << "Nhap ten NV : " << endl; 
    getline(cin,this->Ten) ; 
    cout<< "Nhap sdt : " << endl; 
    cin >> this->sdt ;
    cout << "Nhap KPI:  " << endl; 
    cin >> this->KPI;
}
void NhanVien::Nhap1() 
{
    fflush(stdin) ; 
    cout << "Nhap ten NV : " << endl; 
    getline(cin,this->Ten) ; 
    cout<< "Nhap sdt : " << endl; 
    cin >> this->sdt ;
    cout << "Nhap KPI:  " << endl; 
    cin >> this->KPI;
}