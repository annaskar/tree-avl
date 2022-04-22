#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "tree.h"
#include"foo.h"
#include<cstring>
#include<string>
class AVL_tree : public tree,foo
{
    public:

        foo *rootAVL; // ΔΗΜΙΟΥΡΓΙΑ ΡΙΖΑΣ ΓΙΑ ΤΟ AVL TREE

        int height(foo*); //ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΕΠΙΣΤΡΕΔΗ ΤΟ ΥΨΟΣ ΤΟΥ ΔΕΝΤΡΟΥ

        foo*rightRotate(foo*); //ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΚΑΝΕΙ ΤΗΝ ΔΕΞΙΑ ΠΕΡΙΣΤΡΟΦΗ

        foo*leftRotate(foo*); //ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΚΑΝΕΙ ΤΗΝ ΑΡΙΣΤΕΡΗ ΠΕΡΙΣΤΡΟΦΗ

        AVL_tree();    //ΚΕΝΟΣ ΚΑΤΑΣΚΕΥΑΣΤΗΣ

        foo*insert_AVLTREE(char*,foo*); //ΣΥΝΑΡΤΗΣΗ ΕΙΣΑΓΩΓΗΣ ΛΕΞΕΩΝ ΣΤΟ AVL TREE

        virtual ~AVL_tree(); //ΚΑΤΑΣΤΡΟΦΕΑΣ


 /*   protected:

    private:*/

};

#endif // AVL_TREE_H
