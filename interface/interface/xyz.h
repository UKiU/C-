#ifndef XYZ_H
#define XYZ_H
#include <glad.h>
#include <gl/GL.h>
#include <gl/glut.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

void GLGrid(float pt1x, float pt1y, float pt1z, float pt2x, float pt2y, float pt2z, int num)

{

	const float _xLen = (pt2x - pt1x) / num;
	const float _yLen = (pt2y - pt1y) / num;
	const float _zLen = (pt2z - pt1z) / num;
	glLineWidth(2.f);
	glLineStipple(1, 0x0303);//线条样式

	glBegin(GL_LINES);
	glEnable(GL_LINE_SMOOTH);

	int xi = 0;
	int yi = 0;
	int zi = 0;

	//绘制平行于X的直线
	for (zi = 0; zi <= num; zi++)
	{
		float z = _zLen * zi + pt1z;
		for (yi = 0; yi <= num; yi++)
		{
			float y = _yLen * yi + pt1y;
			glVertex3f(pt1x, y, z);
			glVertex3f(pt2x, y, z);
		}
	}
	//绘制平行于Y的直线
	for (zi = 0; zi <= num; zi++)
	{
		float z = _zLen * zi + pt1z;
		for (xi = 0; xi <= num; xi++)
		{
			float x = _xLen * xi + pt1x;
			glVertex3f(x, pt1y, z);
			glVertex3f(x, pt2y, z);
		}
	}
	//绘制平行于Z的直线
	for (yi = 0; yi <= num; yi++)
	{
		float y = _yLen * yi + pt1y;
		for (xi = 0; xi <= num; xi++)
		{
			float x = _xLen * xi + pt1x;
			glVertex3f(x, y, pt1z);
			glVertex3f(x, y, pt2z);
		}
	}
	glEnd();
}
void ordination() {

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);                   //设置反走样
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);       //设置反走样
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glRotatef(-45, 0.0, 1.0, 0.0);
	//网格
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(-4, -4, -4);
	GLGrid(0,0,0,8,0,8,20);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-4,4, -4);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.9f, 0.9f, 0.0f);
	GLGrid(0, 0, 0, 8, 0, 8, 20);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-4, -4, -4);
	glRotatef(90, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.9f, 0.0f);
	GLGrid(0, 0, 0, 8, 0, 8, 20);
	glPopMatrix();




	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_POLYGON_SMOOTH);

}


#endif
