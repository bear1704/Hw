#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

#include "Object.h"

void Object::draw(int loc_a_vertex)
{
	glVertexAttribPointer(loc_a_vertex, 3, GL_FLOAT, false, 0, &vb[0]);
	
	glEnableVertexAttribArray(loc_a_vertex);
	
	glDrawArrays(GL_TRIANGLES, 0, vb.size());

	glDisableVertexAttribArray(loc_a_vertex);	
}

void Object::print()
{
	for (size_t i=0; i<vb.size(); ++i)
  {
    const glm::vec3& p = vb[i];

    std::cout << "v " << p.x << " " << p.y << " " << p.z << std::endl;
  }
}

bool Object::load_simple_obj(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "failed to open file: " << filename << std::endl;
		return false;
	}

	Object* obj = new Object();

	std::vector<glm::vec3> tmp_vertices;
	std::vector<glm::vec2> tmp_texcoords;
	std::vector<glm::vec3> tmp_normals;

	std::string line;
	std::locale loc;

	float x, y, z;
	std::string type_str;
	char slash;				// get only on character '\'

	std::stringstream ss;

	while (!file.eof())
	{
		std::getline(file, line);

		ss.clear();
		ss.str(line);

		// comment or space		
		if (line[0] == '#' || std::isspace(line[0], loc))
		{
			continue; // skip
		}
		// vertex
		else if (line.substr(0, 2) == "v ")
		{
			glm::vec3 vertex;
			ss >> type_str >> vertex.x >> vertex.y >> vertex.z;
			tmp_vertices.push_back(vertex);
		}
		// texture coordinate
		else if (line.substr(0, 3) == "vt ")
		{
			glm::vec2 texcoord;
			ss >> type_str >> texcoord.s >> texcoord.t;
			tmp_texcoords.push_back(texcoord);
		}
		// vertex normal
		else if (line.substr(0, 3) == "vn ")
		{
			glm::vec3 norm;
			ss >> type_str >> norm.x >> norm.y >> norm.z;
			tmp_normals.push_back(norm);
		}
		// faces
		else if (line.substr(0, 2) == "f ")
		{
			glm::u16vec3 vert_idx;
			glm::u16vec3 coord_idx;

			ss >> type_str >> vert_idx.x >> slash >> coord_idx.x >>
				vert_idx.y >> slash >> coord_idx.y >>
				vert_idx.z >> slash >> coord_idx.z;

			vb.push_back(tmp_vertices[vert_idx[0] - 1]);
			vb.push_back(tmp_vertices[vert_idx[1] - 1]);
			vb.push_back(tmp_vertices[vert_idx[2] - 1]);
		}
	}
	
	std::cout << "finished to read: " << filename << std::endl;
	return true;
}
