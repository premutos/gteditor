#ifndef __GTEDITOR_MAIN_WINDOW_GUI_HH__
#define __GTEDITOR_MAIN_WINDOW_GUI_HH__

#include <wx/wx.h>
#include <wx/aui/auibook.h>
#include <boost/shared_ptr.hpp>

namespace gteditor {
namespace gui {

class Configuration;

class MainWindow : public wxFrame
{
public:
  MainWindow(boost::shared_ptr<Configuration> cfg);
  ~MainWindow();

private:
  void onCloseWindow(wxCloseEvent& ev);
  void onOpenPreferences(wxCommandEvent& ev);
  void onClosePreferences(wxCloseEvent& ev);
  void onExit(wxCommandEvent& ev);

  wxMenuBar * menubar;

  // LivecastPreferences * preferences;
  boost::shared_ptr<Configuration> cfg;
};

}
}

#endif
