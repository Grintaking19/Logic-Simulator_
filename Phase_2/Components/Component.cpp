#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

GraphicsInfo Component::Graphics_Info()
{
	return m_GfxInfo;
}

void Component::SetGraphicsInfo(GraphicsInfo G)
{
	m_GfxInfo = G;
}

Component::Component()
{}

Component::~Component()
{}

