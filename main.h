//Declares functions used in main
void read_source_image();
void def_tiff();
void write_to_dest_image();

FILE *fp;
FILE *d;  //File pointers
typedef unsigned short int usi;
typedef unsigned int uint;

//Structure for bitmap header
struct BMP_HEADER
{
    char ch[2];
    uint szofbmp;
    usi dump1;
    usi dump2;
    uint offset;
};

//Structure for bitmap info header
struct BITMAP_INFO_HEADER
{
    uint size;
    int w;
    int h;
    usi colorpanes;
    usi bitsperpixel;
    int compression;
    int imagesize;
    int garbage[4];
};

//Structure for TIFF header
struct TIFF_HEADER
{
  char ch_tiff[2];
  usi arb;
  uint offset_tiff_0;
};

//Structure for TIFFTAG directory
struct TIFFTAG
{
  usi size;
  usi tagid[200];
  short datatype[200];
  long datacount[200];
  long dataoffset[200];
  int nextoff;
};

//Structure for image data of destination image
struct IMAGE_DATA
{ usi w ;
usi h ;
usi bps;
usi comp;
usi pi ;
uint off;
usi sppixel ;
usi rps ;
uint sbc ;
unsigned long int xr;
unsigned long int yr;
usi resunit ;
};

//Variable declarations
struct BMP_HEADER bmphead;
struct BITMAP_INFO_HEADER bih;
int h;
int w;
int * pixarray;

//Declaration of color table structure
int color_table[256];

