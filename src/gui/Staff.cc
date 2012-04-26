#include "Staff.hh"
#include "../lib/Log.hh"

using namespace gteditor::gui;
using namespace gteditor::lib;

Staff::Staff(wxWindow * parent, wxPoint position, wxSize size)
  : wxControl(parent, wxID_ANY, position, wxSize(1000, 200), wxBORDER_SIMPLE),
    topMargin(50),
    bottomMargin(50),
    rightMargin(50),
    leftMargin(50),
    interMargin(20),
    nbString(6)
{
  this->Bind(wxEVT_PAINT, &Staff::OnPaint, this, wxID_ANY);
}

void Staff::OnPaint(wxPaintEvent& WXUNUSED(event))
{
  LogError::getInstance().sysLog(DEBUG, "OnPaint");
  wxPaintDC dc(this);
  dc.SetBrush(wxNullBrush);

  unsigned int gap = (this->GetSize().GetHeight() - this->topMargin - this->interMargin - this->bottomMargin) / (5 + this->nbString);
  unsigned int length = this->GetSize().GetWidth();
  wxPoint p1 = wxPoint(this->rightMargin, this->topMargin);
  wxPoint p2 = wxPoint(length - this->leftMargin, this->topMargin);

  for (unsigned int i = 0; i < 5; i++)
  {
    dc.DrawLine(p1, p2);
    p1.y += gap;
    p2.y += gap;
  }

  p1.y += this->interMargin;
  p2.y += this->interMargin;


  for (unsigned int i = 0; i < this->nbString; i++)
  {
    dc.DrawLine(p1, p2);
    p1.y += gap;
    p2.y += gap;
  }

}
