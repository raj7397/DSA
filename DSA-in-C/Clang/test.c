#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
   // char *word[3];
    char word[4][20];
    for(i=0;i<3;i++)
    {
       // word[i] = (char*)malloc(100);
       // printf("\naddress: %d\n",word[i]);
        printf(" Enter a word: ");
        
        scanf("%s", word[i]);
    }
    for(i=0;i<3;i++)
    {
        printf("\n%s \n",word[i]);
     //   word[i] = (char*)malloc(100);
       // printf("\naddress: %d\n",word[i]);
      //  printf(" Enter a word: ");
        
        //scanf("%s", word[i]);
    }
    printf("%s ", word[0]);
    return 0;
}