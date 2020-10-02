#ifndef FORMAS_H
#define FORMAS_H

// Colocar o código aqui

HWND caixa_de_formas;

void ConstroiCFormas(HWND hwnd){
	caixa_de_formas = CreateWindow(
		"STATIC",
		"formas",
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    100,		// posição x
	    100,		// posição y
	    300,	// tamanho x
	    200,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL
	);
}

void formasResize(HWND hwnd, LPARAM lp){
	SetWindowPos(
				caixa_de_formas, 
				NULL,
				(LOWORD(lp) / 3),
				0,
				(LOWORD(lp) / 3)*2,
				HIWORD(lp),
				NULL
			);
	glViewport(0, 0, (LOWORD(lp) / 3)*2, HIWORD(lp));
}


#endif // deve ser a ultima linha do arquivo
