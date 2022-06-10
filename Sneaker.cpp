#include"Sneaker.h"
#include"QLSN.h"
#include<iomanip>
#include<fstream>
Sneaker::Sneaker() 
{
    this->Type=0; 
    this->Giathanh=0; 
    this->MaSP=0; 
    this->Soluong=0; 
    this->TenSP="A";
    this->Next=NULL ; 
    this->Pre=NULL; 
}
Sneaker::~Sneaker()
{

}
void Sneaker::Show()
{  
    cout << setw(10)<<left<< this->MaSP <<"\t"; 
    cout << setw(20)<<left<< this->TenSP <<"\t"; 
    cout << setw(12)<<left<< this->Giathanh<< "\t";
    cout << setw(15)<<left<< this->Soluong<<"\t"; 
    cout << setw(2)<<left<< this->Type<< "\t";  
    cout << endl; 
}
void Sneaker::Nhap(QLSN* A)
{
    cout<<"Nhap Ma San Pham"<< endl; 
    
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
}
