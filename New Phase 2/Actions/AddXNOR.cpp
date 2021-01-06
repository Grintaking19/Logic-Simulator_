#include "AddXNOR.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

AddXNOR::AddXNOR(ApplicationManager* pApp) :Action(pApp)
{
}

AddXNOR::~AddXNOR(void)
{
}

void AddXNOR::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNOR::Execute()
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

	/*XNOR* pX;
	pX->Graphics_Info() = GInfo;
	pX= new XNOR(pX->GraphicsInfo_(), AND2_FANOUT);
	pManager->AddComponent(pX);*/

	XNOR* pX = new XNOR(GInfo, AND2_FANOUT);
	pManager->AddComponent(pX);
}

void AddXNOR::Undo()
{

}

void AddXNOR::Redo()
{

}

