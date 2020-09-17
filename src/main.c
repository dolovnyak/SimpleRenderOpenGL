#include <math.h>
#include "scop.h"

typedef struct s_check
{
	GLFWwindow *window;
	int space_flag;
}				t_check;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
	// Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true,
	// и приложение после этого закроется
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
//	if(key == GLFW_KEY_SPACE && action == GLFW_PRESS)
//		*space_flag = !(*space_flag);
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

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "LearnOpenGL", NULL, NULL);
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

	float vertices[] = {
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

//	GLfloat texCoords[] = {
//			0.0f, 0.0f,  // Нижний левый угол
//			1.0f, 0.0f,  // Нижний правый угол
//			0.5f, 1.0f   // Верхняя центральная сторона
//	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	t_texture raw_texture = load_bmp("../resources/chaton.bmp");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, raw_texture.width, raw_texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, raw_texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	t_mat4 m1 = mvm_identity_m4x4();
	m1 = mvm_scale(m1, (t_vec3){3.f, 7.f, -2.f});
	m1 = mvm_scale(m1, (t_vec3){-2.f, 4.f, 5.f});
	m1 = mvm_x_rotate(m1, 60.f);
	m1 = mvm_y_rotate(m1, 60.f);
	m1 = mvm_z_rotate(m1, -60.f);
	m1 = mvm_translate(m1, (t_vec3){13.f, -2.f, 0.25f});

	t_mat4 model = mvm_identity_m4x4();
	model = mvm_x_rotate(model, -70.f);

	t_mat4 view = mvm_identity_m4x4();
	view = mvm_translate(view, (t_vec3){0.f, 0.f, -3.f});

	t_mat4 projection = mvm_perspective(66.f, (float) width / (float) height, 0.1f, 100.f);

	t_vec3 cubePositions[] = {
			(t_vec3){ 0.0f,  0.0f,  0.0f},
			(t_vec3){ 2.0f,  5.0f, -15.0f},
			(t_vec3){-1.5f, -2.2f, -2.5f},
			(t_vec3){-3.8f, -2.0f, -12.3f},
			(t_vec3){ 2.4f, -0.4f, -3.5f},
			(t_vec3){-1.7f,  3.0f, -7.5f},
			(t_vec3){ 1.3f, -2.0f, -2.5f},
			(t_vec3){ 1.5f,  2.0f, -2.5f},
			(t_vec3){ 1.5f,  0.2f, -1.5f},
			(t_vec3){-1.3f,  1.0f, -1.5f}
	};

	float angle_x = 0.f;
	float angle_y = 0.f;
	float angle_z = 0.f;
	glEnable(GL_DEPTH_TEST);
	glUseProgram(shaderProgram);
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSetKeyCallback(window, key_callback);

		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		GLfloat redValue = (sinf(timeValue + 100) / 2) + 0.5;
		GLfloat blueValue = (sinf(timeValue + 200) / 2) + 0.5;
		GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "coefs");
		glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

		t_mat4 trans = mvm_identity_m4x4();
		if (glfwGetKey(window, GLFW_KEY_1))
			angle_x += 0.7f;
		if (glfwGetKey(window, GLFW_KEY_2))
			angle_y += 0.7f;
		if (glfwGetKey(window, GLFW_KEY_3))
			angle_z += 0.7f;
		trans = mvm_x_rotate(trans, angle_x);
		trans = mvm_y_rotate(trans, angle_y);
		trans = mvm_z_rotate(trans, angle_z);

		GLint transformLocation = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLocation, 1, GL_FALSE, (GLfloat*)&trans);


		GLint viewLocation = glGetUniformLocation(shaderProgram, "view");
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, (GLfloat*)&view);

		GLint projectionLocation = glGetUniformLocation(shaderProgram, "projection");
		glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, (GLfloat*)&projection);

		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);
		for(GLuint i = 0; i < 10; i++)
		{
			model = mvm_identity_m4x4();
			model = mvm_translate(model, cubePositions[i]);
			GLint modelLocation = glGetUniformLocation(shaderProgram, "model");
			glUniformMatrix4fv(modelLocation, 1, GL_FALSE, (GLfloat*)&model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		glBindVertexArray(0);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	ft_printf("Hello, World!\n");
	glfwTerminate();
	return 0;
}
