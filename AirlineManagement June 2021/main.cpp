#include <vector>
#include <string.h>

#include "essential.h"
#include "Airplane.h"
#include "Attendant.h"
#include "Flight.h"
#include "Human.h"
#include "Passenger.h"
#include "Pilot.h"
#include "Ticket.h"
#include "Time.h"

using namespace std;

string fn, ln, idnum, pidnum;
string flightno, Airplaneno;
string origin, destination;

int hour, minute;
int yearB, monthB, dayB;
int yearH, monthH, dayH;
int yearR, monthR, dayR;
int rank_, seats;
int lastLine;
int addChoice = 0;
int ichoice;
int index, index2;
int flag = 0;

unsigned int SIZE_, choice_;

vector <int>        INDEX;
vector <AirPlane>   vAirplane;
vector <Attendant>  vAttendant;
vector <Flight>     vFlight;
vector <Passenger>  vPassenger;
vector <Pilot>      vPilot;
vector <Ticket>     vTicket;
vector <Date>       vDate;
vector <Time>       vTime;

string g(int x, int y){
    string t;
    gotoxy(x, y);
    cin>>t;
    return t;
}

int gint(int x, int y){
    int t;
    gotoxy(x, y);
    cin>>t;
    return t;
}

void mainPage();
void ask();
void backToMainMenu();

void add();
void addPassenger();
void addPilot();
void addAttendant();
void addTicket();
void addAirplane();
void addFlight();

void list();
void listPassenger();
void listPilot();
void listAttendant();
void listAirplane();
void listFlight();

void emptyPassenger();
void emptyPilot();
void emptyAttendant();
void emptyAirplane();
void emptyFlight();

int choosePassenger();
int choosePilot();
int chooseAttendant();

void report();
void reportDate();
void reportAiplaneSerialNo();
void reportPersonnelCode();
void reportIDNum();
void searchPassenger(string);
void searchPilot(string);
void searchAttendant(string);

main(){
    cls();
    mainPage();
}

void mainPage(){
    cls();
    gotoxy(1, 8);
    cout<<"                                                 ";
    rectnew(0, 0, 22, 9);
    //p(7,1, "Main Menu");
    p(2,1, "Main Menu");
    gotoxy(1,3);
    cout<<" 1 "<<c186<<" Add";
    gotoxy(1,4);
    cout<<" 2 "<<c186<<" List";
    gotoxy(1,5);
    cout<<" 3 "<<c186<<" Report";
    /*
    gotoxy(1,4);
    cout<<" 4 "<<c186<<" Edit";
    gotoxy(1,5);
    cout<<" 5 "<<c186<<" Sort";
    gotoxy(1,6);
    cout<<" 6 "<<c186<<" Delete";
    */
    gotoxy(1,6);
    cout<<" 9 "<<c186<<" Exit";
    gotoxy(1,8);
    cout<<" Press Selection: ";
    int fpps;
    cin>>fpps;
    switch(fpps){
        case 1:
            add();
            break;
        case 2:
            list();
            break;
        case 3:
            report();
            break;
        case 9: exit(0);
            break;
        default:
            gotoxy(1, 11);
            cout<<"You have to choose a number which is in the menu!";
            delay(DELAYTIME);
            mainPage();
            break;
    }
}

void ask(){
    y++;
    rect(3, y, 35, y+2);
    y++;
    p(5, y, "Back to Main Menu? (Y/N) ");
    gotoxy(30, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        mainPage();
        break;
    default:
        exit(0);
    }
}

void backToMainMenu(){
    y++;
    p(5, y++, "Going Back To Main Menu.");
    p(5, y++, "Please wait ...");
    delay(DELAYTIME);
    mainPage();
}

void add(){
    cls();
    p(2, 1, "Add");
    p(2, 3, "1   Passenger");
    p(2, 4, "2   Pilot");
    p(2, 5, "3   Attendant");
    p(2, 6, "4   Ticket");
    p(2, 7, "5   Airplane");
    p(2, 8, "6   Flight");
    p(2, 9, "9   Main Menu");

    p(2, 11, "Press Selection: ");
    rectnew(0, 0, 22, 12);

    gotoxy(20, 11);
    cin>>addChoice;

    switch(addChoice){
    case 1:
        addPassenger();
        backToMainMenu();
        break;
    case 2:
        addPilot();
        backToMainMenu();
        break;
    case 3:
        addAttendant();
        backToMainMenu();
        break;
    case 4:
        addTicket();
        ask();
        backToMainMenu();
        break;
    case 5:
        addAirplane();
        backToMainMenu();
        break;
    case 6:
        addFlight();
        backToMainMenu();
        break;
    case 9:
    default:
        mainPage();
    }
}

