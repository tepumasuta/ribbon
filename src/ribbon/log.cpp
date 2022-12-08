#include "log.hpp"

INITIALIZE_EASYLOGGINGPP
namespace Ribbon
{
    std::shared_ptr<el::Logger> Logger::s_EngineLogger;
    std::shared_ptr<el::Logger> Logger::s_ClientLogger;
    const std::array<el::Level, 5> Logger::s_LogLevels{
        el::Level::Info,
        el::Level::Warning,
        el::Level::Error,
        el::Level::Trace,
        el::Level::Fatal,
    };

    void Logger::Init()
    {
        s_EngineLogger = std::shared_ptr<el::Logger>(el::Loggers::getLogger("Engine"));
        s_ClientLogger = std::shared_ptr<el::Logger>(el::Loggers::getLogger("Client"));

        el::Configurations defaultConf;
        defaultConf.setToDefault();
        el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
        SetPattern(defaultConf, "[%level] {%logger} %datetime %func@%line: %msg");
        el::Loggers::reconfigureLogger("Engine", defaultConf);
        el::Loggers::reconfigureLogger("Client", defaultConf);
    }
    
    void Logger::SetPattern(el::Configurations& config, const char* pattern)
    {
        for (const auto& level: s_LogLevels)
        {
            config.set(level, el::ConfigurationType::Format, pattern);
        }
    }
}
