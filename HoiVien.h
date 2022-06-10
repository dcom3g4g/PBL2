#include<string>
using namespace std ; 
class HoiVien
{
    private:
    int MaHV ; 
    string Ten ; 
    int sdt ; 
    int level ;  
    int tong ; 
    public:
    HoiVien() ; 
    ~HoiVien() ; 
    void Show()  ; 
    int GetMaHV() ; 
    void SetMaHV(int ) ; 
    string GetTen() ; 
    void SetTen(string ) ;
    int Getsdt() ; 
    void Setsdt(int) ;
    int Getlevel() ; 
    void Settong(int) ; 
    int Gettong() ; 
    void Setlevel(int) ;  
    void Nhap() ; 
    void Nhap1() ; 
} ; 