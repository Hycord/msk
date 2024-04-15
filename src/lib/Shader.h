/*
  Shader.h
  Created: April 15, 2024
*/
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

class Shader
{
private:
  std::string m_Filepath;
  unsigned int m_RendererID;
  std::unordered_map<std::string, int> m_UniformLocationCache;
  
  int GetUniformLocation(const std::string &name);
  
  
  static ShaderProgramSource ParseShader(const std::string &data);
  static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
  static unsigned int CompileShader(unsigned int type, const std::string &source);

public:
  Shader(const std::string &filepath);
  ~Shader();

  void Bind() const;
  void Unbind() const;

  bool CompileShader();

  void SetUniform4f(const std::string name, float v0, float v1, float v2, float v3);
  void SetUniform1f(const std::string name, float v0);
};
