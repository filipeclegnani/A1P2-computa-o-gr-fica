#ifndef FORMAS_H
#define FORMAS_H

// Colocar o código aqui

HWND caixa_de_formas;

int ConstroiCFormas(HWND hwnd){
	caixa_de_formas = CreateWindow(
		"STATIC",
		"Fórmas",
	    WS_VISIBLE | WS_CHILD | WS_BORDER,
	    X_WINDOWSIZE / 3,		// posição x
	    0,		// posição y
	    (X_WINDOWSIZE / 3)*2,	// tamanho x
	    Y_WINDOWSIZE,	// tamanho y
	    hwnd,
	    (HMENU)0,
	    NULL,
	    NULL
	);
	
	
	HDC dc;
	dc = GetDC(caixa_de_formas);
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	
	int pf = ChoosePixelFormat(dc, &pfd);
	if(pf == 0){
		MessageBox(NULL,"ChoosePixelFormat(dc, &pfd);","ERRO",MB_OK);
		return GetLastError();
	}
	if(SetPixelFormat(dc, pf, &pfd) == FALSE){
		MessageBox(NULL, "SetPixelFormat(dc, pf, &pfd)", "ERRO", MB_OK);
		return GetLastError();
	}
	DescribePixelFormat(dc, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	
	HGLRC hRC;
	hRC = wglCreateContext(dc);
	wglMakeCurrent(dc, hRC);
	return 0;
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

void quadrado(){
 	
	glClear(GL_COLOR_BUFFER_BIT);
	
//	gluOrtho2D(-50, 50, -50, 50);
	// de -50 a 50
	glTranslatef(0.0, 0.0, 0.0); //translacao 
//	glScalef(0, 0, 0); // escala
	glRotatef( 0.0, 0.0, 0.0, 0.0); // rotacao eixo Z
		
	glBegin(GL_QUADS);
		
	glColor3f(0.0f, 1.0f, 1.0f);  // cor	
	glVertex2f(-0.5, 0.5); // vertices
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	
	glEnd();
	glFlush();
 } 

void triangulo(){
	// desenha triangulo
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0.0, 0.0, 0.0); //translacao 
	glScalef(0, 0, 0); // escala
	glRotatef( 0.0, 0.0, 0.0, 0.0); // rotacao eixo Z
	glBegin(GL_TRIANGLES);
	glVertex2i(0, 1);
	glVertex2i(1, -1);
	glVertex2i(-1, -1);
	glEnd();
	glFlush();
}
#endif // deve ser a ultima linha do arquivo
