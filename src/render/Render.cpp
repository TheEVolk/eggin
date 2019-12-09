#include <iostream>
#include "Windows.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Render.hpp"
#include "Mesh.hpp"

Render::Render()
{
	this->drawListCount = 0;
}

void Render::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO: modern
		throw std::exception(("Unable to init SDL, error: " + std::string(SDL_GetError())).c_str());
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	this->window = SDL_CreateWindow(
		"Cube",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	SDL_GL_CreateContext(this->window);
	if (this->window == nullptr) {
		throw std::exception("Unable to create window.");
	}

	// ������������� OpenGL
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // ������������� ������� ���� �� ������
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // �������� ���� �������
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f); // ����������� ���������� �����������
	glMatrixMode(GL_MODELVIEW); // ��������� � ���������� �����
}

void Render::start()
{

}

void Render::frame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (short int i = 0; i < this->drawListCount; i++) {
		auto a = this->drawList[i];
		((void (*) ())a->data)();
	}
	SDL_GL_SwapWindow(this->window);
}

void Render::addMesh(Mesh* mesh)
{
	this->drawList[this->drawListCount] = mesh;
	this->drawListCount++;
}

Render::~Render()
{

}