#include "AVL.h"
#include"tree.h"
#include<cstring>
#include<string>
#include"foo.h"

AVL::AVL():tree()
{
    Hleft=NULL;
    Hright=NULL;
}

void AVL::addnewAVL(char*e)
{
  foo*neo=new foo; //ΝΕΟΣ ΚΟΜΒΟΣ
    foo *parent;
    strcpy(neo->p,e);
    neo->left=NULL;
    neo->right=NULL;
    parent=NULL;

    if(root==NULL)
    {
        root=neo;
    }

    else
    {

     foo*par=root;

    while(par!=NULL)
         {
             parent=par;
         if(strcmp(e,par->p)>0)
           {par=par->right;
           Hright=1+Hright;

            }
         else

            {par=par->left;}
              Hleft=1+Hleft;
            }

      if(strcmp(e,parent->p)>0)
             {parent->right=neo;
          // cout<<"2"<<endl;

             }
      else
        {parent->left=neo;
               //   cout<<"1"<<endl;

        }
}
cout<<Hleft;
}

AVL::~AVL()
{
    //dtor
}
