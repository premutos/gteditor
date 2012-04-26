#ifndef __GTEDITOR_CONFIGURATION_HH__
#define __GTEDITOR_CONFIGURATION_HH__

#include "gui/Configuration.hh"

namespace gteditor {

class Configuration : public gui::Configuration
{
public:

  class BadProgramOptions
  {
  };

  struct ProgramOption
  {
    std::string confFilename;
    std::string mainWinName;
    std::string mainWinSize;
    std::string logOutput;
    std::string logIdent;
    int hSize;
    int vSize;
    unsigned int logLevel;
    bool logColor;
    bool logDate;
    bool logPid;

    ProgramOption();
    int parseMainWinSize();
  };

public:
  Configuration();
  void parseOpts(int argc, char**argv);

  inline const boost::shared_ptr<ProgramOption> getOpts() const { return this->opts; }

private:
  boost::shared_ptr<ProgramOption> opts;
};

}

#endif
