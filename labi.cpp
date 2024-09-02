#include <iostream>
#include "labirint.h"
#include "putman.h"

int main()
{
    setlocale(LC_ALL,"RUS");
    int mod;
    cout<<"Input:\n1 - Debug\n2) - Auto\n> ";
    cin>>mod;
    if (cin.fail()) {
        cout << "Ошибка ввода. Пожалуйста, введите целое число: или 1, или 2." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return 12;
    }
    if(mod<1){cout<<endl<<"Выбран некорректный режим"<<endl;return 12;}
    if(mod>2){cout<<endl<<"Выбран некорректный режим"<<endl;return 12;}
    if(mod ==1){
        int a;size_t mem;
        clock_t timee;
        cout<<"please, write size labirint"<<endl<<">";
        cin>>a;
        if (cin.fail()) {
            cout << "Ошибка ввода. Пожалуйста, введите целое число(размер лабиринта)" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return 12;
        }
        if((a>480)||(a<4)){cout<<"Пожалуста, перезапустите приложение и введите размер лабиринта >=4 и <=480"<<endl;return 12;}
        Labirint lab(a,mod);
        mem = lab.getMaxMem();
        Putman b(lab,mod);
        timee = b.Getresult();
    }
    if(mod ==2){
        size_t size_lab[5]={0};
        int mem_lab[5]={0};
        clock_t results[5];
        size_lab[0] = 30;
        for(int i=1;i<5;i++){
            size_lab[i] = size_lab[i-1]*2;
        }
        for(int i=0;i<5;i++){
            cout<<size_lab[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<5;i++){
            Labirint a(size_lab[i],mod);
            mem_lab[i] = a.getMaxMem();
            Putman b(a,mod);
            results[i] = b.Getresult();
        }
        for(int i=0;i<5;i++){
            cout<<endl<<"Размер лабиринта: "<<size_lab[i]<<" ";
            cout<<"Затрачиваемая память для создания "<<i+1<<" лабиринта: "<<mem_lab[i]<<" ";
            cout<<"Время его прохода "<<i+1<<" time: "<<results[i]<<endl<<endl;
        }
    }
    return 0;
}