void addPassenger(){
    cls();
    flag = 1;
    do{
        y = firstLine;
        p(5, 2, "Adding a new passenger");
        p(2, y++, "First Name:                ");
        p(2, y++, "Last Name:                 ");
        p(2, y++, "ID Number:                 ");
        y++;
        p(2, y++, "Are you sure? (Y/N)        ");

        rect(1, 3, 30, 7);
        y = firstLine;

        fn = g(14, y++);
        ln = g(13, y++);
        idnum = g(13, y++);
        gotoxy(22, 8);
        cin>>choice;
        if(choice == 'Y' || choice == 'y'){
            flag = 0;
        }
    }while(flag);
    Passenger newPassenger(fn, ln, idnum);
    vPassenger.push_back( newPassenger );
    p(5, y+=2, "Passenger added successfully!");
}

void addPilot(){
    flag = 1;
    do{
        cls();
        //y = firstLine;
        p(5, 2, "Adding a new Pilot");
        p(2, y++, "First Name:");
        p(2, y++, "Last Name:");
        p(2, y++, "ID Number:");
        p(2, y++, "Personnel code:");
        p(2, y++, "Rank:");

        rect(1, 3, 30, 9);

        y++;
        p(5, y++, "Birth Date information ");

        y++;
        p(2, y++, "Year (1900 - present):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");

        rect(1, 11, 30, 15);

        y++;
        p(2, y++, "Are you sure? (Y/N)        ");
        y++;
        p(5, y++, "Hire Date information");
        y++;
        lastLine = y;
        p(2, y++, "Year (1900 - present):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");

        rect(1, 19, 30, 23);
        y++;

        y = firstLine;

        fn = g(14, y++);
        ln = g(13, y++);
        idnum = g(13, y++);
        pidnum = g(18, y++);
        rank_ = gint(8, y++);

        y+=3;
        yearB = gint(25, y++);
        monthB = gint(17, y++);
        dayB = gint(15, y++);

        y++;
        gotoxy(22, y++);
        cin>>choice;

        if(choice == 'Y' || choice == 'y'){
            flag = 0;
        }

    }while(flag);
    Date newDateB(yearB, monthB, dayB),
        newDateH, today;
    do{
        y = lastLine;

        yearH = gint(25, y++);
        monthH = gint(17, y++);
        dayH = gint(15, y++);
        newDateH.setDate(yearH, monthH, dayH);
        y++;
        p(2, y++, "                                                         ");
        p(2, y++, "                                                         ");
        p(2, y++, "                                                         ");
        if((newDateB + 18) > newDateH || newDateH > today){
            y-=2;
            p(2, y++, "Invalid Hire Date!");
            p(2, y++, "They must be 18 on the entered date and it cant be in future.");
            y = lastLine;
            p(25, y++, "    ");
            p(17, y++, "  ");
            p(15, y++, "  ");
        }
    }while( (newDateB + 18) > newDateH || newDateH > today);
    Pilot newPilot(fn, ln, idnum, pidnum, newDateB, newDateH, rank_);
    vPilot.push_back( newPilot );

    p(5, y+=2, "Pilot added successfully!");

}

void addAttendant(){
    flag = 1;
    do{
        cls();
        y = firstLine;
        p(5, 2, "Adding a new Pilot");
        p(2, y++, "First Name:");
        p(2, y++, "Last Name:");
        p(2, y++, "ID Number:");
        p(2, y++, "Personnel code:");

        rect(1, 3, 30, 8);

        y++;
        p(5, y++, "Birth Date information ");

        y++;
        p(2, y++, "Year (1900 - present):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");

        rect(1, 10, 30, 14);

        y++;
        p(2, y++, "Are you sure? (Y/N)        ");
        y++;
        p(5, y++, "Hire Date information");
        y++;
        lastLine = y;
        p(2, y++, "Year (1900 - present):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");

        rect(1, 18, 30, 22);
        y++;

        y = firstLine;

        fn = g(14, y++);
        ln = g(13, y++);
        idnum = g(13, y++);
        pidnum = g(18, y++);

        y+=3;
        yearB = gint(25, y++);
        monthB = gint(17, y++);
        dayB = gint(15, y++);

        y++;
        gotoxy(22, y++);
        cin>>choice;

        if(choice == 'Y' || choice == 'y'){
            flag = 0;
        }

    }while(flag);
    Date newDateB(yearB, monthB, dayB),
        newDateH, today;

    do{

        y = lastLine;
        yearH = gint(25, y++);
        monthH = gint(17, y++);
        dayH = gint(15, y++);
        newDateH.setDate(yearH, monthH, dayH);

        y++;
        p(2, y++, "                                                         ");
        p(2, y++, "                                                         ");
        p(2, y++, "                                                         ");
        if((newDateB + 18) > newDateH || newDateH > today){
            y-=2;
            p(2, y++, "Invalid Hire Date!");
            p(2, y++, "They must be 18 on the entered date and it cant be in future.");
            y = lastLine;
            p(25, y++, "    ");
            p(17, y++, "  ");
            p(15, y++, "  ");
        }
    }while((newDateB + 18) > newDateH || newDateH > today);
    Attendant newAttendant(fn, ln, idnum, pidnum, newDateB, newDateH);
    vAttendant.push_back( newAttendant );

    p(5, y+=2, "Attendant added successfully!");
}

