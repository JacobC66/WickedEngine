#ifndef MESH_H
#define MESH_H

#include <vector>
#include "maths\Vector2.h"
#include "maths\Vector3.h"
#include "Object.h"

namespace wicked
{
	class Mesh
		: public Object
	{
	public:
		std::vector<maths::Vector3> normals;
		std::vector<int> triangles;
		std::vector<maths::Vector2> uv;
		std::vector<maths::Vector3> vertices;
	private:
		std::vector<unsigned int> indexNormals;
		std::vector<unsigned int> indexUV;
		std::vector<unsigned int> indexVertices;

	public:
		Mesh();
		Mesh(const Mesh& mesh);
		bool loadMesh(const char* file);
		const std::vector<unsigned int>& getIndexNormals() const;
		const std::vector<unsigned int>& getIndexUV() const;
		const std::vector<unsigned int>& getIndexVertices() const;
		void setIndexNormals(const std::vector<unsigned int>& normalsIndices);
		void setIndexUV(const std::vector<unsigned int>& uvIndices);
		void setIndexVertices(const std::vector<unsigned int>& verticesIndices);
	};
}

#endif