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


/***************************************设置常量******************************************/

//设置窗口的宽和高
const unsigned int SCR_WIDTH=1000;
const unsigned int SCR_HEIGHT=800;

float mixValue=0.2f;

//缓冲渲染两帧之差的时间
float deltaTime = 0.0f;
float lastFrame = 0.0f;

//初始化相机的位置
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//初始化鼠标光标的位置 屏幕中心
double lastX = SCR_WIDTH / 2.0f;
double lastY = SCR_HEIGHT / 2.0f;
//是否为第一次进入程序
bool firstMouse = true;

/**********************************响应函数*******************************/

//响应键盘输入事件
void processInput(GLFWwindow* window)
{
	//ESC 退出窗口
	//glfwGetKey()用来判断一个键是否按下。第一个参数是GLFW窗口句柄，第二个参数是一个GLFW常量，代表一个键。
	//GLFW_KEY_ESCAPE表示Esc键。如果Esc键按下了，glfwGetKey将返回GLFW_PRESS（值为1），否则返回GLFW_RELEASE（值为0）。
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		//glfwSetWindowShouldClose()函数，为窗口设置关闭标志。第一个参数是窗口句柄，第二个参数表示是否关闭
		//这里为GLFW_TRUE，表示关闭该窗口。
		//注意，这时窗口不会立即被关闭，但是glfwWindowShouldClose()将返回GLFW_TRUE，到了glfwTerminate()就会关闭窗口。
		glfwSetWindowShouldClose(window, true);
	}

	//上键
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		mixValue += 0.01f;
		if (mixValue >= 1.0f)
			mixValue = 1.0f;
	}
	//下键
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		mixValue -= 0.01f;
		if (mixValue <= 0.0f)
			mixValue = 0.0f;
	}

	//WASD移动摄像机
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

}

//改变窗口的大小的时候，视口也应该被调整。
//对窗口注册一个回调函数(Callback Function)，它会在每次窗口大小被调整的时候被调用
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//OpenGL渲染窗口的尺寸大小
	//glViewport函数前两个参数控制窗口左下角的位置。第三个和第四个参数控制渲染窗口的宽度和高度（像素）
	glViewport(0, 0, width, height);
}

//响应鼠标事件 创建鼠标的回调函数
//xpos,ypos鼠标的位置
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//如果为第一次进入 记录当前鼠标位置 为初始化鼠标位置
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	//计算当前帧和上一帧的位置差
	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos; // 这里如果不反过来 实际操作过程中向上移动摄像机 物体也会跟着向上移动 实际应该向下

	/*cout << "鼠标左右为" <<xpos << endl;
	cout << "鼠标上下为" <<ypos << endl;*/

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}
//响应鼠标滚轮 
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

/****************************************************************************/


int oglmain() {

/***********************窗口创建以及初始化*********************/
	glfwInit();// 初始化GLFW
	/*glfwWindowHint用来配置GLFW，第一个参数是选项名，第二个参数是这个选项的值*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// 将主版本号设为3（因为用的OpenGL版本是3.3）
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// 将此版本号设为3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// 使用核心模式
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);如果是MAC OS X系统需要加上这句

	/*创建窗口对象*/
	GLFWwindow* window = glfwCreateWindow(1000, 800, "OpengGL_Testing", nullptr, nullptr);// 设置窗口大小、名字
	if (window == nullptr) {
		cout << "创建窗口失败" << endl;
		glfwTerminate();// 销毁所有剩余的窗口和游标
		return -1;
	}
	glfwMakeContextCurrent(window);// 设置当前的上下文（OpenGL是一个庞大的状态机，其状态被称为上下文）

	/*使用GLAD管理指针*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "初始化GLAD失败" << endl;
		return -1;
	}

	/*设置视口，告诉OpenGL渲染窗口的尺寸大小*/
	glViewport(0, 0, 1000, 800);// 前两个是窗口左下角的位置，后两个是宽和高

	/*告诉GLFW，每次窗口调用的时候使用framebuffer_size_callback函数*/
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*监听鼠标移动事件 回调鼠标响应函数*/
	glfwSetCursorPosCallback(window, mouse_callback);
	/*监听鼠标滚轮的移动*/
	glfwSetScrollCallback(window, scroll_callback);

	/*隐藏鼠标的光标 光标会一直停留在窗口中*/
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


/******************************绘制图像相关************************************/

	//启用深度测试，默认是关闭的
	//GLFW会自动生成Z-buffer 深度缓冲
	glEnable(GL_DEPTH_TEST);

	// 着色器
	Shader myShader;

	float xyz[]={
		0.0f, 0.0f,0.0f,//x轴线
		0.0f, 1.0f,0.0f,
		0.2f, 0.0f,0.0f,
		0.2f, 1.0f,0.0f,
		0.4f, 0.0f,0.0f,
		0.4f, 1.0f,0.0f,
		0.6f, 0.0f,0.0f,
		0.6f, 1.0f,0.0f,

		0.0f, 0.0f,0.0f,//y轴线
		0.1f, 0.0f,0.0f
		
	};

	//立方体  6个面 每个面2个三角形 一个三角形3个点 6*3*2  36个顶点
	float vertices[] = {
		// 位置                顶点颜色              UV
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

	//设置立方体的世界空间的位置   通过不同的世界空间矩阵设置
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
	// 创建顶点数组对象VAO（Vertex Array Object）
	unsigned int VAO;
	glGenVertexArrays(1, &VAO); // 第一个参数是几个对象，如果是多个对象的时候可以在第二个参数传一个数组进去
	glBindVertexArray(VAO); // 绑定VAO

	// 创建顶点缓冲对象VBO（Vertex Buffer Object）
	unsigned int VBO;
	glGenBuffers(1, &VBO);// 第一个参数是几个对象，如果是多个对象的时候可以在第二个参数传一个数组进去
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // 绑定VBO

	// 将顶点数据绑定到GL_ARRAY_BUFFER上
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// VAO的设置
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


/****************************************渲染循环********************************************/

	// glfwWindowShouldClose用来检查window是否被要求退出
	while (!glfwWindowShouldClose(window)) {
		//计算上下两帧的渲染时间差
		float currentFrame = float(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		processInput(window); // 处理输入

		/*渲染操作*/
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);// 用颜色清空屏幕
		//清除深度信息
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		//获取时间
		float timeValue = float(glfwGetTime());
		//利用时间获取sin值(-1,1)转换成(0,1)
		float sinTime = sin(timeValue) / 2.0f + 0.5f;

		//创建MVP矩阵4X4  局部->世界->投影----裁剪空间
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		//MVP赋值
		//传入变化的Zoom 作为视角角度 实现缩放功能
		view=glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		myShader.use();
		myShader.setMat4("view",view);
		myShader.setMat4("projection",projection);
		myShader.setMat4("model",model);

		/*绑定VAO*/
		glBindVertexArray(VAO);

		//绘制
		glDrawArrays(GL_LINE_STRIP, 0, 36);



		glfwSwapBuffers(window); // 交换颜色缓冲
		glfwPollEvents(); // 检查有没有触发事件（比如键盘输入、鼠标移动等等），更新窗口状态，并调用对应的回调函数
	}

	//解除绑定
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	/*释放资源*/
	glfwTerminate();

	return 0;
}


#endif // OGL_H
