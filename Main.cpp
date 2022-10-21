
#include "GL/glew.h"
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>

#include "GameObject.h"
#include "Pixel.h"
#include "Texture.h"
#include "TexturedCube.h"
#include "ChessBoard.h"
#include "HeightMap.h"
#include "Vendor\stb_image\Texturing.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

//STB
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define LEFT_ARROW 75
#define RIGHT_ARROW 77

using namespace std;


static const int WIDTH = 800;
static const int HEIGHT = 600;

GameObject gameObject;
Texture* texture;
Texturing* texturing;
TexturedCube gObject;
ChessBoard chessBoard;
HeightMap heightMap;
//Shader shader;

void input(int key, int x, int y);
void init();
void display();
void timer(int);
void updateCamera();
int cameraPos;

bool isPressed = false;

//Initial Calls + Window Setup
int main(int argc, char* argv[]) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	//Window initialising
	{
		int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
		int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;
		glutInitWindowPosition(windowX, windowY);
		glutInitWindowSize(WIDTH, HEIGHT);
		glutCreateWindow("My First Window");
	}

	chessBoard.SetRandom(); //Sets the offset for each chess tile

	glutDisplayFunc(display);
	glutSpecialFunc(input);
	glutTimerFunc(0, timer, 0);
	init();
	glutMainLoop();
	
	delete texture;

	return 0;

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		float positions[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, //0
			0.5f, -0.5f, 1.0f, 0.0f, //1
			0.5f, 0.5f, 1.0f, 1.0f, //2
			-0.5f, 0.5f, 0.0f, 1.0f //3
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		//Texture blending
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		//Shaders
		Shader shader("res/shaders/Basic.shader"); //locating the shader
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);

		//Textures
		Texturing texturing("Textures/cloudimage.png"); //locating the png image
		texturing.Bind();
		shader.SetUniform1i("u_Texture", 0);

		//Unbinding
		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		//Rendering
		Render render;

		float r = 0.0f;
		float increment = 0.05f;

		//while (!glfwWindowShouldClose(window))
		//{
		//	render.Clear();

		//	shader.Bind();
		//	shader.SetUniform4f(u_Color, r, 0.3f, 0.8f, 1.0f);

		//	render.Draw(va, ib, shader);
		//}

	}
}

//Change Initial Camera View + Texture
void init() {
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0, WIDTH, HEIGHT, 0,0,1);
	gluPerspective(50.0, (double)WIDTH / (double)HEIGHT, 1.0, 1000.0);

	//updateCamera();
	gluLookAt(
		0, 30, 50,
		0, 0, 0,
		0, 1, 0
	);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	texture = new Texture("Textures/cloudimage.png");
	//texture = new Texture("Textures/wolfram.png");
}

void display() {

	updateCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(1, 0, 1, 0);

	//Display HeightMap
	{
	glPushMatrix();
	heightMap.DrawMap(15, 100, texture);
	glPopMatrix();
	}

	//Display ChessBoard
	{
	glPushMatrix();
	glTranslatef(0, 0.5f, 0);
	glRotatef(90, 1, 0, 0);
	chessBoard.draw();
	glPopMatrix();
	}

	glutSwapBuffers();

}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);		//	Comment this if you want to pause
}

void updateCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;


	if (!isPressed)
	{
		if (GetKeyState(GLUT_KEY_RIGHT) & 0x8000)
		{
			cout << "D" << endl;
			isPressed = true;
			cameraPos--;
		}
		else if (GetKeyState(GLUT_KEY_LEFT) & 0x8000)
		{
			
			cout << "A" << endl;
			isPressed = true;
			cameraPos++;
		}
	}
	else
	{
		Sleep(500);
		isPressed = false;
	}

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5; 
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX,0,0,
		0, 1, 0
	);
}

void input(int key, int x, int y) {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;


	if (key == (GLUT_KEY_RIGHT))
	{
		cout << "D" << endl;
		isPressed = true;
		cameraPos--;
	}
	else if (key == (GLUT_KEY_LEFT))
	{

		cout << "A" << endl;
		isPressed = true;
		cameraPos++;
	}

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5;
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX, 0, 0,
		0, 1, 0
	);
}