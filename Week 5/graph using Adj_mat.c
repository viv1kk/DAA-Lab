#include <stdio.h>
#include <stdlib.h>

char* addNodes(char*, int**, char, char, int*);
int* addEdges(char*, int*, char, char, int);
int* createMat(int*, int, int);
void deleteEdge(int*, int, int , int);
int* updateMat(int*, int, int);
void searchEdge(int*, int, int, int);
int searchNode(char*, char, int);
char* deleteNode(char*, int, int*);
void printAllNodes(char*, int);
void printAllEdges(int*, char*, int);
void printAdjMat(int*, int);

int main(){
  printf("Undiercted Graph \n\n");
  printf("1. Add an Edge\n");
  printf("2. Delete a Node\n");
  printf("3. Delete an Edge\n");
  printf("4. Search a Node\n");
  printf("5. Search an Edge\n");
  printf("6. Print All Nodes\n");
  printf("7. Print All Edges\n");
  printf("8. Print the Adjecency Matrix\n\n");
  
  int ch;
  char* nodes = NULL;
  int* adjMat = NULL;
  int sizeN = 0;

  while(1){
    fflush(stdin);
    printf("Enter the Choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1:{
        char a, b;
        printf("\nInput 2 nodes of the edge : ");
        fflush(stdin);
        scanf("%c%c", &a, &b);
        fflush(stdin);
        nodes = addNodes(nodes, &adjMat, a, b, &sizeN);
        adjMat = addEdges(nodes, adjMat, a, b, sizeN);
      }break;
      case 2:{
        char a;
        printf("\nEnter the Node you want to delete : ");
        fflush(stdin);
        scanf("%c", &a);
        int index = searchNode(nodes, a, sizeN);
        if(index != -1){
          nodes = deleteNode(nodes, index, &sizeN);
          adjMat = updateMat(adjMat, index, sizeN);
        }else
          printf("\nNode Doesn't exist.\n");
      }break;
      case 3:{
        char a, b;
        printf("\nInput 2 nodes of the edge : ");
        fflush(stdin);
        scanf("%c%c", &a, &b);
        fflush(stdin);

        int ia = searchNode(nodes, a, sizeN);
        int ib = searchNode(nodes, b, sizeN);

        if(ia == -1 || ib == -1)
          printf("Check the Input Nodes and try again!!");
        else
          deleteEdge(adjMat, ia, ib, sizeN);
      }  break;
      case 4:{
        char a;
        printf("\nEnter the Node you want to search : ");
        fflush(stdin);
        scanf("%c", &a);
        int ind = searchNode(nodes, a, sizeN);

        if(ind == -1)
          printf("Node not Found!");
        else
          printf("Node Found!");
      }  break;
      case 5: {
        char a, b;
        printf("\nInput 2 nodes of the edge : ");
        fflush(stdin);
        scanf("%c%c", &a, &b);
        fflush(stdin);

        int ia = searchNode(nodes, a, sizeN);
        int ib = searchNode(nodes, b, sizeN);

        if(ia == -1 || ib == -1)
          printf("Check the Input Nodes and try again!!");
        else
          searchEdge(adjMat, ia, ib, sizeN);
      }  break;
      case 6:
        printAllNodes(nodes, sizeN);
              break;
      case 7:
        printAllEdges(adjMat, nodes, sizeN);
              break;
      case 8:
        printAdjMat(adjMat, sizeN);
              break;
      default:
          printf("Invalid Input!");
          break;
    }
  }
  free(nodes);
  free(adjMat);
  return 0;
}

int* addEdges(char* nodes, int* mat, char a, char b, int size){
  int x = size;
  int ia = searchNode(nodes, a, size);
  int ib = searchNode(nodes, b, size);

  for(int i = 0; i < x; i++){
    for(int j = 0; j < x; j++){
      int ind = (x*i)+j;
      if((i == ia && j == ib) || (j == ia && i == ib))
        mat[ind] = 1;
    }
  }return mat;
}

