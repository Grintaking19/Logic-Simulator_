#include "AddConnection.h"
#include "Select.h"
#include "..\Components\Connection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Select(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Click to Select The Source Pin: ");
	Component* SourceComponent=GetSelectedComponent();
	Gate* SourceGate= dynamic_cast <Gate*> (SourceComponent);
	pOut->PrintMsg("Click to Select The Destination Pin: ");
	Component* DstComponent = GetSelectedComponent();
	Gate* DstGate = dynamic_cast <Gate*> (DstComponent);
	//SourcePin = SourceGate->GetOutputPin();
	
	//DestPin = SourceGate->GetInputPin();




	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	/*GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;*/
	//Connection* pA = new Connection(GInfo, AND2_FANOUT);
	//pManager->AddComponent(pA);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

