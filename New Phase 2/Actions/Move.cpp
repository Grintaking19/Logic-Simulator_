#include "Select.h"
#include "Move.h"
#include "..\ApplicationManager.h"

Move :: Move(ApplicationManager* pApp) : Select(pApp)
{
}

Move::~Move(void)
{
}

void Move::ReadActionParameters()
{
	/*
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Select* Select_ = dynamic_cast <Select*> (pManager->pAct);
	//Print Action Message
	if (pManager->Selected_Component == NULL)
		pOut->PrintMsg("You must select a component first");
	else
	{
		SelectedComponent = pManager->Selected_Component; //Reference
		pOut->PrintMsg("Click where you want to move the gate");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
	*/
}

void Move::Execute()
{
	//Select SelectFirst(pManager);
	//ReadActionParameters();

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Select* Select_ = dynamic_cast <Select*> (pManager->pAct);
	//Print Action Message
	if (pManager->Selected_Component == NULL)
		pOut->PrintMsg("You must select a component first");
	else
	{
		Component* & SelectedComponent_ = pManager->Selected_Component; //Reference
		pOut->PrintMsg("Click where you want to move the gate");

		//Wait for User Input
		pIn->GetPointClicked(Cx, Cy);

		//Calculate the rectangle Corners
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to change position of the component

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;

		SelectedComponent_->SetGraphicsInfo(GInfo);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
	

	/*if (SelectedComponent != NULL)
	{

		//Calculate the rectangle Corners
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to change position of the component

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;

		SelectedComponent->SetGraphicsInfo(GInfo);
	}
	*/
}

void Move::Undo()
{}

void Move::Redo()
{}

