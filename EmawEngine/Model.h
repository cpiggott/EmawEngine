#pragma once

#include "resource.h"
#include "graphics_device_interface.h"
#include "Asset.h"
#include <string>
#include <iostream>
#include <fstream>
#include <fbxsdk.h>
#include <vector>

using namespace std;

struct Vertex {
	float x;
	float y;
	float z;
};

// a, b, and c are indicies in the vertex buffer
struct Triangle {
	int a;
	int b;
	int c;
};

class Model {
private:
	std::vector<Vertex> vertexBuffer;
	std::vector<Triangle> triangleList;
public:
	Model();
	~Model();
	void* load(char*);
	void* getData();
	bool unload();
	std::vector<Vertex> getVertexBuffer();
	std::vector<Triangle> getTriangleList();
};