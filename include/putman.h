#ifndef PUTMAN_H
#define PUTMAN_H
#include "labirint.h"
using namespace std;
class Putman
{
    public:
        Putman(Labirint&,int);
        void radar();
        virtual ~Putman();
        void create_dirsi();
        void init_dirsi();
        void view_dirsi();
        int radar(Labirint&);
        void copymass(int *mass);
        clock_t Getresult();
    protected:
    private:
        clock_t result;
        int *dirsi;
        int modi=0;
};

#endif // PUTMAN_H
