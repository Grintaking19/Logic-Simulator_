#include "Select.h"
#include "../ApplicationManager.h"

Select ::Select(ApplicationManager* pApp) : Action(pApp)
{

}

void Select::Execute()
{
	Component* SelectedComponent = GetSelctedComponent();
	SelectedComponent->Draw(pManager->GetOutput(), true);

}

bool BelongToRectangularArea(GraphicsInfo GfxInfo, int x, int y)
{
	if ((x > GfxInfo.x1) && (x < GfxInfo.x2))
		if ((y > GfxInfo.y1) && (y < GfxInfo.y2))
			return true;
	return false;
}

Component* Select:: GetSelctedComponent()
{
	Component** ComponentsList = pManager->ComponentsList();
	Component* SelectedComponent;
	Input* pInput = pManager->GetInput();
	int x, y;
	pInput->GetPointClicked(x, y);
	for (int i = 0; i < pManager->CompCount; i++)
	{
		GraphicsInfo RectangularArea = ComponentsList[i]->Graphics_Info();
		if (BelongToRectangularArea(RectangularArea, x, y))
			SelectedComponent = ComponentsList[i];
	}
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