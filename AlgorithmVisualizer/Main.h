#pragma once

#include "wx/wx.h" 
#include "Window.h"


class Main : public wxApp
{
public:
	Main();
	~Main();

	virtual bool OnInit();
private:
	Window* Tframe = nullptr;
};