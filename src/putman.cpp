#include "putman.h"

void shuffle_2(int*arr){
    if(arr==nullptr)return;
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i =0; i<4;i++){
        int randomIndex=rand()%4;
        int temp = arr[i];
        arr[i]=arr[randomIndex];
        arr[randomIndex]=temp;
    }
}
Putman::Putman(Labirint& co,int mod)
{
    clock_t startPos, finishPos;
    modi=mod;
    if(mod==1){
        create_dirsi();
        co.here_start();
        while(true){
            int rada = radar(co);
            if(rada == 5){break;};
        }
        cout<<"finish!"<<endl;
        return;
    }
    if(mod==2){
        create_dirsi();
        co.null_labirint();
        startPos = clock();
        while(true){
            int rada = radar(co);
            if(rada == 5){finishPos = clock();result=finishPos-startPos;if(modi==1){cout<<"finish!"<<endl;}break;}
        }
        return;
    }
}
clock_t Putman::Getresult(){
    return result;
}
Putman::~Putman(){
    delete[] dirsi;
}
void Putman::create_dirsi(){
    dirsi= new int[4];
}
void Putman::init_dirsi(){
    for(int i=0;i<4;i++){
        dirsi[i]=i+1;
    }
}
int check_count(int *mass){
    int counti=0;
    for(int i=0;i<4;i++){
        if(mass[i]>0)counti+=1;
    }
    return counti;
}
void Putman::copymass(int *mass){
    if(mass==nullptr)return;
    for(int i=0;i<4;i++){
        if(mass[i]!=0){dirsi[i]=i+1;}
        else{dirsi[i]=0;}
    }
}

int Putman::radar(Labirint& co){
    init_dirsi();
    bool checki = co.chek_finish(); int j=0;
    if(checki){return 5;}
    int mass[4]={0};
    co.check_dirs(mass);
    copymass(mass);
    int counti = check_count(dirsi);
    if(counti==0){
        co.minusuzels();
        if(modi==1){co.veiw_visiter();}
        return 199;
    }
    if(counti>1){co.plusuzels();if(modi==1){co.veiw_visiter();}}
    //shuffle_2(dirsi);
    int po;
    while(j<4){
        po=dirsi[j];
        if(po!=0){
            break;
        }
        j++;
    }
    switch(po){
        case 1:{
            co.select_dir(1);
            if(modi==1){co.veiw_visiter();}
            break;
        }
        case 2:{
            co.select_dir(2);
            if(modi==1){co.veiw_visiter();}
            break;
        }
        case 3:{
            co.select_dir(3);
            if(modi==1){co.veiw_visiter();}
            break;
        }
        case 4:{
            co.select_dir(4);
            if(modi==1){co.veiw_visiter();}
            break;
        }
        default:
        {
            break;
        }
    }
    return 2;
}

