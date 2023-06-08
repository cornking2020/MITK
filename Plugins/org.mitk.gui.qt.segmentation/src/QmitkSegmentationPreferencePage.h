/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef QmitkSegmentationPreferencePage_h
#define QmitkSegmentationPreferencePage_h

#include "org_mitk_gui_qt_segmentation_Export.h"

#include <berryIQtPreferencePage.h>
#include <QmitkSetupVirtualEnvUtil.h>
#include <QStandardPaths>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class QWidget;

namespace Ui
{
  class QmitkSegmentationPreferencePageControls;
}


class QmitkSAMInstaller : public QmitkSetupVirtualEnvUtil
{
public:
  const QString VENV_NAME = ".sam";
  const QString SAM_VERSION = "1.0"; // currently, unused
  const std::vector<QString> PACKAGES = {QString("numpy"),
                                         QString("opencv-python"),
                                         QString("git+https://github.com/facebookresearch/segment-anything.git"),
                                         QString("SimpleITK")};
  const QString STORAGE_DIR;
  inline QmitkSAMInstaller(
    const QString baseDir = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + QDir::separator() +
                            qApp->organizationName() + QDir::separator())
    : QmitkSetupVirtualEnvUtil(baseDir), STORAGE_DIR(baseDir){};
  bool SetupVirtualEnv(const QString &) override;
  QString GetVirtualEnvPath() override;
};


class MITK_QT_SEGMENTATION QmitkSegmentationPreferencePage : public QObject, public berry::IQtPreferencePage
{
  Q_OBJECT
  Q_INTERFACES(berry::IPreferencePage)

public:

  QmitkSegmentationPreferencePage();
  ~QmitkSegmentationPreferencePage() override;

  void Init(berry::IWorkbench::Pointer workbench) override;

  void CreateQtControl(QWidget* widget) override;

  QWidget* GetQtControl() const override;

  bool PerformOk() override;

  void PerformCancel() override;

  void Update() override;

protected Q_SLOTS:

  void OnLabelSetPresetButtonClicked();
  void OnSuggestionsButtonClicked();
  void OnInstallBtnClicked();
  void OnClearInstall();
  QString OnSystemPythonChanged(const QString&);

protected:
  /**
   * @brief Searches and parses paths of python virtual enviroments
   * from predefined lookout locations
   */
  void AutoParsePythonPaths();
  
  /**
   * @brief Get the virtual env path from UI combobox removing any
   * extra special characters.
   *
   * @return QString
   */
  QString GetPythonPathFromUI(const QString&) const;

  /**
   * @brief Get the Exact Python Path for any OS
   * from the virtual environment path.
   * @return QString
   */
  QString GetExactPythonPath(const QString&) const;
  void WriteStatusMessage(const QString&);
  void WriteErrorMessage(const QString&);
  
  QNetworkAccessManager m_Manager;
  Ui::QmitkSegmentationPreferencePageControls* m_Ui;
  QmitkSAMInstaller m_Installer;
  QWidget* m_Control;
  QString m_PythonPath;
  bool m_IsInstalled = false;
  bool m_Initializing;
};

#endif
