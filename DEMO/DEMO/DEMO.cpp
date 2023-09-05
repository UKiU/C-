#include <math.h>
#include <GL/glut.h>
#include <iostream>

#define NUM_POINTS 6
struct Point2 {
	float x;
	float y;
	Point2(int px=NULL, int py=NULL) { x = px; y = py; }
	void SetPoint2(int px, int py) { x = px; y = py; }
};

Point2 vec[NUM_POINTS+1];
bool mouseLeftDown = false;

double B(int n, int i, float t) {
	int sum = 1;
	if (i == n || i == 0) return pow(t, i) * pow(1 - t, n - i);
	int j;
	for (j = n - i + 1; j <= n; j++)
		sum *= j;
	for (j = 1; j <= i; j++)
		sum /= j;
	return sum * pow(t, i) * pow(1 - t, n - i);
}

Point2 setBezier(float t) {
	Point2 p;
	p.x = 0;
	p.y = 0;
	for (int k = 0; k <= NUM_POINTS; k++) {
		p.x += vec[k].x * B(NUM_POINTS - 1, k, t);
		p.y += vec[k].y * B(NUM_POINTS - 1, k, t);
	}
	return p;
}

//draw a point
void setPoint() {
	glPointSize(10.0f);
	//black（R G B)
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int b = 0; b < NUM_POINTS; b++)
		glVertex2f(vec[b].x, vec[b].y);
	glEnd();
}

//draw line
void setLine(Point2 f, Point2 g) {
	glLineWidth(1.5f);
	glBegin(GL_LINE_STRIP);
	glVertex2f(f.x, f.y);
	glVertex2f(g.x, g.y);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(1.0, 0.0, 0.0);
	for (int a = 0; a < NUM_POINTS - 1; a++)
		setLine(vec[a], vec[a + 1]);
	setPoint();

	Point2 p_current = vec[0];
	for (float c = 0; c <= 1; c += 0.05) {
		Point2 p = setBezier(c);
		setLine(p_current, p);
		//glFlush();
		p_current = p;
	}

	glFlush();
	glutSwapBuffers();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	for (int d = 0; d < NUM_POINTS; d++)
		vec[d].SetPoint2(10 + 100 * d, 500 - 5 * d * d);//生成不在同一直线的若干点

}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLsizei)w, (GLsizei)h, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mouseLeftDown = true;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		mouseLeftDown = false;

}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void motion(int x, int y) {
	if (mouseLeftDown) {
		for (int c = 0; c < NUM_POINTS; c++) {
			if (distance(vec[c].x, vec[c].y, x, y) < 20)
				vec[c].SetPoint2(x, y);
		}
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bezier");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();
	return 0;
}