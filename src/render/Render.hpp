#pragma once
#include <string>

class Mesh;
struct SDL_Window;

class Render {
private:
	SDL_Window* window;
	Mesh* drawList[4096];
	short int drawListCount;
	short int nextDrawId;
public:
	Render();
	void init();
	void start();
	void frame();
	void addMesh(Mesh* mesh);
  ~Render();
protected:

};