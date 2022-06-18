#include<iostream>

using namespace std;

void checkDuplicate(char * str){
    for(int i=0 ; str[i] ; i++) {
            // cout<<"str[i] "<<str[i]<<endl;
        if(str[i]==-1) continue;

        int count=1;
        char crtChr=str[i];
        for(int j=i+1; str[j] ; j++)
            if(str[j] == str[i]){ str[j]=-1; count++; }
        
        if(count > 1)
        cout<<crtChr << " occured "<< count <<" times "<<endl;

    }

}

void bitSet ( char *str) {
    int *bitSet= new int[26*2];

    for(int i=0; str[i] ; i++)
        if( str[i]>='a' && str[i]<='z' ) bitSet[str[i]-97]++;

    for(int i=0 ; i<26; i++) if(bitSet[i]>1 )   
        cout << (char)(i+ 97) << " occured " << bitSet[i] << " times" << endl; 
    
}

int main() {
    // for(int i=0; i<200; i++) cout<<i<<" = "<<(char)(i)<<endl;
    char  str[]="findings";
    // checkDuplicate(str);
    bitSet(str);
    return 0;
}