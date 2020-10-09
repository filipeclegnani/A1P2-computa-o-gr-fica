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

struct FORMA {
	float altura;
	float base;
};
struct FORMA form;

int ultimoid = 1;

typedef struct {
	float translacaoX;
	float translacaoY;
	float escala;
	float rotacaoZ;
	float base;
	float altura;
	COR cor;
	int id;
} quads ;

typedef struct {
	float raio;
	COR cor;
	float angulo;
	int id;
	float escala;
} CIRCULOS;

typedef struct {
	int id;
	float gl_translatex;
	float gl_translatey;
	float gl_rotate;
	float gl_scale;
	COR cor;
	float base;
	float altura;
} t_triangulo;

int qtdci = 1;
CIRCULOS circulos[100];
int qtdqu = 1;
quads quadrados[100];
int qtdtr = 1;
t_triangulo triangulos[100];


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

FORMA recebeForm(HWND hwnd, HWND hwnd2) {

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

float receberaio() {
	char cR[5];

	GetWindowTextA(craio, cR, 5);
	return  (float)(atoi(cR)) / 100;

}


void triangulo(t_triangulo t) {
	// desenha triangulo
	glTranslatef(t.gl_translatex, t.gl_translatey, 0.0); //translacao
	glScalef(t.gl_scale, t.gl_scale, 0); // escala
	glRotatef( 0.0, 0.0, 0.0, t.gl_rotate); // rotacao eixo Z
	glBegin(GL_TRIANGLES);

	glColor3f(t.cor.R, t.cor.G, t.cor.B);

	glVertex2f(0, t.altura);
	glVertex2f(t.base , (-1));
	glVertex2f((-1) * t.base , -1);

	glEnd();
	glFlush();
}

void circulo(CIRCULOS c) {

	GLfloat vertices = 1000;
	GLfloat angulo;
	glScalef(c.escala, c.escala, 0);
	
	glBegin(GL_POLYGON);
	glColor3f(c.cor.R, c.cor.G, c.cor.B);
	for(int i=0; i < vertices; i++) {
		angulo = 2 * PI * i / vertices;
		glVertex2f(cos(angulo)*(c.raio),sin(angulo)*(c.raio));
	}
	glEnd();
	glFlush();
}

void quadrado(quads q) {

	//glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(q.translacaoX, q.translacaoY, 0.0); //translacao
	glScalef(q.escala, q.escala, 1); // escala
	glRotatef(0.0, 0.0, 0.0, q.rotacaoZ); // rotacao eixo Z

	glBegin(GL_QUADS);

	glColor3f(q.cor.R, q.cor.G, q.cor.B);
	glVertex2f(q.base, q.altura);
	glVertex2f ((-1)* q.base, q.altura); // vertices
	glVertex2f((-1) * q.base, (-1) * q.altura);
	glVertex2f(q.base, (-1) * q.altura);
	glEnd();
	glFlush();
}

void add_triangulo() {
	triangulos[qtdtr].id = ultimoid;
	triangulos[qtdtr].cor = getcolor(1);
	FORMA fr = recebeForm(taltura, tbase);
	triangulos[qtdtr].altura = fr.altura;
	triangulos[qtdtr].base = fr.base;
	triangulos[qtdtr].gl_scale = 1;
	qtdtr++;
	ultimoid++;
}

void add_quadrado() {
	quadrados[qtdqu].id = ultimoid;
	quadrados[qtdqu].cor = getcolor(2);
	FORMA fr = recebeForm(qaltura, qbase);
	quadrados[qtdqu].altura = fr.altura;
	quadrados[qtdqu].base = fr.base;
	quadrados[qtdqu].escala = 1;
	qtdqu++;
	ultimoid++;
}

void add_circulo() {
	circulos[qtdci].id = ultimoid;
	circulos[qtdci].cor = getcolor(3);
	circulos[qtdci].raio = receberaio();
	circulos[qtdci].escala = 1;
	qtdci++;
	ultimoid++;
}

void redesenhatodas() {
	int idatual = 1;
	int idcirculo = 1;
	int idquadrado = 1;
	int idtringulo = 1;
	printf("redesenhando\n");
	glClear(GL_COLOR_BUFFER_BIT);
	while(idatual < ultimoid) {
		if(idatual == circulos[idcirculo].id) {
			circulo(circulos[idcirculo]);
			idcirculo++;
		} else {
			if(idatual == quadrados[idquadrado].id) {
				quadrado(quadrados[idquadrado]);
				idquadrado++;
			} else {
				if(idatual == triangulos[idtringulo].id) {
					triangulo(triangulos[idtringulo]);
					idtringulo++;
				} else {
					printf("erro");
				}
			}
		}
		glFlush();
		glEnd();
		idatual++;
	}
}

void lstsetescala(float i) {
	// encontra o ultimo
	int idatual = 1;
	int idcirculo = 1;
	int idquadrado = 1;
	int idtringulo = 1;
	int lst;
	while(idatual < ultimoid) {
		if(idatual == circulos[idcirculo].id) {
			lst = 1;
			idcirculo++;
		} else {
			if(idatual == quadrados[idquadrado].id) {
				lst = 2;
				idquadrado++;
			} else {
				if(idatual == triangulos[idtringulo].id) {
					lst = 3;
					idtringulo++;
				} else {
					printf("erro");
				}
			}
		}
		idatual++;
	}
	// define
	switch(lst){
		case 1:
			// circulo
			circulos[idcirculo - 1].escala = circulos[idcirculo - 1].escala + i;
			break;
		case 2:
			// quadrado
			
			break;
		case 3:
			// triangulo
			
			break;
	}
}

#endif // deve ser a ultima linha do arquivo
