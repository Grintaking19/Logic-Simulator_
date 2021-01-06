#include "Input.h"
#include "Output.h"
#include <cstring>

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	//This the ASCII value of the three buttoms and we do so bec. WaitKeyPress accepts the ASCII value
	const char Enter = '\r';
	const char  Escape = '\e';
	const char Backspace = '\b';

	string str = " ";
	char ch;
	pWind->FlushKeyQueue();
	do
	{
		pWind->WaitKeyPress(ch);
		switch (ch)
		{
		case Backspace:
			if (!str.empty()) //we check that the string is not empty because if it is empty and we made Backspace this will cause erorrs 
			{
				str.pop_back(); // pop_back is member function of class string deletes the last character in the str 
				pOut->PrintMsg(str); //we update the string displayed after we pressed backspace (after the last character was deleted)
			}
			break;
		case Escape:
			if (!str.empty()) // mmake sure that there is string to be deleted because if there is not, it will be pointless to delete it.
			{
				str.clear();
			}
			break;
		case Enter: //if we pressed enter just get out of the loop and end the string
			break;
		default:   // if ch is not enter or backspace or escape , just add the character to the string and then display it.
			str.push_back(ch); //push_back add the character to the end of the string
			pOut->PrintMsg(str);
			break;
		}
	} while (ch != Escape && ch != Enter);
	return str;

}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
				//Ali//
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOT: return ADD_INV;
			case ITM_BUFF: return ADD_Buff;
			case ITM_NAND:return ADD_NAND_GATE_2;
			case ITM_NOR2:return ADD_NOR_GATE_2;
			case ITM_NOR3:return ADD_NOR_GATE_3;
			case ITM_XOR2:return ADD_XOR_GATE_2;
			case ITM_XOR3:return ADD_XOR_GATE_3;
			case ITM_XNOR:return ADD_XNOR_GATE_2;
			case ITM_SWITCH:return ADD_Switch;
			case ITM_LED:return ADD_LED;
			case ITM_CONNECTION:return ADD_CONNECTION;

			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
