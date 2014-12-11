#include <stdio.h>
#include <windows.h>

//mutate given values for x,y location of mouse pointer
//this function is for testing purposes only
int getCursorLocation(int* x, int* y)
{
	POINT cursor;
	GetCursorPos(&cursor);
	*x = cursor.x;
	*y = cursor.y;
	return 0;
}

//mutate given values for rgb ints for pixel value at x,y location
int getPixelValue(int x, int y, int* red, int* green, int* blue)
{
	FARPROC pGetPixel;
	HINSTANCE hGDI = LoadLibrary("gdi32.dll");
	if(hGDI){
		pGetPixel = GetProcAddress(hGDI, "GetPixel");
		
		//get device context
		HDC hdc = GetDC(NULL);
		
		if(hdc){
			//get pixel values at location 10,10
			COLORREF color = (*pGetPixel) (hdc, x, y);
			*red = GetRValue(color);
			*green = GetGValue(color);
			*blue = GetBValue(color);
		}
		FreeLibrary(hGDI);
	}
	
	//success
	return 0;
}

int main(int argc, char **argv)
{
	int cursorX;
	int cursorY;
	getCursorLocation(&cursorX, &cursorY);
	
	int red;
	int green;
	int blue;
	getPixelValue(cursorX, cursorY, &red, &green, &blue);
	
	printf("the cursor location is %d, %d\n", cursorX, cursorY);
	printf("Pixel there %d %d %d\n", red, green, blue);
	return 0;
}
