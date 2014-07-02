/*
 * UOS-ROS packages - Robot Operating System code by the University of Osnabrück
 * Copyright (C) 2013 University of Osnabrück
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in 
 * the documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 * BUSINESS  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * fps_motion_tool.cpp
 *
 * Author: Henning Deeken {hdeeken@uos.de}
 *
 */
#include <fps_motion_tool.h>

namespace fps_motion_tool
{

FPSMotionTool::FPSMotionTool()
{
    shortcut_key_ = 'q';
    m_config_widget = NULL;
}

FPSMotionTool::~FPSMotionTool()
{
    if (m_config_widget != NULL)
    {
        delete m_config_widget;
    }
}

// onInitialize() is called by the superclass after scene_manager_ and
// context_ are set.  It should be called only once per instantiation.
void FPSMotionTool::onInitialize()
{
	m_pos_offset = 0.1;
	m_fly =false;
}

void FPSMotionTool::activate() 
{
    m_config_widget = new FPSMotionConfigWidget(this);
}

void FPSMotionTool::deactivate() 
{ 
}

// Handling key events to label marked faces or to get db structure
int FPSMotionTool::processKeyEvent(QKeyEvent *event, rviz::RenderPanel* panel)
{
	std::cout << "m offset " << m_pos_offset << std::endl; 
	if (event->key() == Qt::Key_W)
    {
		if(m_fly)
			((rviz::FPSMotionViewController*) panel->getViewController())->fly(0.0, 0.0, -m_pos_offset);
		else
			((rviz::FPSMotionViewController*) panel->getViewController())->move(0.0, 0.0, -m_pos_offset);
    }
    
    if (event->key() == Qt::Key_A)
    {
		if(m_fly)
		((rviz::FPSMotionViewController*) panel->getViewController())->fly(-m_pos_offset, 0.0, 0.0);
		else
		((rviz::FPSMotionViewController*) panel->getViewController())->move(-m_pos_offset, 0.0, 0.0);
    }
	
	if (event->key() == Qt::Key_S)
    {
		if(m_fly)
			((rviz::FPSMotionViewController*) panel->getViewController())->fly(0.0, 0.0, m_pos_offset);
		else
			((rviz::FPSMotionViewController*) panel->getViewController())->move(0.0, 0.0, m_pos_offset);
    }
    
    if (event->key() == Qt::Key_D)
    {
		if(m_fly)
			((rviz::FPSMotionViewController*) panel->getViewController())->fly(m_pos_offset, 0.0, 0.0);
		else
			((rviz::FPSMotionViewController*) panel->getViewController())->move(m_pos_offset, 0.0, 0.0);
    }

    // if 'f' is pressed switch walk/fly mode
    if (event->key() == Qt::Key_F)
    {
        m_fly = !m_fly;
    }

    // if 'r' is pressed reset the view
    if (event->key() == Qt::Key_R)
    {
		m_fly = false;
        ((rviz::FPSMotionViewController*) panel->getViewController())->reset();
    }

    // if 't' is pressed open the config widget
    if (event->key() == Qt::Key_T)
    {
		m_config_widget->exec();
    }
    
    return Render;
}

// Handling mouse event and mark the clicked faces
int FPSMotionTool::processMouseEvent(rviz::ViewportMouseEvent& event)
{
  if (event.panel->getViewController())
  {
    event.panel->getViewController()->handleMouseEvent(event);
    setCursor( event.panel->getViewController()->getCursor() );
  }
  return 0;
}

} // end namespace rviz_egomotion_tool

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(fps_motion_tool::FPSMotionTool, rviz::Tool )
