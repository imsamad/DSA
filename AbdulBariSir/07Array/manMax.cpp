#include<iostream>
using namespace std;

int main() {
    int arr[10]={6,3,8,10,16,7,5,2,9,14};
    int min=arr[0],max=arr[0];

    for(int i=1 ; i< 10; i++)
        if(arr[i] < min) min=arr[i];
        else if(arr[i] > max) max=arr[i];

    cout<<"Min => "<<min<<endl;
    cout<<"Max => "<<max<<endl;

    return 0;
}