#include<iostream>

using namespace std;

int pal(char *str, int s, int l) {
    if(l == s ) return 1;

    if(str[s] == str[l]) return pal(str, s+1 , l-1);
    return 0;

}
int main() {
    cout<<pal("RADAR",0,4)<<endl;    
    cout<<pal("REFER",0,4)<<endl;    
    cout<<pal("APPLE",0,4)<<endl;    
     return 0;
}