/*
 * D3D12GraphicsPSO.h
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#ifndef LLGL_D3D12_GRAPHICS_PIPELINE_H
#define LLGL_D3D12_GRAPHICS_PIPELINE_H


#include "D3D12RenderPSOBase.h"


namespace LLGL
{


class D3D12GraphicsPSO final : public D3D12RenderPSOBase
{

    public:

        // Constructs the graphics PSO with the specified descriptor.
        D3D12GraphicsPSO(
            ID3D12Device*                       device,
            D3D12PipelineLayout&                defaultPipelineLayout,
            const GraphicsPipelineDescriptor&   desc,
            const D3D12RenderPass*              defaultRenderPass,
            PipelineCache*                      pipelineCache           = nullptr
        );

        // Binds this graphics PSO to the specified command context.
        void Bind(D3D12CommandContext& commandContext) override;

    private:

        void CreateNativePSO(
            ID3D12Device*                       device,
            const D3D12PipelineLayout&          pipelineLayout,
            const D3D12RenderPass*              renderPass,
            const GraphicsPipelineDescriptor&   desc,
            D3D12PipelineCache*                 pipelineCache   = nullptr
        );

        ComPtr<ID3D12PipelineState> CreateNativePSOWithDesc(ID3D12Device* device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& desc, const char* debugName);

    private:

        /*
        Secondary PSO if index format is undefined for strip topologies:
        - Primary PSO for D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF
        - Secondary PSO for D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF
        */
        ComPtr<ID3D12PipelineState> secondaryPSO_;

        D3D12_PRIMITIVE_TOPOLOGY    primitiveTopology_  = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;

};


} // /namespace LLGL


#endif



// ================================================================================
