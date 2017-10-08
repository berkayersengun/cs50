#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    
    
   if (argc==2)
   {
       
       
   
    int m=strlen(argv[1]);
    
    // loop for checking if argv[1] only have letters 
        for (int j=0; j<m ; j++ )    
            
        {
            if (isalpha (argv[1][j]))
            {
                
            }    
            else  
            {      
                printf("\n");
                return 1;
            }
       
        }
    
    printf("plaintext: "); 
    //p = plaintext
       string p = get_string();
       
       printf("ciphertext: "); 
       
        for  (int i=0,q=0,   n=strlen(p); i<n; i++)
        {
                
               
                if (isupper(p[i])) //
                {
                    if (isupper (argv[1][q%m])) //
                    {
                        printf("%c",  (((p[i]-65 +   ( (argv[1][(q%m)])-65))     %26 ))     + 65 );
                        q++;
                
                    }
                    else if (islower (argv[1][q%m]))
                    {
                         printf("%c",  (((p[i]-65 +   ( (argv[1][(q%m)])-97))     %26 ))     + 65 );
                         q++;
                    }
                    
                   // printf(" %i and\n",x);
                    
                }
                
                else if (islower(p[i])) //
                
                {
                   if(islower (argv[1][q%m])) //
                   {
                   
                   printf("%c",  (((p[i]-97 +   ( (argv[1][(q%m)])-97))     %26 ))     + 97 );
                     q++;
                   }
                   
                   else if (isupper (argv[1][q%m]))
                   {
                      printf("%c",  (((p[i]-97 +   ( (argv[1][(q%m)])-65))     %26 ))     + 97 ); 
                      q++;
                   }
                 
                     // printf("  %i\n",x);
                      
                   
                
                }
                
                
                
                
                
                
                else 
                {
                    printf("%c",p[i]);
                
                }
                  
        }
    
      printf("\n");  
   }
    
    else 
    {
    printf("\n");
    return 1; 
    }
    
}
