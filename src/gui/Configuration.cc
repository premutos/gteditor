#include "Configuration.hh"
#include "../lib/Log.hh"

using namespace gteditor::gui;
using namespace gteditor::lib;

static boost::shared_ptr<Configuration> instance;

const boost::shared_ptr<Configuration> Configuration::getInstance()
{
  if (instance.get() == 0)
  {
    LogError::getInstance().sysLog(CRITICAL, "configuration not set");
  }
  return instance;
}

void Configuration::setInstance(const boost::shared_ptr<Configuration> cfg)
{
  instance = cfg;
}

Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}
