#ifndef foo_H
#define foo_H
#include<cstring>
#include<string>
#include<iostream>
#include"foo.h"
using namespace std;

class foo //ΚΛΑΣΗ ΚΟΜΒΟΥ
{

    public:
        foo();//ΚΕΝΟΣ ΚΑΤΑΣΤΕΥΑΣΤΗΣ
        foo(char*); //CONSTRACTOR ΔΗΜΙΟΥΡΓΙΑΣ ΚΟΜΒΟΥ ΜΕ ΤΗΝ ΛΕΞΗ ΕΙΣΑΓΩΓΗΣ
        virtual ~foo(); //ΚΑΤΑΣΤΡΟΦΕΑΣ
        char*Getdata(){return p;}
        foo *Getleft(){return left;}
        foo *Getright(){return right;}
        void Setleft(foo*val){left=val;}
        void Setright(foo*val){right=val;}
   /* protected:

    private:*/
        int height;
        char p[20];  //ΠΙΝΑΚΑΣ ΧΑΡΑΚΤΗΡΩΝ ΓΙΑ ΝΑ ΒΑΛΟΥΜΕ ΤΗΝ ΥΠΟΚΕΙΜΕΝΗ ΛΕΞΗ
        foo *left;  //LEFT ΚΟΜΒΟΥ
        foo *right;  //RIGHT ΚΟΜΒΟΥ
        int pl;     //ΠΛΗΘΟΣ ΕΜΦΑΝΙΣΕΩΝ ΛΕΞΗΣ
};



#endif // foo_H
