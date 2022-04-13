//Includes required header files
#include <stdio.h>
#include<stdlib.h>
#include "main.h"

//Function to read the bitmap source image
void read_source_image()
{
struct BMP_HEADER bmphead;
struct BITMAP_INFO_HEADER bih;  //Will store headers of bitmap image

    FILE *fp= fopen("first.bmp","rb");   //Creates a pointer to the source image file
    fread(bmphead.ch,2,1,fp);   //Reads first two characters(BM for bitmap images)
    fread(&bmphead.szofbmp,12,1,fp);    //Reads the rest of the bitmap header, accesess it through a pointer to bmphead.szofbmp
    fread(&bih.size,sizeof(bih),1,fp);      //Reads full bitmap info header, accesses it through a pointer to bih.size
    fread(color_table,sizeof(color_table),1,fp);    //Reads the color table, compulsary for 8-bit bitmap images
    int pixeldata[bih.h][bih.w];    //Declares 2 dimensional array that will store pixels of the image
        h=bih.h;
        w=bih.w;
        fseek(fp,bmphead.offset,SEEK_SET);  //Points the file pointer to the offset of the source image
        for(int i=bih.h-1;i>=0;i--)
        {
            for(int j=0;j<bih.w;j++)
            {
                fread(&pixeldata[i][j],1,1,fp); //Reads the pixels of the image, stored as integers(8-bits per pixel)
            }
        }
    pixarray = &pixeldata[0][0];    //Pointer to pixeldata
        fclose(fp); //Closes source image file
        return;
}

