#pragma once
#include"Sneaker.h"
#include"QLSPP.h"
class QLSN  
{
    private: 
    Sneaker *head ;
    Sneaker *tail ; 
    int n; 
    public:
    QLSN() ; 
    ~QLSN() ; 
    Sneaker* Gethead() ; 
    Sneaker* Gettail() ;
    void Sethead(Sneaker*);
    void Settail(Sneaker*); 
    void AddF() ;   
    void Show() ;   
    void ISfromfile() ; 
    void Endday() ; 
    Sneaker* Find(int ) ;
    void DeletebyMaSP(int ); 
    void SapxeptheoMaSP() ; 
    void SapxeptheoGia() ;  
    void ChinhsuaTTbyMaSP(int ) ; 
    friend void SneakerCoTheSuDung(SPPhu,QLSN );
} ; 