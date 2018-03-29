#include <fstream>
#include <sstream>
#include <algorithm>
#include "Mesh.h"

namespace wicked
{
	Mesh::Mesh()
		: Object(typeid(Mesh).raw_name()),
		normals{},
		triangles{},
		uv{},
		vertices{}
	{
	}

	Mesh::Mesh(const Mesh& mesh)
		: Object(mesh.getName()),
		normals(mesh.normals),
		triangles{mesh.triangles},
		uv(mesh.uv),
		vertices(mesh.vertices)
	{
		setIndexNormals(mesh.getIndexNormals());
		setIndexUV(mesh.getIndexUV());
		setIndexVertices(mesh.getIndexVertices());
	}

	bool wicked::Mesh::loadMesh(const char * file)
	{
		std::ifstream meshFile(file);
		bool v{ false }, vt{ false }, vn{ false };

		if (!meshFile)
			return false;

		while (meshFile)
		{
			std::string data;
			meshFile >> data;

			if (data == "v")
			{
				maths::Vector3 vertex;
				v = true;
				meshFile >> vertex.x >> vertex.y >> vertex.z;
				vertices.push_back(vertex);
			}
			else if (data == "vt")
			{
				maths::Vector2 texture;
				vt = true;
				meshFile >> texture.x >> texture.y;
				uv.push_back(texture);
			}
			else if (data == "vn")
			{
				maths::Vector3 normal;
				vn = true;
				meshFile >> normal.x >> normal.y >> normal.z;
				normals.push_back(normal);
			}
			else if (data == "f")
			{
				std::string str;
				std::getline(meshFile, str);
				std::replace(str.begin(), str.end(), '/', ' ');
				std::stringstream ss(str);
				std::vector<unsigned int> indices;

				for (unsigned int i{ 0 }; ss >> i;)
					indices.push_back(i);

				if (indices.size() == 3)
				{
					for (size_t i = 0; i < indices.size(); i++)
						indexVertices.push_back(indices[i]);
				}
				else if (indices.size() == 6)
				{
					if (vt)
						for (size_t i = 0; i < indices.size() / 2; i++)
						{
							indexVertices.push_back(indices[i * 2]);
							indexUV.push_back(indices[(i * 2) + 1]);
						}
					else if (vn)
						for (size_t i = 0; i < indices.size() / 2; i++)
						{
							indexVertices.push_back(indices[i * 2]);
							indexNormals.push_back(indices[(i * 2) + 1]);
						}
				}
				else if (indices.size() == 9)
				{
					for (size_t i = 0; i < indices.size() / 3; i++)
					{
						indexVertices.push_back(indices[i * 3]);
						indexUV.push_back(indices[(i * 3) + 1]);
						indexNormals.push_back(indices[(i * 3) + 2]);
					}
				}
			}
			else
				continue;
		}

		return true;
	}

	const std::vector<unsigned int>& Mesh::getIndexNormals() const
	{
		return indexNormals;
	}

	const std::vector<unsigned int>& Mesh::getIndexUV() const
	{
		return indexUV;
	}

	const std::vector<unsigned int>& Mesh::getIndexVertices() const
	{
		return indexVertices;
	}

	void Mesh::setIndexNormals(const std::vector<unsigned int>& normalsIndices)
	{
		indexNormals = normalsIndices;
	}

	void Mesh::setIndexUV(const std::vector<unsigned int>& uvIndices)
	{
		indexUV = uvIndices;
	}

	void Mesh::setIndexVertices(const std::vector<unsigned int>& verticesIndices)
	{
		indexVertices = verticesIndices;
	}
}