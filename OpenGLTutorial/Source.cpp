#define GLEW_STATIC
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello triangle", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	// Start GLEW extension handler
	glewExperimental = GLU_TRUE;
	glewInit();

	// Get version info
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// tell GL to only draw a pixel if it's closer to the viewer than
	// whatever is currently there
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glfwTerminate();
	return 0;
}