char* addNodes(char* nodes, int** mat, char a, char b, int* size){
  if(nodes == NULL){
    nodes = (char*) malloc(2*sizeof(char));
    nodes[0] = a;
    nodes[1] = b;
    *size = 2;
    *mat = createMat(*mat, *size, 0);
  }else{
    int f1 = 1, f2 = 1;
    int s = *size;
    for(int i = 0; i < s; i++){ // checking whether the nodes already exist
      if(a == nodes[i])
        f1 = 0;
      if(b == nodes[i])
        f2 = 0;
    }
    if(f1 || f2)
      nodes = (char*) realloc(nodes, ((*size)+(f1+f2)));
    if(f1){
      nodes[s] = a;
      s++;
    }
    if(f2){
      nodes[s] = b;
      s++;
    }
    *mat = createMat(*mat, *size, (f1+f2));
    *size = s;
  }
  return nodes;
}


void deleteEdge(int* mat, int i, int j, int size){
  if(mat != NULL){
    mat[(i*size)+j] = 0;
    mat[(j*size)+i] = 0;
  }else
    printf("\nMatrix doesn't Exist!\n");
}

int* createMat(int* mat, int size, int ext){
  int *newMat = NULL;
  if(mat != NULL){
    newMat = (int*)malloc(sizeof(int)*(size+ext)*(size+ext));
    for(int i = 0; i < (size+ext); i++){
      for(int j = 0; j < (size+ext); j++){
        int ms = (i*(size+ext))+j;
        if(i < size && j < size){
          int ns = (i*size)+j;
          newMat[ms] = mat[ns];
        }
        else
          newMat[ms] = 0;
      }
    }
    free(mat);
  }
  else{
    mat = (int*) calloc(size+ext, sizeof(int));
    return mat;
  }
  return newMat;
}

int* updateMat(int* mat, int ind, int size){
  if(mat != NULL){
    int s = size-1;
    int* newMat = (int*) malloc(sizeof(int)*s*s);

    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        int ms = i*(size)+j;

        if(i != ind || j != ind){
          int ns = (i*s)+j;
          newMat[ms] = mat[ns];
        }else
          newMat[ms] = 0;
      }
    }
    free(mat);
    return newMat;
  }
  else
    printf("\nMatrix doesn't Exist!\n");
  return mat;
}

void searchEdge(int* mat, int a, int b, int size){
  if(mat != NULL){
    if(mat[(a*size)+b] == 1 && mat[(b*size)+a] == 1)
    printf("The Edge Exists");
    else
    printf("The Edge doesn't Exist");
  }else
    printf("\nMatrix doesn't Exist\n");
}

char* deleteNode(char* nodes, int index, int* size){
  if(nodes != NULL){
    for(int i = index; i < *size-1; i++)
      nodes[i] = nodes[i+1];
    nodes = (char*)realloc(nodes, *size-1);
    (*size)--;
  }else
    printf("\nCreate Nodes First!\n");
  return nodes;
}

int searchNode(char* nodes, char t, int size){
  for(int i = 0; i < size; i++)
    if(nodes[i] == t)
      return i;
  return -1;
}


void printAllNodes(char* nodes, int size){
  int i = 0;
  while(i < size){
    printf("%c, ", nodes[i]);
    i++;
  }
  printf("\n");
}


void printAllEdges(int* mat, char* nodes, int size){
  for(int i = 0; i < size; i++)
    for(int j = 0; j < i; j++){
      int ind = (size*i)+j;
      if(mat[ind])
        printf("%c <-----> %c\n", nodes[i], nodes[j]);
  }
}

void printAdjMat(int* mat, int size)
{
  printf("\n");
  printf("Adjecency Matrix : \n\n");
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      int ind = (size*i)+j;
      printf("%d, ", mat[ind]);
    }
    printf("\n");
  }
}
