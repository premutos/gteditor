#include "Configuration.hh"
#include "lib/Log.hh"
#include "gui/MainWindow.hh"

namespace gteditor {

class GTEditor : public wxApp
{
public:
  GTEditor();
  ~GTEditor();
  virtual bool OnInit();

private:
  boost::shared_ptr<Configuration::ProgramOption> parseProgramOptions();

  boost::shared_ptr<Configuration> cfg;
  boost::shared_ptr<gui::MainWindow> gui;
};

}

using namespace gteditor;

IMPLEMENT_APP(GTEditor);

GTEditor::GTEditor()
  : cfg(new Configuration)
{
}

GTEditor::~GTEditor()
{
}

bool GTEditor::OnInit()
{
  try
  {
    this->cfg->parseOpts(wxApp::argc, wxApp::argv);
  }
  catch (const Configuration::BadProgramOptions& ex)
  {
    return EXIT_FAILURE;
  }
  
  this->gui.reset(new gui::MainWindow(cfg));
  gui->Show(true);

  return true;
}
