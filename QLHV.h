#include"HoiVien.h"
class QLHV
{
    private:
        int n ; 
        HoiVien *p ; 
    public:
        QLHV() ; 
        ~QLHV() ; 
        void ISfromfile() ;  
        void Show() ; 
        void Endday() ; 
        void Add() ; 
        HoiVien* Find(int) ; 
        void FindMSV(const int ) ; 
        void Update() ; 
        void Delete( int) ; 
        void Printbill() ; 
        void Uudai(int ) ; 
        
}; 