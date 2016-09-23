#include "readBMP.h"

using namespace std;

int main(){
	BITMAPINFOHEADER *bitmapInfoHeader = new BITMAPINFOHEADER;
	BITMAPFILEHEADER *bitmapFileHeader = new BITMAPFILEHEADER;
	unsigned char *bitmapData;
	bitmapData = LoadBitmapFile("input1.bmp", bitmapInfoHeader, bitmapFileHeader);

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

}

