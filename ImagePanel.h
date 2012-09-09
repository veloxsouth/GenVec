#pragma once
#include <wx\panel.h>
#include <wx\bitmap.h>

class ImagePanel :
	public wxPanel
{
public:
	ImagePanel(wxWindow* parent);
	virtual ~ImagePanel(void);
protected:
	void OnPaint(wxPaintEvent& evt);
	//wxImage* m_img;
	wxBitmap m_bitmap;
};

