#include "AddNOT.h"
#include "..\ApplicationManager.h"

AddNOT::AddNOT(ApplicationManager* pApp) :Action(pApp)
{
}

AddNOT::~AddNOT(void)
{
}

void AddNOT::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("NOT Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOT::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NOT* pN = new NOT(GInfo, AND2_FANOUT);
	pManager->AddComponent(pN);
}

void AddNOT::Undo()
{

}

void AddNOT::Redo()
{

}

