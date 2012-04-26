#include "MainWindow.hh"
#include "Configuration.hh"
#include "../lib/Log.hh"
#include <boost/lexical_cast.hpp>

using namespace gteditor::gui;
using namespace gteditor::lib;

enum gteditor_menu_t
{
  GTEDITOR_MENU_FILE_QUIT = 1,
  GTEDITOR_MENU_EDIT_PREFERENCES,
};

MainWindow::MainWindow(boost::shared_ptr<Configuration> cfg)
  : wxFrame(NULL, 
            wxID_ANY, 
            cfg->mainWinName, 
            wxDefaultPosition, 
            wxSize(cfg->hSize, cfg->vSize)),
    // preferences(0),
    cfg(cfg)
{
  //
  // icon
  this->SetIcon(wxIcon(wxT("res/livecast_admin_logo.png")));

  // file menu
  wxMenu * file = new wxMenu;  
  file->Append(GTEDITOR_MENU_FILE_QUIT, wxT("&Quit\tCtrl-q"), wxT("Quit"));

  // edit menu
  wxMenu * edit = new wxMenu;
  edit->Append(GTEDITOR_MENU_EDIT_PREFERENCES, wxT("&Preferences\tCtrl-p"), wxT("Preferences"));

  // view menu
  wxMenu * view = new wxMenu;
  view->AppendSeparator();

  // help menu
  wxMenu * help = new wxMenu;

  // menu bar
  menubar = new wxMenuBar;
  menubar->Append(file, wxT("&File"));
  menubar->Append(edit, wxT("&Edit"));
  menubar->Append(view, wxT("&View"));
  menubar->Append(help, wxT("&Help"));
  this->SetMenuBar(menubar);

  // bind menu action
  this->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::onExit, this, GTEDITOR_MENU_FILE_QUIT);
  this->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::onOpenPreferences, this, GTEDITOR_MENU_EDIT_PREFERENCES);

  this->Centre();  

  this->Bind(wxEVT_CLOSE_WINDOW, &MainWindow::onCloseWindow, this, wxID_ANY);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onCloseWindow(wxCloseEvent& WXUNUSED(ev))
{
  LogError::getInstance().sysLog(DEBUG, "hide main window");
  this->Hide();
}

void MainWindow::onOpenPreferences(wxCommandEvent& WXUNUSED(ev))
{
  LogError::getInstance().sysLog(DEBUG, "onpen preferences");
//   if (this->preferences == 0)
//   {
//     this->preferences = new LivecastPreferences(this);
//   }
//   this->preferences->Bind(wxEVT_CLOSE_WINDOW, &MainWindow::onClosePreferences, this, wxID_ANY);
//   this->preferences->Show(true);
}

void MainWindow::onClosePreferences(wxCloseEvent& WXUNUSED(ev))
{
  LogError::getInstance().sysLog(DEBUG, "close preferences");
  // this->preferences->Show(false);
}

void MainWindow::onExit(wxCommandEvent& WXUNUSED(ev))
{
  LogError::getInstance().sysLog(DEBUG, "exit");
  this->Destroy();
}
