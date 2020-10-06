#ifndef JANELA_H
#define JANELA_H
// Colocar o código aqui

#define EVT_ADDTriangulo	1
#define EVT_ADDRetangulo	2
#define EVT_ADDCirculo		3

#define EVT_MOVCima			5
#define EVT_MOVBaixo		6
#define EVT_MOVEsquerda		7
#define EVT_MOVDireita		8

#define EVT_ESCMais			9
#define EVT_ESCMenos		10

#define EVT_RTTHorario		11
#define EVT_RTTAntihorario	12



HWND campo_de_botoes;

HWND tbase;
HWND taltura;
HWND tred;
HWND tgreen;
HWND tblue;


HWND qbase;
HWND qaltura;
HWND qred;
HWND qgreen;
HWND qblue;


HWND craio;
HWND cred;
HWND cgren;
HWND cblue;



void initriangulo(HWND hwnd);
void iniretangulo(HWND hwnd);
void inicirculo(HWND hwnd);
void initranslacao(HWND hwnd);
void iniescala(HWND hwnd);
void inirotacao(HWND hwnd);
int intbypercent(LONG max, float percent);

void ConstroiBotoes(HWND hwnd){
	
	RECT size;
	GetWindowRect(hwnd, &size);
	
	campo_de_botoes = CreateWindow(
		"STATIC",
		"",
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    0,		// posição x
	    0,		// posição y
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
	initranslacao(hwnd);
	iniescala(hwnd);
	inirotacao(hwnd);
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
        intbypercent(maxX, 2),		// posição x
        intbypercent(maxY, 1.5),		// posição y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    tbase=CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 2),		// posição x
	    intbypercent(maxY, 4.8),		// posição y
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
        intbypercent(maxX, 20),		// posição x
        intbypercent(maxY, 1.5),		// posição y
        intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    taltura=CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 20),		// posição x
	    intbypercent(maxY, 4.8),		// posição y
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
        intbypercent(maxX, 38),		// posição x
        intbypercent(maxY, 1.5),		// posição y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    tred=CreateWindow(
	    "Edit",	//R
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 38),		// posição x
	    intbypercent(maxY, 4.8),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    tgreen=CreateWindow(
	    "Edit",	//G
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 50),		// posição x
	    intbypercent(maxY, 4.8),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    tblue=CreateWindow(
	    "Edit",	//B
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 62),		// posição x
	    intbypercent(maxY, 4.8),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar triangulo",	// Botão
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posição x
	    intbypercent(maxY, 9),		// posição y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDTriangulo,	// codigo do botão
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
        intbypercent(maxX, 2),		// posição x
        intbypercent(maxY, 14),		// posição y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    qbase=CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 2),		// posição x
        intbypercent(maxY, 17.3),		// posição y
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
        intbypercent(maxX, 20),		// posição x
        intbypercent(maxY, 14),		// posição y
        intbypercent(maxX, 17),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    qaltura=CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 20),		// posição x
        intbypercent(maxY, 17.3),		// posição y
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
        intbypercent(maxX, 38),		// posição x
        intbypercent(maxY, 14),		// posição y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    qred=CreateWindow(
	    "Edit",	//R
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 38),		// posição x
        intbypercent(maxY, 17.3),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    qgreen=CreateWindow(
	    "Edit",	//G
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 50),		// posição x
        intbypercent(maxY, 17.3),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    qblue=CreateWindow(
	    "Edit",	//B
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 62),		// posição x
        intbypercent(maxY, 17.3),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar quadrado",	// Botão
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posição x
	    intbypercent(maxY, 21.5),		// posição y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDRetangulo,	// codigo do botão
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
        intbypercent(maxX, 2),		// posição x
        intbypercent(maxY, 26.5),		// posição y
        intbypercent(maxX, 13),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    craio=CreateWindow(
	    "Edit",
	    "",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 2),		// posição x
	    intbypercent(maxY, 29.9),		// posição y
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
        intbypercent(maxX, 38),		// posição x
        intbypercent(maxY, 26.5),		// posição y
        intbypercent(maxX, 20),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    qred=CreateWindow(
	    "Edit",	//R
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 38),		// posição x
	    intbypercent(maxY, 29.9),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    qgreen=CreateWindow(
	    "Edit",	//G
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 50),		// posição x
	    intbypercent(maxY, 29.9),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
    qblue=CreateWindow(
	    "Edit",	//B
	    "000",	// Caixa de texto
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 62),		// posição x
	    intbypercent(maxY, 29.9),		// posição y
	    intbypercent(maxX, 10),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    NULL,
	    NULL,
	    NULL
	);
	
	CreateWindow(
	    "Button",
	    "Adicionar circulo",	// Botão
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    intbypercent(maxX, 1),		// posição x
	    intbypercent(maxY, 34.2),		// posição y
	    intbypercent(maxX, 98),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
	    hwnd,
	    (HMENU)EVT_ADDCirculo,	// codigo do botão
	    NULL,
	    NULL
	);
}

