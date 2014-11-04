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
 * DAMAGES  (INCLUDING,  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 * BUSINESS  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * fps_motion_tool.cpp
 *
 *  Author: Henning Deeken <hdeeken@uos.de>
 *
 */

#ifndef RVIZ_FPS_MOTION_TOOL_H
#define RVIZ_FPS_MOTION_TOOL_H

#include <vector>
#include <map>
#include <QMessageBox>
#include <QApplication> 
#include <QIcon>

#include <ros/console.h>
#include <rviz/viewport_mouse_event.h>
#include <rviz/visualization_manager.h>
#include <rviz/mesh_loader.h>
#include <rviz/geometry.h>
#include <rviz/properties/vector_property.h>
#include <rviz/tool.h>
#include <rviz/tool_manager.h>
#include <rviz/display_group.h>

#include "rviz/display_context.h"
#include "rviz/render_panel.h"
#include "rviz/viewport_mouse_event.h"
#include "rviz/selection/selection_manager.h"
#include "rviz/view_controller.h"
#include "rviz/view_manager.h"
#include "rviz/load_resource.h"

#include "rviz/default_plugin/tools/move_tool.h"

#include <fps_motion_view_controller.h>
#include <fps_motion_config_widget.h>

/**
 * 
 *@class FPSMotionTool
 * 
 *@brief Implements a rviz tool that allows to navigate in a egoshooter mode.
 */

namespace Ogre
{
class SceneNode;
class Vector3;
}

namespace rviz
{
     
class FPSMotionConfigWidget;
class FPSMotionTool: public rviz::Tool
{
Q_OBJECT
public:
    FPSMotionTool();
    ~FPSMotionTool();
    virtual void onInitialize();
    virtual void activate();
    virtual void deactivate();

    virtual int processKeyEvent(QKeyEvent* event, rviz::RenderPanel* panel);
    virtual int processMouseEvent(rviz::ViewportMouseEvent& event);

	double getOffset() { return m_pos_offset;}
	void setOffset(double offset) {m_pos_offset = offset;}

private:
	ros::NodeHandle n_;
	rviz::FPSMotionConfigWidget* m_config_widget;
	Ogre::SceneNode* m_sceneNode;
	bool m_fly;
	bool m_fly_by_default;
    double m_pos_offset;    
};
} // end namespace rviz
#endif
