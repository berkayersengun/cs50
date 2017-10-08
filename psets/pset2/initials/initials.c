#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
 
     string w = get_string();
  
     if (w[0]!= ' ')
       
      {
       printf ("%c",toupper(w[0]));
       
      }
   
   
   for (int  i=0;  i < strlen(w)-1; i++)
   {
   
              if (w[i]== ' ' && w[i+1]!= ' ' )
           {
           printf ("%c",toupper(w[i+1]));
      
           }
     
   }
      
 printf ("\n");
   
      }
 
 
  
   
