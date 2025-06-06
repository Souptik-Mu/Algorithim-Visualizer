//#include "Sorting.h"
//#include "Window.h"

#include "Sorting.h"
void Window::Swap(int ia, int ib)
{
	short temp;
	temp = arr[ia];
	arr[ia] = arr[ib];
	arr[ib] = temp;
}

void Window::ExecuteSort(int Type)
{
	switch (Type)
	{
	case 0:		BubbleExec();
		break;
	case 1:		SelectionExec();
		break;
	case 2:		InsertionExec();
		break;
	case 3:		MergeExec();
		break;
	case 4:		QuickExec();
		break;
	case 5:		ShellExec();
		break;
	case 6:		HeapExec();
		break;
	case 7:		RadixExec();
		break;
	default:
		break;
	}
}

void Window::BubbleExec()
{
	//const auto sf = [this]()
	//{
		for (int i = 0; i < n - 1; i++)
		{
			
			this->sts->SetValue((i * this->sts->GetRange() / (n - 2)));

			for (int j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					this->Swap(j, j + 1);
					this->DrwPanel->DrawArr(this->arr, this->n, false, i, i + 1, j);
					Update();
				}
			}
		}
			this->DrwPanel->DrawArr(this->arr, this->n, true);
	//}; 
	
}
void Window::SelectionExec()
{
}
void Window::InsertionExec()
{
}
void Window::MergeExec()
{
}
void Window::QuickExec()
{
}
void Window::ShellExec()
{
}
void Window::HeapExec()
{
}
void Window::RadixExec()
{
}
