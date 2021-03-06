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
			ConstroiCFormas(hwnd);
			ConstroiBotoes(hwnd);
			formasResize(hwnd, lp);
			break;


		case WM_PAINT:
			
			
			//redesenhatodas();
			break;

		case WM_MOUSEMOVE:
			SetCursor(LoadCursor(NULL, IDC_ARROW));
			break;
		case WM_SIZE:
			formasResize(hwnd, lp);
			redesenhatodas();
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


void botaoPressionado(WPARAM wParam) {
	// adicionar nesse switch oo eventos disparados por bot~oes
	switch(wParam) {
		case EVT_ADDTriangulo:
			add_triangulo();
			break;
		case EVT_ADDRetangulo:
			add_quadrado();
			break;
		case EVT_ADDCirculo:
			add_circulo();
			break;
		case EVT_RTTAntihorario:
			printf("anti\n");
			lstsetrotacao(-.1f);
			break;
		case EVT_RTTHorario:
			printf("horario\n");
			lstsetrotacao(.1f);
			break;
		case EVT_ESCMais:
			lstsetescala(.5f);
			break;
		case EVT_ESCMenos:
			lstsetescala(-.5f);
			break;
		case EVT_MOVBaixo:
			lstsettranslacao(0.0f, -0.1f);
			break;
		case EVT_MOVCima:
			lstsettranslacao(0.0f, 0.1f);
			break;
		case EVT_MOVDireita:
			lstsettranslacao(0.1f, 0.0f);
			break;
		case EVT_MOVEsquerda:
			lstsettranslacao(-0.1f, 0.0f);
			break;
	}
	
	redesenhatodas();
}






