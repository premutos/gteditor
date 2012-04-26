#include "Configuration.hh"
#include "lib/Log.hh"

#include <wx/wx.h>

#include <fstream>

#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string/case_conv.hpp>

namespace po = boost::program_options;

using namespace gteditor;
using namespace gteditor::lib;

Configuration::ProgramOption::ProgramOption()
  : confFilename("/usr/local/etc/livecast-monitor.conf"),
    logOutput("stdout"),
    hSize(-1),
    vSize(-1),
    logLevel(5),
    logColor(false),
    logDate(false),
    logPid(false)
{
}

int
Configuration::ProgramOption::parseMainWinSize()
{
  int rc = 0;
  try
  {
    std::string::size_type xpos = this->mainWinSize.find("x");
    if (xpos != std::string::npos)
    {
      this->hSize = boost::lexical_cast<int>(this->mainWinSize.substr(0, xpos));
      this->vSize = boost::lexical_cast<int>(this->mainWinSize.substr(xpos + 1));
    }
    else
    {
      LogError::getInstance().sysLog(ERROR, "bad value of main window size: missing 'x' separator");
      rc = -1;
    }
  }
  catch (const boost::bad_lexical_cast& ex)
  {
    LogError::getInstance().sysLog(ERROR, "bad value of main window size: %s", ex.what());
    rc = -1;
  }
  return rc;
}

//
//

Configuration::Configuration()
{
}

void Configuration::parseOpts(int argc, char**argv)
{
  this->opts.reset(new Configuration::ProgramOption);
  bool error = false;
  try
  {
    
    po::variables_map input_arg;
    po::options_description desc("Usage");
    desc.add_options()
      ("help,h", "produce this message")
      ("conf", po::value<std::string>(&this->opts->confFilename)->default_value(this->opts->confFilename), "set configuration file name")
      ("log-output", po::value<std::string>(&this->opts->logOutput)->default_value(this->opts->logOutput), "log output (syslog, stdout)")
      ("log-ident", po::value<std::string>(&this->opts->logIdent)->default_value(argv[0]), "set log ident")
      ("log-level", po::value<unsigned int>(&this->opts->logLevel)->default_value(this->opts->logLevel), "set log level 2 to 7")
      ("log-color", po::bool_switch(&this->opts->logColor), "set color log")
      ("log-date", po::bool_switch(&this->opts->logDate), "put date in log")
      ("log-pid", po::bool_switch(&this->opts->logPid), "put pid in log")
      ("main-win-name", po::value<std::string>(&this->mainWinName)->default_value(argv[0]), "set main window name")
      ("main-win-size", po::value<std::string>(&this->opts->mainWinSize), "set main window size")
      ;

    po::positional_options_description p;
    p.add("conf", -1);

    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), input_arg);
    po::notify(input_arg);

    std::ifstream f(this->opts->confFilename.c_str());
    po::store(po::parse_config_file(f, desc, false), input_arg);
    f.close();
    po::notify(input_arg);

    if (input_arg.count("help"))
    {
      std::cout << desc << std::endl;      
      exit(0);
    }

    boost::algorithm::to_lower(this->opts->logOutput);
    if (this->opts->logOutput == "stdout")
    {
		  LogError::getInstance().setMode(STDOUT);
    }
    else if (this->opts->logOutput == "syslog")
    {
		  LogError::getInstance().setMode(SYSLOG);
    }
    LogError::getInstance().setLevel(this->opts->logLevel);
    LogError::getInstance().setIdent(this->opts->logIdent.c_str());
    LogError::getInstance().setLockMode(true);
    LogError::getInstance().setColorMode(this->opts->logColor);
    LogError::getInstance().setDateMode(this->opts->logDate);
    LogError::getInstance().setPidMode(this->opts->logPid);

    if (input_arg.count("main-win-size"))
    {
      if (this->opts->parseMainWinSize() < 0)
      {
        error = true;
      }
      else
      {
        this->hSize = this->opts->hSize;
        this->vSize = this->opts->vSize;
      }
    }
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << std::endl;
    error = true;
  }

  if (error)
  {
    throw new BadProgramOptions;
  }

}
