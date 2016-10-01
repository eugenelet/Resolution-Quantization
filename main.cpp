#include "bitmapRW.h"

#define DOWN_QUANTIZE 7

using namespace std;


int pow2(int exponent){
	int base = 1;
	for(int i = 0; i < exponent; i++)
		base *= 2;
	return base;
}

int main(int argc, char** argv){

    if ( (argc < 2) || (strcmp(argv[1],"-h") == 0) ) { 
          cerr << "usage: ./[executable file name] [input file name]" << endl;
          exit(1);
    } 

    char* input_file = argv[1];
    char* output_file;
    char* output_string;
    if(strcmp(input_file, "input1.bmp") == 0)
    	output_string = "output1_";
    else if(strcmp(input_file, "input2.bmp") == 0)
    	output_string = "output2_";
    else
    	output_string = "output";
    char buffer[10];
	BITMAPINFOHEADER *bitmapInfoHeader = new BITMAPINFOHEADER;
	BITMAPFILEHEADER *bitmapFileHeader = new BITMAPFILEHEADER;
	unsigned char *bitmapData;

	for(int i = 1; i <= DOWN_QUANTIZE; i++){
		bitmapData = LoadBitmapFile(input_file, bitmapInfoHeader, bitmapFileHeader);
		// bitmapInfoHeader->biBitCount = (8-i)*4;
		// bitmapInfoHeader->biSizeImage = (bitmapInfoHeader->biBitCount*bitmapInfoHeader->biWidth*
												// bitmapInfoHeader->biHeight)/8 ;
		for(int row = 0; row < bitmapInfoHeader->biHeight; row++)
			for(int col = 0; col < bitmapInfoHeader->biWidth; col++){
				for(int count = 0; count < (bitmapInfoHeader->biBitCount)/8; count++){
					bitmapData[row*bitmapInfoHeader->biWidth*((bitmapInfoHeader->biBitCount)/8) + col*((bitmapInfoHeader->biBitCount)/8) + count] 
						= (bitmapData[row*bitmapInfoHeader->biWidth*((bitmapInfoHeader->biBitCount)/8) 
							+ col*((bitmapInfoHeader->biBitCount)/8) + count] 
							/ pow2(i) );	
					bitmapData[row*bitmapInfoHeader->biWidth*((bitmapInfoHeader->biBitCount)/8) + col*((bitmapInfoHeader->biBitCount)/8) + count] 
						= (bitmapData[row*bitmapInfoHeader->biWidth*((bitmapInfoHeader->biBitCount)/8) 
							+ col*((bitmapInfoHeader->biBitCount)/8) + count] 
							* pow2(i) );	
				}
			}
		sprintf(buffer, "%d", i);
		char *tmp = (char*) malloc(1 + strlen(output_string) + strlen(buffer) + strlen(".bmp"));
		strcpy(tmp, output_string);
		strcat(tmp, buffer);
		strcat(tmp, ".bmp");
		output_file = tmp;

		WriteBitmapFile(output_file, bitmapInfoHeader, bitmapFileHeader, bitmapData);
	}

}

