#pragma once

#include "resource.h"
#include "graphics_device_interface.h"
#include "Asset.h"
#include <string>
#include <iostream>
#include <fstream>
#include <fbxsdk.h>
#include <vector>

class Model {
public:
	Model();
	~Model();
	void* load(char*);
	void* getData();
	bool unload();
private:

};