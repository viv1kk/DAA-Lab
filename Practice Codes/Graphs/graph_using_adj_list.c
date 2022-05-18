#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
  char data;
  struct LL* next;
}List;

void createNode(char**, int*, char, char);
void printAllNodes(char*, int);
void printAllAdjList(List**, char*, int);
void printAdjListOfNode(List**, int);
void removeEdge(List***, int, char);
void removeNode(List***, char**, int*, int*, char);
void modifyList(List**, int,  List*, char);
void printAllEdges(List**, char*, int);
List* searchEdgeAdjList(List**,int ,char);
void addEdges(List***, char*, int,int*, char, char);
int searchNode(char*, int, char);
void addToList(List**, char*, int, char, char); // adj List

int main()
{
  printf("Undiercted Graph Adjacency List:\n\n");
  printf("1. Add an Edge\n"); // done
  printf("2. Delete a Node\n");
  printf("3. Delete an Edge\n"); //done
  printf("4. Search a Node\n"); // done
  printf("5. Search an Edge\n"); // done
  printf("6. Print All Nodes\n");// done
  printf("7. Print All Edges\n"); //done
  printf("8. Print Adjacency List of a Node\n"); // done
  printf("9. Print All the Adjacency Lists\n"); //done
  printf("10. Exit\n");

  List** nodePtrArr = NULL;


  char* nodes = NULL;
  int sizeN = 0;
  int sizeE = 0;

  int ch = 0;

  while(1)
  {
    fflush(stdin);
    printf("\nYour Choice : ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
      {
        char x, y;
        printf("Enter the 2 nodes : ");
        fflush(stdin);
        scanf("%c%c", &x, &y);

        createNode(&nodes, &sizeN, x, y);
        addEdges(&nodePtrArr, nodes, sizeN, &sizeE, x, y);
      }
              break;
      case 2:
      {
        // delete a node -- delete node + correct adjecency list
        char x;
        printf("\nInput the node you want to delete : ");
        fflush(stdin);
        scanf("%c", &x);

        removeNode(&nodePtrArr, &nodes, &sizeN, &sizeE, x);
      }
              break;
      case 3:
      {
        // delete An edge

        char x, y;
        printf("\nEnter the 2 nodes : ");
        fflush(stdin);
        scanf("%c%c", &x, &y);

        int indX = searchNode(nodes, sizeN, x);
        int indY = searchNode(nodes, sizeN, y);

        if(indX == -1 || indY == -1)
          printf("Node not found!\n");
        else
        {
          removeEdge(&nodePtrArr, indX, y); // because undirected graph so remove edge from both nodes
          removeEdge(&nodePtrArr, indY, x);
        }

      }
            break;
      case 4:
      {
        char x;
        printf("\nInput the Node you want to Search : ");
        fflush(stdin);
        scanf("%c", &x);

        int ind = searchNode(nodes, sizeN, x);

        if(ind == -1)
          printf("Node not Found!\n");
        else
          printf("Node found!\n");
      }
              break;
      case 5:
      {
        char x, y;
        printf("\nInput 2 nodes : ");
        fflush(stdin);
        scanf("%c%c", &x, &y);

        int ind = searchNode(nodes, sizeN, x);

        if(ind == -1)
          printf("Node not Found!\n");
        else
        {
          if(searchEdgeAdjList(nodePtrArr, ind, y) != NULL)
            printf("Edge Found!\n");
          else
            printf("Edge not Found!\n");
        }
      }
              break;
      case 6:
      {
        printAllNodes(nodes, sizeN);
      }
              break;
      case 7:
      {
        printAllEdges(nodePtrArr, nodes, sizeN);
      }
              break;
      case 8:
      {
        printf("Print Adjacency List of a Node ");
        char x;
        printf("\nInput the Node of the List : ");
        fflush(stdin);
        scanf("%c", &x);

        int ind = searchNode(nodes, sizeN, x);

        if(ind == -1)
          printf("Node not Found!\n");
        else
        {
          printf("%c : ", nodes[ind]);
          printAdjListOfNode(nodePtrArr, ind);
        }

      }
              break;
      case 9:
      {
        printAllAdjList(nodePtrArr, nodes, sizeN);
      }
              break;
      case 10:
      {
        return 0;
      }
              break;
    }
  }
  free(nodes);
  return 0;
}

void createNode(char** nodes, int* size, char a, char b)
{
  if(*nodes == NULL)
  {
    char* temp = (char*) malloc(2*sizeof(char));
    temp[0] = a;
    temp[1] = b;

    free(*nodes);
    *size = 2;
    *nodes = temp;
  }
  else
  {
    int f1 = 1, f2 = 1;
    int s = *size;
    for(int i = 0; i < s; i++) // checking whether the nodes already exist
    {
      if(a == (*nodes)[i])
        f1 = 0;
      if(b == (*nodes)[i])
        f2 = 0;
    }
    if(f1 || f2)
      *nodes = (char*) realloc(*nodes,(*size)+(f1+f2));
    if(f1)
    {
      (*nodes)[s] = a;
      s++;
    }
    if(f2)
    {
      (*nodes)[s] = b;
      s++;
    }
    *size = s;
  }
}


