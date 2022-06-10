#include"HoaDon.h"
HoaDon::HoaDon()
{
    this->Ngay=0;
    this->Nam=0;
    this->Thang=0;
    this->TongTien=0;
    this->Pre=NULL;
    this->SoLuongSP=0;
    this->Next=NULL;
    this->MaHD=0; 
    this->MaHV=0; 
    this->MaNV=0; 
}
HoaDon::~HoaDon()
{
    delete[] this->Next ; 
    delete[] this->Pre; 
}
void HoaDon::Show()
{
    cout<<this->Ngay <<"/"<< this->Thang<<"/"<<this->Nam <<endl; 
    cout<<"Ma HD: "<< this->MaHD <<endl; 
    cout<< "Ma NV: "<< this->MaNV <<endl; 
    cout<<"Ma HV: "<< this->MaHV << endl; 
    cout <<"So Luong Mat Hang Da Mua: "<< this->SoLuongSP << endl; 
    for (int i=0;i<this->SoLuongSP;i++)
    {
        cout <<"Ten SP" <<i+1<<":  "<< (this->k+i)->TenSP<<endl; 
        cout <<"Gia Thanh: "<< (this->k+i)->GiaThanh<<endl; 
        cout <<"So Luong: "<< (this->k+i)->SoLuong <<endl; 
    }
    cout<< "------------------------------" <<endl; 
    cout<<"Tong hoa don: "<< this->TongTien<<" VND"<< endl; 
}
