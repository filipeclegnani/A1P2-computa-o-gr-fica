#ifndef JANELA_H
#define JANELA_H

// Colocar o código aqui

void ConstroiBotoes(HWND hwnd){
	CreateWindow(
	    "Button",
	    "Botão",	// Botão
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    10,		// posição x
	    60,		// posição y
	    400,	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL
	);
}


























#endif // deve ser a ultima linha do arquivo
