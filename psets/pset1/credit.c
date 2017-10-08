#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    long long cn,cnx,cn1 ; 
    int cnxx,i,cny,a,b,m=0,t,q=0,z,y,cnz,j;
    
    printf ("Number: \n"); 

        // cn = card number // 
        
     cn= get_long_long(); 
   
   
   cnx= cn/10 ; 
   cnxx = (cnx % 10)*2 ; 
   
   //b equals to second to last digit // 
   
  if (cnxx>=10)
  {
      b=cnxx/10 + cnxx %10 ; 
   
  }
  else
  {
      b=cnxx ;
      
  }
  
// a equals to total sum of the rest of the digits // 
   
   for (i=0; i<16; i++)
   {
       
        cnx = cnx/100 ; 
       cny = (cnx %10)*2 ; 
     
    if (cny>=10)
     {
        a= cny/10 + cny%10 ; 
    
     }
     
     else
     {
         a=cny;
     }
     
     i++ ;  
     
     m=m+a ;
     
   }
   
   // t equals to total sum starting by second to last digit // 
     t=m+b ; 

// y equals to first to last digit //
    cn1=cn;
    y= cn1%10 ; 
    
    // q equals to the total sum of the numbers that werent multiplied //
       
   for (z=0; z<16; z++)
   
   {
       
       cn1=cn1/100 ; 
       cnz=cn1%10 ;
       q=q+cnz ; 
       
      
   }
  
  
    
    j= (q+y+t)%10 ;
     
    
if (j==0 && (cn/10000000000000==37 || cn/10000000000000==34) )
{
    printf("AMEX\n");
}

else if  (j==0 && (cn/100000000000000==51||cn/100000000000000==52||cn/100000000000000==53||cn/100000000000000==54||cn/100000000000000==55))
{
    printf("MASTERCARD\n");
}

else if   (j==0 && (cn/1000000000000==4||cn/1000000000000000==4))
{
    printf ("VISA\n");
}
else
{
    printf("INVALID\n");
}
    
    
}
