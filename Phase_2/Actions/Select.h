#pragma once
#include "Action.h"
#include "..\Components\AND2.h"


class Select : public Action
{
public:
		Select(ApplicationManager* pApp);
		virtual ~Select();

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();
		bool BelongToRectangularArea(GraphicsInfo GfxInfo, int x, int y);
		Component* GetSelctedComponent();

};
