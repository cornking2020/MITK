/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#include <QmitkDataNodeShowDetailsAction.h>

// mitk gui qt application
#include "QmitkNodeDetailsDialog.h"

namespace ShowDetailsAction
{
  void Run(berry::IWorkbenchPartSite::Pointer workbenchPartSite, QWidget* parent /* = nullptr*/)
  {
    auto selectedNodes = AbstractDataNodeAction::GetSelectedNodes(workbenchPartSite);

    QmitkNodeDetailsDialog infoDialog(selectedNodes, parent);
    infoDialog.exec();
  }
}

QmitkDataNodeShowDetailsAction::QmitkDataNodeShowDetailsAction(QWidget* parent, berry::IWorkbenchPartSite::Pointer workbenchpartSite)
  : QAction(parent)
  , QmitkAbstractDataNodeAction(workbenchpartSite)
{
  setText(tr("Show details"));
  m_Parent = parent;
  InitializeAction();
}

QmitkDataNodeShowDetailsAction::QmitkDataNodeShowDetailsAction(QWidget* parent, berry::IWorkbenchPartSite* workbenchpartSite)
  : QAction(parent)
  , QmitkAbstractDataNodeAction(berry::IWorkbenchPartSite::Pointer(workbenchpartSite))
{
  setText(tr("Show details"));
  m_Parent = parent;
  InitializeAction();
}

QmitkDataNodeShowDetailsAction::~QmitkDataNodeShowDetailsAction()
{
  // nothing here
}

void QmitkDataNodeShowDetailsAction::InitializeAction()
{
  connect(this, &QmitkDataNodeShowDetailsAction::triggered, this, &QmitkDataNodeShowDetailsAction::OnActionTriggered);
}

void QmitkDataNodeShowDetailsAction::OnActionTriggered(bool checked)
{
  if (m_WorkbenchPartSite.Expired())
  {
    return;
  }

  ShowDetailsAction::Run(m_WorkbenchPartSite.Lock(), m_Parent);
}
