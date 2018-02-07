#include "mesh.h"

namespace place {

	Mesh::Mesh(Vertex* vertices, unsigned int numVertices, GLenum usage)
	{
		m_DrawCount = numVertices;

		//	Create and bound the Array Object
		glGenVertexArrays(1, &m_VertexArrayObject);
		glBindVertexArray(m_VertexArrayObject); // === Like glBegin() === //

		//	Create and bound the Buffer Object
		glGenBuffers(NUM_BUFFERS, m_VertexArrayBuffers);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexArrayBuffers[POSITION_VB]);

		//	"Send" the data to the GPU
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, usage);

		//	Telling to OpenGL how to manipulate the data in GPU
		for(int i = 0; i < NUM_ATTRIB; ++i)
		{
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i,
														SIZE_ATTRIB,
														GL_FLOAT,
														GL_FALSE,
														NUM_ATTRIB * SIZE_ATTRIB * sizeof(GLfloat),
														(void*) (i * SIZE_ATTRIB * sizeof(GLfloat)));
		}

		glBindVertexArray(0); // ===	Like glEnd() === //
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1, &m_VertexArrayObject);
	}

	void Mesh::draw(GLenum mode)
	{
		glBindVertexArray(m_VertexArrayObject);

		glDrawArrays(mode, 0, m_DrawCount);

		glBindVertexArray(0);
	}
}
