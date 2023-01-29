#pragma once

#include "../debug/Debug.hpp"
#include "glm/glm.hpp"
#include "glm/gtx/normal.hpp"

struct Vertex {
	glm::vec2 Position;
	glm::vec4 Color;
	glm::vec2 TexCoords;
	int TexID;
};

struct Vertex3D {
	glm::vec3 Position;
	glm::vec4 Color;
	glm::vec2 TexCoords;
	float TexID;
};

struct Vertex3DN {
	glm::vec3 Position;
	glm::vec4 Color;
	glm::vec2 TexCoords;
	glm::vec3 Normal;
	float TexID;
};

struct VertexMesh {
	glm::vec3 Position;
	glm::vec2 TexCoords;
	glm::vec3 Normal;
	float TexID;
};

struct Vertex3DLight {
	glm::vec3 Position;
	glm::vec4 LightColor;
};

struct Triangle {
	Vertex3D v1;
	Vertex3D v2;
	Vertex3D v3;
};

struct TriangleN {
	Vertex3DN v1;
	Vertex3DN v2;
	Vertex3DN v3;
};

struct TriangleLight {
	Vertex3DLight v1;
	Vertex3DLight v2;
	Vertex3DLight v3;
};

struct Cube {
	Triangle* t[12];

	~Cube() { 
		for (Triangle* ts : t) {
			delete ts;
		}
	};
};

class VertexBuffer {
private:
	unsigned int m_RendererID;
	size_t m_DataPtr;

public:
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer(unsigned int size);
	~VertexBuffer();

	void AddVertexData(const void* data, int size, int offset);
	void AddVertexData(const void* data, int size);

	static void addPoly(glm::vec3 pos0, glm::vec3 pos1, glm::vec3 pos2, glm::vec2 texPos0, glm::vec2 texPos1, glm::vec2 texPos2, glm::vec4 color, float texId, VertexBuffer& vb);
	static void addPolyN(glm::vec3 pos0, glm::vec3 pos1, glm::vec3 pos2, glm::vec2 texPos0, glm::vec2 texPos1, glm::vec2 texPos2, glm::vec4 color, float texId, VertexBuffer& vb);
	static void addPoly(glm::vec3 pos0, glm::vec3 pos1, glm::vec3 pos2, glm::vec4 color, VertexBuffer& vb);

	static void addCube(glm::vec3 position, float sideLength, glm::vec4 color, float texId, VertexBuffer& vb);
	static void addCubeN(glm::vec3 position, float sideLength, glm::vec4 color, float texId, VertexBuffer& vb);
	static void addLightSource(glm::vec3 position, float sideLength, glm::vec4 color, VertexBuffer& vb);

	void Bind() const;
	void Unbind() const;
};