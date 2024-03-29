#include "OR3.h"
OR3::OR3(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW && GetInputPinStatus(3) == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (GetInputPinStatus(1) == HIGH || GetInputPinStatus(2) == HIGH || GetInputPinStatus(3) == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void OR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR3(m_GfxInfo);
}

//returns status of outputpin
int OR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}