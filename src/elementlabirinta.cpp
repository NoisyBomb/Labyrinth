#include "elementlabirinta.h"

ElementLabirinta::ElementLabirinta()
{
    x0=0;y0=0;
}

ElementLabirinta::ElementLabirinta(int x_0,int y_0):x0(x_0),y0(y_0)
{}

ElementLabirinta::~ElementLabirinta()
{}

void ElementLabirinta::Setx0y0(int x_0,int y_0){
    x0 = x_0;
    y0 = y_0;
}
void ElementLabirinta::Setwall0(int wall_0){
    wall = wall_0;
}
int ElementLabirinta::Getx0y0(int *x_0,int *y_0){
    *x_0=x0;
    *y_0= y0;
}
int ElementLabirinta::Getwall0(){
    return wall;
}
void ElementLabirinta::InitWall(int wall0){
    wall=wall0;
}
void ElementLabirinta::operator=(const int ObjM)
{
    wall = ObjM;
}


