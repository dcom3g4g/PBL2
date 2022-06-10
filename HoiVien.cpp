#include"HoiVien.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std ; 
HoiVien::HoiVien()
{
    MaHV=0; 
    sdt=0;
    level=0; 
    tong=0; 
}
HoiVien::~HoiVien() 
{

}
void HoiVien::Show()
{
    cout <<setw(10)<<left << this->MaHV <<"\t";
    cout << setw(20)<<left << this->Ten <<"\t"; 
    cout <<"0"<<setw(10)<< this ->sdt<<"\t";
    cout <<setw(10)<<left<< this->level ; 
    cout << this->tong <<"\t" ; 
    cout <<endl;
}
int HoiVien::GetMaHV() 
{
    return this->MaHV ; 
}
void HoiVien::SetMaHV(int a) 
{
    this->MaHV=a ; 
} 
string HoiVien::GetTen() 
{
    return this->Ten ; 
}
void HoiVien::SetTen(string a) 
{
    this->Ten=a ; 
}
int HoiVien::Getsdt() 
{
    return this->sdt ; 
}
void HoiVien::Setsdt(int a ) 
{
    this->sdt=a ; 
}
int HoiVien::Getlevel() 
{
    return this->level ; 
}
void HoiVien::Setlevel(int a) 
{
    this->level=a ; 
} 
int HoiVien::Gettong() 
{
    return this->tong ; 
}
void HoiVien::Settong(int a) 
{
    this->tong=a ; 
} 
void HoiVien::Nhap()
{
    int a; 
    ifstream sn("D:\\VSCODE\\DA1\\hv.txt") ; 
    sn>> a ;
    if (a>1000) a=0; 
    this->MaHV=++a ; 
    fflush(stdin) ; 
    cout << "Nhap ten HV : " << endl; 
    getline(cin,this->Ten) ; 
    cout<< "Nhap sdt : " << endl; 
    cin >> this->sdt ;
    cout << "Nhap level:  " << endl; 
    cin >> this->level;
    if (this->level==1)
        this->tong=500000 ; 
    if (this->level==2)
        this->tong=2000000 ; 
    if (this->level==3)
        this->tong=5000000 ; 
    if (this->level==4)
        this->tong=10000000 ; 
    if (this->level==5)
        this->tong=20000000 ; 
}
void HoiVien::Nhap1()
{
    fflush(stdin) ; 
    cout << "Nhap ten HV : " << endl; 
    getline(cin,this->Ten) ; 
    cout<< "Nhap sdt : " << endl; 
    cin >> this->sdt ;
    cout << "Nhap level:  " << endl; 
    cin >> this->level;
    if (this->level==1)
        this->tong=500000 ; 
    if (this->level==2)
        this->tong=2000000 ; 
    if (this->level==3)
        this->tong=5000000 ; 
    if (this->level==4)
        this->tong=10000000 ; 
    if (this->level==5)
        this->tong=20000000 ; 
}