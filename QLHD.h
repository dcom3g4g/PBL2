#include"HoaDon.h"
#include"QLSN.h"
#include"QLSPP.h"
#include"QLHV.h"
#include"QLNV.h"
#include"SPHD.h"
#include<stdio.h>
#include<stdlib.h>
class QLHD
{
    private:
    HoaDon *head;
    HoaDon *tail;
    int n;
    public:
    QLHD();
    ~QLHD();
    HoaDon* Getheal() ;
    HoaDon* Gettail() ;
    void Sethead(HoaDon*);
    void Settail(HoaDon*); 
    friend class QLSN ;
    friend class QLSPP; 
    friend class QLNV ; 
    friend class QLHV ; 
    void Nhap(QLHV&,QLNV&,QLSN&,QLSPP&) ; 
    void Show() ; 
    void Endday() ; 
    void ISfromFile() ; 
    void SapXepTheoMaHD(QLHD&) ; 
    HoaDon* FindMAHD(int) ; 
    void DeletebyMaHD(int) ; 
    void ChinhsuaTTbyMaHD(int ,QLSN,QLSPP) ;  
    void Update(HoaDon*,QLHV&,QLNV&,QLSN&,QLSPP&) ;
    void Sosanhthang(int year) ;  
};