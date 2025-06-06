#include "Window.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
	EVT_BUTTON(103,Window::GenarateArr)
	EVT_COMBOBOX(101, Window::WriteInfo)
	EVT_BUTTON(104, Window::SortArr)
	EVT_SLIDER(105, Window::SliderControl)
wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY, "Algorithm visualizer", wxDefaultPosition, wxDefaultSize)
{
	Controls = this->CreateToolBar(wxTB_HORIZONTAL);
	As = new wxStaticText(Controls, wxID_ANY, "   Array Size :", wxPoint(15, 15), wxSize(70, 20));
	ArSize = new wxSpinCtrl(Controls, 102, "", wxDefaultPosition, wxSize(50, 20), wxSP_ARROW_KEYS | wxALIGN_CENTRE_HORIZONTAL, 10, 500, 20);
	GenArr = new wxButton(Controls, 103, "Genarate", wxDefaultPosition, wxSize(60, 20));
	Algo = new wxComboBox(Controls, 101, "", wxDefaultPosition, wxSize(100, 30), *Choices , wxCB_READONLY);
	Run = new wxButton(Controls, 104, "Run", wxDefaultPosition, wxSize(60, 20));
	Delay = new wxSlider(Controls, 105 , 10, 0, 2000, wxDefaultPosition, wxSize(150, 20)); // wxSL_LABELS 

	Algo->Select(0);
	Run->Disable();
	Controls->AddControl(As);
	Controls->AddControl(ArSize);
	Controls->AddControl(GenArr);
	Controls->AddControl(Algo);
	Controls->AddControl(Run);
	Controls->AddControl(Delay);
	Controls->Realize();

	InfoPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 200));
	DrwPanel = new Display(this, wxID_ANY, wxDefaultPosition, wxSize(600, 400));
	DrwPanel->SetBackgroundColour(wxColor(252, 227, 195));

	BotmSizer = new wxBoxSizer(wxHORIZONTAL);
	BotmSizer->Add(InfoPanel, 0, wxEXPAND | wxTOP, 1);
	BotmSizer->Add(DrwPanel, 2, wxEXPAND | wxALL , 2);
	this->SetSizerAndFit(BotmSizer);

	infoSz = new wxBoxSizer(wxVERTICAL);
	SrtTyp = new wxStaticText(InfoPanel, wxID_ANY, "Algorithm :"+Sort[Algo->GetSelection()]);
	delay = new wxStaticText(InfoPanel, 150, " Delay : " + wxString::Format(wxT("%d"), (int)Delay->GetValue()) + "ms");
	Pas = new wxStaticText(InfoPanel, wxID_ANY , "");
	tim = new wxStaticText(InfoPanel, wxID_ANY, "Time elapsed : ");
	comentsrt = new wxStaticText(InfoPanel, wxID_ANY, "Sorting...");
	sts = new wxGauge(InfoPanel, wxID_ANY, 100);

	infoSz->Add(SrtTyp, 0, wxALL, 2);
	infoSz->Add(delay,0, wxALL, 2);
	infoSz->Add(Pas, 0, wxALL, 2);
	infoSz->Add(tim, 0, wxALL, 2);
	infoSz->Add(comentsrt, 0, wxALL, 2);
	infoSz->Add(sts, 0, wxALL, 2);

	InfoPanel->SetSizerAndFit(infoSz);
	

	Pas->Show(false);
	tim->Show(false);
	comentsrt->Show(false);
	sts->Show(false);
	
}

Window::~Window()
{
	delete Choices;
	delete DrwPanel;
}

void Window::SliderControl(wxCommandEvent& evt)
{
	delay->SetLabelText(" Delay : " + wxString::Format(wxT("%d"), (int)Delay->GetValue()) + "ms");
	evt.Skip();
}

void Window::GenarateArr(wxCommandEvent& evt)
{	
	this->n = ArSize->GetValue();
	free(this->arr);
	this->arr = new short[n];
	this->Progress = 0;
	Pas->Show(false);
	tim->Show(false);
	comentsrt->Show(false);
	sts->Show(false);
	srand(time(0));
	for (short i = 0; i < n; i++)
		arr[i] = (rand() % 350)+1;
	this->DrwPanel->DrawArr(arr, n);
	
	delay->Show(true);
	Run->Enable();
	evt.Skip();
}

void Window::WriteInfo(wxCommandEvent& event)
{
	SrtTyp->SetLabelText("Algorithm :" + Sort[Algo->GetSelection()]);
}

void Window::SortArr(wxCommandEvent& evt) //Run
{
	Run->Disable();
	GenArr->Disable();
	Algo->Disable();
	ArSize->Disable();
	
	Pas->Show(true);
	tim->Show(true);
	comentsrt->Show(true);
	sts->Show(true);
	sts->SetValue(this->Progress);
	//this->Progress = 0;
	

	//here select and call sorting
		
	ArSize->Enable();
	Algo->Enable();
	GenArr->Enable();
	Run->Enable();

	//evt.Skip();
}




