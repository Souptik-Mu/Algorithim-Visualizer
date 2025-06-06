#pragma once

//#include<cstdlib>

#include"wx/wx.h"
#include"wx/slider.h"
#include"wx/toolbar.h"
#include"wx/spinctrl.h"

#include "Display.h"
#include "SortingThread.h"

#include<chrono>
#include<thread>


class Window : public wxFrame , public SortingCallback
{
public:		//Events declereation
	Window();
	~Window();


	void SliderControl(wxCommandEvent&);
	void GenarateArr(wxCommandEvent&);
	void WriteInfo(wxCommandEvent& event);
	void SortArr(wxCommandEvent&);
	//void OnIdle(wxIdleEvent&);

public:		//Sorting related declearation {Definations are in "Sorting.cpp"}
	const wxString Sort[8] = { "Bubble Sort" ,"Selection Sort" ,"Insertion Sort" ,
								"Merge Sort","Quick Sort" ,"Shell Sort" ,
									"Heap Sort" ,"Radix Sort" };
	wxArrayString* Choices = new wxArrayString(8, Sort);
	
	short* arr, n;
	int Progress;
	

	//void Swap(int, int);
	//void ExecuteSort(int);

	//void BubbleExec();
	//void SelectionExec();
	//void InsertionExec();
	//void MergeExec();
	//void QuickExec();
	//void ShellExec();
	//void HeapExec();
	//void RadixExec();

public:		//window components

	Display* DrwPanel;
	
	wxToolBar* Controls;
	wxPanel* InfoPanel;
	wxBoxSizer* BotmSizer;
	wxStaticText* As;
	wxSpinCtrl* ArSize;
	wxButton* GenArr;
	wxComboBox* Algo;
	wxButton* Run;
	wxSlider* Delay;

	wxBoxSizer* infoSz;
	wxStaticText* SrtTyp;
	wxStaticText* delay;
	wxStaticText* Pas;
	wxStaticText* tim;
	wxStaticText* comentsrt;
	wxGauge* sts;
	
	wxDECLARE_EVENT_TABLE();
};

