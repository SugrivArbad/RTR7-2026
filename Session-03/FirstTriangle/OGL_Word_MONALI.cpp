#include <GL/freeglut.h>

bool bIsFullScreen = false;

int main(int argc, char* argv[])
{
	// function declarations
	void initialize(void);
	void uninitialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);

	// code
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First RTR7 Program : Sugriv Vitthal Arbad");

	initialize();
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	// flow should not come here
	return (0);
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}



typedef struct Coordinate
{
	float x;
	float y;
	float z;
} coordinate_t;

#define QUAD_BASE_5 (5.0f)

#define SCALE_X_BASE QUAD_BASE_5
#define SCALE_Y_BASE QUAD_BASE_5
#define SCALE_5_BASE QUAD_BASE_5
#define SCALE_FACTOR (8.0f) // SCALE_FACTOR is inversely propotional to Letter size

#define SHIFT_BASE_5 (QUAD_BASE_5)


void drawSqaure(coordinate_t q1, coordinate_t q2, coordinate_t q3, coordinate_t q4)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(q1.x, q1.y, q1.z);
	////glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(q2.x, q2.y, q2.z);
	////glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(q3.x, q3.y, q3.z);
	////glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(q2.x, q2.y, q2.z);
	////glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(q3.x, q3.y, q3.z);
	////glVertex3f(1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(q4.x, q4.y, q4.z);
	////glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

void drawM_V1_26Apr2026()
{
	float SCALE_X = SCALE_X_BASE * 5;
	float SCALE_Y = SCALE_Y_BASE * 5;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = -SHIFT_BASE_5;

	coordinate_t R1[] = {
		{(0 + SHIFT_X) / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{(0 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(1 + SHIFT_X) / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{(1 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{(0 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(1 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(2.5f + SHIFT_X) / SCALE_X, 1 / SCALE_Y, 0 / SCALE_5},
		{(2.5f + SHIFT_X) / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{(5 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(4 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(2.5f + SHIFT_X) / SCALE_X, 1 / SCALE_Y, 0 / SCALE_5},
		{(2.5f + SHIFT_X) / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);

	coordinate_t R4[] = {
		{(4 + SHIFT_X) / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{(4 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5},
		{(5 + SHIFT_X) / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{(5 + SHIFT_X) / SCALE_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R4[0], R4[1], R4[2], R4[3]);
}

void drawM()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	////float SHIFT_X = -((SHIFT_BASE_5 * 3) / SCALE_X + (1 / SCALE_X));
	float letterCount = 3.0f;
	float SHIFT_X =  -((SHIFT_BASE_5 * letterCount) / SCALE_X);

	coordinate_t R1[] = {
		{0 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{2.5f / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{2.5f / SCALE_X + SHIFT_X, 3 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{5 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{2.5f / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{2.5f / SCALE_X + SHIFT_X, 3 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);

	coordinate_t R4[] = {
		{4 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R4[0], R4[1], R4[2], R4[3]);
}

void drawO()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = -((SHIFT_BASE_5 * 2) / SCALE_X) + (1 / SCALE_X);

	coordinate_t R1[] = {
		{0 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{2 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{1 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);

	coordinate_t R4[] = {
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R4[0], R4[1], R4[2], R4[3]);
}

void drawN()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = -((SHIFT_BASE_5 * 1) / SCALE_X) + (1 / SCALE_X);

	coordinate_t R1[] = {
		{0 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{4 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{4 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);
}

void drawA()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = -((SHIFT_BASE_5 * 0) / SCALE_X)  + (1 / SCALE_X);
	////float SHIFT_X = 0;

	coordinate_t R1[] = {
		{0 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{4 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{1.5f / SCALE_X + SHIFT_X, 1.5f / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 2.5f / SCALE_Y, 0 / SCALE_5},
		{3.5f / SCALE_X + SHIFT_X, 1.5f / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 2.5f / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);
}

void drawL()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = ((SHIFT_BASE_5 * 1) / SCALE_X) + (1 / SCALE_X);

	coordinate_t R1[] = {
		{0 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);
}


void drawI()
{
	float SCALE_X = SCALE_X_BASE * SCALE_FACTOR;
	float SCALE_Y = SCALE_Y_BASE * SCALE_FACTOR;
	float SCALE_5 = SCALE_5_BASE;

	float SHIFT_X = ((SHIFT_BASE_5 * 2) / SCALE_X) + (1 / SCALE_X);

	coordinate_t R1[] = {
		{1 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 0 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R1[0], R1[1], R1[2], R1[3]);

	coordinate_t R2[] = {
		{1 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X + SHIFT_X, 5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R2[0], R2[1], R2[2], R2[3]);

	coordinate_t R3[] = {
		{2 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 1 / SCALE_Y, 0 / SCALE_5},
		{2 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X + SHIFT_X, 4 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(R3[0], R3[1], R3[2], R3[3]);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawM();
	drawO();
	drawN();
	drawA();
	drawL();
	drawI();

	glutSwapBuffers();
}

void display_V1_26Apr2026(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// First triagle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();


	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;

	case 'F':
	case 'f':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;

	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;

	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}


/*********************************************************************************\
C:\Users\Sugriv\RTR7-2026\Session-03\FirstTriangle>cl.exe /c /EHsc /I c:\freeglut\include OGL_Word_MONALI.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

OGL_Word_MONALI.cpp

C:\Users\Sugriv\RTR7-2026\Session-03\FirstTriangle>link.exe OGL_Word_MONALI.obj /LIBPATH:C:\freeglut\lib\x64 freeglut.lib /SUBSYSTEM:CONSOLE
Microsoft (R) Incremental Linker Version 14.43.34810.0
Copyright (C) Microsoft Corporation.  All rights reserved.


C:\Users\Sugriv\RTR7-2026\Session-03\FirstTriangle>OGL_Word_MONALI.exe
\*********************************************************************************/

