#include "FileWithUsers.h"


void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load("Users.xml");

    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem( "ID", user.getId() );
    xml.AddElem( "LOGIN", user.getLogin() );
    xml.AddElem( "PASSWORD", user.getPassword() );
    xml.AddElem( "NAME", user.getName() );
    xml.AddElem( "SURNAME", user.getSurname() );
    xml.Save("Users.xml");
}


vector <User> FileWithUsers::loadUsersFromFile() {
    vector <User> users;
    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem("USERS");
    xml.IntoElem();
    while (xml.FindElem("USER")) {
        User user;
        xml.IntoElem();
        xml.FindElem("ID");
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("LOGIN");
        user.setLogin(xml.GetData());
        xml.FindElem("PASSWORD");
        user.setPassword(xml.GetData());
        xml.FindElem("NAME");
        user.setName(xml.GetData());
        xml.FindElem("SURNAME");
        user.setSurname(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::changePasswordInFile (User loggedUser) {
    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem("USERS");
    xml.IntoElem();
    while ( xml.FindElem("USER") ) {
        xml.FindChildElem("ID");
        if ( atoi( MCD_2PCSZ(xml.GetChildData())) == loggedUser.getId()) {
            xml.FindChildElem("PASSWORD");
            xml.SetChildData(loggedUser.getPassword());
            break;
        }
    }
    xml.Save("Users.xml");
}
