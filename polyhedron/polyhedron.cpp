#include<GL/glut.h>
#include<GL/glu.h>
float xRotated,yRotated,zRotated;
void displayOctahedron(void)
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-4.5);
	glColor3f(0.8,0.2,0.1);
	glRotatef(xRotated,1.0,0.0,0.0);
	glRotatef(yRotated,0.0,1.0,0.0);
	glRotatef(zRotated,0.0,0.0,1.0);
	glScalef(1.0,1.0,1.0);
	glutSolidOctahedron();
	glFlush();
}
void reshapeOctahedron(int x,int y)
{
	if(y==0||x==0)
		return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
	glViewport(0,0,x,y);
}
void idleOctahedron(void)
{
	yRotated+=0.03;
	displayOctahedron();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,350);
	glutCreateWindow("Octahedron Rotation Animation");
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	xRotated=yRotated=zRotated=300;
	xRotated=33;
	yRotated=40;
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(displayOctahedron);
	glutReshapeFunc(reshapeOctahedron);
	glutIdleFunc(idleOctahedron);
	glutMainLoop();
	return 0;
} 