void addTicket(){

    flag = 1;
    do{
        cls();
        p(5, 2, "Adding a new Ticket");
        p(2, y++, "Origin: ");
        p(2, y++, "Destination: ");
        rect(1, 3, 30, 6);
        y++;
        p(5, y++, "Ticket Date information ");
        y++;

        lastLine = y;
        p(2, y++, "Year (present - ):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");
        rect(1, 8, 30, 12);
        y++;

        p(5, y++, "Ticket Time information ");

        y++;
        p(2, y++, "Hour: ");
        p(2, y++, "Minute: ");
        rect(1, 14, 30, 17);

        y++;
        p(2, y++, "Are you sure? (Y/N)        ");

        y = firstLine;
        origin = g(10, y++);
        destination = g(15, y++);

        y = lastLine;
        yearB = gint(21, y++);
        monthB = gint(17, y++);
        dayB = gint(15, y++);

        y+=3;
        hour = gint(8, y++);
        minute = gint(10, y++);
        y++;
        gotoxy(22, y++);
        cin>>choice;

        if(choice == 'Y' || choice == 'y'){
            flag = 0;
        }

    }while(flag);


    Time newTime(hour, minute);
    vTime.push_back(newTime);

    Date newDateT;
    newDateT.setDateFuture(yearB, monthB, dayB);
    vDate.push_back(newDateT);

    SIZE_ = vPassenger.size();
    if(SIZE_ <= 0){
        emptyPassenger();
    }
    ichoice = choosePassenger();
    Ticket newTicket(origin, destination, vPassenger[ichoice-1], newDateT, newTime);

    cls();
    cout<<newTicket;
    vTicket.push_back(newTicket);
    y+=5;

    p(5, y+=2, "Ticket added successfully!");

}

void addAirplane(){
    cls();

    p(5, 2, "Adding a new Airplane");

    p(2, y++, "Serial No.: ");
    p(2, y++, "Seats: ");

    y = firstLine;

    Airplaneno = g(14, y++);
    seats = gint(9, y++);

    AirPlane newAirplane(seats, Airplaneno);
    vAirplane.push_back( newAirplane );
    p(5, y+=2, "Airplane added successfully!");
}

