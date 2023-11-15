#include <stdio.h>
#include <string.h>

int main()
{
    typedef struct
  {
   char date[20];
   float bloodIron;
  } reading;


 // an instance of the struct
 reading Today;
 Today.bloodIron=13;

 // an array of the struct
 reading Week[7];
 Week[0].bloodIron=5;
 
 strcpy(Week[0].date,"12/13");

}