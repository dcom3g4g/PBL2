#include"QLHD.h"
#include<fstream>
#include<iomanip>
QLHD::QLHD()
{
    this->head=NULL;
    this->tail=NULL;
}
QLHD::~QLHD()
{

}
HoaDon* QLHD::Getheal()
{
    return this->head;
}
HoaDon* QLHD::Gettail()
{
    return this->tail;
}
void QLHD::Sethead(HoaDon *h)
{
    this->head=h;
}
void QLHD::Settail(HoaDon *t)
{
    this->tail=t;
}
void QLHD::Nhap(QLHV& C,QLNV& D,QLSN& A,QLSPP& B)
{   
    this->n++ ; 
    HoaDon *a=new HoaDon ; 
    int t=0; 
    Sneaker* H=A.Gethead() ; 
    SPPhu*H1=B.Gethead() ; 
    cout<<" Nhap Ngay, thang, nam: " <<endl; 
    cin>> a->Ngay  ; 
    cin>> a->Thang ; 
    cin>> a->Nam ; 
    int b; 
    do
    {
        cout<<"Nhap Ma Hoa Don"<< endl; 
        cin>>a->MaHD ; 
        if (this->FindMAHD(a->MaHD)!=NULL)
        cout<<"Ma HD nay da ton tai moi nhap lai"<< endl; 
    } while (this->FindMAHD(a->MaHD)!=NULL) ; 
    do
    {
        cout<<"Nhap Ma NV"<< endl; 
        cin>>a->MaNV ; 
        if (D.Find(a->MaNV)==NULL)
        cout<<"Ma NV nay khong co moi nhap lai"<< endl; 
    } while (D.Find(a->MaNV)==NULL) ; 
    do
    {
        cout<<"Nhap Ma HV"<< endl; 
        cin>>a->MaHV ; 
        if (C.Find(a->MaHV)==NULL)
        cout<<"Ma HV nay khong co moi nhap lai"<< endl; 
    } while (C.Find(a->MaHV)==NULL) ; 
    do 
    {
    cout <<"Nhap So Luong Mat Hang" << endl; 
    cin >> a->SoLuongSP ; 
        if (a->SoLuongSP<=0) 
            cout<<"Ban Nhap Sai Moi Nhap Lai"<< endl; 
    }
    while (a->SoLuongSP<=0) ; 
    for (int i=0;i<a->SoLuongSP;i++)
    {
        do
        {
        cout<<"Sneaker nhap 1 , San pham phu nhap 0:"<< endl; 
        cin>> a->k[i].check ; 
            if (a->k[i].check!=1 && a->k[i].check!=0)
                cout<<"Ban Da Nhap Sai Moi Nhap Lai"<< endl; 
        } while (a->k[i].check!=1 && a->k[i].check!=0) ; 
        if (a->k[i].check==1)
        {
            do 
            {
                cout<< "Nhap Ma SP" <<i+1 <<": "<< endl;
                cin>> a->k[i].MaSP;
                if (A.Find(a->k[i].MaSP)==NULL)
                    cout<<"Cua Hang Khong Co Sp nay"<< endl; 
            } while (A.Find(a->k[i].MaSP)==NULL) ; 
            
            a->k[i].TenSP=A.Find(a->k[i].MaSP)->TenSP  ; 
            a->k[i].GiaThanh=A.Find(a->k[i].MaSP)->Giathanh  ; 
            cout <<"Nhap So Luong: "<< endl; 
            cin>> a->k[i].SoLuong ;
            while (a->k[i].SoLuong > A.Find(a->k[i].MaSP)->Soluong)
            
            {
                cout<<"So luong hang con lai khong du moi nhap lai"<< endl; 
                cout <<"Nhap So Luong: "<< endl; 
                cin>> a->k[i].SoLuong ;
            }
            t=t+ a->k[i].GiaThanh* a->k[i].SoLuong ; 
        }
        else 
        {
            do 
            {
                cout<< "Nhap Ma SP" <<i+1 <<": "<< endl;
                cin>> a->k[i].MaSP;
                if (B.Find(a->k[i].MaSP)==NULL)
                    cout<<"Cua Hang Khong Co Sp nay"<< endl; 
            } while (B.Find(a->k[i].MaSP)==NULL) ; 
            a->k[i].TenSP=B.Find(a->k[i].MaSP)->TenSP  ; 
            a->k[i].GiaThanh=B.Find(a->k[i].MaSP)->Giathanh  ; 
            cout <<"Nhap So Luong: "<< endl; 
            cin>> a->k[i].SoLuong ;
            while (a->k[i].SoLuong > B.Find(a->k[i].MaSP)->Soluong)
            
            {
                cout<<"So luong hang con lai khong du moi nhap lai"<< endl; 
                cout <<"Nhap So Luong: "<< endl; 
                cin>> a->k[i].SoLuong ;
            }
            t=t+ a->k[i].GiaThanh* a->k[i].SoLuong ; 
        }
        cout<<"     -----------"<< endl; 
    }
    a->TongTien=t-(t/100*(C.Find(a->MaHV)->Getlevel()*2)) ; 
    a->Next=NULL;
    a->Pre=NULL;
    if (this->head==NULL)
    {    
        this->head=a; 
        this->tail=a; 
        this->head->Pre=NULL; 
        this->tail->Pre=NULL; 
        this->head->Next=NULL; 
        this->tail->Next=NULL; 
    }
    else 
    {
        this->head->Pre=a; 
        a->Next=this->head;
 
        this->head=a; 
    }
    Update(a,C,D,A,B) ; 
}
void QLHD::Show()
{
    HoaDon* temp=this->head; 
    int i=0; 
    while (i!=this->n)
    {
        i++ ; 
        temp->Show() ;
        temp=temp->Next; 
    }
}
void QLHD::Endday()
{
    ofstream hd("D:\\VSCODE\\DA1\\hoadon.txt") ;
    HoaDon* temp=head; 
    hd<< this->n<<endl ;
    int i=0; 
    while(temp!=NULL)
    {
        hd<<temp->Ngay<<endl;
        hd<<temp->Thang<<endl;
        hd<<temp->Nam<<endl;
        hd<<temp->MaHD<<endl;
        hd<<temp->MaNV<<endl;
        hd<<temp->MaHV<<endl;
        hd<<temp->SoLuongSP<<endl;
        for(int j=0;j<(temp->SoLuongSP);j++)
        {
            hd<<temp->k[i].MaSP<<endl  ;
            hd<<temp->k[i].TenSP<< endl; 
            hd<<temp->k[i].GiaThanh<<endl  ; 
            hd<<temp->k[i].SoLuong<<endl  ; 
            
        } 
        hd<<temp->TongTien<<endl;

        temp=temp->Next ;  
    }
}
void QLHD::ISfromFile()
{
    ifstream sn("D:\\VSCODE\\DA1\\hoadon.txt") ; 
    sn>> this->n ; 
    int t=0; 
    for (int i=0;i<this->n;i++)
    {
    HoaDon *a=new HoaDon; 
    sn.ignore();
    sn>>a->Ngay;
    sn>>a->Thang;
    sn>>a->Nam;
    sn>>a->MaHD ; 
    sn>>a->MaNV;
    sn>>a->MaHV;
    sn>>a->SoLuongSP;  
    for(int j=0;j<(a->SoLuongSP);j++ )
    {
        sn>>(a->k+j)->MaSP;
        sn.ignore() ; 
        getline(sn,(a->k+j)->TenSP) ; 
        sn>>(a->k+j)->GiaThanh;
        sn>>(a->k+j)->SoLuong;
    }
    sn>>a->TongTien;
    a->Next=NULL;
    a->Pre=NULL;
    if (this->head==NULL)
    {
        this->head=a; 
        this->tail=a; 
        this->head->Pre=NULL; 
        this->tail->Pre=NULL; 
        this->head->Next=NULL; 
        this->tail->Next=NULL; 
    }
    else 
    {
        this->head->Pre=a; 
        a->Next=this->head; 
        this->head=a; 
    }
    }
}
HoaDon* QLHD::FindMAHD(int M)
{
    HoaDon* temp=this->head;  
    while(temp!=NULL)
    {
        if (temp->MaHD==M) return temp ; 
        temp=temp->Next ;
    }
    return NULL; 
}
void QLHD::DeletebyMaHD(int M)
{
    HoaDon *p=FindMAHD(M)  ; 
    if (this->n<=1)   
    {
        this->head=NULL; 
        this->tail=NULL ; 
    }
    else if(p==this->head) 
    {
        this->head=p->Next ; 
    }
    else if(p==this->tail) 
    {
        this->tail=p->Pre ; 
    }
    else 
    {   
        p->Pre->Next=p->Next ;
        p->Next->Pre=p->Pre; 
    }
    this->n--;
    cout<<"Da Xoa Thanh Cong "<< endl; 
}
void QLHD::SapXepTheoMaHD(QLHD& B)
{
    HoaDon *d,*c; 
    d=this->head; 
    c=NULL; 
    while(d!=NULL)
    {
        c=d->Next ; 
        while (c!=NULL)
        {   
            if(d->MaHD>c->MaHD)
            {   HoaDon A;
                A.Ngay=d->Ngay ; 
                A.Thang=d->Thang ;
                A.Nam=d->Nam ;  
                A.MaHD=d->MaHD;
                A.MaNV=d->MaNV;
                A.MaHV=d->MaHV ; 
                A.SoLuongSP=d->SoLuongSP; 
                A.TongTien=d->TongTien ; 
                for (int i=0;i<A.SoLuongSP;i++)
                {
                    A.k[i].check=d->k[i].check ; 
                    A.k[i].TenSP=d->k[i].TenSP ; 
                    A.k[i].GiaThanh=d->k[i].GiaThanh ; 
                    A.k[i].SoLuong=d->k[i].SoLuong ;
                    A.k[i].MaSP=d->k[i].MaSP ;  
                } 
                d->Ngay=c->Ngay ; 
                d->Thang=c->Thang ;
                d->Nam=c->Nam ;  
                d->MaHD=c->MaHD;
                d->MaNV=c->MaNV;
                d->MaHV=c->MaHV ; 
                d->SoLuongSP=c->SoLuongSP; 
                d->TongTien=c->TongTien ; 
                for (int i=0;i<d->SoLuongSP;i++)
                {
                    d->k[i].check=c->k[i].check ; 
                    d->k[i].TenSP=c->k[i].TenSP ; 
                    d->k[i].GiaThanh=c->k[i].GiaThanh ; 
                    d->k[i].SoLuong=c->k[i].SoLuong ;
                    d->k[i].MaSP=c->k[i].MaSP ;  
                }
                c->Ngay=A.Ngay ; 
                c->Thang=A.Thang ;
                c->Nam=A.Nam ;  
                c->MaHD=A.MaHD;
                c->MaNV=A.MaNV;
                c->MaHV=A.MaHV ; 
                c->SoLuongSP=A.SoLuongSP; 
                c->TongTien=A.TongTien ; 
                for (int i=0;i<c->SoLuongSP;i++)
                {
                    c->k[i].check=A.k[i].check ; 
                    c->k[i].TenSP=A.k[i].TenSP ; 
                    c->k[i].GiaThanh=A.k[i].GiaThanh ; 
                    c->k[i].SoLuong=A.k[i].SoLuong ;
                    c->k[i].MaSP=A.k[i].MaSP ;   
                } 
            }
            c=c->Next ;
        }
        d=d->Next ; 
    }
}
void QLHD::ChinhsuaTTbyMaHD(int x,QLSN A,QLSPP B) 
{
    HoaDon* a=FindMAHD(x) ; 
    int t=0; 
    cout<<" Nhap Ngay, thang, nam: " <<endl; 
    cin>> a->Ngay  ; 
    cin>> a->Thang ; 
    cin>> a->Nam ; 
    cout<< "Nhap Ma HD: "<< endl;
    cin>> a->MaHD;
    cout<< "Nhap Ma NV: "<< endl;
    cin>> a->MaNV;
    cout<< "Nhap Ma HV: "<< endl;
    cin>> a->MaHV;
    cout <<"Nhap So Luong Mat Hang" << endl; 
    cin >> a->SoLuongSP ; 
    for (int i=0;i<a->SoLuongSP;i++)
    {
        cout<<"Sneaker nhap 1 , San pham phu nhap 0:"<< endl; 
        cin>> a->k[i].check ; 
        if (a->k[i].check==1)
        {
            cout<< "Nhap Ma SP" <<i+1 <<": "<< endl;
            cin>> a->k[i].MaSP;
            a->k[i].TenSP=A.Find(a->k[i].MaSP)->TenSP  ; 
            a->k[i].GiaThanh=A.Find(a->k[i].MaSP)->Giathanh  ; 
            cout <<"Nhap So Luong: "<< endl; 
            cin>> a->k[i].SoLuong ;
            t=t+ a->k[i].GiaThanh* a->k[i].SoLuong ; 
        }
        else 
        {
            cout<< "Nhap Ma SP" <<i+1 <<": "<< endl;
            cin>> a->k[i].MaSP;
            a->k[i].TenSP=B.Find(a->k[i].MaSP)->TenSP  ; 
            a->k[i].GiaThanh=B.Find(a->k[i].MaSP)->Giathanh  ; 
            cout <<"Nhap So Luong: "<< endl; 
            cin>> a->k[i].SoLuong ;
            t=t+ a->k[i].GiaThanh* a->k[i].SoLuong ; 
        }
        cout<<"     -----------"<< endl; 
    }
    a->TongTien=t ; 
}
void QLHD::Update(HoaDon *A ,QLHV& B ,QLNV& C,QLSN& D,QLSPP& E) 
{
    B.Find(A->MaHV)->Settong(B.Find(A->MaHV)->Gettong() + A->TongTien) ; 
    C.Find(A->MaNV)->SetSoluongban(C.Find(A->MaNV)->GetSoluongban() + A->TongTien/100000) ;
    
    for (int i=0;i<A->SoLuongSP;i++)
    {
        if(A->k[i].check==1)
        {
            D.Find(A->k[i].MaSP)->Soluong=D.Find(A->k[i].MaSP)->Soluong - A->k[i].SoLuong ; 
        }
        if(A->k[i].check==0)
        {
            E.Find(A->k[i].MaSP)->Soluong=E.Find(A->k[i].MaSP)->Soluong - A->k[i].SoLuong ; 
        }
    } 
}
void QLHD::Sosanhthang(int year)
{
    int b[13] ; 
    for(int i=1;i<13;i++)
    b[i]=0; 
    int sum=0 ; 
    HoaDon* bd=head ; 
    while(bd!=NULL)
    {  
        if (bd->Nam==year)
        {
            b[bd->Thang]=b[bd->Thang]+bd->TongTien ; 
            sum+=bd->TongTien ; 
        }
        bd=bd->Next ; 
    }
    if (sum==0)
        cout <<"Nam Nay Khong Co Hoa Don Nao"<< endl; 
    else 
    {
    cout<< "          THONG KE DOANH SO NAM "<<year << endl<< endl; ;  
    cout<<"\t\t"<< "Thang "<<"\t"<<setw(15)<<"\t"<< "Tong tien" <<"\t"<< setw(18)<<"\t"<<"Ty le"<< endl; 
    for (int i=1;i<=12;i++)
    {
        float x; 
        x=float(b[i])/float(sum)*100 ; 
    cout<<"\t"<<setw(2)<<"\t"<<i<<"\t\t"<<setw(19) <<b[i]<<"\t"<<setw(20) <<"\t"<<x <<"%"<< endl; 
    }
    cout<<"\t\t Tong Tien: "<<sum <<endl; 
    }
}