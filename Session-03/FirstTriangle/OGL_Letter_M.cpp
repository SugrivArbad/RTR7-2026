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

#define SCALE_X (15.0f)
#define SCALE_Y (5.0f)
#define SCALE_5 (5.0f)

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

void drawM()
{
	coordinate_t MR1[] = {
		{0 / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{0 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(MR1[0], MR1[1], MR1[2], MR1[3]);

	coordinate_t MR2[] = {
		{0 / SCALE_X, 2.5 / SCALE_Y, 0 / SCALE_5},
		{1 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5},
		{2.5 / SCALE_X, 1 / SCALE_Y, 0 / SCALE_5},
		{3 / SCALE_X, 1.5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(MR2[0], MR2[1], MR2[2], MR2[3]);

	coordinate_t MR3[] = {
		{1.75 / SCALE_X, 1.5 / SCALE_Y, 0 / SCALE_5},
		{2.5 / SCALE_X, 1 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X, 2.5 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(MR3[0], MR3[1], MR3[2], MR3[3]);

	coordinate_t MR4[] = {
		{4 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X, 3 / SCALE_Y, 0 / SCALE_5},
		{4 / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5},
		{5 / SCALE_X, 0 / SCALE_Y, 0 / SCALE_5}
	};
	drawSqaure(MR4[0], MR4[1], MR4[2], MR4[3]);
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawM();

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
* x64 Native Tools Command Prompt VS2022 : run following commands
* cl.exe /c /EHsc /I C:\freeglut\include OGL.cpp
* link.exe OGL.obj / LIBPATH:c:\freeglut\lib\x64 freeglut.lib / SUBSYSTEM:CONSOLE
* OGL.exe
\*********************************************************************************/

