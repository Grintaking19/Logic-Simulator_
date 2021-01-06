#pragma once
#include "Action.h"

class Move : public Select
{
private:
	int Cx, Cy;
public:
		Move(ApplicationManager* pApp);
		virtual ~Move(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();
};
