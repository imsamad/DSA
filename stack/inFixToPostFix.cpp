#include<iostream>
#include "LLstack.cpp"
using namespace std;
int pre(char op){
    if(op=='+' || op=='-')return 1;
    else if(op=='*' || op=='/')return 2;
    else if(op=='^') return 3;
    else if( op=='!' || op=='=') return 4;
    else return 5;
}

int isOperand(char x){
    return x=='+' || x=='-' || x=='*' || x=='/' ? 0 : 1;
}

char * toPostFix(char * inFix){
    int j=0,i=0;
    while(inFix[i]) i++;
    char *postFix=new char[i];
    Stack <char>*st=new Stack<char>();
    i=0;
    while(inFix[i]){
        if(st->isEmpty()) st->push(inFix[i++]);
        else 
            if(pre(inFix[i]) > pre(st->stackTop()))
                st->push(inFix[i++]);
            else postFix[j++]=st->pop();     
    }
    while(!st->isEmpty()) postFix[j++]=st->pop();
    return postFix;
}
int evaluate(char *postFix){
    int i=0;
    Stack <int>*st=new Stack<int>();
    while(postFix[i]){
        if(!isOperand(postFix[i])){
            int res=0,y=st->pop(),x=st->pop();
            switch (postFix[i++]) {
                case '+':  res=x+y; break;
                case '-':  res=x-y; break;
                case '*':  res=x*y; break;
                case '/':  res=x/y; break;
            }
            st->push(res);
        }else st->push((int)postFix[i++]-'0');
    }
    return st->pop();
}
int main(){
    // char  *inFix="a+b*c-/e";         
    // string inFix="a+b*c-d/e";       
    string inFix="3*5+6/2-4";       
    char *postFix=toPostFix(&inFix[0]);
    cout<<"Infix "<<inFix<<endl;
    cout<<"Postfix "<<postFix<<endl;
    cout<<"Evaluate "<<evaluate(postFix);
    cout<<endl;
    return 0;
}