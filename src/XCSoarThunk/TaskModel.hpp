/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2016 Peter F Bradshaw
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \addtogroup XCSoarThunk
 * @{
 */
#ifndef __TASKMODEL_HPP
#define __TASKMODEL_HPP

#include <QAbstractTableModel>
#include "Engine/Task/Points/Type.hpp"
#include "Engine/Task/Factory/TaskFactoryType.hpp"

class Waypoint;

class QPainterPath;
class QString;

class TaskModel : public QAbstractTableModel
  {

  Q_OBJECT;

public:

  /**
   * Specify the task type.
   * @param task One of TaskFactoryType.
   */
  void TaskType(TaskFactoryType type);

  /**
   * Give the task type.
   * @return One of TaskFactoryType (defaults to FAI_GENERAL if not set).
   */
  TaskFactoryType TaskType() const;

  /**
   * Give the task type as a string.
   * @return The name of the current task type.
   */
  QString TaskTypeAsString() const;

  /**
   * Give the number of columns in the task waypoint list.
   * @return Always 3.
   */
  int ColumnCount() const;

  /**
   * Give the number of nodes in the task.
   * @return The total number of waypoints in the task.
   */
  int RowCount() const;
 
 /**
  * Add a node to the end of the list.
  * @param node The new waypoint.
  */
 void AddRow( const Waypoint &node);

 /**
  * Specify the node type.
  * @param index The node index, \f$0 \le index < this->RowCount()\f$
  * @param type  The turnpoint type.
  */
 void NodeType(int index, TaskPointType type);

 /**
  * Draw the specified turnpoint.
  * @param index The node index, \f$0 \le index < this->RowCount()\f$
  * @return The drawing in the form of a QPainterPath.
  */
 QPainterPath DrawNode(int index);

protected:

private:

  };
#endif  // __TASKMODEL_HPP
/**
 * @}
 */
