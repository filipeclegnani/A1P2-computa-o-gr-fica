#ifndef JANELA_H
#define JANELA_H

// Colocar o c�digo aqui

void ConstroiBotoes(HWND hwnd){
	CreateWindow(
	    "Button",
	    "Bot�o",	// Bot�o
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    10,		// posi��o x
	    60,		// posi��o y
	    400,	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL
	);
}


























#endif // deve ser a ultima linha do arquivo
