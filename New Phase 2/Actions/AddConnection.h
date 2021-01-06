#pragma once
#include "action.h"
#include "..\Components\Connection.h"
#include "Select.h"
#include "..\Components\OutputPin.h"
#include "..\Components\InputPin.h"

class AddConnection : public Select
{
private:
	OutputPin* SourcePin;
	InputPin* DestPin;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
