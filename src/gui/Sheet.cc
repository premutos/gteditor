#include "Sheet.hh"
#include "Staff.hh"
#include "../lib/Log.hh"

using namespace gteditor::gui;
using namespace gteditor::lib;

Sheet::Sheet(wxWindow * parent)
  : wxScrolledWindow(parent, wxID_ANY)
{
  this->SetScrollbars(10, 10, 100, 100);
  this->box = new wxBoxSizer(wxVERTICAL);
  this->SetSizer(this->box);
}

Sheet::~Sheet()
{
}

void Sheet::addStaff()
{
  Staff * staff = new Staff(this, wxDefaultPosition, wxDefaultSize);
  this->box->Add(staff, 0, wxTOP | wxBOTTOM, 10);
}
