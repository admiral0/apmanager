#include "apmanager.h"
#include "config.h"
#include "ui_main.h"
#include "apwizard.h"
apmanager::apmanager() : QMainWindow(),ui(new Ui::main)
{
  settings=new QSettings("apmanager","apmanager");
  profiles=settings->value("profiles").toHash();
  wizard=NULL;
  ui->setupUi(this);
  connect(ui->actionExit,SIGNAL(triggered(bool)),this,SLOT(aboutToQuit()));
  connect(ui->newProfile,SIGNAL(released()),this,SLOT(newProfile()));
}

apmanager::~apmanager(){
  delete ui;
}
void apmanager::aboutToQuit(){
  this->close();
}

void apmanager::newProfile(){
  if(wizard)
    delete wizard;
  wizard=new ApWizard();
  connect(wizard,SIGNAL(finished(int)),this,SLOT(wizardFinished(int)));
  wizard->show();
}
void apmanager::wizardFinished ( int result )
{
#ifdef DEBUG
  qDebug()<< wizard->ui->wifi_driver->currentText();
#endif
}

QHash< QString, QVariant > apmanager::getProfile ( const QString& name )
{
  return profiles.value(name).toHash();
  
}


