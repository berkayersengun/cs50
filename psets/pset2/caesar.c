#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    
    
   if (argc==2)
   {
       
    int k = atoi(argv[1]); 
    
    printf("plaintext: "); 
    //p = plaintext
    string p = get_string();
        
      printf("ciphertext: ");  
        
        for  (int i=0,  n=strlen(p); i<n; i++)
        {
            if (isalpha (p[i]) && isupper(p[i])   )
            {
            
                printf("%c",((p[i]-65+k)%26)+65);
                
            }
            
            else if (isalpha (p[i])  && islower(p[i])   )
            
            {
                printf("%c",((p[i]-97+k)%26)+97);
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