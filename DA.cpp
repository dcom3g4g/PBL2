
#ifndef Sneaker_H
#define Sneaker_H
#include "QLSPP.h"
#include "QLSN.h"
#include "QLHD.h"
#include <fstream>
#include<iomanip>
QLSN SN;
QLHD HD;
QLSPP SPP;
QLNV NV;
QLHV HV;
int main()
{
    int m;
    int nv,hd,spp,sn,hv; 
    SN.ISfromfile(); 
    SPP.ISfromfile() ; 
    NV.ISfromfile(); 
    HD.ISfromFile() ; 
    HV.ISfromfile() ;
    do
    {   cout<<"--------------------------------------------------------"<<endl;
        cout << "|                                                      |" << endl;
        cout << "|                      DO AN PPL2                      |" << endl;
        cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
        cout << "|      Sinh vien thuc hien:                            |" << endl;
        cout << "|         1.Nguyen Hoang Vu                            |" << endl;
        cout << "|         2.Tran Van Hai                               |" << endl;
        cout << "|                                                      |" << endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout << "|\t            QUAN LY SHOP SNEAKER               |" << endl;
        cout<<"|------------------------------------------------------|"<<endl;
        cout << "|\t 1.Quan Ly Nhan Vien                           |" << endl;
        cout << "|\t 2.Quan Ly Hoi Vien                            |" << endl;
        cout << "|\t 3.Quan Ly San Pham Phu                        |" << endl;
        cout << "|\t 4.Quan Ly Sneaker                             |"<< endl;
        cout << "|\t 5.Quan Ly Hoa Don                             |" << endl;
        cout << "|\t 0.Thoat                                       |" << endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout << "Moi Nhap Cong Viec: " << endl;
        cin >> m;
        if (m==1)
            {  system("cls"); 
                 do
                {   cout <<"--------------------------------------------------------"<<endl;
                    cout << "|                                                      |" << endl;
                    cout << "|                      DO AN PPL2                      |" << endl;
                    cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
                    cout << "|      Sinh vien thuc hien:                            |" << endl;
                    cout << "|         1.Nguyen Hoang Vu                            |" << endl;
                    cout << "|         2.Tran Van Hai                               |" << endl;
                    cout << "|                                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|\t             QUAN LY Nhan Vien                 |" << endl;
                    cout <<"|------------------------------------------------------|"<<endl;
                    cout << "|\t 1.Them nhan vien                              |" << endl;
                    cout << "|\t 2.Tim NV                                      |" << endl;
                    cout << "|\t 3.In danh sach NV                             |" << endl;
                    cout << "|\t 4.In luong NV                                 |" << endl;
                    cout << "|\t 5.Chinh sua thong tin nhan vien theo Ma NV:   |" <<endl; 
                    cout << "|\t 6.Xoa NV theo ma NV                           |" << endl; 
                    cout << "|\t 7.Ket thuc ngay                               |" <<endl; 
                    cout << "|\t 9.Thoat                                       |" << endl;
                    cout<<"--------------------------------------------------------"<<endl;
                    cout << "Moi Nhap Cong Viec" << endl;
                    cin>> nv ; 
                    switch (nv)
                    
                    {
                    case 1:
                    {system("cls"); 
                        NV.Add() ; 
                        cout<<"Ban da them nhan vien thanh cong "<<endl;
                        NV.Endday();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                       
                    }
                    case 2:
                    {system("cls"); 
                        int x ; int n=0;
                        cout<<"Nhap MaNV Nhan Vien can tim: "<<endl; 
                        cin>> x ; 
                        int z=0; 
                        if (NV.Find(x)==NULL) 
                        {
                            z=1; 
                            cout<<"Cua hang kh co nhan vien nay"<< endl; 
                        }
                        else 
                        {
                            if (z==0) 
                            {cout<<"                           DANH SACH NHAN VIEN "<<endl;
                                cout<<setw(10)<<left<<"Ma NV"<<"\t"<<setw(20)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"KPI"<<endl;
                                NV.Find(x)->Show() ;
                            }
                                
                        }
                        NV.Endday();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break;                    
                    }
                    case 3:
                    {
                     system("cls");
                        NV.Show() ; 
                        NV.Endday();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                       
                    }
                    // case 4 :
                    // {system("cls");
                    //     NV.Sosanh(); 
                    //     getchar() ;
                    //     cout<<"Nhap Bat Ky De tro lai"<< endl; 
                    //     getchar() ;
                    //     system("cls"); 
                    //     break; 
                    // }
                    case 4:
                    {system("cls");
                        NV.luongall() ; 
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 5:
                    {system("cls");
                        NV.Update() ;                     
                        NV.Endday(); 
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 6:
                    {   system("cls");
                        int x; 
                        cout<< "Nhap Ma NV can xoa"<< endl; 
                        cin >> x ; 
                        NV.Delete(x); 
                       
                        NV.Endday();
                        //cout<< "Ban da xoa NV co Ma NV la: "<<x<<endl;
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 7:
                    {system("cls");
                        NV.Endday();
                        break;
                    }
                    
                    case 9:
                    {
                        system("cls");
                        break; 
                    }
                    default:
                    {
                        cout<<"Ban Da Nhap Sai Moi Ban Nhap Lai"<< endl; 
                        break;
                    }
                }

                } while (nv!=9);
            }
            /// hoi vien
            if(m==2)
            {
                do
                {system("cls");
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|                                                      |" << endl;
                    cout << "|                      DO AN PPL2                      |" << endl;
                    cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
                    cout << "|      Sinh vien thuc hien:                            |" << endl;
                    cout << "|         1.Nguyen Hoang Vu                            |" << endl;
                    cout << "|         2.Tran Van Hai                               |" << endl;
                    cout << "|                                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|\t             QUAN LY HOI Vien                 |" << endl;
                    cout <<"|-----------------------------------------------------|"<<endl;
                    cout << "|\t 1.Them Hoi vien                              |" << endl;
                    cout << "|\t 2.Tim HV                                     |" << endl;
                    cout << "|\t 3.In danh sach HV                            |" << endl;
                    cout << "|\t 4.In uu dai                                  |" << endl;
                    cout << "|\t 5.Sua thong tin hoi vien theo Ma HV          |" << endl;
                    cout << "|\t 6.Xoa thong tin hoi vien theo Ma HV          |" << endl;  
                    cout << "|\t 7.Ket thuc ngay                              |" << endl; 
                    cout << "|\t 9.Thoat                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "Moi Nhap Cong Viec" << endl;
                    cin>> hv ; 
                    switch (hv)
                    {
                    case 1:
                    {system("cls"); 
                        HV.Add() ; 
                        
                        HV.Endday();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 2:
                    {system("cls"); 
                        int x ; 
                        cout<<"Nhap MaHV Nhan Vien can tim: "<<endl; 
                        cin>> x ; 
                        int z=0; 
                        if (HV.Find(x)==NULL) 
                        {
                            z=1; 
                            cout<<"Cua hang kh co hoi vien nay"<< endl; 
                        }
                        else 
                        {                        cout<<"                           DANH SACH HOI VIEN "<<endl;
                        cout<<setw(10)<<left<<"Ma HV"<<"\t"<<setw(20)<<left<<"Ho Va Ten"<<"\t"<<setw(12)<<left<<"SDT"<<"\t"<<setw(10)<<left<<"level"<<setw(10)<<"TongTien"<<endl;
                        HV.Find(x)->Show() ; 
                        }
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 3:
                    { 
                        system("cls");
                        HV.Show() ; 
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 4 :
                    {system("cls"); 
                        int x; 
                        cout<<"Moi Nhap Muc Uu Dai Cua Ban De Xem Chi Tiet"<< endl; 
                        do
                        {
                            cin >> x; 
                            if (x>5||x<1)
                            cout<<"Ban Nhap Sai Moi Nhap Lai"<< endl; 
                        } while(x>5|| x<1) ;
                        
                        HV.Uudai(x); 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 5: 
                    {system("cls"); 
                        
                        HV.Update() ; 
                    
                        HV.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break;  
                    }
                    case 6:
                    {system("cls"); 
                        int x=0; 
                        cout<<"Moi Nhap Ma HV"<< endl; 
                        cin>> x ; 
                        
                        HV.Delete(x) ;  
                        HV.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 7:
                    {
                        system("cls"); 
                        HV.Endday() ; 
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 9:
                    {
                        system("cls");
                        break;
                    } 
                    default:
                    {
                        cout<<"Ban Da Nhap Sai Moi Ban Nhap Lai"<< endl; 
                        break; 
                    }
                    }
                } while (hv!=9);
            }
            /// spp 
            if(m==3)
            {
                do
                {system("cls");
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|                                                      |" << endl;
                    cout << "|                      DO AN PPL2                      |" << endl;
                    cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
                    cout << "|      Sinh vien thuc hien:                            |" << endl;
                    cout << "|         1.Nguyen Hoang Vu                            |" << endl;
                    cout << "|         2.Tran Van Hai                               |" << endl;
                    cout << "|                                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|\t           QUAN LY SAN PHAM PHU                |" << endl;
                    cout << "|------------------------------------------------------|"<<endl;
                    cout << "|\t 1.Them San Pham                               |" << endl;
                    cout << "|\t 2.Tim SP                                      |" << endl;
                    cout << "|\t 3.In danh sach SP                             |" << endl;
                    cout << "|\t 4.In ra dong sneaker phu hop                  |" << endl;
                    cout << "|\t 5.Sap xem theo gia                            |" << endl;
                    cout << "|\t 6.Sap xep theo ma SP                          |" << endl; 
                    cout << "|\t 7.Xoa san pham theo ma SP                     |" << endl; 
                    cout << "|\t 8.Chinh sua thong tin san pham bang Ma Sp     |" << endl;
                    cout << "|\t 9.KetThucNgay                                 |" << endl;
                    cout << "|\t 10.Thoat                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout << "Moi Nhap Cong Viec" << endl;
                    cin>> spp ; 
                    switch (spp)
                    {
                    case 1:
                    {system("cls"); 
                        SPP.AddF(); 
                        SPP.Endday();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 2:
                    {system("cls"); 
                        int x ; 
                        cout<<"Nhap MaSP San Pham can tim: "<<endl; 
                        cin>> x ; 
                        int z=0; 
                        if (SPP.Find(x)==NULL) 
                        {
                            z=1; 
                            cout<<"Cua hang kh co sp nay"<< endl; 
                        }
                        else 
                        {
                            SPP.Find(x)->Show() ; 
                        }
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 3:
                    {
                        system("cls"); 
                        SPP.Show1() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 4 :
                    {system("cls"); 
                        int x ; 
                        cout<<"Nhap MaSP San Pham can xem: "<<endl; 
                        cin>> x ; 
                        if (SPP.Find(x)==NULL)
                            cout<<"Cua Hang Khong Co San Pham Nay"<< endl; 
                        else
                            SneakerCoTheSuDung(SPP.Find(x),SN) ; 
                        
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 5:
                    {system("cls"); 
                        SPP.SapxeptheoGia() ;
                        SPP.Show1() ; 
                        SPP.Endday() ;  
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 6:
                    {system("cls"); 
                        SPP.SapxeptheoMaSP() ; 
                        SPP.Show1() ; 
                        SPP.Endday() ;  
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 7:
                    {system("cls"); 
                        int x ; 
                        cout<<"Nhap Ma SP"<< endl; 
                        cin>> x ; 
                        if (SPP.Find(x)==NULL)
                            cout<<"Cua Hang Khong Co San Pham Nay"<< endl; 
                        else 
                            SPP.DeletebyMaSP(x) ; 
                        SPP.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 8:
                    {system("cls"); 
                        int x ; 
                        cout<<"Nhap Ma SP"<< endl; 
                        cin>> x ; 
                        if (SPP.Find(x)==NULL)
                            cout<<"Cua Hang Khong Co San Pham Nay"<< endl; 
                        else 
                            SPP.ChinhsuaTTbyMaSP(x) ; 
                        SPP.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 9:
                    {system("cls"); 
                        SPP.Endday() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                   case 10:{
                        system("cls");
                        break;} 
                    default:
                    {
                        cout<<"Ban Da Nhap Sai Moi Ban Nhap Lai"<< endl; 
                        break;
                    }
                    }

                } while (spp!=10);
            }
            /// sneaker 
            if(m==4)
            {
                do
                {system("cls");
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|                                                      |" << endl;
                    cout << "|                      DO AN PPL2                      |" << endl;
                    cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
                    cout << "|      Sinh vien thuc hien:                            |" << endl;
                    cout << "|         1.Nguyen Hoang Vu                            |" << endl;
                    cout << "|         2.Tran Van Hai                               |" << endl;
                    cout << "|                                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|\t           QUAN LY SNEAKER                     |" << endl;
                    cout << "|------------------------------------------------------|"<<endl;
                    cout << "|\t 1.Them San Pham                               |" << endl;
                    cout << "|\t 2.Tim SP                                      |" << endl;
                    cout << "|\t 3.In danh sach SP                             |" << endl;
                    cout << "|\t 4.In ra dong San pham phu phu hop             |" << endl;
                    cout << "|\t 5.Sap xem theo ma SP                          |" << endl;
                    cout << "|\t 6.Sap xep theo gia SP                         |"<<endl; 
                    cout << "|\t 7.Xoa SP theo Ma SP                           |"<< endl; 
                    cout << "|\t 8.Chinh sua thong tin SP theo Ma SP           |"<< endl; 
                    cout << "|\t 9.Ket Thuc Ngay                               |"<<endl; 
                    cout << "|\t 10.Thoat                                      |" << endl;
                    cout << "|------------------------------------------------------|"<<endl;
                    cout << "Moi Nhap Cong Viec                               " << endl;
                    cin>> sn ; 
                    switch (sn)
                    {
                    case 1:
                    {
                        system("cls");
                        SN.AddF(); 
                        SN.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 2:
                    {system("cls");
                        int x ; 
                        cout<<"Nhap MaSP San Pham can tim: "<<endl; 
                        cin>> x ; 
                        
                        if (SN.Find(x)==NULL) 
                        {
                            cout<<"Cua hang kh co sp nay"<< endl; 
                        }
                        else 
                        {
                        cout<<"                           DANH SACH SNEAKER "<<endl;
                        cout<<setw(10)<<left<<"Ma Sp"<<"\t"<<setw(20)<<left<<"Ten Sp"<<"\t"<<setw(12)<<left<<"Gia Thanh"<<"\t"<<setw(15)<<left<<"So Luong"<<setw(2)<<left<<"Loai"<<"\t"<<endl;
                        SN.Find(x)->Show() ; 
                        }
                        
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 3:
                    {system("cls");
                        SN.SapxeptheoMaSP();
                        SN.Endday() ; 
                        SN.Show() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 4 :
                    {system("cls");
                        int x ; 
                        cout<<"Nhap MaSP San Pham can xem: "<<endl; 
                        cin>> x ; 
                        if (SN.Find(x)==NULL) 
                        {
                            cout<<"Cua hang kh co sp nay"<< endl; 
                        }
                        else 
                            SPPhuLienQuan(x,SPP) ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 5:
                    {system("cls");
                        SN.SapxeptheoMaSP() ; 
                        SN.Show() ;
                        SN.Endday() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break;  
                    }
                    case 6:
                    {system("cls");
                        SN.SapxeptheoGia() ; 
                        SN.Show() ; 
                        SN.Endday() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 7:
                    {system("cls");
                        int x ; 
                        cout<<"Nhap Ma SP"<< endl; 
                        cin>> x ; 
                        if (SN.Find(x)==NULL) 
                        {
                            cout<<"Cua hang kh co sp nay"<< endl; 
                        }
                        else
                        {
                            SN.DeletebyMaSP(x) ; 
                            cout<<"Xoa thanh cong"<<endl;
                        }
                        SN.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 8:
                    {system("cls");
                        int x ; 
                        cout<<"Nhap Ma SP"<< endl; 
                        cin>> x ; 
                        if (SN.Find(x)==NULL) 
                        {
                            cout<<"Cua hang kh co sp nay"<< endl; 
                        }
                        else
                            SN.ChinhsuaTTbyMaSP(x);
                        SN.Endday(); 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 9:
                    {system("cls");
                        SN.Endday() ; 
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break;  
                    }
                    case 10:{
                        system("cls");
                        break;} 
                    default:
                    {
                        cout<<"Ban Da Nhap Sai Moi Ban Nhap Lai"<< endl; 
                        break;
                    }
                    }

                } while (sn!=10);
            }
            /// hoa don 
            if(m==5)
            {
                do
                {system("cls");
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|                                                      |" << endl;
                    cout << "|                      DO AN PPL2                      |" << endl;
                    cout << "|         DE TAI: QUAN LI CUU HANG SNEAKER             |" << endl;
                    cout << "|      Sinh vien thuc hien:                            |" << endl;
                    cout << "|         1.Nguyen Hoang Vu                            |" << endl;
                    cout << "|         2.Tran Van Hai                               |" << endl;
                    cout << "|                                                      |" << endl;
                    cout <<"--------------------------------------------------------"<<endl; 
                    cout <<"--------------------------------------------------------"<<endl;
                    cout << "|\t           QUAN LY HOA DON                     |" << endl;
                    cout <<"|------------------------------------------------------|"<<endl;
                    cout << "|\t 1.Them Hoa Don                                |" << endl;
                    cout << "|\t 2.Tim Hoa Don                                 |" << endl;
                    cout << "|\t 3.In danh sach Hoa Don                        |" << endl;
                    cout << "|\t 4.Sap xep theo ma Hoa Don                     |" << endl;
                    cout << "|\t 5.Xoa Hoa Don theo ma HD                      |" << endl;
                    cout << "|\t 6.Ket Thuc Ngay                               |"<<endl; 
                    cout << "|\t 7.So sanh doanh thu theo thang trong nam      |"<< endl; 
                    cout << "|\t 9.Thoat                                       |" << endl;
                     cout <<"--------------------------------------------------------"<<endl;
                    cout << "Moi Nhap Cong Viec" << endl;
                    cin>> hd ; 
                    switch (hd)
                    {
                    case 1:
                    {system("cls");
                        HD.Nhap(HV,NV,SN,SPP) ;
                        HD.Endday();
                        NV.Endday() ; 
                        HV.Endday() ; 
                        SPP.Endday() ; 
                        SN.Endday() ;  
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 2:
                    {system("cls");
                        int x ; 
                        cout<<"Nhap MaHD can tim: "<<endl; 
                        cin>> x ; 
                        if (HD.FindMAHD(x)==NULL) 
                        {
                            cout<<"Cua hang khong co hoa don nay"<< endl; 
                        }
                        else 
                        {
                            HD.FindMAHD(x)->Show() ; 
                        }
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 3:
                    {
                        system("cls");
                        HD.Show() ; 
                        // HD.InHoaDon();
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 4 :
                    {system("cls");
                        HD.SapXepTheoMaHD(HD) ; 
                        HD.Show() ; 
                        HD.Endday();
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break;  
                    }
                    case 5:
                    {
                        system("cls");
                        int x ; 
                        cout<<"Nhap Ma Hoa Don can xoa:" << endl; 
                        cin>> x; 
                        if (HD.FindMAHD(x)==NULL) 
                        {
                            cout<<"Cua hang khong co hoa don nay"<< endl; 
                        }
                        else 
                            HD.DeletebyMaHD(x) ;
                        HD.Endday();  
                         getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 6:
                    {
                        system("cls");
                        NV.Endday() ; 
                        HV.Endday() ; 
                        SPP.Endday() ; 
                        SN.Endday() ; 
                        HD.Endday() ; 
                        break ; 
                    }
                    case 7:
                    {
                        int year ; 
                        system("cls") ; 
                        cout<<"Nhap Nam"<< endl; 
                        cin>>year ; 
                        HD.Sosanhthang(year) ; 
                        getchar() ;
                        cout<<"Nhap Bat Ky De tro lai"<< endl; 
                        getchar() ;
                        system("cls"); 
                        break; 
                    }
                    case 9:{
                        system("cls");
                        break;} 
                    default:
                    {
                        cout<<"Ban Da Nhap Sai Moi Ban Nhap Lai"<< endl; 
                        break;
                    }
                    }

                } while (hd!=9);
            }
            if (m>5||m<0) 
            {
                system("cls") ; 
                cout<<"Ban da nhap sai moi nhap lai" << endl; 
            }   
    }   while (m != 0);
            return 0;
    
}
#endif