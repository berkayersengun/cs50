#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main (int argc,string argv[])
{     
    
    if (argc==2)
    {
         string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
          
          printf ("%c is second\n",k);
          
        char c[52];
            for (int i=0;i<52;i++)
            {
                     c[i] = alp[i];           
                      
                  
               string b= crypt(c,"50");
            //    printf("%s and %c\n",b,c[i]);
                if(b==argv[1])
                {
                    printf("letter is %c\n",alp[i]);    
                  
                                    
                }
                
                
                
                
            }
        
    }
    
    else  
    {
          
            
         return 1 ;   
           
          
          
            
    }
}


 

  
