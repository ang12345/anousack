#include<GL/glut.h>

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	//glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,400.0,0.0,300.0);
}

void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(100,100);//v1
	glVertex2i(300,100);//v2
	glVertex2i(300,200);//v3
	glVertex2i(100,200);//v4
	glEnd();
	glEnd();
	glFlush();
}
	void main(int argc,char**argv)
	{
		glutInit (& argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowPosition(50,100);
		glutInitWindowSize(800,600);
		glutCreateWindow("Draw flag with openGL program");
		init();
		glutDisplayFunc(myDisplay);
		glutMainLoop();

	}
