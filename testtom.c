#include<stdio.h>
#include<stdlib.h>

int a[10][10],n,m,i,j,source, s[10],b[10];
int visited[10];

void create(){
    printf("\nEnter the number of vertices in the digraph: ");
    scanf("%d,&n");
    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0;i<=n;i++){
        for(j=1;j<=n;j++)
        scanf("%d,a[i][j]");
    }
}

void bfs(){
    int q[10],u,front=0,rear=-1;
    printf("\nEnter the source vertex to find other nodes reachable or not: ");
    scanf("%d",&source);
    q[++rear]=source;
    visited[source]=1;
    printf("\nThe reachable vertices are: ");
    while(front<=rear){
        u=q[front++];
        for(i=1;i<=n;i++){
            if(a[u][i]==1&&visited[i]==0){
                q[++rear]=i;
                visited[i]=1;
                printf("\n%d",i);
            }
        }
    }
}

void dfs(int source){
    int v, top=-1;
    s[++top]=1;
    b[source]=1;
    for(v=1;v<=n;v++){
        if(a[source][v]==1&&b[v]==0){
            printf("\n%d->%d", source, v);
            dfs(v);
        }
    }
}