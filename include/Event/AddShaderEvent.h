#pragma once

#include <string>

#include "Event/EventBase.h"
#include "Event/EventTypes.h"
#include "Promise.h"

namespace RixinSDL {
    class AddShaderEvent : public EventBase {
    private:
        //  Private stuff here
        static const int numShaders = 5;
        std::string shaderPaths[numShaders];
        EmilyPromise::Promise<int>& sProgramPromise;
    public:
        //  Public stuff here
        enum ShaderType {
            Vertex,
            Tesellation,
            Evaluation,
            Geometry,
            Fragment,
            Compute,
        };

        AddShaderEvent(
            const std::string& vertexFile,
            const std::string& fragmentFile,
            EmilyPromise::Promise<int>& promise
        ) : EventBase(EventTypes::ADD_SHADER_EVENT),
            sProgramPromise{promise} {
                
            shaderPaths[ShaderType::Vertex] = vertexFile;
            shaderPaths[ShaderType::Fragment] = fragmentFile;
        }

        void AddShader(ShaderType shaderType, const std::string& path) {
            shaderPaths[shaderType] = path;
        }
    };
} // RixinSDL
