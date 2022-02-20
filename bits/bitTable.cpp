#include<iostream>
using namespace std;
             
int main(){
    for(int i=0;i<100;i++){
        for(int j=1;j<=20;j++)
        cout<< i << "<<" << j << " = " << (i<<j) << ", " << i << ">>" << j << " = " << (i>>j) <<endl;             
        cout<< "==================" <<endl;
    }
    return 0;
}