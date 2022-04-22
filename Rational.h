#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{
    public:
        Rational();
        Rational(int,int);

        virtual ~Rational();

        int Getar() { return ar; }
        void Setar(int val) { ar = val; }
        int Getpar() { return par; }
        void Setpar(int val) { par = val; }

   /* protected:

    private:*/
        int ar;
        int par;
};



bool operator==(Rational a,Rational b)
{
    return(a.par==b.par && a.ar==b.ar);
}

#endif // RATIONAL_H
