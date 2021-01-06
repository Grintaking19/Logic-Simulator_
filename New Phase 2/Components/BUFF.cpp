#include "BUFF.h"
BUFF::BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	if (m_InputPins[0].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}

}
// Function Draw
// Draws 1-input NOT gate
void BUFF:: Draw(Output* pOut, bool Selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFF(m_GfxInfo, Selected);
}

//returns status of outputpin
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}