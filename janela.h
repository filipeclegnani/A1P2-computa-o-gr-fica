#ifndef JANELA_H
#define JANELA_H
// Colocar o c�digo aqui
HWND campo_de_botoes;

void ConstroiBotoes(HWND hwnd){
	campo_de_botoes = CreateWindow(
		"STATIC",
		"Caixa de bot�es",
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    0,		// posi��o x
	    0,		// posi��o y
	    300,	// tamanho x
	    200,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL
	);
	
}
	void janelaResize(HWND hwnd, LPARAM lp){
		SetWindowPos(
				campo_de_botoes, 
				NULL,
				0,
				0,
				LOWORD(lp) / 3,
				HIWORD(lp),
				NULL
			);
}


























#endif // deve ser a ultima linha do arquivo
