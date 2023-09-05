#ifndef OGL_H
#define OGL_H

#include <glad.h>
#include <glfw3.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include <iostream>
#include "shader.h"
#include "camera.h"

using namespace std;


/***************************************���ó���******************************************/

//���ô��ڵĿ�͸�
const unsigned int SCR_WIDTH=1000;
const unsigned int SCR_HEIGHT=800;

float mixValue=0.2f;

//������Ⱦ��֮֡���ʱ��
float deltaTime = 0.0f;
float lastFrame = 0.0f;

//��ʼ�������λ��
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//��ʼ��������λ�� ��Ļ����
double lastX = SCR_WIDTH / 2.0f;
double lastY = SCR_HEIGHT / 2.0f;
//�Ƿ�Ϊ��һ�ν������
bool firstMouse = true;

/**********************************��Ӧ����*******************************/

//��Ӧ���������¼�
void processInput(GLFWwindow* window)
{
	//ESC �˳�����
	//glfwGetKey()�����ж�һ�����Ƿ��¡���һ��������GLFW���ھ�����ڶ���������һ��GLFW����������һ������
	//GLFW_KEY_ESCAPE��ʾEsc�������Esc�������ˣ�glfwGetKey������GLFW_PRESS��ֵΪ1�������򷵻�GLFW_RELEASE��ֵΪ0����
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		//glfwSetWindowShouldClose()������Ϊ�������ùرձ�־����һ�������Ǵ��ھ�����ڶ���������ʾ�Ƿ�ر�
		//����ΪGLFW_TRUE����ʾ�رոô��ڡ�
		//ע�⣬��ʱ���ڲ����������رգ�����glfwWindowShouldClose()������GLFW_TRUE������glfwTerminate()�ͻ�رմ��ڡ�
		glfwSetWindowShouldClose(window, true);
	}

	//�ϼ�
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mixValue += 0.01f;
		if (mixValue >= 1.0f)
			mixValue = 1.0f;
	}
	//�¼�
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mixValue -= 0.01f;
		if (mixValue <= 0.0f)
			mixValue = 0.0f;
	}

	//WASD�ƶ������
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

}

//�ı䴰�ڵĴ�С��ʱ���ӿ�ҲӦ�ñ�������
//�Դ���ע��һ���ص�����(Callback Function)��������ÿ�δ��ڴ�С��������ʱ�򱻵���
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//OpenGL��Ⱦ���ڵĳߴ��С
	//glViewport����ǰ�����������ƴ������½ǵ�λ�á��������͵��ĸ�����������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�
	glViewport(0, 0, width, height);
}

//��Ӧ����¼� �������Ļص�����
//xpos,ypos����λ��
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//���Ϊ��һ�ν��� ��¼��ǰ���λ�� Ϊ��ʼ�����λ��
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	//���㵱ǰ֡����һ֡��λ�ò�
	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos; // ��������������� ʵ�ʲ��������������ƶ������ ����Ҳ����������ƶ� ʵ��Ӧ������

	/*cout << "�������Ϊ" <<xpos << endl;
	cout << "�������Ϊ" <<ypos << endl;*/

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}
//��Ӧ������ 
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

/****************************************************************************/


