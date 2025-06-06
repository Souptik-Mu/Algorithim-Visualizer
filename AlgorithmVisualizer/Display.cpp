#include "Display.h"


Display::Display(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent,id, pos, size)
{
	
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	this->Bind(wxEVT_PAINT, &Display::OnPaint, this);	
}

Display::~Display()
{
	delete[] Arr;
}

void Display::DrawArr(short* arr, short N ,bool f, int Red1 , int Red2 , int Green)
{
	this->Arr = arr;
	this->N = N;
	R1 = Red1;
	R2 = Red2;
	G1 = Green;
	F = f;
	Refresh();
}

void Display::OnPaint(wxPaintEvent& evt)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	
	if (gc)
	{		
		for (int i = 0; i < N; i++)
		{
			if (i == R1 || i == R2)
			{
				gc->SetPen(wxColor(255, 50, 50, 250));
				gc->SetBrush(wxColor(255, 50, 50, 50));	
			}
			else if (i == G1)
			{
				gc->SetPen(wxColor(85, 177, 85, 250));
				gc->SetBrush(wxColor(85, 177, 85, 50));
			}
			else if (F)
			{
				gc->SetPen(wxColor(85, 177, 85, 250));
				gc->SetBrush(wxColor(85, 177, 85, 250));
			}
			else
			{
				gc->SetPen(wxColor(113, 96, 232, 150));
				gc->SetBrush(wxColor(113, 96, 232, 250));
			}

			gc->DrawRectangle(10 + (580 / N) * i, 380 + 10, 580 / N, -Arr[i]);
				
		}
		delete gc;
	}
}
