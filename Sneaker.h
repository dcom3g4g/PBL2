#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"SP.h"
class QLSN ; 
using namespace std ; 
class Sneaker: public SP 
{
    public:
    Sneaker *Next; 
    Sneaker *Pre ; 
    public:
    friend class QLSN ; 
    Sneaker() ; 
    ~Sneaker() ;
    void Nhap(QLSN*) ;  
    void Show(); 
}; 
