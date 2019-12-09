#pragma once
#include <string>

enum RenderType
{
	RENDERTYPE_FUNCTION
};

class Mesh {
private:
public:
	RenderType renderType;
	void* data;

	Mesh();
    ~Mesh();
protected:

};