void addFlight(){

    cls();
    SIZE_ = vPilot.size();

    if(SIZE_ <= 0){
        emptyPilot();
    }
    ichoice = choosePilot();
    y+=2;
    p(5, y++, "Adding a new Flight");

    lastLine = y;//5
    p(2, y++, "Flight No.: ");
    p(2, y++, "Airplane No: ");
    p(2, y++, "Origin: ");
    p(2, y++, "Destination: ");
    y++;
    p(5, y++, "Flight Date information: ");

    p(2, y++, "Year (present - ):");
    p(2, y++, "Month (1-12):");
    p(2, y++, "Day (1-31):");
    y++;
    p(5, y++, "Ticket Time information: ");

    p(2, y++, "Hour: ");
    p(2, y++, "Minute: ");

    y = lastLine;

    flightno = g(14, y++);
    Airplaneno= g(15, y++);
    origin = g(10, y++);
    destination = g(15, y++);
    y+=2;
    yearB = gint(21, y++);
    monthB = gint(17, y++);
    dayB = gint(15, y++);

    y+=2;
    hour = gint(8, y++);
    minute = gint(10, y++);

    Date newDateF;
    newDateF.setDateFuture(yearB, monthB, dayB);
    vDate.push_back(newDateF);

    y+=2;
    Time newTime(hour, minute);
    vTime.push_back(newTime);

    Flight newFlight(flightno, Airplaneno,
                     origin, destination,
                     newDateF, newTime, vPilot[ichoice-1]);
    vFlight.push_back(newFlight);

    for(ifor = 0; ifor<vAirplane.size(); ifor++){
        if(vAirplane[ifor].getSerialNo() == Airplaneno){
            vAirplane[ifor].addFlightToAirplane(vFlight[vFlight.size()-1]);
        }
    }
    p(5, y+=2, "Flight added successfully! wait ...");
    delay(DELAYTIME);

    do{
        cls();

        p(5, y, "Add Passenger to Flight? (Y/N)     ");
        p(5, y+4, "                             ");
        gotoxy(36, y++);
        cin>>choice;
        switch(choice){
        case 'y':
        case 'Y':
            addChoice = 1;
            ichoice = choosePassenger();
            vFlight[vFlight.size()-1].addPassengerToFlight(vPassenger[ichoice-1]);

            p(5, y+=2, "Passenger added successfully!");
            break;
        default:
            addChoice = 0;
        }
    }while(addChoice == 1);

    do{
        cls();

        p(5, y, "Add Attendant to Flight? (Y/N)     ");
        p(5, y+4, "                             ");
        gotoxy(36, y++);
        cin>>choice;
        switch(choice){
        case 'y':
        case 'Y':
            addChoice = 1;
            ichoice = chooseAttendant();
            vFlight[vFlight.size()-1].addAttendantToFlight(vAttendant[ichoice-1]);

            p(5, y+=2, "Attendant added successfully!");
            break;
        default:
            addChoice = 0;
        }
    }while(addChoice == 1);

}

void list(){
    cls();

    p(2, 1, "List");
    p(2, 3, "1   Passengers");
    p(2, 4, "2   Pilots");
    p(2, 5, "3   Attendants");
    p(2, 6, "4   Airplanes");
    p(2, 7, "5   Flights");
    p(2, 8, "9   Main Menu");

    p(2, 10, "Press Selection: ");
    rectnew(0, 0, 22, 11);
    gotoxy(20, 10);
    cin>>addChoice;

    switch(addChoice){
    case 1:
        listPassenger();
        ask();
        backToMainMenu();
        break;
    case 2:
        listPilot();
        ask();
        backToMainMenu();
        break;
    case 3:
        listAttendant();
        ask();
        backToMainMenu();
        break;
    case 4:
        listAirplane();
        ask();
        backToMainMenu();
        break;
    case 5:
        listFlight();
        ask();
        backToMainMenu();
        break;
    case 9:
    default:
        mainPage();
    }

}

void listPassenger(){
    cls();
    SIZE_ = vPassenger.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Passenger Information");
        //       2345678901234567890123456789012345678901234567890
        p(2, 3, "no.  FirstName    LastName       ID Number");
        //y++;
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            p(7, y, vPassenger[ifor].getFirstName());
            p(20, y, vPassenger[ifor].getLastName());
            p(35, y, vPassenger[ifor].getIDNum());
            y++;
        }

        rect(1, 4, 50, y++);
    }
    else{
        emptyPassenger();
    }
}

void listPilot(){
    cls();
    SIZE_ = vPilot.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Pilot Information");
        //               10        20        30        40        50        60        70        80        90
        //       23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
        p(2, 3, "no.  FirstName    LastName       IDNumber   PersonnelCode Rank  BirthDate  HireDate");
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            p(7, y, vPilot[ifor].getFirstName());
            p(20, y, vPilot[ifor].getLastName());
            p(35, y, vPilot[ifor].getIDNum());
            p(46, y, vPilot[ifor].getPIDNum());
            gotoxy(60, y);
            cout<<vPilot[ifor].getRank();
            gotoxy(66, y);
            vPilot[ifor].getBirthDate();
            gotoxy(77, y);
            vPilot[ifor].getHireDate();

            y++;
        }
        rect(1, 4, 90, y++);
    }
    else{
        emptyPilot();
    }
}

