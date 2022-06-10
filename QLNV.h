#include"NhanVien.h"
class QLNV
{
    private:
        int n ; 
        NhanVien *p ; 
    public:
        QLNV() ; 
        ~QLNV() ; 
        void ISfromfile() ;  
        void Show() ; 
        void luongall() ;
        void Sosanh() ;  
        void Endday() ; 
        void Add() ; 
        NhanVien* Find(int ) ; 
        void FindMSV(const int ) ; 
        void Update() ; 
        void Delete( int) ; 

}; 