#include "stdafx.h"
#include "Model.h"

using namespace std;

vector<Vertex> vertexBuffer;
vector<Triangle> triangleList;

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

	// initialize fbx loader thing
	FbxManager* FbxLoader = NULL;
	FbxLoader = FbxManager::Create();
	FbxIOSettings* IOsettings = FbxIOSettings::Create(FbxLoader, IOSROOT);
	FbxLoader->SetIOSettings(IOsettings);

	FbxImporter* importer = FbxImporter::Create(FbxLoader, "");
	FbxScene* scene = FbxScene::Create(FbxLoader, "");

	bool success = importer->Initialize(filename, -1,
		FbxLoader->GetIOSettings());
	if (!success) {
		OutputDebugString(L"some kinda failure\n");
	}
	success = importer->Import(scene);
	if (!success) {
		OutputDebugString(L"some kinda failure\n");
	}

	importer->Destroy();

	FbxNode* node = scene->GetRootNode();
	if (node) {
		for (int i = 0; i < node->GetChildCount(); i++) {
			FbxNode* childNode = node->GetChild(i);
			if (childNode->GetNodeAttribute() == NULL) {
				continue;
			}
			FbxNodeAttribute::EType attributeType = childNode->GetNodeAttribute()->GetAttributeType();
			if (attributeType != FbxNodeAttribute::eMesh) {
				continue;
			}
			FbxMesh* mesh = (FbxMesh*)childNode->GetNodeAttribute();
			FbxVector4* verticies = mesh->GetControlPoints();
			for (int j = 0; j < mesh->GetPolygonCount(); j++) {
				int numVerticies = mesh->GetPolygonSize(j);
				if (numVerticies != 3) {
					// yeah, I know that this is awful, but strings were being real bitchy.
					OutputDebugString(L"3 verticies expected; ");
					switch (numVerticies) {
					case 4:
						OutputDebugString(L"4");
						break;
					default:
						OutputDebugString(L"unknown");
						break;
					}
					OutputDebugString(L" given; make sure your model only has triangles.\n");
				}
				for (int k = 0; k < numVerticies; k++) {
					int controlPointIndex = mesh->GetPolygonVertex(j, k);
					Vertex vertex;
					vertex.x = (float)verticies[controlPointIndex].mData[0];
					vertex.y = (float)verticies[controlPointIndex].mData[1];
					vertex.z = (float)verticies[controlPointIndex].mData[2];
					
					// search for this vertex in the vertex buffer
					bool found = false;
					int index = -1;
					for (int m = 0; m < vertexBuffer.size(); m++) {
						if (vertex.x == vertexBuffer[m].x && vertex.y == vertexBuffer[m].y && vertex.z == vertexBuffer[m].z) {
							found = true;
							index = m;
							break;
						}
					}
					if (!found) {
						index = vertexBuffer.size();
						vertexBuffer.push_back(vertex);
					}

					if (k == 0) {
						triangleList.push_back(Triangle());
						triangleList[triangleList.size() - 1].a = index;
					} else if (k == 1) {
						triangleList[triangleList.size() - 1].b = index;
					} else if (k == 2) {
						triangleList[triangleList.size() - 1].c = index;
					}
				}
			}
		}
	}

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

vector<Vertex> Model::getVertexBuffer() {
	return vertexBuffer;
}

vector<Triangle> Model::getTriangleList() {
	return triangleList;
}