void listAttendant(){
    cls();
    SIZE_ = vAttendant.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Attendant Information");
        //               10        20        30        40        50        60        70
        //       2345678901234567890123456789012345678901234567890123456789012345678901234567890
        p(2, 3, "no.  FirstName    LastName       IDNumber   PersonnelCode BirthDate  HireDate");
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            p(7, y, vAttendant[ifor].getFirstName());
            p(20, y, vAttendant[ifor].getLastName());
            p(35, y, vAttendant[ifor].getIDNum());
            p(46, y, vAttendant[ifor].getPIDNum());
            gotoxy(60, y);
            vAttendant[ifor].getBirthDate();
            gotoxy(71, y);
            vAttendant[ifor].getHireDate();

            y++;
        }
        rect(1, 4, 82, y++);
    }
    else{
        emptyAttendant();
    }
}

void listAirplane(){
    cls();
    SIZE_ = vAirplane.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Airplane Information");
        //               10        20        30        40        50        60        70
        //       2345678901234567890123456789012345678901234567890123456789012345678901234567890
        p(2, 3, "no.  SerialNo     Seats");
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            p(7, y, vAirplane[ifor].getSerialNo());
            gotoxy(20, y);
            cout<<vAirplane[ifor].getSeats();

            y++;
        }
        rect(1, 4, 30, y++);
    }
    else{
        emptyAirplane();
    }
}

void listFlight(){
    cls();
    SIZE_ = vFlight.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Flight Information");
        //               10        20        30        40        50        60        70
        //       2345678901234567890123456789012345678901234567890123456789012345678901234567890
        p(2, 3, "no.  Date       Time  FlightNo  AirplaneNo   Pilot               ");
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            gotoxy(7, y);
            vFlight[ifor].printDate();
            gotoxy(18, y);
            vFlight[ifor].printTime();
            p(24, y, vFlight[ifor].getFlightNo());
            p(34, y, vFlight[ifor].getAirplaneNo());
            p(47, y, vFlight[ifor].getPilot().getLastName() + ", " + vFlight[ifor].getPilot().getFirstName());
            y+=2;

            if(vFlight[ifor].getvAttendantSize() > 0){
                p(5, y++, "Attendants: ");
                gotoxy(0, y);
                vFlight[ifor].printvAttendant();
                y += 7;
            }
            if(vFlight[ifor].getvPassengerSize() > 0){
                p(5, y++, "Passengers: ");
                gotoxy(0, y);
                vFlight[ifor].printvPassenger();
                y += vFlight[ifor].getvPassengerSize()*4;
            }
        }
        rect(1, 4, 70, y++);
    }
    else{
        emptyFlight();
    }
}

/*
void listTicket(){
    cls();
    SIZE_ = vTicket.size();
    y = firstLine+1;
    if(SIZE_>0){
        p(2, 2, "    Printing Ticket Information");
        //               10        20        30        40        50        60        70
        //       2345678901234567890123456789012345678901234567890123456789012345678901234567890

        p(2, 3, "no.  Date      Time  FlightNo  AirplaneNo   Pilot           Attendant       Passenger ");
        for(ifor = 0; ifor < SIZE_; ifor++){
            p(2, y, ifor+1);
            //p(7, y, vFlight[ifor].printDate());
            gotoxy(7, y);
            vFlight[ifor].printDate();
            //p(17, y, vFlight[ifor].printTime());
            gotoxy(17, y);
            vFlight[ifor].printTime();
            p(23, y, vFlight[ifor].getFlightNo());
            p(33, y, vFlight[ifor].getAirplaneNo());
            p(46, y, vFlight[ifor].getPilot.getFirstName() + ", " + vFlight[ifor].getPilot.getLastName());

            y++;
        }
        //p(5, y+=2, "--- End of the Airplane List ---");
        rect(1, 4, 30, y++);

    }
    else{
        p(5, y++, "Ticket Information List is Empty!");
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();

    }
}
*/

void emptyPassenger(){
    p(5, y++, "Passenger Information List is Empty!");
    //       567890123456789012345678901234567
    p(5, y, "Do you want to add any? (Y/N) ");
    gotoxy(35, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        addPassenger();
        break;
    default:
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();
    }
}

void emptyPilot(){
    p(5, y++, "Pilot Information List is Empty!");
    //       567890123456789012345678901234567
    p(5, y, "Do you want to add any? (Y/N) ");
    gotoxy(35, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        addPilot();
        break;
    default:
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();
    }
}

void emptyAttendant(){
    p(5, y++, "Attendant Information List is Empty!");
    //       567890123456789012345678901234567
    p(5, y, "Do you want to add any? (Y/N) ");
    gotoxy(35, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        addAttendant();
        break;
    default:
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();
    }
}

void emptyAirplane(){
    p(5, y++, "Airplane Information List is Empty!");
    //       567890123456789012345678901234567
    p(5, y, "Do you want to add any? (Y/N) ");
    gotoxy(35, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        addAirplane();
        break;
    default:
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();
    }
}

