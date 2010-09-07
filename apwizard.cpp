/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "apwizard.h"
#include <QMessageBox>
#include "config.h"

ApWizard::ApWizard() : QWizard() ,ui(new Ui::Wizard){
  ui->setupUi(this);
  connect(this,SIGNAL(currentIdChanged(int)),this,SLOT(validatePage(int)));
}
ApWizard::~ApWizard() {

}
void ApWizard::validatePage(int page)
{
#ifdef DEBUG
 qDebug()<< "Validating page" << page;
#endif
 //Profile page
 switch(page){
   QStringList err;
   case 0:
     if(ui->profileName->text()==""){
	err<< tr("Profile name is empty");
     }
     //if(
   default:
#ifdef DEBUG
qDebug()<< "WTF?!" <<page << "there is no such index in wizard!";
#endif
 }
   
}

