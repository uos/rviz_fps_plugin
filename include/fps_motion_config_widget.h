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
 * fps_motion_config_widget.h
 *
 * Author: Henning Deeken <hdeeken@uos.de>
 */

#ifndef FPS_MOTION_CONFIG_WIDGET_H
#define FPS_MOTION_CONFIG_WIDGET_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <iostream>
#include <string>

#include <fps_motion_tool.h>

/**
 * 
 *@class FPSMotionConfigWidget
 * 
 *@brief widget to setup the behavior of the FPSMotionTool
 *
 */

namespace fps_motion_tool
{
class FPSMotionTool;
class FPSMotionConfigWidget: public QDialog
{

Q_OBJECT
public:
    FPSMotionConfigWidget(FPSMotionTool* m_parent_tool = 0);
    virtual ~FPSMotionConfigWidget();
    virtual void exec();

private Q_SLOTS:
    void saveButtonClicked();


private:
    void setComboBoxes();

    FPSMotionTool* m_parent_tool;
    QLineEdit* m_offset_edit;
};
}
#endif
