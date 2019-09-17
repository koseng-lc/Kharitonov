#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>

using namespace std;

#define UK_KOEF 2
#define ORDE 28

void printPersamaan(int* koef_kharitonov){
    for(int i=0;i<=ORDE;i++){
        stringstream ss;
        if(i==0){
            ss<<" + ";
        }else if(i<ORDE){
            ss<<"s^"<<i<<" + ";
        }else{
            ss<<"s^"<<i;
        }
        cout<< koef_kharitonov[i] << ss.str();
    }
    cout<<endl<<endl;
}

int main(){    
    //srand(time(0));

    int interval[ORDE+1][UK_KOEF];
    for(int i=0;i<=ORDE;i++){
        int x = rand()%26 + 1;
        interval[i][0] = x;
        interval[i][1] = x + rand()%6+1;
    }

    cout<<"Interval Polynomial"<<endl;

    for(int i=0;i<=ORDE;i++){
        stringstream ss;
        if(i==0){
            ss<<" + ";
        }else if(i<ORDE){
            ss<<"s^"<<i<<" + ";
        }else{
            ss<<"s^"<<i;
        }
        cout<< "[" << interval[i][0] << "," << interval[i][1] << "]" << ss.str();
    }

    cout<<endl<<endl;

    int koef_kharitonov1[ORDE+1];
    int koef_kharitonov2[ORDE+1];
    int koef_kharitonov3[ORDE+1];
    int koef_kharitonov4[ORDE+1];

    for(int i=0;i<=ORDE;i++){
        int tanda_pers1 = (i>>1)&0b00000001;
        int tanda_pers2 = (i&0b00000001) ^ ((i&0b00000010)>>1);
        int tanda_pers3 = !tanda_pers2;
        int tanda_pers4 = !tanda_pers1;

        koef_kharitonov1[i] = interval[i][tanda_pers1];
        koef_kharitonov2[i] = interval[i][tanda_pers2];
        koef_kharitonov3[i] = interval[i][tanda_pers3];
        koef_kharitonov4[i] = interval[i][tanda_pers4];
    }
    cout<<"Persamaan Kharitonov - 1"<<endl;
    printPersamaan(koef_kharitonov1);
    cout<<"Persamaan Kharitonov - 2"<<endl;
    printPersamaan(koef_kharitonov2);
    cout<<"Persamaan Kharitonov - 3"<<endl;
    printPersamaan(koef_kharitonov3);
    cout<<"Persamaan Kharitonov - 4"<<endl;
    printPersamaan(koef_kharitonov4);

    return 0;
}

