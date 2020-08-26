#include "scop.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true,
	// и приложение после этого закроется
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	char cwd[500];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_printf("Current working dir: %s\n", cwd);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		ft_printf("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		ft_printf("Failed to initialize GLEW");
		return -1;
	}


	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	GLuint shaderProgram = create_shader_program(
			(const char *[]){"../shaders/vertex.glsl", "../shaders/fragment.glsl", NULL},
			(const GLuint[]){GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, 0});

	GLfloat vertices[] = {
			0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,        // Нижний правый угол
			-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,       // Нижний левый угол
			0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.5f, 1.0f        // Верхний угол
	};

	GLfloat texCoords[] = {
			0.0f, 0.0f,  // Нижний левый угол
			1.0f, 0.0f,  // Нижний правый угол
			0.5f, 1.0f   // Верхняя центральная сторона
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	t_texture raw_texture = load_bmp("../resources/chaton.bmp");
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, raw_texture.width, raw_texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, raw_texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(shaderProgram);
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSetKeyCallback(window, key_callback);

//		GLfloat timeValue = glfwGetTime();
//		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
//		GLfloat redValue = (sin(timeValue + 100) / 2) + 0.5;
//		GLfloat blueValue = (sin(timeValue + 200) / 2) + 0.5;
//		GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "coefs");
//		glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	ft_printf("Hello, World!\n");
	glfwTerminate();
	return 0;
}
