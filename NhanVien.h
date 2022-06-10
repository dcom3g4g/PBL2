#include<string>
using namespace std ; 
class NhanVien
{
    private:
    int MaNV ; 
    string Ten ; 
    int sdt ; 
    int KPI ; 
    int n;  
    public:
    NhanVien() ; 
    ~NhanVien() ; 
    void Show()  ; 
    int GetMaNV() ; 
    void SetMaNV(int ) ; 
    string GetTen() ; 
    void SetTen(string ) ;
    int Getsdt() ; 
    void Setsdt(int) ;
    int GetSoluongban() ; 
    void SetSoluongban(int) ;  
    void Nhap() ; 
    void Nhap1() ; 
} ; 