/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    
    
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
  

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    int width= bi.biWidth;
   // int npadding = 
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
     
    else 
    {
       // int height= bi.biHeight;
       
        bi.biWidth = bi.biWidth * n ;
        bi.biHeight = bi.biHeight * n ; 
    
        
            //add padding to the width if it isnt a multiple of 4.
            if ((sizeof(RGBTRIPLE)*bi.biWidth)%4==0)
            {
            bi.biSizeImage = (sizeof(RGBTRIPLE)*bi.biWidth)*abs(bi.biHeight);
            //printf("%i\n",bi.biWidth);
            }
            
            else
            {
            bi.biSizeImage = ((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight);
            }
        
        bf.bfSize= bi.biSizeImage + sizeof(BITMAPFILEHEADER)+ sizeof (BITMAPINFOHEADER);
       
       // printf("%u\n",bi.biSizeImage);
        
    }
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
     int  cursor =sizeof(RGBTRIPLE)*width;
     int  npadding = (4 - (cursor*n) % 4) % 4;
    // iterate over infile's scanlines
    // define a new integer to replace biHeight which can be negative (int biHeight;)
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
       
           for (int j=0; j<width; j++)
           {
                RGBTRIPLE triple;
                
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int a=0; a<n; a++)
                {
                    
                fwrite (&triple, sizeof(RGBTRIPLE), 1, outptr);
               
                // printf("%i\n",width);  
                }
                
                //fwrite (&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
               //printf("%i\n",padding); 
        if (cursor%4 != 0)
        {
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            // then add it back (to demonstrate how)
            
            for (int k = 0; k < npadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
        
        if(i%2==0)
            fseek(inptr, -(cursor+padding), SEEK_CUR);   
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
  
    // success
    return 0;
}
