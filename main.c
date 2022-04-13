//Includes required header files
#include <stdio.h>
#include<stdlib.h>
#include "main.h"

//Main function that calls all other functions
int main()
{
  read_source_image();
  def_tiff();
  write_to_dest_image();

  return 0;
}




