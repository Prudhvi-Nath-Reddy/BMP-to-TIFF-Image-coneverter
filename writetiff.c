//Includes required header files
#include <stdio.h>
#include<stdlib.h>
#include "main.h"

//Function to write pixel values from pixarray to destination image
void write_to_dest_image()
{
  struct TIFF_HEADER header;
  struct TIFFTAG directory;
  struct IMAGE_DATA imgdata;  //Stores header, tag directory and image data of tiff image

  FILE *d = fopen("destination_image.tiff","w");  //Creates a pointer to the destination image file
  fwrite(header.ch_tiff,2,1,d); //Writes first two characters(II for tiff images)
  fwrite(&header.arb,6,1,d);  //Writes arbitrary values into tiff header
  fseek(d,header.offset_tiff_0,SEEK_SET); //Points the file pointer to the tifftag directory
  fwrite(&directory.size,2,1,d);  //Writes number of elements of arrays in the directory structure

  //Writes tifftag directory values into the file
  for (int i=0;i<directory.size;i++)
  {
    fwrite(&directory.tagid[i],2,1,d);  //Tag ID
    fwrite(&directory.datatype[i],2,1,d); //Datatype size
    fwrite(&directory.datacount[i],4,1,d);  //Datacount
    fwrite(&directory.dataoffset[i],4,1,d); //Dataoffset
  }

  fwrite(&directory.nextoff,4,1,d); //Writes offset to where pixels are stored
  fseek(d,imgdata.off,SEEK_SET);  //Points the file pointer to where the pixels must be stored in the destination iamge

  
  for (int i=0 ;i<h;i++)
  {
    for (int j=0;j<w;j++)
    {
      fputc(*((pixarray+i*w)+j),d); //Writes all the pixels into the destination image, stored as integers(8-bits per pixel)
    }
  }
  fclose(d);  //Closes destination image file
  return;
}