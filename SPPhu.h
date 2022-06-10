#pragma once
class QLSN;
class QLSPP ;  
#include"Sneaker.h"
#include"SP.h"
class SPPhu: public SP
{
    public:
    SPPhu* NEXT; 
    SPPhu* PRE ; 
    int SPfor[5] ;
    bool SPall ; 
    public:
    friend class QLSPP ; 
    SPPhu() ; 
    ~SPPhu() ; 
    void Show() ; 
    void Nhap(QLSPP*) ; 
    friend void SneakerCoTheSuDung(SPPhu*,QLSN ); 
};