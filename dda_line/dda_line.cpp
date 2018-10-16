#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
float x,y,x1,z1,x2,y2,dx,dy,step;
void dda()
{
	int xinc,yinc,k;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(6.0);
	glColor3f(0.0,0.0,1.0);
	dx=x2-x1;
	dy=y2-z1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	xinc=dx/(float)step;
	yinc=dy/(float)step;
	x=x1;
	y=z1;
	for(k=0;k<=step;k++)
	{
		glBegin(GL_LINES);
		glVertex2f(x,y);
		x=x+xinc;
		y=y+yinc;
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}
main(int argc,char **argv)
{
	printf("\n enter the coordinate of x1 and y1\n");
	scanf("%f%f",&x1,&z1);
	printf("\n enter the coordinates of x2 and y2\n");
	scanf("%f%f",&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA line drawing");
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(dda);
	glutMainLoop();
	return 0;
}

