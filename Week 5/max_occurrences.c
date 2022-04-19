/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void findmostFreq(char*);

int main()
{
  int cases;
  scanf("%d", &cases);

  for(int i = 0; i < cases; i++)
  {
    char* alpha = (char*)malloc(1);
    scanf("%s", alpha);

    findmostFreq(alpha);
    free(alpha);
  }
}

void findmostFreq(char* alpha)
{
  int a = 'a';
  int z = 'z';
  int* freq = (int*) calloc(26, sizeof(int));

  for(int i = 0; i < (int)strlen(alpha); i++)
  {
    if(alpha[i] >= a && alpha[i] <= z)
    {
      freq[alpha[i]-a]++;
    }
  }

  int max = 0;
  for(int i = 0; i < 26; i++)
  {
    // printf("%d, ", freq[i]);
    if(freq[i] > freq[max])
      max = i;
  }

  if(freq[max] <= 1)
    printf("No Duplicate Found\n");
  else
    printf("\n %c - %d\n", max+a, freq[max]);
  free(freq);
}