void addEdges(List*** nPtrArr, char* nodes, int size, int* sizeE, char a, char b)
{
  if(*nPtrArr == NULL)
  {
    List** temp = (List**) malloc(size*sizeof(List*));

    // init to NULL all the ptrs
    for(int i = 0; i < 2; i++)
    {
      temp[i] = (List*) malloc(sizeof(List));
    }

    temp[0]->data = b;
    temp[0]->next = NULL;

    temp[1]->data = a;
    temp[1]->next = NULL;
    *nPtrArr = temp;
  }
  else
  {
    List** temp = (List**) malloc(size*sizeof(List*));

    for(int i = 0; i < size; i++)
    {
      if(i < *sizeE)
      {
        temp[i] = (*nPtrArr)[i];
      }
      else
        temp[i] = NULL;
    }
    List** s = temp;
    temp = *nPtrArr;
    *nPtrArr = s;

    free(temp);

    addToList(*nPtrArr, nodes, size, a, b);
  }
  *sizeE = size;
}

void addToList(List** nPtrArr, char* nodes, int size, char a, char b)
{
  List* tempA = (List*)malloc(sizeof(List));
  List* tempB = (List*)malloc(sizeof(List));

  tempA->data = b;
  tempA->next = NULL;

  tempB->data = a;
  tempB->next = NULL;

  int indA = searchNode(nodes, size, a);
  int indB = searchNode(nodes, size, b);

  if(indA == -1 || indB == -1)
  {
    free(tempA);
    free(tempB);
    printf("Nodes not found!!\n");
    return;
  }

  // for list A
  modifyList(nPtrArr, indA, tempA, a);
  // for list B
  modifyList(nPtrArr, indB, tempB, b);
}

void modifyList(List** nPtrArr, int ind,  List* temp, char x)
{
    List* l = nPtrArr[ind];
    if(l == NULL)
    {
      nPtrArr[ind] = temp;
    }
    else if(searchEdgeAdjList(nPtrArr, ind, x) == NULL)
    {
      List* t = l;
      while(l != NULL)
      {
        t = l;
        l = l->next;
      }
      t->next = temp;
    }
    else
    {
      free(temp);
    }
}

List* searchEdgeAdjList(List** nodePtrArr, int ind, char t)
{
  List *temp = nodePtrArr[ind];

  while(temp != NULL)
  {
    if(temp->data == t)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

int searchNode(char* nodes, int size, char tar)
{
  int i = 0;
  while(i < size)
  {
    if(nodes[i] == tar)
    {
      return i;
    }
    i++;
  }
  return -1;
}

void removeNode(List*** nodePtrArr, char** nodes, int* sizeN, int* sizeE, char x)
{
  for(int i = 0; i < *sizeE; i++)
  {
    removeEdge(nodePtrArr, i, x);
  }
  int indX = searchNode(*nodes, *sizeN, x);

  if(indX == -1)
  {
    printf("Node not Found!\n");
  }
  else
  {
    // remove node from AdjList
    List** temp = (List**) malloc(((*sizeE)-1)*sizeof(List**));
    for(int i = 0, j = 0; i < *sizeN;)
    {
      if(i == indX)
      {
        i++;
        continue;
      }
      temp[j++] = (*nodePtrArr)[i++];
    }

    List **t = *nodePtrArr;
    *nodePtrArr = temp;
    temp = t;

    free(temp);
    (*sizeE)--;

    // remove node from Node List
    char* tempN  = (char*) malloc(((*sizeN)-1)*sizeof(char*));
    for(int i = 0, j = 0; i < *sizeN;)
    {
      if(i == indX)
      {
        i++;
        continue;
      }
      tempN[j++] = (*nodes)[i++];
    }

    char *tn = *nodes;
    *nodes = tempN;
    tempN = tn;

    free(tempN);
    (*sizeN)--;
  }
}

void removeEdge(List*** nodePtrArr, int ind, char tar)
{
  List* start = (*nodePtrArr)[ind];
  List* del = searchEdgeAdjList(*nodePtrArr, ind, tar);

  if(del != NULL)
  {
    if(start == del)
    {
      (*nodePtrArr)[ind] = start->next;
      free(start);
    }
    else
    {
      while(start->next != del)
      {
        start = start->next;
      }
      start->next = del->next;
      (*nodePtrArr)[ind] = start;
      free(del);
    }
  }
}

void printAllNodes(char* nodes, int size)
{
  int i = 0;

  while(i < size)
  {
    printf("%c, ", nodes[i]);
    i++;
  }
  printf("\n");
}

void printAdjListOfNode(List** nodePtrArr, int ind)
{
  List* temp = nodePtrArr[ind];
  while(temp != NULL)
  {
    printf("%c --> ", temp->data);
    temp = temp->next;
  }
  printf("NULL");
}

void printAllEdges(List** nodesPtrArr, char* nodes, int size)
{
  for(int i = 0; i < size; i++)
  {
    List* temp = nodesPtrArr[i];
    while(temp != NULL)
    {
      printf("%c --> %c\n", nodes[i], temp->data);
      temp = temp->next;
    }
  }
}

void printAllAdjList(List** adjPtr, char* nodes, int size)
{
  int i = 0;
  printf("\nAdjacency List of all the nodes : \n\n");
  while(i < size)
  {
    printf("%c : ", nodes[i]);
    if(adjPtr[i] != NULL)
      printAdjListOfNode(adjPtr, i);
    else
      printf("NULL");
    printf("\n");
    i++;
  }
}
