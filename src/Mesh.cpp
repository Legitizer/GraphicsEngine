#include "Mesh.h"

Mesh::Mesh(float *vertices, int sizeof_vertices_,  unsigned int *elements, int sizeof_elements_){
    this->vertices_ = vertices;
    this->elements_ = elements;

    this->sizeof_vertices_ = sizeof_vertices_;
    this->sizeof_elements_ = sizeof_elements_;

    if (vertices_ != NULL && elements_ != NULL) {
        initialize_vertex_arrays_();
    }
}

void Mesh::initialize_vertex_arrays_(){
    // Generates ONE vertex array object whos ID is stored in vao_.
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
        // Generates a vertex buffer object and stores its ID in positions_vbo_. This will be filled with vertex positions.
        glGenBuffers(1, &positions_vbo_);
        glBindBuffer(GL_ARRAY_BUFFER, positions_vbo_);
            glBufferData(GL_ARRAY_BUFFER, sizeof_vertices_ * sizeof(float), vertices_, GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Index/Element Array Buffer
        glGenBuffers(1, &ebo_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof_elements_ * sizeof(unsigned int), elements_, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::draw(){
    glBindVertexArray(vao_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glDrawElements(GL_TRIANGLES, sizeof_elements_, GL_UNSIGNED_INT, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}