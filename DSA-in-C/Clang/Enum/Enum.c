#include <stdio.h>
#include <string.h>
enum STATE{
    ON,OFF
};
typedef struct  Stud {
    int roll;
    int class;
    struct Stud * pstr;
    char name[10];
} STUDENT;
typedef enum mState{
    married =100,
    single,
    divorced,
    widow
} MSTATE;
int main(int argc, char ** argv)
{
    MSTATE ms = widow;
    printf("ms: %d\n",ms);
    STUDENT s1;
    enum STATE myState = 30;
    printf("myState: %d\n",myState);

}