void initranslacao(HWND hwnd){
	
	RECT size;
	GetWindowRect(campo_de_botoes, &size);
	
	LONG
	maxX = size.right - 8,
	maxY = size.bottom - 30;
	
	
	CreateWindow(
        "Static",
        "Translacao",	// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 2),		// posição x
        intbypercent(maxY, 39),		// posição y
        intbypercent(maxX, 25),	// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    
    HWND hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 13.5),		// posição x
	    intbypercent(maxY, 42),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_MOVCima,
	    NULL,
	    NULL
	);

	HBITMAP hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\setac.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
	
    hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 2),		// posição x
	    intbypercent(maxY, 47.5),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_MOVEsquerda,
	    NULL,
	    NULL
	);

	hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\setae.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
	
	hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 25),		// posição x
	    intbypercent(maxY, 47.5),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_MOVDireita,
	    NULL,
	    NULL
	);

	hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\setad.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
	
	hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 13.5),		// posição x
	    intbypercent(maxY, 47.5),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_MOVBaixo,
	    NULL,
	    NULL
	);

	hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\setab.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
}

void iniescala(HWND hwnd){
	
	RECT size;
	GetWindowRect(campo_de_botoes, &size);
	
	LONG
	maxX = size.right - 8,
	maxY = size.bottom - 30;
	
	CreateWindow(
        "Static",
        "Escala",					// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 40),		// posição x
        intbypercent(maxY, 39),		// posição y
        intbypercent(maxX, 25),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    
    HWND hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 42),		// posição x
	    intbypercent(maxY, 47.5),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_ESCMenos,
	    NULL,
	    NULL
	);

	HBITMAP hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\menos.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
	
	hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 42),		// posição x
	    intbypercent(maxY, 42),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_ESCMais,
	    NULL,
	    NULL
	);

	hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\mais.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
}

void inirotacao(HWND hwnd){
	
	RECT size;
	GetWindowRect(campo_de_botoes, &size);
	
	LONG
	maxX = size.right - 8,
	maxY = size.bottom - 30;
	
	CreateWindow(
        "Static",
        "Rotacao",					// campo de texto
        WS_VISIBLE | WS_CHILD,
        intbypercent(maxX, 65),		// posição x
        intbypercent(maxY, 39),		// posição y
        intbypercent(maxX, 20),		// tamanho x
        intbypercent(maxY, 3.5),		// tamanho y
        hwnd,
        NULL,
        NULL,
        NULL
    );
    
    HWND hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 69),		// posição x
	    intbypercent(maxY, 42),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_RTTHorario,
	    NULL,
	    NULL
	);

	HBITMAP hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\horario.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
    
    hImage = CreateWindow(
	    "Static",
	    NULL,	// imagem
	    WS_VISIBLE | WS_CHILD | SS_BITMAP,
	    intbypercent(maxX, 69),		// posição x
	    intbypercent(maxY, 47.5),		// posição y
	    0,	// tamanho x
	    0,	// tamanho y
	    hwnd,
	    (HMENU)EVT_RTTAntihorario,
	    NULL,
	    NULL
	);

	hLogoImage = (HBITMAP)LoadImage(	// carrega o bitmap
	                         NULL,
	                         "img\\anti-horario.bmp",
	                         IMAGE_BITMAP,
	                         30,
							 30,
	                         LR_LOADFROMFILE
	                     );
	
	SendMessage(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hLogoImage);
}

/*
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
*/

int intbypercent(LONG max, float percent){
	percent = percent / 100;
	
	return (int)max * percent;
}
























#endif // deve ser a ultima linha do arquivo
