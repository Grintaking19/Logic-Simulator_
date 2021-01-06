#pragma once
#include "Select.h"
#include "..\ApplicationManager.h"

class MultipleSelect : public Select
{
private:
	int CountSelected;
	Component* SelectedComponents[ApplicationManager::MaxCompCount];
public:
	MultipleSelect(ApplicationManager* pApp);
	virtual ~MultipleSelect(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	Component** GetSelectedComponents();
};
