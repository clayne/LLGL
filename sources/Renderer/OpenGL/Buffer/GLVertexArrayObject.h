/*
 * GLVertexArrayObject.h
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#ifndef LLGL_GL_VERTEX_ARRAY_OBJECT_H
#define LLGL_GL_VERTEX_ARRAY_OBJECT_H


#include "../OpenGL.h"
#include "GLVertexInputLayout.h"
#include <LLGL/Container/ArrayView.h>


namespace LLGL
{


class GLStateManager;
struct GLVertexAttribute;

// Wrapper class for an OpenGL Vertex-Array-Object (VAO), for GL 3.0+.
class GLVertexArrayObject
{

    public:

        // Release VAO from GL context.
        void Release();

        // Builds the specified attribute using a 'glVertexAttrib*Pointer' function.
        void BuildVertexLayout(const GLVertexInputLayout& inputLayout);

        // Returns the ID of the hardware vertex-array-object (VAO)
        inline GLuint GetID() const
        {
            return id_;
        }

        // Returns the input layout hash from the last time BuildVertexLayout was called.
        inline std::size_t GetInputLayoutHash() const
        {
            return inputLayoutHash_;
        }

    private:

        void BuildVertexAttribute(const GLVertexAttribute& attribute);

    private:

        GLuint      id_                 = 0; // Vertex array object ID.
        GLuint      attribIndexEnd_     = 0; // Last VAO attribute index; This is needed when the input layout changes.
        std::size_t inputLayoutHash_    = 0;

};


} // /namespace LLGL


#endif



// ================================================================================
