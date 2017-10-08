#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    
   printf("O Hai! ");
    
    float dl;
    int c,q,d,n,p ;
    
    do
    
    {
        printf("How much change is owed?\n");
        dl = get_float() ;
         
    }
   
    while (dl<=0);
    
    
    c = round (dl*100) ;
    q = round (c/25); 
    d = round ((c-(q*25))/10);
    n = round ((c-(q*25)-(d*10))/5);
    p = round (c-(q*25)-(d*10)-(n*5)); 
    
  printf("%i\n",d+q+n+p);
    
   
    
}

   