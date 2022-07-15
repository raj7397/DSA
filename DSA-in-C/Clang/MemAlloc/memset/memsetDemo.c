#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
    char buffer[10]= "Rajkalashs";
    memset(buffer, 'a',5*sizeof(char));
    memset(buffer + 5, 'b',5*sizeof(char));
    printf("buffer: %s\n",buffer);
}