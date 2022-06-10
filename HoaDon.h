#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"QLSN.h"
#include"QLSPP.h"
#include"SPHD.h"
using namespace std;
class HoaDon
{
    public:
    HoaDon *Next;
    HoaDon *Pre;
    int Ngay ; 
    int Thang ; 
    int Nam ; 
    int MaHD;
    int MaNV;
    int MaHV;
    int SoLuongSP; 
    int TongTien ; 
    SPHD k[100] ; 
    public:
    HoaDon();
    ~HoaDon();
    friend class QLSN ; 
    friend class QLSPP ; 
    void Show();
};