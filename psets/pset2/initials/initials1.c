#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
  

    
    string w = get_string();
    
    printf ("%c",toupper(w[0]));
    for (int  i=0;  i < strlen(w); i++)
    {
    
   
   
   if ( w[i]==' ')
   
   {
   
  printf ("%c",toupper(w[i+1]));
   
   } 
    }    
 printf ("\n");
   
    
}
