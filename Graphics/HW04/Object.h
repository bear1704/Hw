#pragma once
#include <string>
#include <vector>

#include <glm/glm.hpp>

class Object
{
public:
  Object() {}

  void draw(int loc_a_vertex);
  void print();
	
	bool load_simple_obj(const std::string& filename);

private:
  std::vector<glm::vec3> vb;     // vertices  
};