int oglmain() {

/***********************���ڴ����Լ���ʼ��*********************/
	glfwInit();// ��ʼ��GLFW
	/*glfwWindowHint��������GLFW����һ��������ѡ�������ڶ������������ѡ���ֵ*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// �����汾����Ϊ3����Ϊ�õ�OpenGL�汾��3.3��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// ���˰汾����Ϊ3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// ʹ�ú���ģʽ
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);�����MAC OS Xϵͳ��Ҫ�������

	/*�������ڶ���*/
	GLFWwindow* window = glfwCreateWindow(1000, 800, "OpengGL_Testing", nullptr, nullptr);// ���ô��ڴ�С������
	if (window == nullptr) {
		cout << "��������ʧ��" << endl;
		glfwTerminate();// ��������ʣ��Ĵ��ں��α�
		return -1;
	}
	glfwMakeContextCurrent(window);// ���õ�ǰ�������ģ�OpenGL��һ���Ӵ��״̬������״̬����Ϊ�����ģ�

	/*ʹ��GLAD����ָ��*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "��ʼ��GLADʧ��" << endl;
		return -1;
	}

	/*�����ӿڣ�����OpenGL��Ⱦ���ڵĳߴ��С*/
	glViewport(0, 0, 1000, 800);// ǰ�����Ǵ������½ǵ�λ�ã��������ǿ�͸�

	/*����GLFW��ÿ�δ��ڵ��õ�ʱ��ʹ��framebuffer_size_callback����*/
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*��������ƶ��¼� �ص������Ӧ����*/
	glfwSetCursorPosCallback(window, mouse_callback);
	/*���������ֵ��ƶ�*/
	glfwSetScrollCallback(window, scroll_callback);

	/*�������Ĺ�� ����һֱͣ���ڴ�����*/
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


/******************************����ͼ�����************************************/

	//������Ȳ��ԣ�Ĭ���ǹرյ�
	//GLFW���Զ�����Z-buffer ��Ȼ���
	glEnable(GL_DEPTH_TEST);

	// ��ɫ��
	Shader myShader;

	float xyz[]={
		0.0f, 0.0f,0.0f,//x����
		0.0f, 1.0f,0.0f,
		0.2f, 0.0f,0.0f,
		0.2f, 1.0f,0.0f,
		0.4f, 0.0f,0.0f,
		0.4f, 1.0f,0.0f,
		0.6f, 0.0f,0.0f,
		0.6f, 1.0f,0.0f,

		0.0f, 0.0f,0.0f,//y����
		0.1f, 0.0f,0.0f
		
	};

	//������  6���� ÿ����2�������� һ��������3���� 6*3*2  36������
	float vertices[] = {
		// λ��                ������ɫ              UV
		-0.5f, -0.5f, -0.5f,   0.0f,0.0f,1.0f,        0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,   0.0f,0.0f,1.0f,        1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,   0.0f,0.0f,1.0f,        1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,   0.0f,0.0f,1.0f,        1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,   0.0f,0.0f,1.0f,        0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f,0.0f,1.0f,        0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,   1.0f,0.0f,0.0f,        0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,   1.0f,0.0f,0.0f,        1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,   1.0f,0.0f,0.0f,        1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,   1.0f,0.0f,0.0f,        1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,   1.0f,0.0f,0.0f,        0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,   1.0f,0.0f,0.0f,        0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,   0.0f,1.0f,0.0f,        1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   0.0f,1.0f,0.0f,        1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f,1.0f,0.0f,        0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,   0.0f,1.0f,0.0f,        0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,   0.0f,1.0f,0.0f,        0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,   0.0f,1.0f,0.0f,        1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,   1.0f,1.0f,0.0f,        1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,   1.0f,1.0f,0.0f,        1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,   1.0f,1.0f,0.0f,        0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,   1.0f,1.0f,0.0f,        0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,   1.0f,1.0f,0.0f,        0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,   1.0f,1.0f,0.0f,        1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,   0.0f,1.0f,1.0f,        0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,   0.0f,1.0f,1.0f,        1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,        1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,        1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,        0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,   0.0f,1.0f,1.0f,        0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,   1.0f,1.0f,1.0f,        0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,   1.0f,1.0f,1.0f,        1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,   1.0f,1.0f,1.0f,        1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,   1.0f,1.0f,1.0f,        1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,   1.0f,1.0f,1.0f,        0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,   1.0f,1.0f,1.0f,        0.0f, 1.0f
	};

	//���������������ռ��λ��   ͨ����ͬ������ռ��������
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	// ���������������VAO��Vertex Array Object��
	unsigned int VAO;
	glGenVertexArrays(1, &VAO); // ��һ�������Ǽ�����������Ƕ�������ʱ������ڵڶ���������һ�������ȥ
	glBindVertexArray(VAO); // ��VAO

	// �������㻺�����VBO��Vertex Buffer Object��
	unsigned int VBO;
	glGenBuffers(1, &VBO);// ��һ�������Ǽ�����������Ƕ�������ʱ������ڵڶ���������һ�������ȥ
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // ��VBO

	// ���������ݰ󶨵�GL_ARRAY_BUFFER��
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// VAO������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


/****************************************��Ⱦѭ��********************************************/

	// glfwWindowShouldClose�������window�Ƿ�Ҫ���˳�
	while (!glfwWindowShouldClose(window)) {
		//����������֡����Ⱦʱ���
		float currentFrame = float(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		processInput(window); // ��������

		/*��Ⱦ����*/
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);// ����ɫ�����Ļ
		//��������Ϣ
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		//��ȡʱ��
		float timeValue = float(glfwGetTime());
		//����ʱ���ȡsinֵ(-1,1)ת����(0,1)
		float sinTime = sin(timeValue) / 2.0f + 0.5f;

		//����MVP����4X4  �ֲ�->����->ͶӰ----�ü��ռ�
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		//MVP��ֵ
		//����仯��Zoom ��Ϊ�ӽǽǶ� ʵ�����Ź���
		view=glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		myShader.use();
		myShader.setMat4("view",view);
		myShader.setMat4("projection",projection);
		myShader.setMat4("model",model);

		/*��VAO*/
		glBindVertexArray(VAO);

		//����
		glDrawArrays(GL_LINE_STRIP, 0, 36);



		glfwSwapBuffers(window); // ������ɫ����
		glfwPollEvents(); // �����û�д����¼�������������롢����ƶ��ȵȣ������´���״̬�������ö�Ӧ�Ļص�����
	}

	//�����
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	/*�ͷ���Դ*/
	glfwTerminate();

	return 0;
}


#endif // OGL_H
