#include "log.hpp"

INITIALIZE_EASYLOGGINGPP
namespace Ribbon
{
    el::Logger* Logger::s_EngineLogger;
    el::Logger* Logger::s_ClientLogger;
    const std::array<el::Level, 5> Logger::s_LogLevels{
        el::Level::Info,
        el::Level::Warning,
        el::Level::Error,
        el::Level::Trace,
        el::Level::Fatal,
    };
    static el::Configurations defaultConf;

    void Logger::Init()
    {
        s_EngineLogger = el::Loggers::getLogger("Engine");
        s_ClientLogger = el::Loggers::getLogger("Client");

        defaultConf.setToDefault();
        el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
        SetPattern(defaultConf, "[%level] {%logger} %datetime %func@%line: %msg");
        el::Loggers::reconfigureLogger(s_EngineLogger->id(), defaultConf);
        el::Loggers::reconfigureLogger(s_ClientLogger->id(), defaultConf);
    }
    
    void Logger::SetPattern(el::Configurations& config, const char* pattern)
    {
        for (const auto& level: s_LogLevels)
        {
            config.set(level, el::ConfigurationType::Format, pattern);
        }
    }
}
