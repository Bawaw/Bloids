#include <stdlib.h>
#include <glew.h>
#include <glut.h>
#include <iostream>
/*
void redraw(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
}

void renderScene(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_LIGHTING);

	int ends[2][2];
	ends[0][0] = (int)(200);  
	ends[0][1] = (int)(450);
	ends[1][0] = (int)(600);
	ends[1][1] = (int)(150);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (int i = 0; i < 2; ++i) {
		glVertex2iv((GLint *)ends[i]);
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glewInit();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D Computer Graphics");
	glutReshapeFunc(reshape);
	glutDisplayFunc(renderScene);
	glutMainLoop();
	glutDisplayFunc(redraw);
	glutMainLoop();
	return 0;
}

*/