#include<iostream>
// #include "../13Stack/Stack.cpp"
#include "../14Queue/Q-Stack.cpp"
#include <limits>
using namespace std;



class Graph{
    int **A,size;
    const int I;
    public:
    Graph(int size=7):I(numeric_limits<int>::max()) {
    // visited=new int[size+1];    
    A=new int*[size+1];
    this->size=size;

    for(int i=0;i<=size;i++) A[i]=new int[size+1];


    // int ARR[size+1][size+1]={
    //     {0,0,0,0,0,0,0,0},
    //     {0,0,1,1,1,0,0,0},
    //     {0,1,0,1,0,0,0,0},
    //     {0,1,1,0,1,1,0,0},
    //     {0,1,0,1,0,1,0,0},
    //     {0,0,0,1,1,0,1,1},
    //     {0,0,0,0,0,1,0,0}, 
    //     {0,0,0,0,0,1,0,0}
    // };    
 
    int ARR[size+1][size+1]={
        {0,0,0,0,0,0,0,0},
        {0,I,25,I,I,I,5,I},
        {0,25,I,12,I,I,I,10},
        {0,I,12,I,8,I,I,I},
        {0,I,I,8,I,16,I,14},
        {0,I,I,8,16,I,20,18},
        {0,5,I,I,I,20,I,I},
        {0,I,10,I,14,18,I,I},
    };

    for(int i=1;i<=size;i++)   
        for(int j=1;j<=size;j++) 
            A[i][j]=ARR[i][j];
    }

    void display() { 

        for(int i=0;i<=size;i++){   
            for(int j=0;j<=size;j++) {
                cout<<A[i][j]<<", ";
            }
            cout<<endl;   
        }   
    }


    void BFS(int i=1) {

    int *visited=new int[size+1];
        cout<<"BFS - ";
        Queue <int>*q=new Queue<int>();       
        cout<<i<<", ";
        q->enqueue(i);
        visited[i]=1;

        int u;
        while(!q->isEmpty()) {
            u=q->dequeue();

            for(int v=1;v<=size;v++)
                if(!visited[v] && A[u][v]==1 ) {
                    cout<<v<<", ";
                    q->enqueue(v);
                    visited[v]=1;
                }
        }
    delete visited;
    visited=new int[size+1];

    cout<<endl;
    }
    
    void DFS_FUN(int u,int *visited)  {
        
        if(!visited[u]) {
            cout<<u<<", ";
            visited[u]=1;
            for(int v=1;v<=size;v++) if(A[u][v]==1 && !visited[v] ) DFS_FUN(v,visited);
        }    
    
    }
    
    void DFS(int u) {
        cout<<"DFS - ";
        int *visited=new int[size+1];
        DFS_FUN(u,visited);
        cout<<endl;
    }
    void prims() {
        int span[2][size-1];
        
        int near[size+1];
        for(int i=1;i<=size;i++) near[i]=I;
        
        int u,v,min=I;
        
        for(int i=1;i<=size;i++) {
            for(int j=1;j<=size;j++){
                    if(A[i][j] < min ) {
                        min=A[i][j];
                        u=i; v=j;
                    }
            }
        }
        span[0][0]=u; span[1][0]=v;
        near[u]=near[v]=0;
        // for(int i=0;i<size+1;i++) cout<<near[i]<<"\t";    
        // cout<<endl;

        for(int x=1;x<=size;x++)
            if(!near[x]) continue;
            else if(A[x][u] < A[x][v]  )
                near[x]=u;
            else 
                near[x]=v;


        for(int i=1;i<size-1;i++){

            int min=I,a;

            for(int j=1;j<=size;j++) {
                if(near[j] && A[j][near[j]] < min ) {
                    min=A[j][near[j]];
                    a=j;
                }
            }

            // span[0][i]=a; span[1][i]=near[a];
            span[0][i]=near[a]; span[1][i]=a;

            near[a]=0;

            for(int j=1;j<=size;j++) {
                if(near[j] && A[j][a] < A[j][near[j]] ) {
                     near[j]=a;
                }
            }        
 
        }    

        for(int i=0;i<size-1;i++) {
            cout<<"["<<span[0][i]<<", "<<span[1][i]<<"], ";
        }    

        cout<<endl;
        // for(int i=0;i<size+1;i++) cout<<near[i]<<"\t";    
        // cout<<endl;

    }

};
int main() {
     Graph g;
    g.prims();
    //  g.display();
    // for(int i=1;i<=10;i++) {
    // cout<<numeric_limits<int>::max()<<endl;
    //  g.DFS(i);
    //  g.BFS(i);
    // }



     return 0;
}





