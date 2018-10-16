#include<GL/glut.h>
#include<stdio.h>
void circle(float xx,float yy);
float r,xc,yc,x,y,p;
void circle_alg()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(8.0);
	x=0;
	y=r;
	glBegin(GL_POINTS);
	circle(x,y);
	while(x<=y)
	{
		if(p<0)
		{
			x=x+1;
			p=p+(2*x)+1;
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p+(2*(x-y))+1;
		}
		circle(x,y);
	}
	glEnd();
	glFlush();
}
void circle(float xx,float yy)
{
	glVertex2f(xc+xx,yc+yy);
	glVertex2f(xc+xx,yc-yy);
	glVertex2f(xc-xx,yc+yy);
	glVertex2f(xc-xx,yc-yy);
	glVertex2f(xc+yy,yc+xx);
	glVertex2f(xc+yy,yc-xx);
	glVertex2f(xc-yy,yc-xx);
	glVertex2f(xc-yy,yc+xx);
}
main(int argc,char **argv)
{
	printf("enter the values for xc and yc\n");
	scanf("%f%f",&xc,&yc);
	printf("enter the value for radius r\n");
	scanf("%f",&r);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Circle Drawing");
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(-100,100,-100,100,-10,10);
	glutDisplayFunc(circle_alg);
	glutMainLoop();
	return 0;
}