void emptyFlight(){
    p(5, y++, "Flight Information List is Empty!");
    //       567890123456789012345678901234567
    p(5, y, "Do you want to add any? (Y/N) ");
    gotoxy(35, y++);
    cin>>choice;
    switch(choice){
    case 'y':
    case 'Y':
        addFlight();
        break;
    default:
        p(2, y+=2, "Going Back To Main Menu ... ");
        delay(DELAYTIME);
        mainPage();
    }
}

int choosePassenger(){
    SIZE_ = vPassenger.size();
    if(SIZE_<=0){
        flag=1;
    }
    listPassenger();
    if(flag == 1){
        listPassenger();
        flag =0;
    }
    y+=2;
    lastLine = y;
    SIZE_ = vPassenger.size();
    do{
        y = lastLine;
        //       5678901234567890123456
        p(5, y, "Enter passenger no.:    ");
        choice_ = gint(26, y++);
        if(choice_>SIZE_){
            p(5, y++, "Invalid input! Try again ...");
        }
    }while(choice_>SIZE_);

    return choice_;
}

int choosePilot(){
    SIZE_ = vPilot.size();
    if(SIZE_<=0){
        flag=1;
    }
    listPilot();
    if(flag == 1){
        listPilot();
        flag =0;
    }
    y++;
    lastLine = y;
    SIZE_ = vPilot.size();
    do{
        y = lastLine;
        //       5678901234567890123456
        p(5, y, "Enter Pilot no.:    ");
        choice_ = gint(22, y++);
        if(choice_>SIZE_){
            p(5, y++, "Invalid input! Try again ...");
        }
    }while(choice_>SIZE_);

    return choice_;
}

int chooseAttendant(){
    SIZE_ = vAttendant.size();
    if(SIZE_==0){
        flag=1;
    }
    listAttendant();
    if(flag == 1){
        listAttendant();
        flag =0;
    }
    y+=2;
    lastLine = y;
    SIZE_ = vAttendant.size();
    do{
        y = lastLine;
        //       5678901234567890123456
        p(5, y, "Enter Attendant no.:    ");
        choice_ = gint(26, y++);
        if(choice_>SIZE_){
            p(5, y++, "Invalid input! Try again ...");
        }
    }while(choice_>SIZE_);

    return choice_;
}

int chooseAirplane(){
    SIZE_ = vAirplane.size();
    if(SIZE_==0){
        flag=1;
    }
    listAirplane();
    if(flag == 1){
        listAirplane();
        flag =0;
    }
    y+=2;
    lastLine = y;
    SIZE_ = vAirplane.size();
    do{
        y = lastLine;
        //       5678901234567890123456
        p(5, y, "Enter Airplane no.:    ");
        choice_ = gint(26, y++);
        if(choice_>SIZE_){
            p(5, y++, "Invalid input! Try again ...");
        }
    }while(choice_>SIZE_);

    return choice_;
}

void report(){
    cls();
    y = 3;
    //        234567890123456789012345678901234567890
    p(2, 1, "Report based on ...");
    p(2, y++, "1   Date");
    p(2, y++, "2   Airplane Serial Number");
    p(2, y++, "3   Personnel Code");
    p(2, y++, "4   ID Number");
    p(2, y++, "9   Main Menu");
    y++;
    p(2, y, "Press Selection: ");
    rectnew(0, 0, 30, 10);
    gotoxy(20, y++);
    cin>>addChoice;

    switch(addChoice){
    case 1:
        reportDate();
        ask();
        backToMainMenu();
        break;
    case 2:
        reportAiplaneSerialNo();
        ask();
        backToMainMenu();
        break;
    case 3:
        reportPersonnelCode();
        ask();
        backToMainMenu();
        break;
    case 4:
        reportIDNum();
        ask();
        backToMainMenu();
        break;
    case 9:
    default:
        mainPage();
    }
}

