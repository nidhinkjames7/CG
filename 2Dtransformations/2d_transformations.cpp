#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
int ch;
float x1=0.5,x2=0.8,x3=0.8,x4=0.5,y=0.5,y2=0.5,y3=0.8,y4=0.8;
float X1,X2,X3,X4,Y1,Y2,Y3,Y4;
void display(void)
{
	float tx,ty;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7,0.3,0.3);
	glPointSize(10.0);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
	glColor3f(0.8,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(X1,Y1);
	glVertex2f(X2,Y2);
	glVertex2f(X3,Y3);
	glVertex2f(X4,Y4);
	glEnd();
	glFlush();
}
void translate()
{
	float tx,ty;
	printf("enter value for tx and ty\n");
	scanf("%f%f",&tx,&ty);
	X1=x1+tx;
	X2=x2+tx;
	X3=x3+tx;
	Y1=y+ty;
	Y2=y2+ty;
	Y3=y3+ty;
	X4=x4+tx;
	Y4=y4+ty;
}
void rotate()
{
	int theta;
	printf("enter an angle\n");
	scanf("%d",&theta);
	X1=x1*cos(theta)-y*sin(theta);
	X2=x2*cos(theta)-y2*sin(theta);
	X3=x3*cos(theta)-y3*sin(theta);
	X4=x4*cos(theta)-y4*sin(theta);
	Y1=x1*sin(theta)+y*cos(theta);
	Y2=x2*sin(theta)+y2*cos(theta);
	Y3=x3*sin(theta)+y3*cos(theta);
	Y4=x4*sin(theta)+y4*cos(theta);	
}
void scale()
{
	float sx,sy;
	printf("enter values for sx and sy\n");
	scanf("%f%f",&sx,&sy);
	X1=x1*sx;
	X2=x2*sx;
	X3=x3*sx;
	X4=x4*sx;
	Y1=y*sy;
	Y2=y2*sy;
	Y3=y3*sy;
	Y4=y4*sy;
}
int main(int argc,char **argv)
{

		printf("2D TRANSFORMATION OPERATIONS ARE\n");
		printf("1:TRANSLATION\n");
		printf("2:ROTATION\n");
		printf("3:SCALING\n");
		printf("ENTER UR CHOICE\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				translate();
				break;
			case 2: 
				rotate();
				break;
			case 3:
				scale();
				break;
			default:
				printf("wrong choice\n");
				break;
		}
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("2D TRANSFORMATIONS");
	glutDisplayFunc(display);
	//glOrtho(0.0,640.0,0.0,480.0,1.0,-1.0);

	glutMainLoop();
	return 0;
}

