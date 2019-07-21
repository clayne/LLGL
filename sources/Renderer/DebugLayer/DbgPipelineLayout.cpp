/*
 * DbgPipelineLayout.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2018 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "DbgPipelineLayout.h"
#include "DbgCore.h"


namespace LLGL
{


DbgPipelineLayout::DbgPipelineLayout(PipelineLayout& instance, const PipelineLayoutDescriptor& desc) :
    instance { instance },
    desc     { desc     }
{
}

void DbgPipelineLayout::SetName(const char* name)
{
    DbgSetObjectName(*this, name);
}


} // /namespace LLGL



// ================================================================================