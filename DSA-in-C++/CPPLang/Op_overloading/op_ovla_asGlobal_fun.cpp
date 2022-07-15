#include <iostream>
#include <string.h>

typedef struct _String{
    char *str;

}String;
String operator+(String fName, String lName)
{
    String name;
    name.str = (char*)malloc(strlen(fName.str)+strlen(lName.str)+1);
    strcpy(name.str,fName.str);
    strcat(name.str,lName.str);
    return name;
}
using namespace std;
int main()
{
    String name,fName,lName;
    fName.str = strdup("Rajkalash");
    lName.str = strdup("Rajbhar");
   /* name.str = (char*)malloc(strlen(fName.str)+strlen(lName.str) +1);
    strcpy(name.str, fName.str);
    strcat(name.str,lName.str);
    printf("Name: %s\n",name.str);*/
    name = fName+ lName;
    printf("name: %s",name.str);

}