#include "drawable.h"
#include "stdhdr.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
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
	std::vector< vec3 > temp_vertices, temp_normals;

	while(!stream.eof()){

		string line;
		string header;
		getline(stream,line);

		istringstream sstream(line);
		sstream >> header;

		if(header == "v"){

			vec3 vertex;
			sstream >> vertex.x >> vertex.y >> vertex.z;
			temp_vertices.push_back(vertex);
		}
		else if(header == "vn"){
			
			vec3 norm;
			sstream >> norm.x >> norm.y >> norm.z;
			temp_normals.push_back(norm);
		}
		else if(header == "f"){
			uint32_t v, tx, n;

			string remainder;
			getline(sstream, remainder);

			std::stringstream dummy(remainder);
			int count = std::distance(std::istream_iterator<std::string>(dummy), 
										std::istream_iterator<std::string>());
		
			size_t slashes = std::count(remainder.begin(), remainder.end(), '/');
			std::replace(remainder.begin(), remainder.end(), '/', ' ');
			istringstream lastStream(remainder);

			if((slashes / count) == 2){
				
				while(lastStream >> v >> tx >> n){
					vertexIndices.push_back(v);
					normalIndices.push_back(n);
				}
			}
		}
		else
			continue;
	}

	/* Process the vertices and normals */

	for(unsigned int i=0; i < vertexIndices.size(); i++){
		int v_idx = vertexIndices[i];
		int n_idx = normalIndices[i];
		vec3 vertex = temp_vertices[v_idx - 1];
		vec3 normal = temp_normals[n_idx - 1];
		vertices.push_back(vertex);
		normals.push_back(normal);
	}

	return true;
}

void DrawableOBJ::draw(){

	glBegin(GL_TRIANGLES);

	for(unsigned int i=0; i<vertices.size(); i++){

		vec3 vert, norm;
		vert = vertices[i];
		norm = normals[i];

		glNormal3f(norm.x, norm.y, norm.z);
		glVertex3f(vert.x, vert.y, vert.z);
	}

	glEnd();
}

DrawableOBJ::DrawableOBJ(){}
DrawableOBJ::~DrawableOBJ(){}


