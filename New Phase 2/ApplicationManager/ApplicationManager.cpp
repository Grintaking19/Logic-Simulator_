#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions/AddXNOR.h"
#include "Actions/AddNOT.h"
#include "Actions/AddBUFF.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddXORgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddSWITCH.h"
#include "Actions/AddANDgate3.h"
#include "Actions/Select.h"
#include "Actions/Move.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	Selected_Component = NULL;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new Select(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNOR(this);
			break;

		case ADD_INV:
			pAct = new AddNOT(this);
			break;

		/*case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;*/

		case ADD_Buff:
			pAct= new Move(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
			

		case ADD_CONNECTION:

			//TODO: Create AddConection Action here
			break;
	

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		//delete pAct;
		//pAct = NULL;  Move them to UpdateInterface 
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);

	Select* Select_ = dynamic_cast <Select*> (pAct);
	if (Select_)
	{

		Selected_Component = Select_->SelectedComponent;
		Selected_Component->Draw(OutputInterface, true);
	}
	else
		Selected_Component = NULL;
	//delete pAct;
	//pAct = NULL; 
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}


int ApplicationManager::GetComponentsCount() const
{
	return CompCount;
}

Component** ApplicationManager::ComponentsList()
{
	return CompList;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}