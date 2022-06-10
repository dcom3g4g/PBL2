#pragma once
#include"SPPhu.h"
class QLSPP
{
    private:
    SPPhu *head ;
    SPPhu *tail ; 
    int n; 
    public:
    QLSPP() ; 
    ~QLSPP() ; 
    SPPhu* Gethead() ; 
    SPPhu* Gettail() ;
    void Sethead(SPPhu*);
    void Settail(SPPhu*);
    void AddF() ; 
    void Show1() ; 
    void ISfromfile() ;
    void Endday() ;
    SPPhu* Find(int ) ;
    void DeletebyMaSP(int );
    void SapxeptheoMaSP() ;
    void SapxeptheoGia() ;
    void ChinhsuaTTbyMaSP(int ) ;
    friend void SPPhuLienQuan(int ,QLSPP) ; 
    void CapNhat() ; 
};