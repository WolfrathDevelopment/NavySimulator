#include "drawable.h"
#include "stdhdr.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <inttypes.h>

using std::string;
using std::vector;
using std::ios;
using std::istringstream;

bool DrawableOBJ::parseFromFile(string file){

	std::fstream stream;

	try{
		stream.open(file.c_str(), ios::in);
	}catch(...){ return false;}

	if(!stream.good())
		return false;

	std::vector< uint32_t > vertexIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices, temp_normals;

	while(!stream.eof()){

		string line;
		string header;
		getline(stream,line);

		istringstream sstream(line);
		sstream >> header;

		if(header == "v"){

			glm::vec3 vertex;
			sstream >> vertex.x >> vertex.y >> vertex.z;
			temp_vertices.push_back(vertex);
		}
		else if(header == "vn"){
			
			glm::vec3 norm;
			sstream >> norm.x >> norm.y >> norm.z;
			temp_normals.push_back(norm);
		}
		else if(header == "f"){
			uint32_t v[3], tx[3], n[3];

			string remainder;
			getline(sstream, remainder);
			std::replace(remainder.begin(), remainder.end(), '/', ' ');
			istringstream lastStream(remainder);

			lastStream 	>> v[0] >> tx[0] >> n[0]
						>> v[1] >> tx[1] >> n[1]
						>> v[2] >> tx[2] >> n[2];

			vertexIndices.push_back(v[0]);
			vertexIndices.push_back(v[1]);
			vertexIndices.push_back(v[2]);

			normalIndices.push_back(n[0]);
			normalIndices.push_back(n[1]);
			normalIndices.push_back(n[2]);
		}
		else
			continue;
	}

	/* Process the vertices and normals */

	for(unsigned int i=0; i < vertexIndices.size(); i++){
		int v_idx = vertexIndices[i];
		int n_idx = normalIndices[i];
		glm::vec3 vertex = temp_vertices[v_idx - 1];
		glm::vec3 normal = temp_normals[n_idx - 1];
		vertices.push_back(vertex);
		normals.push_back(normal);
	}

	return true;
}

void DrawableOBJ::draw(){

	glBegin(GL_TRIANGLES);

	for(unsigned int i=0; i<vertices.size(); i++){

		glm::vec3 vert, norm;
		vert = vertices[i];
		norm = normals[i];

		glNormal3f(norm.x, norm.y, norm.z);
		glVertex3f(vert.x, vert.y, vert.z);
	}

	glEnd();
}

DrawableOBJ::DrawableOBJ(){}
DrawableOBJ::~DrawableOBJ(){}


