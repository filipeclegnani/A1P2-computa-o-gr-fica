#ifndef JANELA_H
#define JANELA_H
// Colocar o c�digo aqui

#define EVT_ADDTriangulo	5
#define EVT_ADDRetangulo	6
#define EVT_ADDCirculo		7


HWND campo_de_botoes;

void initriangulo(HWND hwnd);
void iniretangulo(HWND hwnd);
void inicirculo(HWND hwnd);
int intbypercent(LONG max, float percent);

void ConstroiBotoes(HWND hwnd){
	
	RECT size;
	GetWindowRect(hwnd, &size);
	
	campo_de_botoes = CreateWindow(
		"STATIC",
		"",
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    0,		// posi��o x
	    0,		// posi��o y
	    300,	// tamanho x
	    size.bottom,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL	
	);
	initriangulo(hwnd);
	iniretangulo(hwnd);
	inicirculo(hwnd);
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
        intbypercent(maxY, 1.5),		// posi��o y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 4.8),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 1.5),		// posi��o y
        intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 4.8),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 1.5),		// posi��o y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 4.8),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 4.8),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 4.8),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar triangulo",	// Bot�o
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posi��o x
	    intbypercent(maxY, 9),		// posi��o y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDTriangulo,	// codigo do bot�o
	    NULL,
	    NULL
	);
}

void iniretangulo(HWND hwnd){
	
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
        intbypercent(maxY, 14),		// posi��o y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 17.3),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 14),		// posi��o y
        intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 17.3),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 14),		// posi��o y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 17.3),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 17.3),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 17.3),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar quadrado",	// Bot�o
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posi��o x
	    intbypercent(maxY, 21.5),		// posi��o y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDRetangulo,	// codigo do bot�o
	    NULL,
	    NULL
	);
}

void inicirculo(HWND hwnd){
	
	RECT size;
	GetWindowRect(campo_de_botoes, &size);
	
	LONG
	maxX = size.right - 8,
	maxY = size.bottom - 30;
	
	CreateWindow(
        "Static",
        "Raio",	// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 2),		// posi��o x
        intbypercent(maxY, 26.5),		// posi��o y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 29.9),		// posi��o y
	    intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
        intbypercent(maxY, 26.5),		// posi��o y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 29.9),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 29.9),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
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
	    intbypercent(maxY, 29.9),		// posi��o y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar circulo",	// Bot�o
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posi��o x
	    intbypercent(maxY, 34.2),		// posi��o y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDCirculo,	// codigo do bot�o
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
