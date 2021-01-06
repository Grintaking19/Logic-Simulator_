#include "Select.h"
#include "../ApplicationManager.h"

Select ::Select(ApplicationManager* pApp) : Action(pApp)
{
	SelectedComponent = NULL;
}

void Select::Execute()
{
	//Component* SelectedComponent;
	//SelectedComponent = GetSelctedComponent();
	//int n = 0;
	//GetSelectedComponent();
	Select::ReadActionParameters();
	//SelectedComponent->Draw(pManager->GetOutput(), true);

}

bool Select:: BelongToRectangularArea(GraphicsInfo GfxInfo, int x, int y)
{
	if ((x > GfxInfo.x1) && (x < GfxInfo.x2))
		if ((y > GfxInfo.y1) && (y < GfxInfo.y2))
			return true;
	return false;
}

/*void Select::GetSelectedComponent()
{
	Component** ComponentsList = pManager->ComponentsList();

	Input* pInput = pManager->GetInput();
	int x, y;
	pInput->GetPointClicked(x, y);
	for (int i = 0; i < pManager->GetComponentsCount(); i++)
	{
		GraphicsInfo RectangularArea = ComponentsList[i]->Graphics_Info();
		if (BelongToRectangularArea(RectangularArea, x, y))
			SelectedComponent = ComponentsList[i];
	}
}*/

Component* Select:: GetSelectedComponent()
{
	//ReadActionParameters();
	return SelectedComponent;
}

void Select:: Undo()
{

}
void Select:: Redo()
{

}

Select::~Select()
{

}

void Select::ReadActionParameters()
{
	Component** ComponentsList = pManager->ComponentsList();

	Input* pInput = pManager->GetInput();
	Output* pOutput = pManager->GetOutput();
	pOutput->PrintMsg("Click on the component you wish to select");
	int x, y;
	pInput->GetPointClicked(x, y);
	for (int i = 0; i < pManager->GetComponentsCount(); i++)
	{
		GraphicsInfo RectangularArea = ComponentsList[i]->Graphics_Info();
		if (BelongToRectangularArea(RectangularArea, x, y))
			SelectedComponent = ComponentsList[i];
	}
}