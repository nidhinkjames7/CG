#include<GL/gl.h>
#include<GL/glut.h>
void myDraw()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glutSolidCube(7.0);
	glTranslatef(0.0,0.0,-20.0);
	glColor3f(0.0,0.0,1.0);
	glutSolidTeapot(7.0);
	/*execute draw commads*/
	glutSwapBuffers();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,300);
	glutCreateWindow("Depth Test");
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,1.333,0.01,10000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-30);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(myDraw);
	glutMainLoop();
	return 9;
}

