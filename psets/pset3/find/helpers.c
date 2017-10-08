/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n<0)
       {
           return false;
       }
       
              int ep = n-1 ;
              int sp = 0 ;
            
            while(  n>0)
            {
              
              int mid = (ep+sp)/2;
              
           
                if (values[mid] ==value)
                    {
                        return true;
                    }
                    
                else if(value<values[mid]  )
                {
                //ep= sub array end point    
                 ep = mid-1 ;   
                  
                }
                        
                else if (value>values[mid])        
                {
                    
                //sp= sub array start point    
                
                sp=mid+1 ;
                }
                
                                
               
                n=n/2;   
                
                
            }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
       
     
    for (int i=0;i<n-1;i++)
    {
    
     
       
        int min = i ;
    int low,first;
        for(int j=i+1;j<n;j++)
        {
            
            if ( values[min]>values[j])
            {
                min=j;
                
            }
            //printf("%i",min);
         
        }
       // printf("\n");
       
        
        
             if (min != i )    
            {
                  first=values[i];
                  low=values[min];
                  
                  values[i]=low;
                  values[min]=first;
                  
                    //printf("%i and last %i\n",values[0],values[3]);
                 
            }
       
    }    

    return;
}
