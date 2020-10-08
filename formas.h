#ifndef FORMAS_H
#define FORMAS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Colocar o código aqui

#define PI 3.1415926535898

HWND caixa_de_formas;

typedef struct {
	float R;
	float G;
	float B;
} COR;

struct FORMA{
    float altura;
    float base;
};
struct FORMA form;

float translacaoX;
float translacaoY;

float rotacaoZ;

float escala = 1;

int ConstroiCFormas(HWND hwnd) {
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
	if(pf == 0) {
		MessageBox(NULL,"ChoosePixelFormat(dc, &pfd);","ERRO",MB_OK);
		return GetLastError();
	}
	if(SetPixelFormat(dc, pf, &pfd) == FALSE) {
		MessageBox(NULL, "SetPixelFormat(dc, pf, &pfd)", "ERRO", MB_OK);
		return GetLastError();
	}
	DescribePixelFormat(dc, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	HGLRC hRC;
	hRC = wglCreateContext(dc);
	wglMakeCurrent(dc, hRC);
	return 0;
}

void formasResize(HWND hwnd, LPARAM lp) {
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

COR getcolor(int id) {
	HWND R;
	HWND G;
	HWND B;
	char cR[5];
	char cG[5];
	char cB[5];

	COR saida;

	switch(id) {
		case 1:	// triangulo
			R = tred;
			G = tgreen;
			B = tblue;
			break;
		case 2:	// quadrado
			R = qred;
			G = qgreen;
			B = qblue;
			break;
		case 3:	// circulo
			R = cred;
			G = cgreen;
			B = cblue;
			break;
	}

	GetWindowTextA(R, cR, 5);
	GetWindowTextA(G, cG, 5);
	GetWindowTextA(B, cB, 5);

	printf("%s, %s, %s\n", cR, cG, cR);

	saida.R = (float)(atoi(cR)) / 100;
	saida.G = (float)(atoi(cG)) / 100;
	saida.B = (float)(atoi(cB)) / 100;

	printf("%.2f, %.2f, %.2f\n", saida.R, saida.G, saida.B);

	return saida;
}

FORMA recebeForm(HWND hwnd, HWND hwnd2){

    char cR[5];
    char qR[5];

    FORMA saida;

    GetWindowTextA(hwnd, cR, 5);
    GetWindowTextA(hwnd2, qR, 5);


    saida.altura = (float)(atoi(cR)) / 100;
    saida.base = (float)(atoi(qR)) / 100;

    printf("%.2f %.2f\n", saida.altura, saida.base);

    return saida; 
}

void quadrado() {

	//glClear(GL_COLOR_BUFFER_BIT);

//    gluOrtho2D(-50, 50, -50, 50);
	// de -50 a 50
	glTranslatef(translacaoX, translacaoY, 0.0); //translacao
    glScalef(escala, escala, 1); // escala
	glRotatef(0.0, 0.0, 0.0, rotacaoZ); // rotacao eixo Z

	glBegin(GL_QUADS);

	COR cl = getcolor(2);
	glColor3f(cl.R, cl.G, cl.B);
	glVertex2f(-0.5, 0.5); // vertices
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glPushMatrix();
	glEnd();
	glFlush();
}

void triangulo(){
    // desenha triangulo
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); //translacao 
    //glScalef(0, 0, 0); // escala
    glRotatef( 0.0, 0.0, 0.0, 0.0); // rotacao eixo Z
    glBegin(GL_TRIANGLES);
    
	COR cl = getcolor(1);
	glColor3f(cl.R, cl.G, cl.B);
	
	FORMA f = recebeForm(taltura, tbase);
    glVertex2f(0, f.altura);
    glVertex2f(f.base , (-1));
    glVertex2f((-1) * f.base , -1);
    
    glEnd();
    glFlush();
}

void circulo() {
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat vertices = 10000;
	GLfloat angulo;
	COR cl = getcolor(3);
	glColor3f(cl.R, cl.G, cl.B);
	glBegin(GL_POLYGON);
	for(int i=0; i <vertices; i++) {
		angulo = 2 * PI * i / vertices;
		glVertex2f(cos(angulo),sin(angulo));
	}
	glEnd();
	glFlush();
}

#endif // deve ser a ultima linha do arquivo
