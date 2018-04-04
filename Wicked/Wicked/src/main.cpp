#include "classes/Application.h"
#include "Square.h"

#include "classes\Shader.h"
#include "classes\Mesh.h"
#include "classes\RenderMesh.h"
#include "classes\maths\Vector3.h"

const char* svShader
{
	"#version 430 core\n"
	"layout (location = 0) in vec3 vPos;\n"
	"uniform mat4 model;\n"
	"uniform mat4 view;\n"
	"uniform mat4 projection;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = /*projection * view * model **/ vec4(vPos, 1.0f);\n"
	"}"
};

const char* sfShader
{
	"#version 430 core\n"
	"out vec4 fColor;\n"
	"void main()\n"
	"{\n"
	"	fColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
	"}"
};

int main()
{
	using namespace wicked;
	Application app(800, 600, "GameScene");

	//Shader shader(svShader, sfShader);
	//std::vector<maths::Vector3> position{ maths::Vector3(-0.5f, -0.5f, 0.0f), maths::Vector3(0.5f, -0.5f, 0.0f), maths::Vector3(0.0f, 0.5f, 0.0f) };
	//Mesh mesh;
	//mesh.position = position;

	//RenderMesh rm(mesh, shader);

	//Square s(maths::Vector3(0.0f, 0.0f, 0.0f), mesh, svShader, sfShader);
	app.run();

	return 0;
}