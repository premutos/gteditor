#include "gui/Util.hh"
#include "gui/Sheet.hh"
#include "lib/Log.hh"

#include <wx/wx.h>
#include <wx/vscroll.h>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

namespace gteditor {
namespace tests {

class TestSheet : public wxApp
{
public:
  TestSheet();
  ~TestSheet();
  virtual bool OnInit();
};

}
}

using namespace gteditor::gui;
using namespace gteditor::lib;
using namespace gteditor::tests;
namespace po = boost::program_options;

IMPLEMENT_APP(TestSheet);

TestSheet::TestSheet()
{
}

TestSheet::~TestSheet()
{
}

bool TestSheet::OnInit()
{
  try
  {
    po::variables_map input_arg;
    po::options_description desc("Usage");
    desc.add_options()
      ("help,h", "produce this message")
      ("file,f", po::value<std::string>(), "")
      ;

    po::positional_options_description p;
    p.add("file", -1);

    po::store(po::command_line_parser(wxApp::argc, wxApp::argv).options(desc).positional(p).run(), input_arg);
    po::notify(input_arg);

    if (input_arg.count("help"))
    {
      std::cout << desc << std::endl;      
      return false;
    }

    LogError::getInstance().setMode(STDOUT);
    LogError::getInstance().setIdent(wxApp::argv[0]);
    LogError::getInstance().setLockMode(true);
    LogError::getInstance().setColorMode(true);
    LogError::getInstance().setDateMode(true);
    LogError::getInstance().setPidMode(true);
    LogError::getInstance().setLevel(6);
    
    if (input_arg.count("file"))
    {
      LogError::getInstance().sysLog(DEBUG, "parse file: '%s'", input_arg["file"].as<std::string>().c_str());
      std::ifstream fin(input_arg["file"].as<std::string>().c_str());
      fin.close();
    }

    wxFrame * frame = new wxFrame(NULL, wxID_ANY, "test staff");
    Sheet * sheet = new Sheet(frame);
    for (unsigned int i = 0; i < 5; i++) 
      sheet->addStaff();
    wxBoxSizer * box = new wxBoxSizer(wxHORIZONTAL);
    box->Add(sheet, 1, wxEXPAND);
    frame->SetSizer(box);
    frame->Show(true);

  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << std::endl;
    return false;
  }
  
  return true;
}
