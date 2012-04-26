#ifndef __GTEDITOR_STAFF_HH__
#define __GTEDITOR_STAFF_HH__

#include <wx/wx.h>

namespace gteditor {
namespace gui {

class Staff : public wxControl
{
public:
  Staff(wxWindow * parent, wxPoint position, wxSize size);

protected:
  void OnPaint(wxPaintEvent& event);

private:
  unsigned int topMargin;
  unsigned int bottomMargin;
  unsigned int rightMargin;
  unsigned int leftMargin;
  unsigned int interMargin;
  unsigned int nbString;
};

}
}

#endif
