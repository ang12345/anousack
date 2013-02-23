#include <windows.h>  
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
static GLfloat spin = 0.0;
static GLfloat speed = 0.0;
GLUquadricObj *qobj;
float lngh ; float width ; float depth ;
int i;
void box(float lngh,float width,float depth);
void Fan_Physics();
void Fan_Render();
 
static int running = 0;
void init(void) 
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 5.0, 1.0, 5.0, 0.0 };
   GLfloat mat_amb_diff_color_red[]  = {1.0, 0.5, 0.0, 0.5};
   GLfloat mat_amb_diff_color_green[]  = {0.0, 1.0, 0.0, 0.5};
   GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat light_ambient[] = {0.15, 0.15, 0.15, 0.15};
   GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
   glClearColor (0, 1, 1, 0.0);
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
 
}
 
void display(void)
{
 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();             
   glTranslatef(0.0, 0.0, -4.0); 
   gluLookAt(5,5,5,0,1.5,0,0,1,0);

   Fan_Render();
   	glutSwapBuffers();
	glutPostRedisplay();
 
}
 
void Fan_Physics(void)
{
	if (running == 1)
	  speed = speed + 1.8;
      if (speed > 360.0)
         speed = 360.0;
    if (running == 0)
    	speed = speed - 1.8;
    if (speed < 0)
    	speed = 0;
   spin = spin + speed/100;

}
 
void Fan_Render(void)
{
	glPushMatrix();
	glPushMatrix();
	 GLfloat mat_amb_diff_color_red[]  = {1.0, 0.5, 0.0, 0.5};
     GLfloat mat_amb_diff_color_green[]  = {0.0, 1.0, 0.0, 0.5};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff_color_red);
	    qobj = gluNewQuadric();
        gluQuadricDrawStyle(qobj, GLU_FILL);
        gluQuadricDrawStyle(qobj, GLU_FILL); 
        gluQuadricNormals(qobj, GLU_SMOOTH);
        glScalef( 5 , 0.5 , 5 );
        glEnable(GL_NORMALIZE);
        gluSphere(qobj, 0.25, 20, 20);
     glPopMatrix();
     glPushMatrix();
     gluQuadricDrawStyle(qobj, GLU_FILL); 
     gluQuadricNormals(qobj, GLU_FLAT);
     glRotatef(-90, 1.0, 0.0, 0.0);
     gluCylinder(qobj, 0.125, 0.125, 3, 16, 10);
    glPopMatrix();
    glPushMatrix();
     gluQuadricDrawStyle(qobj, GLU_FILL); 
     gluQuadricNormals(qobj, GLU_SMOOTH);
      glTranslatef(0.0, 3.0, 0.0);
      glScalef( 0.5, 0.5, 1);
      glEnable(GL_NORMALIZE);
      gluSphere(qobj, 1 , 20 , 20 ); 
      glPopMatrix();
	glTranslatef(0.0, 3.0, 0.5);
	glRotatef(spin, 0.0, 0.0, 1.0 );
	for (i = 0; i<=360; i=i+60)
	{
		glPushMatrix();
		glRotatef( i, 0.0, 0.0, 1.0 );
		glTranslatef(1.5, 0.0, 0.0);
		glRotatef( -45, 1.0, 0.0, 0.0 );
		glShadeModel(GL_FLAT);   
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);  
	    glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff_color_green);
		box(1.0,0.3,0.01);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPopMatrix();
 
	}
glPopMatrix();
glPopMatrix();
glPopMatrix();
}
 
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}
 
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}
void mouse(int button, int state, int x, int y) 
{
switch (button) {
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN)
{running = 1;
glutIdleFunc(Fan_Physics);}
break;
case GLUT_RIGHT_BUTTON:
if (state == GLUT_DOWN)
{running = 0;
glutIdleFunc(Fan_Physics);}
break;
default:
break;
}
}
 
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize (640, 480); 
   glutInitWindowPosition (0, 0);
   glutCreateWindow ("      fan rotation	");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
 
void box(float lngh, float width, float depth)
 {
	float a = lngh; float b = width; float c = depth;
 
 
glBegin(GL_QUADS);
 
    glColor3f(1.0,0.0,0.0);
    glVertex3f(a, b, -c);     
    glVertex3f(-a, b, -c);    
    glVertex3f(-a, b, c);     
    glVertex3f(a, b, c);      
 
    
    glVertex3f(a, -b, -c);     
    glVertex3f(-a, -b, -c);    
    glVertex3f(-a, -b, c);   
    glVertex3f( a, -b, c);   
    glColor3f(1.0,0.0,0.0);

    glVertex3f(a, b, c);      
    glVertex3f(-a, b, c);    
    glVertex3f(-a, -b, c);    
    glVertex3f(a, -b, c);     
    glColor3f(1.0,0.0,0.0);

    glVertex3f(a, -b, -c);    
    glVertex3f(-a, -b, -c);   
    glVertex3f(-a, b, -c);    
    glVertex3f(a, b, -c);     
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-a, b, c);     
    glVertex3f(-a, b, -c);   
    glVertex3f(-a, -b, -c);   
    glVertex3f(-a, -b, c);    
    glColor3f(1.0,0.0,0.0);
   
    glVertex3f(a, b, -c);     
    glVertex3f(a, b, c);      
    glVertex3f(a, -b, c);     
    glVertex3f(a, -b, -c);    
    glColor3f(1.0,0.0,0.0);
    glEnd(); 

 
}

