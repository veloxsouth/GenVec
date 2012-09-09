#include "ImagePanel.h"
#include <wx\image.h>
#include <wx\dcclient.h>
#include <wx\filedlg.h>
ImagePanel::ImagePanel(wxWindow* parent)
	:wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(400,400))
{
	wxInitAllImageHandlers();
	//wxString filename = wxLoadFileSelector(wxT("image"), wxEmptyString);
	wxString filename = wxT("testImage.bmp");
	//m_img = new wxImage(m_filename);
	m_bitmap.LoadFile(filename, wxBITMAP_TYPE_BMP);
	
	Bind(wxEVT_PAINT, &ImagePanel::OnPaint, this, wxID_ANY);
}


ImagePanel::~ImagePanel(void)
{
}

void ImagePanel::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
    PrepareDC(dc);
	dc.DrawBitmap(m_bitmap, 0, 0, false);
}