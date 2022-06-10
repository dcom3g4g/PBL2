#include"QLSN.h" 
#include<stdlib.h>
#include<fstream>
#include<iomanip>
QLSN::QLSN()
{
    this->head=NULL;
    this->tail=NULL;
}
QLSN::~QLSN()
{

}
Sneaker* QLSN::Gethead()
{
    return this->head ; 
}
Sneaker* QLSN::Gettail()
{
    return this->tail ; 
}
void QLSN::Sethead(Sneaker *h) 
{
    this->head=h ; 
}
void QLSN::Settail(Sneaker *t)
{
    this->tail=t; 
}
void QLSN::AddF()
{
    Sneaker A; 
    this->n++ ; 
    Sneaker *p=new Sneaker; 
    A.Nhap(this) ; 
    p->Giathanh=A.Giathanh; 
    p->TenSP=A.TenSP;
    p->Type=A.Type;
    p->Soluong=A.Soluong;
    p->MaSP=A.MaSP;
    p->Next=NULL;
    p->Pre=NULL;
    if (this->head==NULL)
    {
        this->head=p; 
        this->tail=p; 
        this->head->Pre=NULL; 
        this->tail->Pre=NULL; 
        this->head->Next=NULL; 
        this->tail->Next=NULL; 
    }
    else 
    {
        this->head->Pre=p; 
        p->Next=this->head; 
        this->head=p; 
    }
}
void QLSN::Show() 
{
    Sneaker* temp=head; 
    cout<<"                           DANH SACH SNEAKER "<<endl;
    cout<<setw(10)<<left<<"Ma Sp"<<"\t"<<setw(20)<<left<<"Ten Sp"<<"\t"<<setw(12)<<left<<"Gia Thanh"<<"\t"<<setw(15)<<left<<"So Luong"<<setw(2)<<left<<"Loai"<<"\t"<<endl;
    while (temp!=NULL)
    {   
        temp->Show() ; 
        temp=temp->Next ; 
    }
}
void QLSN::ISfromfile()
{
    ifstream sn("D:\\VSCODE\\DA1\\sneaker.txt") ; 
    sn>> this->n ; 
    for (int i=0;i<n;i++)
    {
    Sneaker *p=new Sneaker; 
    sn>>p->MaSP ; 
    sn.ignore();
    getline(sn,p->TenSP) ; 
    sn>>p->Giathanh; 
    sn>>p->Soluong; 
    sn>>p->Type; 
    p->Next=NULL;
    p->Pre=NULL;
    if (this->head==NULL)
    {
        this->head=p; 
        this->tail=p; 
        this->head->Pre=NULL; 
        this->tail->Pre=NULL; 
        this->head->Next=NULL; 
        this->tail->Next=NULL; 
    }
    else 
    {
        this->head->Pre=p; 
        p->Next=this->head; 
        this->head=p; 
    }
    }
}
void QLSN::Endday()
{
    ofstream sn("D:\\VSCODE\\DA1\\sneaker.txt") ;
    Sneaker* temp=head; 
    sn<< this->n<<endl ; 
    while(temp!=NULL)
    {
        sn<<temp->MaSP<<endl  ; 
        sn<<temp->TenSP<<endl  ; 
        sn<<temp->Giathanh<<endl  ; 
        sn<<temp->Soluong<<endl  ; 
        sn<<temp->Type<<endl  ;
        temp=temp->Next ;  
    }
}
Sneaker* QLSN::Find(int M)
{
    Sneaker* temp=head;  
    while(temp!=NULL)
    {
        if (temp->MaSP==M) return temp ; 
        temp=temp->Next ;
    }
    return NULL; 
}
void QLSN::DeletebyMaSP(int M)
{   
    Sneaker *p=Find(M)  ; 
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
}
void QLSN::SapxeptheoMaSP()
{
    Sneaker *d,*c; 
    d=this->head; 
    c=NULL; 
    while(d!=NULL)
    {
        c=d->Next ; 
        while (c!=NULL)
        {   
            if(d->MaSP>c->MaSP)
            {   Sneaker A;
                A.Giathanh=c->Giathanh ; 
                A.TenSP=c->TenSP ; 
                A.Type=c->Type ; 
                A.MaSP=c->MaSP ; 
                A.Soluong=c->Soluong ; 
                c->Giathanh=d->Giathanh ;
                c->TenSP=d->TenSP ;
                c->Type=d->Type ;
                c->Soluong=d->Soluong ; 
                c->MaSP=d->MaSP ;
                d->Giathanh=A.Giathanh ;
                d->TenSP=A.TenSP ;
                d->Type=A.Type ;
                d->Soluong=A.Soluong ; 
                d->MaSP=A.MaSP ;
            }
            c=c->Next ; 
        }
        d=d->Next ; 
    }
}
void QLSN::ChinhsuaTTbyMaSP(int x) 
{   cout<<"Thong tin Sneaker truoc khi chinh sua"<<endl;
    cout<<setw(10)<<left<<"Ma Sp"<<"\t"<<setw(20)<<left<<"Ten Sp"<<"\t"<<setw(12)<<left<<"Gia Thanh"<<"\t"<<setw(15)<<left<<"So Luong"<<setw(2)<<left<<"Loai"<<"\t"<<endl;
    Find(x)->Show() ;
    cout<<"Nhap TT can sua: " << endl; 
    cout << "Nhap Ma SP: " << endl; 
    cin >> this->Find(x)->MaSP ; 
    fflush(stdin) ; 
    cout << "Nhap ten SP : " << endl; 
    getline(cin,this->Find(x)->TenSP) ; 
    cout<< "Nhap Gia : " << endl; 
    cin >> this->Find(x)->Giathanh ;
    cout << "Nhap So luong:  " << endl; 
    cin >> this->Find(x)->Soluong;
    cout <<"Nhap Loai: " << endl; 
    cin>> this->Find(x)->Type ; 
}
void QLSN::SapxeptheoGia()
{
    Sneaker *d,*c; 
    d=this->head; 
    c=NULL; 
    while(d!=NULL)
    {
        c=d->Next ; 
        while (c!=NULL)
        {   
            if(d->Giathanh>c->Giathanh)
            {   Sneaker A;
                A.Giathanh=c->Giathanh ; 
                A.TenSP=c->TenSP ; 
                A.Type=c->Type ; 
                A.MaSP=c->MaSP ; 
                A.Soluong=c->Soluong ; 
                c->Giathanh=d->Giathanh ;
                c->TenSP=d->TenSP ;
                c->Type=d->Type ;
                c->Soluong=d->Soluong ; 
                c->MaSP=d->MaSP ;
                d->Giathanh=A.Giathanh ;
                d->TenSP=A.TenSP ;
                d->Type=A.Type ;
                d->Soluong=A.Soluong ; 
                d->MaSP=A.MaSP ;
            }
            c=c->Next ; 
        }
        d=d->Next ; 
    }
}
void SneakerCoTheSuDung(SPPhu *C,QLSN A )
{
    Sneaker *p=A.Gethead() ;
    cout <<"=======CAC SNEAKER CO THE SU DUNG SAN PHAM NAY======="<<endl; 
    if (C->SPall==true)  
        A.Show() ; 
    else
    {
        while (p!=NULL)
        {
            for (int i=0;i<5;i++)
            {
                if (C->SPfor[i]==p->MaSP)
                p->Show() ; 
            }
        p=p->Next ; 
        }
    } 
}
