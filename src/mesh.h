#ifndef MESH_H_
#define MESH_H_

#include "common.h"

namespace place {

	class Mesh
	{
	private:
		Mesh(const Mesh& other);
		void operator=(const Mesh& other);

		enum
		{
			POSITION_VB,
			NUM_BUFFERS
		};

		GLuint m_VertexArrayObject;
		GLuint m_VertexArrayBuffers[NUM_BUFFERS];
		GLuint m_DrawCount;

	public:
		Mesh(Vertex* vertices, unsigned int numVertices, GLenum usage);
		~Mesh();
		void draw(GLenum mode);
	};

}

#endif //	MESH_H_
