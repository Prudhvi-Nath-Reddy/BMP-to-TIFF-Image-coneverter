//Includes required header files
#include <stdio.h>
#include<stdlib.h>
#include "main.h"

//Function to define data structures of a tiff image
void def_tiff()
{
  struct TIFF_HEADER header;
  struct TIFFTAG directory;
  struct IMAGE_DATA imgdata;  //Stores header, tag directory and image data of tiff image

  header.ch_tiff[0]='I';
  header.ch_tiff[1]='I';
  header.arb=42;
  header.offset_tiff_0=8; //Offset of tag directory is 8

  directory.size=12;  //Number of elements in tagid and dataoffset arrays

  directory.tagid[0]=256; directory.dataoffset[0]=w;  //Image width
  directory.tagid[1]=257; directory.dataoffset[1]=h;  //Image length
  directory.tagid[2]=258; directory.dataoffset[2]=8;  //Bits per sample(bits per pixel)
  directory.tagid[3]=259; directory.dataoffset[3]=1;  //Compression
  directory.tagid[4]=262; directory.dataoffset[4]=1;  //Photometric interpretation  
  directory.tagid[5]=273; directory.dataoffset[5]=3266; //Strip offset(Offset to the pixeldata)
  directory.tagid[6]=277; directory.dataoffset[6]=1;  //Samples per pixel(Grayscale images have only one sample, from 0-255)
  directory.tagid[7]=278; directory.dataoffset[7]=h;  //Rows per strip(Image length)
  directory.tagid[8]=279; directory.dataoffset[8]=bih.imagesize;  //Strip bytecounts(Image size)
  directory.tagid[9]=282; directory.dataoffset[9]=bih.garbage[0];   //X Resolution
  directory.tagid[10]=283; directory.dataoffset[10]=bih.garbage[1];   //Y Resolution
  directory.tagid[11]=296; directory.dataoffset[11]=3;  //Resolution Unit

  //Initializes arrays datatype and datacount to appropriate values   
  for (int i=0;i<directory.size;i++)
  {
    directory.datatype[i]=3;
    directory.datacount[i]=1;
  } 
  directory.datatype[5]=4; directory.datatype[8]=4;
  directory.datatype[9]=5; directory.datatype[10]=5;

//Initializes image data of destination image
  imgdata.w=w;  //Image width
  imgdata.h=h;  //Image length
  imgdata.bps=8;  //Bits per sample(bits per pixel)
  imgdata.comp=1; //Compression
  imgdata.pi=1; //Photometric interpretation
  imgdata.off=3266; //Strip offset(Offset to the pixeldata)
  imgdata.sppixel=1;  //Samples per pixel(Grayscale images have only one sample, from 0-255)
  imgdata.rps=h;  //Rows per strip(Image length)
  imgdata.sbc=bih.imagesize;  //Strip bytecounts(Image size)
  imgdata.xr=bih.garbage[0];   //X Resolution
  imgdata.yr=bih.garbage[1];  //Y Resolution
  imgdata.resunit=3;  //Resolution Unit

  return;
}

