#include <windows.h>
#include <wingdi.h>
#include <gl/gl.h>

#define X_WINDOWSIZE 800
#define Y_WINDOWSIZE 600

#include "janela.h"
#include "formas.h"


void draw();
void botaoPressionado(WPARAM wParam);

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

	WNDCLASS wc = {};

	wc.lpszClassName = "My Window Class";
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcedure;
	wc.hInstance = hInst;

	RegisterClass(&wc);
	HWND hwnd =	CreateWindow(
	                wc.lpszClassName,
	                "Formas",
	                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
	                0, 
					0, 
					800, 
					600,
	                NULL, NULL, NULL, NULL
	            );
	//if(int i = ConstroiCFormas(hwnd)){
	//	return i;
	//}else{
	//	ShowWindow(hwnd, ncmdshow);
	//}
	
	
	MSG msg = {};

	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

	switch (msg) {

		case WM_CREATE:
			ConstroiBotoes(hwnd);
			//formasResize(hwnd, lp);
			break;
			
		
		case WM_PAINT:
			//draw();
			break;
			
		case WM_SIZE:
			//janelaResize(hwnd, lp);
			formasResize(hwnd, lp);
			PostMessage(hwnd, WM_PAINT, 0, 0);
			break;
		case WM_COMMAND:
			botaoPressionado(wp);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hwnd, msg, wp, lp);
}


void botaoPressionado(WPARAM wParam){
	// adicionar nesse switch oo eventos disparados por bot~oes
	switch(wParam){
		case EVT_ADDTriangulo:
			
		break;
		case EVT_ADDRetangulo:
			
		break;
		case EVT_ADDCirculo:
			
		break;
	}
}

void draw(){
	// desenha triangulo
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(0, 1);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2i(1, -1);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(-1, -1);
	glEnd();
	glFlush();
	return ;
}




