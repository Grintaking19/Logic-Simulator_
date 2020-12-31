#include "MultipleSelect.h"
#include "../ApplicationManager.h"

MultipleSelect :: MultipleSelect(ApplicationManager* pApp) :Select(pApp)
{
	CountSelected = 0;
}

MultipleSelect::~MultipleSelect()
{

}

void MultipleSelect::Execute()
{
	int ArrayCounter = 0;
	while (pManager->GetUserAction() == MULTIPLESELECT)
	{
		Component* SelectedComponent = GetSelctedComponent();
		SelectedComponent->Draw(pManager->GetOutput(), true);
		SelectedComponents[ArrayCounter] = SelectedComponent;
		CountSelected++;
		ArrayCounter++;
	}
}

Component** MultipleSelect:: GetSelectedComponents()
{
	return SelectedComponents;
}