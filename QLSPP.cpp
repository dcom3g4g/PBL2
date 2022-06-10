#include"QLSPP.h"
#include<fstream>
QLSPP::QLSPP()
{
    this->head=NULL;
    this->tail=NULL;
}
QLSPP::~QLSPP()
{

}
SPPhu* QLSPP::Gethead()
{
    return this->head ; 
}
SPPhu* QLSPP::Gettail()
{
    return this->tail ; 
}
void QLSPP::Sethead(SPPhu *h) 
{
    this->head=h ; 
}
void QLSPP::Settail(SPPhu *t)
{
    this->tail=t; 
}
void QLSPP::AddF()
{
    SPPhu A; 
    this->n++ ; 
    SPPhu *p=new SPPhu; 
    A.Nhap(this) ; 
    p->Giathanh=A.Giathanh; 
    p->TenSP=A.TenSP;
    p->Type=A.Type;
    p->Soluong=A.Soluong;
    p->MaSP=A.MaSP;
    for (int i=0;i<5;i++)
        p->SPfor[i]=A.SPfor[i] ; 
    p->SPall=A.SPall ; 
    p->NEXT=NULL;
    p->PRE=NULL;
    if (this->head==NULL)
    {
        this->head=p; 
        this->tail=p; 
        this->head->PRE=NULL; 
        this->tail->PRE=NULL; 
        this->head->NEXT=NULL; 
        this->tail->NEXT=NULL; 
    }
    else 
    {
        this->head->PRE=p; 
        p->NEXT=this->head; 
        this->head=p; 
    }
}
void QLSPP::Show1()
{
    SPPhu* temp=this->head; 
    for (int i=0;i<this->n;i++)
    {
       
        temp->Show() ;
        temp=temp->NEXT; 
    }
}
void QLSPP::ISfromfile() 
{
    ifstream sp("D:\\VSCODE\\DA1\\sp.txt") ; 
    sp>> this->n ; 
    for (int i=0;i<this->n;i++)
    {
    SPPhu *p=new SPPhu; 
    
    sp>>p->MaSP ; 
    sp.ignore();
    getline(sp,p->TenSP) ; 
    sp>>p->Giathanh; 
    sp>>p->Soluong; 
    sp>>p->Type;
    int a; 
    sp>>a; 
    if (a==1) 
        p->SPall=true; 
    else
        p->SPall=false ; 
    for (int i=0;i<5;i++)
    {
        sp>> p->SPfor[i] ; 
    }
    p->NEXT=NULL;
    p->PRE=NULL;
    if (this->head==NULL)
    {
        this->head=p; 
        this->tail=p; 
        this->head->PRE=NULL; 
        this->tail->PRE=NULL; 
        this->head->NEXT=NULL; 
        this->tail->NEXT=NULL; 
    }
    else 
    {
        this->head->PRE=p; 
        p->NEXT=this->head; 
        this->head=p; 
    }
    }
}
void QLSPP::Endday()
{
    ofstream sp("D:\\VSCODE\\DA1\\sp.txt") ;
    SPPhu* temp=head; 
    sp<< this->n<<endl ; 
    for(int i=0;i<this->n;i++)
    {
        sp<<temp->MaSP<<endl  ; 
        sp<<temp->TenSP<<endl  ; 
        sp<<temp->Giathanh<<endl  ; 
        sp<<temp->Soluong<<endl  ; 
        sp<<temp->Type<<endl  ;
        sp<<temp->SPall<<endl;  ; 
        for (int i=0;i<5;i++)
        {
            sp<< temp->SPfor[i]<<" " ; 
        }
        temp=temp->NEXT ;  
        sp<<endl; 
    }
}
SPPhu* QLSPP::Find(int M)
{
    SPPhu* temp=this->head;  
    while(temp!=NULL)
    {
        if (temp->MaSP==M) return temp ; 
        temp=temp->NEXT ;
    }
    return NULL; 
}
void QLSPP::DeletebyMaSP(int M)
{
    SPPhu *p=Find(M)  ; 
    
    if (this->n<=1)   
    {
        this->head=NULL; 
        this->tail=NULL ; 
    }
    else if(p==this->head) 
    {
        this->head=p->NEXT ; 
    }
    else if(p==this->tail) 
    {
        this->tail=p->PRE ; 
    }
    else 
    {   
        p->PRE->NEXT=p->NEXT ;
        p->NEXT->PRE=p->PRE; 
    }
    this->n-- ; 
    cout<<"Xoa thanh cong"<<endl;
}
void QLSPP::SapxeptheoMaSP()
{
    SPPhu *d,*c; 
    d=this->head; 
    c=NULL; 
    while(d!=NULL)
    {
        c=d->NEXT ; 
        while (c!=NULL)
        {   
            if(d->MaSP>c->MaSP)
            {   SPPhu A;
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
            c=c->NEXT ; 
        }
        d=d->NEXT ; 
    }
}
void QLSPP::SapxeptheoGia()
{
    SPPhu *d,*c; 
    d=this->head; 
    c=NULL; 
    while(d!=NULL)
    {
        c=d->NEXT ; 
        while (c!=NULL)
        {   
            if(d->Giathanh>c->Giathanh)
            {   SPPhu A;
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
            c=c->NEXT ; 
        }
        d=d->NEXT ; 
    }
}
void QLSPP::ChinhsuaTTbyMaSP(int x) 
{   cout<<"Thong tin san pham phu Truoc khi chinh sua"<<endl;
    Find(x)->Show();
    cout<<"Nhap TT can sua: " << endl; 
    fflush(stdin) ; 
    cout << "Nhap ten SP : " << endl; 
    getline(cin,this->Find(x)->TenSP) ; 
    cout<< "Nhap Gia : " << endl; 
    cin >> this->Find(x)->Giathanh ;
    cout << "Nhap So luong:  " << endl; 
    cin >> this->Find(x)->Soluong;
    cout <<"Nhap Loai: " << endl; 
    cin>> this->Find(x)->Type ; 
    cout <<"Neu san pham phu hop vs tat cac cac loai sneaker Nhap 1 khong Nhap bat ky "<<endl; 
    int a; 
    cin>> a ; 
    if (a==1) 
        this->Find(x)->SPall=true ; 
    else 
        this->Find(x)->SPall=false ; 
    for (int i=0;i<n;i++)
    {
        cin >> this->Find(x)->SPfor[i] ; 
    }
}
void SPPhuLienQuan(int A , QLSPP B)
{
    SPPhu* p=B.Gethead() ;
    while(p!=NULL)
    {
        if(p->SPall==true) p->Show() ; 
        if (p->SPall==false)
        {
            for (int i=0;i<5;i++)
            if (p->SPfor[i]==A) p->Show() ; 
        }     
        p=p->NEXT ;   
    }
}
void QLSPP::CapNhat() 
{
    this->SapxeptheoMaSP() ; 
    SPPhu* x= this->head ; 
    for(int i=1;i<=this->n;i++)
    {
        x->MaSP=i ; 
        x=x->NEXT ; 
    }
}