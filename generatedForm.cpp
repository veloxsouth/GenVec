///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedForm.h"

///////////////////////////////////////////////////////////////////////////

GeneratedForm::GeneratedForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,400 ), wxTAB_TRAVERSAL );
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

GeneratedForm::~GeneratedForm()
{
}
