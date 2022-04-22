#ifndef TREE_H
#define TREE_H
#include"foo.h"
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

class tree
{
    public:

        foo* root; //ΔΗΜΙΟΥΡΓΕΙΑ ΡΙΖΑΣ ΓΙΑ ΤΟ TREE

        tree(); //ΚΕΝΟΣ CONSTRACORAS ΠΟΥ ΑΡΧΙΚΟΠΟΙΕΙ ΤΗΝ ΡΙΖΑ

        ~tree(); //ΚΑΤΑΣΤΡΟΦΕΑΣ

        bool delete_tree(char*,foo*root); //ΜΕΙΩΣΗ ΤΟ ΠΛΗΘΟΣ ΕΜΦΑΝΙΣΕΩΝ ΜΙΑΣ ΛΕΞΗΣ

        void preorder(foo*root); //ΕΜΦΑΝΗΣΗ ΔΕΔΟΜΕΝΩΝ ΜΕ PREORDER ΤΑΞΙΝOΜΗΣΗ

        void inorder(foo*root);   //ΕΜΦΑΝΗΣΗ ΔΕΔΟΜΕΝΩΝ ΜΕ INORDER ΤΑΞΙΝΟΜΗΣΗ

        void postorder(foo*root); //ΕΜΦΑΝΙΣΗ ΔΕΔΟΜΕΝΩΝ ΜΕ POSTORDER ΤΑΞΙΝΟΜΗΣΗ

        bool search_tree(char*,foo*k); //ΣΥΝΑΡΤΗΣΗ ΑΝΑΖΗΤΗΣΗΣ ΛΕΞΗΣ

        void  insert_TREE(char*e); //ΣΥΝΑΡΤΗΣΗ ΕΙΣΑΓΩΓΗΣ ΛΕΞΕΩΝ

    protected:

    private:



};


#endif // TREE_H
