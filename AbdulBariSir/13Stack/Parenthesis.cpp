#include<iostream>
#include "Stack.cpp"
using namespace std;

int isOperator(char ch) {
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='-' || ch=='('|| ch==')' || ch=='['|| ch==']') return 1;
    return 0;
}

int getPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;   
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        // case '-':
        //     return 4;
        case '(':
        case ')':
            return 4;
        case 'a':
        case 'b':
        case 'c':
        case 'x':
        case 'y':
        case 'z':
            return 4;
        default:
            return -1;
    }
}
 
int compute( int a, int b, char ch ) {
    int res=0;
    switch(ch){
        case '+':res=a+b;break;
        case '-':res=a-b;break;
        case '*':res=a*b;break;
        case '/':res=a/b;break;
        default:res=0;
    }   
    return res;
} 

char * infixToPostfix2 (char * str) {
    Stack <char>*st=new Stack<char>();
    int len=0,k=0;
    for(;str[len];len++);

    char *postfix=new char[len];

    for(int i=0; str[i]; i++) {
        while( !st->isEmpty() && getPrecedence(st->stackTop()) >= getPrecedence(str[i]) )  
            postfix[k++]=st->pop(); 
        st->push(str[i]);
    }

   while(!st->isEmpty()) postfix[k++]=st->pop();
   return postfix;

}

int isBalanced (char * str) {
    Stack <char>*st=new Stack<char>();
    for(int i=0; str[i] ; i++) {
        if(str[i]=='(' || str[i]=='[')
                st->push(str[i]);
        else if ( str[i]==')' || str[i]==']') 
            if(st->isEmpty()) return 0; 
            else st->pop();

    }
    return st->isEmpty() ? 1 : 0;
} 

char * inFixToPostFix (char *str) {
    Stack <char>*st=new Stack<char>();
    int len=0,k=0;

    for(;str[len];len++);

    char *postfix=new char[len];

    for(int i=0; str[i] ; i++) {
        if(!isOperator(str[i])) postfix[k++]=str[i];
        else {
            while( !st->isEmpty() && getPrecedence(st->stackTop()) >= getPrecedence(str[i]) )  
                postfix[k++]=st->pop(); 
            
            st->push(str[i]);
        }
    }
    while(!st->isEmpty()) postfix[k++]=st->pop();
    return postfix;
}

int evaluatePostfix(char *postfix) {
    Stack <int>*st=new Stack<int>();

    for(int i=0;postfix[i];i++) 
        if(!isOperator(postfix[i])) st->push(postfix[i]-'0');
        else st->push(compute(st->pop(),st->pop(),postfix[i]));
        
    return st->pop();
}

int main() {
    // char str[]="((a+b)*(c-d))";
    // cout<<isBalanced(str)<<" isBalanced "<<endl; 

    // char str1[]="a+b*c-d/e";
    char str1[]="3*5+6/2-4";
    char *postfix=inFixToPostFix(str1);
    cout<<"Postfix is "<<postfix<<endl;

    int value=evaluatePostfix(postfix);
    cout<<"evaluatePostfix "<<value<<endl;
 
    return 0;
}