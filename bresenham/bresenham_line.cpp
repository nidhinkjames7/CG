#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
float x1,x2,z1,y2,x,y,step,p,dx,dy;
void bresenham()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(9.0);
	glColor3f(1.0,0.0,0.0);
	int k;
	dx=x2-x1;
	dy=y2-z1;
	step=dx-1;
	p=2*(dy-dx);
	x=x1;
	y=z1;
	for(k=0;k<=step;k++)
	{
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		if(p<0)
		{
			x=x+1;
			p=p+(2*dy);
		}
		else
		{
			x=x+1;
			y=y+1;
			p=p+2*(dy-dx);
		}
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}
main(int argc,char **argv)
{
	printf("enter the coordinate of x1 and y1");
	scanf("%f%f",&x1,&z1);
	printf("enter the coordinates of x2 and y2");
	scanf("%f%f",&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Breseham Line drawing");
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(bresenham);
	glutMainLoop();
	return 0;
}


