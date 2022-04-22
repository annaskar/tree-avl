#ifndef AVL_H
#define AVL_H

#include "tree.h"


class AVL : public tree
{
    public:
        AVL();

        void addnewAVL(char*);

        virtual ~AVL();

        int GetHleft() { return Hleft; }
        void SetHleft(int val) { Hleft = val; }
        int GetHright() { return Hright; }
        void SetHright(int val) { Hright = val; }

    protected:

    private:
        int Hleft=1;
        int Hright=1;
};

#endif // AVL_H
