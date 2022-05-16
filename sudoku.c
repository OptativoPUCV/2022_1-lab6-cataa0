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
  int i, j, k, auxi, auxj;
  for(i = 0 ; i < 9 ; i++){
    for(j = 0 ; j < 9 ; j++){
      if(n->sudo[i][j]){
        for(k = j + 1 ; k < 9 ; k++){
          if(n->sudo[i][j] == n->sudo[i][k]){
            return 0;
          }
        }
      }
    }
  }
  for(j = 0 ; j < 9 ; j++){
    for(i = 0 ; i < 9 ; i++){
      if(n->sudo[i][j]){
        for(k = i + 1 ; k < 9 ; k++){
          if(n->sudo[i][j] == n->sudo[k][j]){
            return 0;
          }
        }
      }
    }
  }
  for(i = 0 ; i < 9 ; i++){
    int aux[10]={0};
    for(j = 0 ; j < 9 ; j++){
      auxi=3*(i/3)+(j/3);
      auxj=3*(i%3)+(j%3);  
      if(n->sudo[auxi][auxj] != 0){
        return 0;
        if(aux[n->sudo[auxi][auxj]] == 0 && aux[n->sudo[auxi][auxj]] != 0){
          aux[n->sudo[auxi][auxj]] = 1;
        }    
      }
    }
  }
  return 1;
}

List* get_adj_nodes(Node* n){
  List* list=createList();
  int i, j, k;
  for(i = 0 ; i < 9 ; i++){
    for(j = 0 ; j < 9 ; j++){
      if(n->sudo[i][j] == 0){
        for(k = 1; k <= 9;k++){
          Node *aux=copy(n);
          aux->sudo[i][j] = k;
          if (is_valid(aux)){
            pushBack(list, aux);
          }
        }
        return list;
      }  
    }
  }  
        
  return list;
}


int is_final(Node* n){
  int i, j;
  for(i = 0 ; i < 9 ; i++){
    for(j = 0 ; j < 9 ; j++){
      if(n->sudo[i][j]==0){
        return 0;
      }
    }
  }  
  return 1;   
}

Node* DFS(Node* initial, int* cont){
  Stack* S=createStack();
  push(S, initial);
  while(get_size(S) != 0){
    Node* n = top(S); 
    pop(S);
    if(is_final(n)){
      return n;
    }
    List *list=get_adj_nodes(n);
    Node *primer=first(list);
    while(primer != NULL){
      push(S, first);
      first=next(list); 
    }
    cont++;
  }
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