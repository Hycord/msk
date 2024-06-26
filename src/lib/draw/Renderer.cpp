/*
  Renderer.cpp
  Created: April 15, 2024
*/

#include "Renderer.h"

Renderer::Renderer(/* args */)
{
}

Renderer::~Renderer()
{
}

void Renderer::Clear() const
{
  GLCall(glClear(GL_COLOR_BUFFER_BIT));

  GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
  GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
{
  shader.Bind();
  va.Bind();
  ib.Bind();

  GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
