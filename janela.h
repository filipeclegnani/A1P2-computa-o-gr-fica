#ifndef JANELA_H
#define JANELA_H
// Colocar o c�digo aqui
HWND campo_de_botoes;

void initriangulo(HWND hwnd);
int intbypercent(LONG max, float percent);

void ConstroiBotoes(HWND hwnd){
	campo_de_botoes = CreateWindow(
		"STATIC",
		"",
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
	initriangulo(hwnd);
	
}

void initriangulo(HWND hwnd){
	
	RECT size;
	GetWindowRect(campo_de_botoes, &size);
	
	LONG
	maxX = size.right - 8,
	maxY = size.bottom - 30;
	
	CreateWindow(
        "Static",
        "Base",	// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 2),		// posi��o x
        intbypercent(maxY, 5),		// posi��o y
        intbypercent(maxX, 13),	// tamanho x
        20,		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 2),		// posi��o x
	    intbypercent(maxY, 15),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    
	CreateWindow(
        "Static",
        "Altura",	// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 20),		// posi��o x
        intbypercent(maxY, 5),		// posi��o y
        intbypercent(maxX, 17),	// tamanho x
        20,		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 20),		// posi��o x
	    intbypercent(maxY, 15),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    
	CreateWindow(
        "Static",
        "Cor RGB",	// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 38),		// posi��o x
        intbypercent(maxY, 5),		// posi��o y
        intbypercent(maxX, 20),	// tamanho x
        20,		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    CreateWindow(
	    "Edit",	//R
	    "00",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 38),		// posi��o x
	    intbypercent(maxY, 15),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    CreateWindow(
	    "Edit",	//G
	    "00",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 50),		// posi��o x
	    intbypercent(maxY, 15),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    CreateWindow(
	    "Edit",	//B
	    "00",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 62),		// posi��o x
	    intbypercent(maxY, 15),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Bot�o",	// Bot�o
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posi��o x
	    intbypercent(maxY, 30),		// posi��o y
	    intbypercent(maxX, 98),	// tamanho x
	    20,	// tamanho y
	    hwnd,
	    (HMENU)0,	// codigo do bot�o
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


int intbypercent(LONG max, float percent){
	percent = percent / 100;
	
	return (int)max * percent;
}
























#endif // deve ser a ultima linha do arquivo
