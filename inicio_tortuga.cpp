/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: javargas
 *
 * Created on February 12, 2017, 11:49 AM
 */
 
/*****************************************************
 * Christian Camilo Taborda Campiño		1632081-3743 *
 * Cristian Camilo Vallecilla Cuellar	1628790-3743 *
 * ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

//Variables generales:
bool axis = false;
int dibujo = 1;

//Dibuja los ejes coordenados:
void dibujarEjes(){
	//X
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(10.0,0.0,0.0);
	glVertex3f(-10.0,0.0,0.0);
	glEnd();
	//Y
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,10.0,0.0);
	glVertex3f(0.0,-10.0,0.0);
	glEnd();
	//Z
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0,0.0,10.0);
	glVertex3f(0.0,0.0,-10.0);
	glEnd();
}

//Dibuja una tortuga de dos dimensiones:
void drawTurtle(){
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
	double x[] = {0.0,0.047,0.081,0.115,0.115,0.108,0.115,0.156,0.2,0.244,0.3,0.35,0.419,0.48,0.541,0.599,
					0.657,0.719,0.767,0.801,0.845,0.896,0.941,0.975,0.971,0.913,0.855,0.794,0.75,0.698,
					0.623,0.558,0.477,0.425,0.378,0.326,0.279,0.292,0.313,0.337,0.357,0.367,0.378,0.391,
					0.412,0.408,0.4,0.381,0.364,0.34,0.3,0.268,0.316,0.378,0.432,0.483,0.507,0.548,0.569,
					0.579,0.514,0.456,0.408,0.357,0.306,0.258,0.207,0.152,0.101,0.04,0.029,0.033,0.0};
	double z[] = {0.985,0.95,0.906,0.855,0.797,0.742,0.684,0.65,0.616,0.585,0.6,0.64,0.657,0.664,0.65,
					0.619,0.572,0.524,0.479,0.432,0.387,0.326,0.261,0.213,0.162,0.196,0.203,0.227,0.261,
					0.281,0.278,0.278,0.305,0.333,0.353,0.357,0.336,0.271,0.22,0.162,0.101,0.039,-0.019,
					-0.084,-0.149,-0.22,-0.3,-0.364,-0.442,-0.521,-0.6,-0.654,-0.681,-0.712,-0.756,-0.79,
					-0.841,-0.882,-0.937,-0.988,-0.992,-0.971,-0.951,-0.94,-0.934,-0.957,-0.981,-0.992,
					-0.978,-0.957,-0.886,-0.824,-0.8};
	for(int i=0; i<sizeof(x)/sizeof(x[0]); i++){
		glVertex3d(x[i], 0, z[i]);
	}
	for(int i=0; i<sizeof(x)/sizeof(x[0]); i++){
		glVertex3d(-1 * x[i], 0, z[i]);
	}
	glEnd();
}

//Dibuja una tortuga de tres dimensiones:
void drawTurtleSphere(){
	//Caparazón:
	glColor3f(1,0,0);
	glPushMatrix();
	glutWireSphere(0.8,80,80);
	glPopMatrix();
	
	//Patas:
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(0.75,0,0.65);
	glutWireSphere(0.2,80,80);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.75,0,0.65);
	glutWireSphere(0.2,80,80);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.65,0,-0.75);
	glutWireSphere(0.2,80,80);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.65,0,-0.75);
	glutWireSphere(0.2,80,80);
	glPopMatrix();
	
	//Cabeza:
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(0,0,0.8);
	glutWireSphere(0.35,80,80);
	glPopMatrix();

	//Ojos:
	glColor3f(0,0,2);
	glPushMatrix();
	glTranslatef(0.2,0.07,1);
	glutWireSphere(0.05,80,80);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.2,0.07,1);
	glutWireSphere(0.05,80,80);
	glPopMatrix();
	
}

//Dibuja el toroide con el cubo inscrito:
void drawFigure(){
	glColor3f(0.0,1.0,0.0);
	glutWireTorus(0.25,0.75, 28, 28);
    glColor3f(0.0,0.0,1.0);
    glutWireCube(.60);
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(dibujo == 1){
		drawTurtle();
	}else if(dibujo == 2){
		drawTurtleSphere();
	}else{
		drawFigure();
	}
	if(axis){
		dibujarEjes();
	}
    glutSwapBuffers();
}

void reshape(int width, int height) {
	if(width > height){
		width = height;
	}else{
		height = width;
	}
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'h':
        printf("\nHelp\n\n");
        printf("c/C - Toggle culling\n");
        printf("q/Q/escape - Quit\n");
        printf("Rotate figure: Axis X: 1 Axis Y: 2 \n");
        printf("Move camera: u/U = up d/D = down l/L = left r/R = right\n");
        printf("Show axis: a/A\n");
        printf("Toggle between 2D turtle, 3D turtle and Toro with cube: t/T\n\n");
        break;
    case 'c':
        if (glIsEnabled(GL_CULL_FACE))
           glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;
    case '1':
        glRotatef(1.0,1.,0.,0.);
        break;
    case '2':
        glRotatef(1.0,0.,1.,0.);
        break;
    case 'a':
		if(axis){
			axis = false;
		}else{
			axis = true;
		}
		break;
	case 't':
		if(dibujo == 1 || dibujo == 2){
			dibujo++;
		}else{
			dibujo = 1;
		}
		break;
	case 'u':
		gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0);
		break;
	case 'd':
		gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 0.0, 0.0);
		break;
	case 'l':
		gluLookAt(0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 'r':
		gluLookAt(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
    case 'q':
        exit(0);
        break;
    case 'H':
        printf("\nHelp\n\n");
        printf("c/C - Toggle culling\n");
        printf("q/Q/escape - Quit\n");
        printf("Rotate figure: Axis X: 1 Axis Y: 2 \n");
        printf("Move camera: u/U = up d/D = down l/L = left r/R = right\n");
        printf("Show axis: a/A\n");
        printf("Toggle between 2D turtle, 3D turtle and Toro with cube: t/T\n\n");
        break;
    case 'C':
        if (glIsEnabled(GL_CULL_FACE))
           glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;
    case 'A':
		if(axis){
			axis = false;
		}else{
			axis = true;
		}
		break;
	case 'T':
		if(dibujo == 1 || dibujo == 2){
			dibujo++;
		}else{
			dibujo = 1;
		}
		break;
	case 'U':
		gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0);
		break;
	case 'D':
		gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 0.0, 0.0);
		break;
	case 'L':
		gluLookAt(0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
	case 'R':
		gluLookAt(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		break;
    case 'Q':
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(520, 520);
    glutInitWindowPosition(50, 20);
    glutCreateWindow("tecnunLogo");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}
