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
 * fps_motion_widget.cpp
 *
 * Author: Henning Deeken <hdeeken@uos.de>
 *
 */

#include <fps_motion_config_widget.h>
namespace fps_motion_tool
{

FPSMotionConfigWidget::FPSMotionConfigWidget(FPSMotionTool* parent_tool)
{
    // Set given db_manager
    m_parent_tool = parent_tool;

    // Construct and layout labels and button
    QLabel* widget_label = new QLabel("Configure FPS Motion");
    
    QLabel* offset_label = new QLabel("Offset: ");
    QLineEdit* m_offset_edit = new QLineEdit();
    m_offset_edit->setText(QString::number(m_parent_tool->getOffset()));
    
    QPushButton* save_button = new QPushButton("Save");
    
    QGridLayout* controls_layout = new QGridLayout();
    controls_layout->addWidget(widget_label, 0, 0);
    controls_layout->addWidget(offset_label, 2, 0);
    controls_layout->addWidget(m_offset_edit, 2, 1);
    controls_layout->addWidget(save_button, 3, 0);

    // Set the top-level layout for this widget.
    setLayout(controls_layout);
    // Make signal/slot connections.
    connect(save_button, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
}

FPSMotionConfigWidget::~FPSMotionConfigWidget()
{
}

void FPSMotionConfigWidget::exec()
{
	QDialog::exec();
}

void FPSMotionConfigWidget::saveButtonClicked()
{
	bool* ok;
	std::cout << "new " << m_offset_edit->text().toDouble(ok) << std::endl;
	m_parent_tool->setOffset(4.0);
	this->hide();
}
}
