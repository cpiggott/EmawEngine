#include "stdafx.h"
#include "Model.h"

using namespace std;

struct vertex {
	float x;
	float y;
	float z;
};

Model::Model() {

}

Model::~Model() {

}

void* Model::load(char* filename) {
	if (strlen(filename) <= 4) {
		OutputDebugString(L"file is of incorrect length\n");
	}
	// todo: fix for upper case input
	if (strncmp(".fbx", filename + (strlen(filename) - 4), 4) != 0) {
		OutputDebugString(L"file extension is incorrect\n");
	}

	// initialize 
	FbxManager* FbxLoader = NULL;
	FbxLoader = FbxManager::Create();
	FbxIOSettings* IOsettings = FbxIOSettings::Create(FbxLoader, IOSROOT);
	FbxLoader->SetIOSettings(IOsettings);

	FbxImporter* importer = FbxImporter::Create(FbxLoader, "");
	FbxScene* scene = FbxScene::Create(FbxLoader, "");

	//bool success = importer->Initialize(filename, );

	// load fbx file
	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		OutputDebugString(L"failed to open model file\n");
	}


	file.close();

	return NULL;
}

void* Model::getData() {
	return NULL;
}

bool Model::unload() {
	return NULL;
}