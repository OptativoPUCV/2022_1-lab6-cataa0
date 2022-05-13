#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i, j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i, j, c, flag = 0, si;
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
    {
        scanf("%c",&c);
        n[i][j]=c-'0';
  for(i=0;i<9;i++){
    flag=0x0000;
    for(j=0;j<9;j++)
        flag|=1<<(n[i][j]-1);
    if(flag!=0x01FF)
        reporta("fila",i,j-1);
  }  
  for(j=0;j<9;j++){
    flag=0x0000;
    for(i=0;i<9;i++)
        flag|=1<<(n[i][j]-1);
    if(flag!=0x01FF)
    reporta("col",i-1,j);
  }
  for(si=0;si<3;si++){
    for(sj=0;sj<3;sj++)
    {
        flag=0x0000;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                flag|=1<<(n[si*3+i][sj*3+j]-1);

        }
        if(flag!=0x01FF)
            reporta("bloque",si*3+i-1,sj*3+j-1);
    }
  }
    
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/