void reportDate(){
    cls();

    SIZE_ = vDate.size();
    if(SIZE_ > 0){
        p(5, 2, "Enter the specific date: ");
        //         2345678901234567890123
        p(2, y++, "Year (present - ):");
        p(2, y++, "Month (1-12):");
        p(2, y++, "Day (1-31):");

        y = firstLine;
        yearR = gint(21, y++);
        monthR = gint(17, y++);
        dayR = gint(15, y++);

        Date newRepDate(yearR, monthR, dayR);
        index = -1;
        for(ifor = 0; ifor<vDate.size(); ifor++){
            if(vDate[ifor] == newRepDate)
                index = ifor;
        }
        if(index != -1){
            index2 = -1;
            for(ifor = 0; ifor<vFlight.size(); ifor++){
                if(vFlight[ifor].getFlightDate() == vDate[index]){
                    index2 = ifor;
                    lastLine = y++;
                    p(2, y, "    Flight Information for ");
                    gotoxy(29, y++);
                    cout<<newRepDate;
                    //               10        20        30        40        50        60
                    //       23456789012345678901234567890123456789012345678901234567890
                    p(2, y++, "no.  Time  FlightNo  AirplaneNo   Pilot               ");
                    for(ifor = 0; ifor < SIZE_; ifor++){
                        p(2, y, ifor+1);
                        gotoxy(7, y);
                        vFlight[ifor].printTime();
                        p(13, y, vFlight[ifor].getFlightNo());
                        p(23, y, vFlight[ifor].getAirplaneNo());
                        p(36, y, vFlight[ifor].getPilot().getLastName() + ", " + vFlight[ifor].getPilot().getFirstName());
                        y+=2;

                        if(vFlight[ifor].getvAttendantSize() > 0){
                            p(5, y++, "Attendants: ");
                            gotoxy(0, y);
                            vFlight[ifor].printvAttendant();
                            y += 7;
                        }
                        if(vFlight[ifor].getvPassengerSize() > 0){
                            p(5, y++, "Passengers: ");
                            gotoxy(0, y);
                            vFlight[ifor].printvPassenger();
                            y += vFlight[ifor].getvPassengerSize()*3 + 1;
                        }
                    }
                    rect(1, lastLine, 70, y++);
                    /*
                    //               10        20        30
                    //       23456789012345678901234567890
                    p(2, y++, "no.  FlightNo  AirplaneNo");
                    p(2, y, ifor);
                    p(7, y, vFlight[ifor].getFlightNo());
                    p(17, y++, vFlight[ifor].getAirplaneNo());
                    p(5, y++, "Pilot:");
                    gotoxy(2, y);
                    vFlight[ifor].printPilot();
                    y+=10;
                    p(5, y++, "Passenger List");
                    gotoxy(2, y++);
                    vFlight[ifor].printvPassenger();
                    y+=4;
                    p(5, y++, "Attendant List");
                    gotoxy(2, y++);
                    vFlight[ifor].printvAttendant();
                    y+=10;
                    */
                }
            }
            if(index2 == -1){
                p(5, y++, "No flight entry with the given date!");
            }
        }
        else{
            p(5, y+=2, "No entry with the given date!");
        }
    }
    else{
        p(5, y+=2, "Empty Date entry!");
    }
}

void reportAiplaneSerialNo(){
    cls();

    SIZE_ = vAirplane.size();
    index = -1;
    if(SIZE_ > 0){
        //       567890123456789012345678901234
        p(5, y, "Enter Airplane Serial No: ");
        Airplaneno = g(31, y++);
        for(ifor = 0; ifor<vAirplane.size(); ifor++){
            if(vAirplane[ifor].getSerialNo() == Airplaneno){
                index = ifor;
                if(vAirplane[ifor].getvFlightSize() == 0){
                    p(5, y++, "The Airplane has no flight!");
                }
                else{
                    vAirplane[ifor].getvFlight();
                    y += vAirplane[ifor].getvFlightSize()*6 +1;
                    cout<<"    ---  \n";
                }
            }
        }
        if(index == -1){
            p(5, y+=2, "No flight entry with the given Airplane Number!");
        }
    }
    else{
        p(5, y, "Empty Airplane entry!");
    }
}

void reportPersonnelCode(){
    cls();

    index = -1;
    if(vPilot.size() > 0 || vAttendant.size() > 0){
        //       567890123456789012345678901234
        p(5, y, "Enter Personnel Code: ");
        pidnum = g(27, y++);
        for(ifor = 0; ifor<vPilot.size(); ifor++){
            if(vPilot[ifor].getPIDNum() == pidnum){
                index = ifor;
                p(5, y++, "Pilot");
                cout<<vPilot[ifor];
                y+=10;
                cout<<"    ---  \n";
            }
        }
        for(ifor = 0; ifor<vAttendant.size(); ifor++){
            if(vAttendant[ifor].getPIDNum() == pidnum){
                index = ifor;
                p(5, y++, "Attendant");
                cout<<vAttendant[ifor];
                y+=10;
                cout<<"    ---  \n";
            }
        }
        if(index == -1){
            p(5, y+=2, "No Personnel entry with the given Personnel Code!");
        }
    }
    /*
    else if(vPilot.size() <= 0){
        emptyPilot();
    }
    else if(vAttendant.size() <== 0){
        emptyAttendant();
    }*/
    else{
        p(5, y, "Empty Personnel entry!");
    }
}

