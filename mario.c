#include <stdio.h>
#include <cs50.h>

int main (void)
{

int height ;
do
{
    printf ("Height: ");
    height= get_int();
     
    
}
    while (height<0 || height>23 );


for (int x=0 ; x<height; x++)
{


   for (int a=0 ; a<height-x-1; a++)
   {
       printf (" ");
   }
   
    for (int b=0 ; b<x+1; b++)
   {
       printf ("#");
   }

printf ("  ");

    for (int y=0; y<x; y++)
    {
    printf ("#");
    }

printf ("#\n");

}




}









