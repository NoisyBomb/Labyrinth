#ifndef LABIRINT_H
#define LABIRINT_H
#include "elementlabirinta.h"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Labirint
{
    private:
    static size_t DynamicMemory;
    static size_t MaxMemory;
    static void memUp(size_t);
    static void memDown(size_t);
    size_t ROWS;
    size_t COLS;
    int x1,y1;
    int x2,y2;
    int x3, y3;
    int x4, y4;
    ElementLabirinta **labi;
    int **uzls;
    int topi=0;
    bool **visiter;
    public:
        static size_t getDynMem();
        static size_t getMaxMem();
        static void setMemCounter(size_t, size_t);
        Labirint(size_t,int);
        void create_labi();
        void view_labi();
        void init_labi();
        void select_tekmem(int co);
        void size_uzls_visiter_laba();
        int get_tekmem();
        void generateMaze(ElementLabirinta **maze, int &numPaths);
        bool isPathExist(ElementLabirinta **maze, int startRow, int startCol, int finishRow, int finishCol);
        void startsx3y3(int,int,int,int);
        void selectx1y1();
        void null_visiter();
        void here_startx3y3();
        void null_uzls();
        void null_topis();
        void init_top(int);
        virtual ~Labirint();
        void init_kordinats_start(int ,int );
        void init_kordinats_finish(int ,int);
        void getx1y1();
        void check_dirs(int*);
        void select_dir(int);
        void null_labirint();
        bool chek_finish();
        void here_start();
        void goUp();
        void goDown();
        void goRight();
        void goLeft();
        void plusuzels();
        void minusuzels();
        void veiw_visiter();
    protected:
};

#endif // LABIRINT_H
