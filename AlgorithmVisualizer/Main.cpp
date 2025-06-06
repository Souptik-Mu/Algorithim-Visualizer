#include "Main.h"

wxIMPLEMENT_APP(Main);

Main::Main()
{
}

Main::~Main()
{
}

bool Main::OnInit()
{
	Tframe = new Window();
	Tframe->Show();
	return true;
}