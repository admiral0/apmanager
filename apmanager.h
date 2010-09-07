#ifndef apmanager_H
#define apmanager_H

#include <QtGui/QMainWindow>
#include "apwizard.h"
#include <QHash>
#include <QString>
#include <QSettings>
namespace Ui{
  class main;
}
class apmanager : public QMainWindow
{
Q_OBJECT
public:
    apmanager();
    virtual ~apmanager();
    apmanager* getInstance();
  public slots:
    void aboutToQuit();
    void newProfile();
    void wizardFinished(int result);
  private:
    QSettings *settings;
    QHash<QString, QVariant > profiles;
    Ui::main *ui;
    ApWizard *wizard;
    static apmanager *self=0;
    QHash< QString, QVariant > getProfile(const QString& name);
   
};

#endif // apmanager_H
