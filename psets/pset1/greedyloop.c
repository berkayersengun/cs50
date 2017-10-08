#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float dl;
    int c,n;
      printf("O hai!");
    do 
    {
        
       printf("How much change is owed?\n");
        dl=get_float() ;
         
        
    }
    
    while(dl<=0); 
    
    n= 100*dl ;
    c=0 ;
    
    while (n>=25)
    {
         c++  ;
         n-=25 ;
     
       
    }
   
    while (n>=10)
    {
        
        c++;
        n-=10;
    }
   while (n>=5)
    {
        
        c++;
        n-=5;
    }
   while (n>=1)
    {
        
        c++;
        n-=1;
    }
  
    
    printf("%i\n",c); 
    
    
    
    
}
