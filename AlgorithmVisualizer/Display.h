#pragma once

#include"wx/wx.h"
#include"wx/frame.h"
#include"wx/thread.h"
#include"wx/graphics.h"
#include"wx/dcbuffer.h"

class Display : public wxWindow
{
public:
	
	Display(wxWindow* , wxWindowID , const wxPoint& , const wxSize&);
	~Display();
		
	void DrawArr(short*, short,bool=false, int = -1, int = -1, int = -1);
	void OnPaint(wxPaintEvent& evt);
	
private:
	int R1, R2, G1;
	bool F;
	short* Arr; short N;
};

