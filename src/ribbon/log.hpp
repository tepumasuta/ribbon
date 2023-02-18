#pragma once
#include "common.hpp"

#include "pch/ribpch.hpp"

namespace Ribbon
{
    class RIB_API Logger
    {
    public:
        static void Init();

        inline static el::Logger* const& GetEngineLogger() { return s_EngineLogger; }
        inline static el::Logger* const& GetClientLogger() { return s_ClientLogger; }
        static const std::array<el::Level, 5> GetSupportedLogLevels() { return s_LogLevels; }
    private:
        static el::Logger* s_EngineLogger;
        static el::Logger* s_ClientLogger;
        static const std::array<el::Level, 5> s_LogLevels;

        static void SetPattern(el::Configurations& config, const char* pattern);
    };
} // namespace Ribbon


// Engine log macros
#define RIB_ENGINE_TRACE CLOG(TRACE, ::Ribbon::Logger::GetEngineLogger()->id().c_str())
#define RIB_ENGINE_INFO  CLOG(INFO, ::Ribbon::Logger::GetEngineLogger()->id().c_str())
#define RIB_ENGINE_WARN  CLOG(WARNING, ::Ribbon::Logger::GetEngineLogger()->id().c_str())
#define RIB_ENGINE_ERROR CLOG(ERROR, ::Ribbon::Logger::GetEngineLogger()->id().c_str())
#define RIB_ENGINE_FATAL CLOG(FATAL, ::Ribbon::Logger::GetEngineLogger()->id().c_str())

// Client log macros
#define RIB_TRACE CLOG(TRACE, ::Ribbon::Logger::GetClientLogger()->id().c_str())
#define RIB_INFO  CLOG(INFO, ::Ribbon::Logger::GetClientLogger()->id().c_str())
#define RIB_WARN  CLOG(WARNING, ::Ribbon::Logger::GetClientLogger()->id().c_str())
#define RIB_ERROR CLOG(ERROR, ::Ribbon::Logger::GetClientLogger()->id().c_str())
#define RIB_FATAL CLOG(FATAL, ::Ribbon::Logger::GetClientLogger()->id().c_str())
