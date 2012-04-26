#ifndef __GTEDITOR_GUI_CONFIGURATION_HH__
#define __GTEDITOR_GUI_CONFIGURATION_HH__

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

namespace gteditor {
namespace gui {

class Configuration
{
public:
  static const boost::shared_ptr<Configuration> getInstance();  
  static void setInstance(const boost::shared_ptr<Configuration> cfg);

  virtual ~Configuration();

  std::string mainWinName;
  int hSize;
  int vSize;

protected:
  Configuration();
};

}
}

#endif
