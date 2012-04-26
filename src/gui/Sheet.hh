#ifndef __GTEDITOR_SHEET_HH__
#define __GTEDITOR_SHEET_HH__

#include <wx/wx.h>
#include <wx/scroll.h>

namespace gteditor {
namespace gui {

class Sheet : public wxScrolledWindow
{
public:
  Sheet(wxWindow * parent);
  ~Sheet();
}

}
}

#endif
