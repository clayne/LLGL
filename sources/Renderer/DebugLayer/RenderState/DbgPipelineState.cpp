/*
 * DbgPipelineState.cpp
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#include "DbgPipelineState.h"
#include "DbgPipelineLayout.h"
#include "../../PipelineStateUtils.h"
#include "../DbgCore.h"
#include "../../CheckedCast.h"


namespace LLGL
{


DbgPipelineState::DbgPipelineState(PipelineState& instance, const GraphicsPipelineDescriptor& desc) :
    instance       { instance                                                 },
    label          { LLGL_DBG_LABEL(desc)                                     },
    pipelineLayout { LLGL_CAST(const DbgPipelineLayout*, desc.pipelineLayout) },
    isGraphicsPSO  { true                                                     },
    isMeshPSO      { false                                                    },
    graphicsDesc   { desc                                                     }
{
}

DbgPipelineState::DbgPipelineState(PipelineState& instance, const ComputePipelineDescriptor& desc) :
    instance       { instance                                                 },
    label          { LLGL_DBG_LABEL(desc)                                     },
    pipelineLayout { LLGL_CAST(const DbgPipelineLayout*, desc.pipelineLayout) },
    isGraphicsPSO  { false                                                    },
    isMeshPSO      { false                                                    },
    computeDesc    { desc                                                     }
{
}

DbgPipelineState::DbgPipelineState(PipelineState& instance, const MeshPipelineDescriptor& desc) :
    instance       { instance                                                 },
    label          { LLGL_DBG_LABEL(desc)                                     },
    pipelineLayout { LLGL_CAST(const DbgPipelineLayout*, desc.pipelineLayout) },
    isGraphicsPSO  { false                                                    },
    isMeshPSO      { true                                                     },
    meshDesc       { desc                                                     }
{
}

DbgPipelineState::~DbgPipelineState()
{
    // dummy
}

bool DbgPipelineState::HasDynamicBlendFactor() const
{
    return
    (
        (isGraphicsPSO && graphicsDesc.blend.blendFactorDynamic && IsBlendFactorEnabled(graphicsDesc.blend)) ||
        (    isMeshPSO &&     meshDesc.blend.blendFactorDynamic && IsBlendFactorEnabled(    meshDesc.blend))
    );
}

bool DbgPipelineState::HasDynamicStencilRef() const
{
    return
    (
        (isGraphicsPSO && graphicsDesc.stencil.referenceDynamic && IsStencilRefEnabled(graphicsDesc.stencil)) ||
        (    isMeshPSO &&     meshDesc.stencil.referenceDynamic && IsStencilRefEnabled(    meshDesc.stencil))
    );
}

void DbgPipelineState::SetDebugName(const char* name)
{
    DbgSetObjectName(*this, name);
}

const Report* DbgPipelineState::GetReport() const
{
    return instance.GetReport();
}


} // /namespace LLGL



// ================================================================================
