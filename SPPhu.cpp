#include"SPPhu.h"
#include"QLSPP.h"
#include<fstream>
SPPhu::SPPhu()
{
    this->Type=0; 
    this->Giathanh=0; 
    this->MaSP=0; 
    this->Soluong=0; 
    this->TenSP="";
    this->NEXT=NULL ; 
    this->PRE=NULL; 
    this->SPall=false ; 
    for (int i=0;i<5;i++)
    {
        this->SPfor[i]=0; 
    }
}
SPPhu::~SPPhu() 
{

}
void SPPhu::Show()
{
    cout << "Ma Sp " << this->MaSP << endl; 
    cout << "Ten sp "<< this->TenSP << endl; 
    cout << "Gia Thanh "<< this->Giathanh<< endl;
    cout << "So Luong "<< this->Soluong<< endl; 
    cout << "Loai: "<< this->Type<< endl;  
        if (this->SPall==true) 
            cout << "Phu hop cho tat ca cac loai Sneaker!"<<endl ;
            else cout<<"khong phu hop cho tat ca"<< endl; 
        cout <<"Phu hop cho cac loai Sneaker co Ma sau: "<<endl; 
        for (int i=0;i<5;i++)
        {
            cout <<this->SPfor[i]<<" ; "; 
        }   
        cout << endl; 
    cout <<"         -----------"<< endl;  
}
void SPPhu::Nhap(QLSPP* A)
{
    cout<<"Nhap Ma SP"<< endl;  
    do
    {
        cin>> this->MaSP ; 
        if (A->Find(this->MaSP)!=NULL)
            cout<<"Da Co Ma Nay Moi Ban Nhap Lai"<< endl; 
    }
    while (A->Find(this->MaSP)!=NULL) ; 
    fflush(stdin) ; 
    cout << "Nhap ten SP : " << endl; 
    getline(cin,this->TenSP) ; 
    cout<< "Nhap Gia : " << endl; 
    cin >> this->Giathanh ;
    cout << "Nhap So luong:  " << endl; 
    cin >> this->Soluong;
    cout <<"Nhap Loai: " << endl; 
    cin>> this->Type ; 
    int a; 
    cout <<"Neu san pham phu hop vs tat cac cac loai sneaker Nhap 1 khong Nhap bat ky "<<endl; 
    cin>> a ; 
    if (a==1) this->SPall=true; else this->SPall=false ; 
    cout << "Nhap Ma Sneaker phu hop vs san pham nay"<< endl ;
    for (int i=0;i<5;i++)
    {
        cin>> this->SPfor[i] ; 
    } 
}