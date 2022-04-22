#include "foo.h"
#include<cstring>
#include<string>

foo::foo() //ΚΕΝΟΣ ΚΑΤΑΣΤΕΥΑΣΤΗΣ
{
    left=NULL; //ΔΕΙΚΤΗΣ LEFT ΣΤΟ ΚΕΝΟ
    right=NULL; //ΔΕΙΚΤΗΣ RIGHT ΣΤΟ ΚΕΝΟ
    pl=0;      //ΠΛΗΘΟΣ ΕΜΦΑΝΙΣΕΩΝ ΛΕΞΗΣ
   height=0;


//ctor
}

foo::foo(char*e) //ΔΗΜΙΟΥΡΓΙΑ ΚΟΜΒΟΥ
{
    strcpy(p,e); //ΑΝΤΙΓΡΑΦΗ ΛΕΞΗΣ
    left=NULL; //ΔΕΙΚΤΗΣ LEFT ΣΤΟ ΚΕΝΟ
    right=NULL; //ΔΕΙΚΤΗΣ RIGHT ΣΤΟ ΚΕΝΟ
    pl=0; //ΠΛΗΘΟΣ ΕΜΦΑΝΙΣΕΩΝ ΛΕΞΗΣ
    height=0;    //ΑΡΧΙΚΟΠΟΙΗΣ ΤΟΥ ΥΨΟΥΣ
    }



foo::~foo() //ΚΑΤΑΣΤΡΟΦΕΑΣ
{
    //dtor
}
