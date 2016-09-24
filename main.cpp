#include "bitmapRW.h"

using namespace std;

int main(int argc, char** argv){

    if ( (argc < 3) || (strcmp(argv[1],"-h") == 0) ) { 
          cerr << "usage: ./[executable file name] [input file name] [output file name]" << endl;
          exit(1);
    } 

    char* input_file = argv[1];
    char* output_file = argv[2];
	BITMAPINFOHEADER *bitmapInfoHeader = new BITMAPINFOHEADER;
	BITMAPFILEHEADER *bitmapFileHeader = new BITMAPFILEHEADER;
	unsigned char *bitmapData;
	bitmapData = LoadBitmapFile(input_file, bitmapInfoHeader, bitmapFileHeader);

	cout << "File Type: " << bitmapFileHeader->bfType << endl;
	cout << "File Size: " << bitmapFileHeader->bfSize << endl;
	cout << "Reserved 1: " << bitmapFileHeader->bfReserved1 << endl;
	cout << "Reserved 2: " << bitmapFileHeader->bfReserved2 << endl;
	cout << "Offset bytes: " << bitmapFileHeader->bfOffBits << endl;

	cout << endl << "============================================" << endl << endl;

	cout << "Struct Size: " << bitmapInfoHeader->biSize << endl;
	cout << "Width: " << bitmapInfoHeader->biWidth << endl;
	cout << "Height: " << bitmapInfoHeader->biHeight << endl;
	cout << "Plane: " << bitmapInfoHeader->biPlanes << endl;
	cout << "Bit/Pixel: " << bitmapInfoHeader->biBitCount << endl;
	cout << "Compression: " << bitmapInfoHeader->biCompression << endl;
	cout << "Image Size: " << bitmapInfoHeader->biSizeImage << endl;
	cout << "X Pixel/Meter: " << bitmapInfoHeader->biXPelsPerMeter << endl;
	cout << "Y Pixel/Meter: " << bitmapInfoHeader->biYPelsPerMeter << endl;
	cout << "Num Color: " << bitmapInfoHeader->biClrUsed << endl;
	cout << "important Color: " << bitmapInfoHeader->biClrImportant << endl;

	WriteBitmapFile(output_file, bitmapInfoHeader, bitmapFileHeader, bitmapData);

}

