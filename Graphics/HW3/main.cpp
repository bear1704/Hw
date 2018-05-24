// hello_world.cpp
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include "vec.hpp"
#include "mat.hpp"
#include "transform.hpp"

void init();
void mydisplay();
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type);

GLuint program; // 쉐이더 프로그램 객체의 레퍼런스 값
GLint  loc_a_position;
GLint  loc_a_color;
GLint  loc_u_M;
GLint  loc_u_V;
GLint  loc_u_P;


int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Hello FreeGLUT");

  init();
  glutDisplayFunc(mydisplay);
  glutMainLoop();

  return 0;
}


// GLSL 파일을 읽어서 컴파일한 후 쉐이더 객체를 생성하는 함수
GLuint create_shader_from_file(const std::string& filename, GLuint shader_type)
{
  GLuint shader = 0;
  shader = glCreateShader(shader_type);
  std::ifstream shader_file(filename.c_str());
  std::string shader_string;
  shader_string.assign(
    (std::istreambuf_iterator<char>(shader_file)),
    std::istreambuf_iterator<char>());

  const GLchar* shader_src = shader_string.c_str();

  glShaderSource(shader, 1, (const GLchar**)&shader_src, NULL);
  glCompileShader(shader);

  return shader;
}


void init()
{
  glewInit();

  // 정점 쉐이더 객체를 파일로부터 생성
  GLuint vertex_shader
    = create_shader_from_file("./shader/vertex.glsl", GL_VERTEX_SHADER);

  // 프래그먼트 쉐이더 객체를 파일로부터 생성
  GLuint fragment_shader
    = create_shader_from_file("./shader/fragment.glsl", GL_FRAGMENT_SHADER);

  // 쉐이더 프로그램 생성 및 컴파일
  program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  loc_u_M = glGetUniformLocation(program, "u_M");
  loc_u_V = glGetUniformLocation(program, "u_V");
  loc_u_P = glGetUniformLocation(program, "u_P");


  loc_a_position = glGetAttribLocation(program, "a_position");
  loc_a_color    = glGetAttribLocation(program, "a_color");



  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void mydisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float position[] = {
    0.0f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.0f, 0.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 1.0f,
  };

  float color[] = {
    1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 1.0f,
  };

  using namespace kmuvcl::math;

  mat4x4f M, V, P;

  mat4x4f T = translate(0.25f, 0.0f, 0.0f);
  mat4x4f R = rotate(30.0f, 0.0f, 0.0f, 1.0f);
  M = T*R;

  V = lookAt(1.0f, 1.0f, 10.0f,
             0.0f, 0.0f, 0.0f,
             0.0f, 1.0f, 0.0f);

  P = perspective(25.0f, 1.0f, 0.001f, 10000.0f);

  glUseProgram(program);

  glUniformMatrix4fv(loc_u_M, 1, false, M);
  glUniformMatrix4fv(loc_u_V, 1, false, V);
  glUniformMatrix4fv(loc_u_P, 1, false, P);


  glVertexAttribPointer(loc_a_position, 4, GL_FLOAT, GL_FALSE, 0, position);
  glVertexAttribPointer(loc_a_color, 4, GL_FLOAT, GL_FALSE, 0, color);

  glEnableVertexAttribArray(loc_a_color);
  glEnableVertexAttribArray(loc_a_position);

  glDrawArrays(GL_TRIANGLES, 0, 3 /* 정점개수 */);

  glDisableVertexAttribArray(loc_a_color);
  glDisableVertexAttribArray(loc_a_position);

  glUseProgram(0);

  glutSwapBuffers();
}
