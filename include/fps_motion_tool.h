/*
 * UOS-ROS packages - Robot Operating System code by the University of Osnabrück
 * Copyright (C) 2014 University of Osnabrück
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
 * fps_motion_tool.h
 *
 *  Author: Henning Deeken <hdeeken@uos.de>
 *
 */

#ifndef RVIZ_FPS_MOTION_TOOL_H
#define RVIZ_FPS_MOTION_TOOL_H

#include <map>
#include <vector>

#include <QIcon>
#include <QMessageBox>
#include <QApplication>

#include <ros/console.h>
#include <rviz/viewport_mouse_event.h>
#include <rviz/visualization_manager.h>
#include <rviz/geometry.h>
#include <rviz/properties/vector_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/enum_property.h>
#include <rviz/properties/bool_property.h>
#include <rviz/tool.h>
#include <rviz/tool_manager.h>
#include <rviz/display_group.h>
#include <rviz/display_context.h>
#include <rviz/render_panel.h>
#include <rviz/viewport_mouse_event.h>
#include <rviz/selection/selection_manager.h>
#include <rviz/view_controller.h>
#include <rviz/view_manager.h>
#include <rviz/load_resource.h>

#include <rviz/default_plugin/tools/move_tool.h>

#include <fps_motion_view_controller.h>

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

private Q_SLOTS:

  void setOffset(){ m_pos_offset = (double) step_length_property_->getFloat(); }
  void setFlyMode(){ m_fly_mode = fly_property_->getBool(); }
  void setLeftHandMode(){ m_left_hand_mode = left_hand_property_->getBool(); }
  void setFallbackTool(){ m_fallback_tool = m_tools.at(fallback_tool_property_->getOptionInt()); }
  void setFallbackViewController(){ m_fallback_view_controller = m_view_controller_classes.at(fallback_view_controller_property_->getOptionInt()); }

private:
  Ogre::SceneNode* m_sceneNode;


  bool m_fly_mode;
  bool m_left_hand_mode;
  bool m_removed_select;

  double m_pos_offset;
  QStringList m_tool_classes;
  std::vector<Tool*> m_tools;
  Tool* m_fallback_tool;

  QStringList m_view_controller_classes;
  QString m_fallback_view_controller;
  std::vector<ViewController*> m_view_controller;

  FloatProperty* step_length_property_ = new FloatProperty( "Step Length", 0.1,
                                                            "The length by with the position is updated on each step.",
                                                            getPropertyContainer(), SLOT( setOffset() ), this );

  BoolProperty* fly_property_ = new BoolProperty( "Fly Mode", false,
                                                            "In fly mode it is possible to move along the z axis as well.",
                                                            getPropertyContainer(), SLOT( setFlyMode() ), this );

  BoolProperty* left_hand_property_ = new BoolProperty( "Left Hand Mode", false,
                                                            "In left hand mode one uses the arrows to move around, instead of wasd.",
                                                            getPropertyContainer(), SLOT( setLeftHandMode() ), this );

  EnumProperty* fallback_tool_property_ = new EnumProperty( "Fallback Tool", QString("rviz/Interact"),
                                                            "Determines to which tool the control switches, if the tool is deactivated.",
                                                            getPropertyContainer(), SLOT( setFallbackTool() ), this );

  void setFallbackToolProperty();

  EnumProperty* fallback_view_controller_property_ = new EnumProperty( "Fallback ViewController", QString("rviz/Orbit"),
                                                            "Determines to which view controller the control switches, if the tool is deactivated.",
                                                            getPropertyContainer(), SLOT( setFallbackViewController() ), this );

  void setFallbackViewControllerProperty();
};
} // end namespace rviz
#endif