void reportIDNum(){
    cls();
    y = firstLine;
    p(5, y, "Enter ID Number: ");
    idnum = g(22, y+=2);
    for(jfor = 0; jfor<3; jfor++){
        switch(jfor){
        case 0:
            searchPassenger(idnum);
            break;
        case 1:
            searchPilot(idnum);
            break;
        case 2:
            searchAttendant(idnum);
            break;
        }
    }
}

void searchPassenger(string id){
    flag = 1;
    index = -1;
    SIZE_ = vPassenger.size();
    if(SIZE_){
        for(ifor = 0; ifor<SIZE_; ifor++){
            if(vPassenger[ifor].getIDNum() == id){
                index = ifor;
                if(flag){
                    p(2, y++, "    Passenger Information");

                    p(2, y++, "no.  FirstName    LastName       ID Number");
                    flag = 0;
                }
                for(ifor = 0; ifor < SIZE_; ifor++){

                    p(2, y, ifor+1);
                    p(7, y, vPassenger[ifor].getFirstName());
                    p(20, y, vPassenger[ifor].getLastName());
                    p(35, y, vPassenger[ifor].getIDNum());
                    y++;
                }
                y++;
            }
            //y--;
            //rect(1, 4, 50, y++);
        }
        if(index == -1){
            p(5, y+=2, "No Person entry with the given ID Number!");
        }
    }
    else{
        p(5, y, "Empty Passenger entry!");
    }
}

void searchPilot(string id){
    flag = 1;
    index = -1;
    SIZE_ = vPilot.size();
    if(SIZE_){
        for(ifor = 0; ifor<SIZE_; ifor++){
            if(vPilot[ifor].getIDNum() == id){
                index = ifor;
                if(flag){
                    p(2, y++, "    Pilot Information");

                    p(2, y++, "no.  FirstName    LastName       IDNumber   PersonnelCode Rank  BirthDate  HireDate");
                    flag = 0;
                }
                for(ifor = 0; ifor < SIZE_; ifor++){

                    p(2, y, ifor+1);
                    p(7, y, vPilot[ifor].getFirstName());
                    p(20, y, vPilot[ifor].getLastName());
                    p(35, y, vPilot[ifor].getIDNum());
                    p(46, y, vPilot[ifor].getPIDNum());
                    gotoxy(60, y);
                    cout<<vPilot[ifor].getRank();
                    gotoxy(66, y);
                    vPilot[ifor].getBirthDate();
                    gotoxy(77, y);
                    vPilot[ifor].getHireDate();

                    y++;
                }
                y++;
            }
            //y--;
            //rect(1, 4, 90, y++);
        }
        if(index == -1){
            p(5, y+=2, "No Pilot entry with the given ID Number!");
        }
    }
    else{
        p(5, y, "Empty Pilot entry!");
    }
}

void searchAttendant(string id){
    flag = 1;
    index = -1;
    SIZE_ = vAttendant.size();
    if(SIZE_){

        for(ifor = 0; ifor<SIZE_; ifor++){
            if(vAttendant[ifor].getIDNum() == id){
                index = ifor;
                if(flag){
                    p(2, y++, "    Attendant Information");

                    p(2, y++, "no.  FirstName    LastName       IDNumber   PersonnelCode BirthDate  HireDate");
                    flag = 0;
                }
                for(ifor = 0; ifor < SIZE_; ifor++){

                    p(2, y, ifor+1);
                    p(7, y, vAttendant[ifor].getFirstName());
                    p(20, y, vAttendant[ifor].getLastName());
                    p(35, y, vAttendant[ifor].getIDNum());
                    p(46, y, vAttendant[ifor].getPIDNum());
                    gotoxy(60, y);
                    vAttendant[ifor].getBirthDate();
                    gotoxy(71, y);
                    vAttendant[ifor].getHireDate();
                    y++;
                }
                y++;
            }
            //y--;
            //rect(1, 4, 80, y++);
        }
        if(index == -1){
            p(5, y+=2, "No Attendant entry with the given ID Number!");
        }
    }
    else{
        p(5, y, "Empty Attendant entry!");
    }
}
