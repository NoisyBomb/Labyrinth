#ifndef ELEMENTLABIRINTA_H
#define ELEMENTLABIRINTA_H


class ElementLabirinta
{
    private:
    int x0,y0;
    int wall;
    public:
        ElementLabirinta();
        ElementLabirinta(int,int);
        void Setx0y0(int,int);
        void Setwall0(int);
        int Getx0y0(int*,int*);
        int Getwall0();
        void operator=(const int ObjM);
        void InitWall(int wall0);
        virtual ~ElementLabirinta();

    protected:
};

#endif // ELEMENTLABIRINTA_H
