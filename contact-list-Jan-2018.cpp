#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x, int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int ID=0, OD=0, ifor=0, jfor=0, a=ID+4, ided=0, iddeln=0, gh=15, qw=0;
char name[50][50], family[50][50], phone[50][13], home[50][13], nameS[50][50], familyS[50][50], phoneS[50][13], homeS[50][13], yn, srch[50],
    c218=218, c210=210, c196=196, c191=191, c176=176, c177=177, c178=178, c179=179, c198=198, c186=186, c202=202, c181=181,
    c192=192, c217=217, c205=205, c195=195, c208=208, c215=215, c180=180, c193=193, c194=194;
    //a for list row
void get(int x, int y, int id);
void done();
void rect(int x1,int y1,int x2,int y2);
void del();
void srch4dl();
void sort();
void sortcpy(int ifor);
void iddel( int iddeln, int a);
void edit();
void idedt(int ided, int a);
void srch4ed();
void search();
void cpysrch(int , int , int);
void searchagain();
void btmm(int y);
void list(int a);
void add();
void rusure();
void fp();
main(){
    system("color 80");
    system("CLS");
    fp();
}
void get(int x, int y, int id){
    gotoxy(x,y);
    cin.get(name[id],50);
    fflush(stdin);
    gotoxy(x,y+2);
    cin.get(family[id],50);
    fflush(stdin);
    gotoxy(x,y+4);
    cin.get(phone[id],13);
    fflush(stdin);
    gotoxy(x,y+6);
    cin.get(home[id],13);
}
void btfp(){
    system("CLS");
    gotoxy(4,10);
    cout<<"Then bye ^_^!";
    for(ifor=5000;ifor>0;ifor--){
        gotoxy(4,11);
        cout<<"Thanks for using my program!";
        gotoxy(4,12);
        cout<<"This will be closed in "<<ifor/900<<" seconds.";
    }
}
void btmm(int y){
    rect(2,y+2,32,y+4);
    gotoxy(4,y+3);
    cout<<"Back To main menu? Y/N ";
    cin>>yn;
    switch(yn){
        case 'Y':
        case 'y':
            fp();
            break;
        case 'N':
        case 'n':
            btfp();
            break;
        default:
            gotoxy(4,y+6);
            cout<<"You have to choose between Y an N, Try again ...";
            delay(2500);
            gotoxy(25,y+3);
            cout<<"      ";
            done();
            break;
    }
}
void done(){
    system("CLS");
    system("color 0d");
    rect(10,5,20,7);
    gotoxy(11,6);
    cout<<"D O N E !";
    btmm(8);
}
void rect(int x1,int y1,int x2,int y2){
    for(ifor=x1;ifor<x2;ifor++){
        gotoxy(ifor, y1);
        cout<<c196;
        gotoxy(ifor, y2);
        cout<<c196;
    }
    for(ifor=y1;ifor<y2;ifor++){
        gotoxy(x1, ifor);
        cout<<c179;
        gotoxy(x2, ifor);
        cout<<c179;
    }
    gotoxy(x1,y1);
    cout<<c218;
    gotoxy(x1,y2);
    cout<<c192;
    gotoxy(x2,y1);
    cout<<c191;
    gotoxy(x2,y2);
    cout<<c217;
}
void srch4dl(){
    OD=0;
    system("CLS");
    rect(2,2,48,9);
    gotoxy(4,3);
    cout<<"How do you want to search in your contacts?";
    gotoxy(4,4);
    cout<<"1) Name";
    gotoxy(4,5);
    cout<<"2) Family";
    gotoxy(4,6);
    cout<<"3) Phone";
    gotoxy(4,7);
    cout<<"4) Home";
    gotoxy(4,8);
    cout<<"Tell me: ";
    int srn;
    cin>>srn;
    if(srn==1||srn==2||srn==3||srn==4){
        rect(2,10,43,13);
        gotoxy(4,11);
        cout<<"Let me know what are you looking for: ";
        gotoxy(4,12);
        fflush(stdin);
        cin.get(srch, 50);
        int k=0;
        OD=0;
        gh=15;
        switch(srn){
            case 1:
                for(ifor=1;ifor<=ID;ifor++){
                    k=strcmp(name[ifor],srch);
                    if(k==0){
                        OD++;
                        cpysrch(OD, ifor, gh);
                        gh++;
                    }
                }
                if(OD!=0){
                    rect(2,14,60,gh);
                    gotoxy(3, gh+1);
                    cout<<"Now choose an ID: ";
                    cin>>iddeln;
                    if(iddeln>OD||iddeln<1){
                        gotoxy(4, gh+1);
                        cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                        gotoxy(4, gh+2);
                        cout<<"Wait until back to search again ...";
                        delay(3000);
                        srch4ed();
                    }
                    else{
                        if(iddeln!=ID){
                            for(ifor=iddeln; ifor<ID; ifor++){
                                strcpy(name[ifor],name[ifor+1]);
                                strcpy(family[ifor],family[ifor+1]);
                                strcpy(home[ifor],home[ifor+1]);
                                strcpy(phone[ifor],phone[ifor+1]);
                            }
                            strcpy(name[ID], "");
                            strcpy(family[ID], "");
                            strcpy(home[ID], "");
                            strcpy(phone[ID], "");
                        }
                        ID--;
                        a=ID+10;
                        rect(10,gh+3,20,gh+5);
                        gotoxy(11,gh+4);
                        cout<<"D O N E !";
                        gotoxy(4,gh+6);
                        cout<<"Back To 1) main menu or 2) list? 1/2 ";
                        int o;
                        cin>>o;
                        switch(o){
                            case 1:
                                fp();
                                break;
                            case 2:
                                list(a);
                                btmm(a+1);
                                break;
                        }
                    }
                }
                else{
                    gotoxy(3,14);
                    cout<<"Sorry! I couldn't find "<<srch<<" in name list.";
                    delay(3000);
                    gotoxy(3, 15);
                    srch4dl();
                }
                break;
            case 2:
                for(ifor=1;ifor<=ID;ifor++){
                    k=strcmp(family[ifor],srch);
                    if(k==0){
                        OD++;
                        cpysrch(OD, ifor, gh);
                        gh++;
                    }
                }
                if(OD!=0){
                    rect(2,14,60,gh);
                    gotoxy(3, gh+1);
                    cout<<"Now choose an ID: ";
                    cin>>iddeln;
                    if(iddeln>OD||iddeln<1){
                        gotoxy(4, gh+1);
                        cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                        gotoxy(4, gh+2);
                        cout<<"Wait until back to search again ...";
                        delay(3000);
                        srch4ed();
                    }
                    else{
                        if(iddeln!=ID){
                            for(ifor=iddeln; ifor<ID; ifor++){
                                strcpy(name[ifor],name[ifor+1]);
                                strcpy(family[ifor],family[ifor+1]);
                                strcpy(home[ifor],home[ifor+1]);
                                strcpy(phone[ifor],phone[ifor+1]);
                            }
                            strcpy(name[ID], "");
                            strcpy(family[ID], "");
                            strcpy(home[ID], "");
                            strcpy(phone[ID], "");
                        }
                        ID--;
                        a=ID+10;
                        rect(10,a+10,20,a+12);
                        gotoxy(11,a+11);
                        cout<<"D O N E !";
                        gotoxy(4,a+14);
                        cout<<"Back To 1) main menu or 2) list? 1/2 ";
                        int o;
                        cin>>o;
                        switch(o){
                            case 1:
                                fp();
                                break;
                            case 2:
                                list(a);
                                btmm(a+1);
                                break;
                        }
                    }
                }
                else{
                    gotoxy(3,14);
                    cout<<"Sorry! I couldn't find "<<srch<<" in family list.";
                    delay(3000);
                    gotoxy(3, 15);
                    srch4dl();
                }
                break;
            case 3:
                for(ifor=1;ifor<=ID;ifor++){
                    k=strcmp(phone[ifor],srch);
                    if(k==0){
                        OD++;
                        cpysrch(OD, ifor, gh);
                        gh++;
                    }
                }
                if(OD!=0){
                    rect(2,14,60,gh);
                    gotoxy(3, gh+1);
                    cout<<"Now choose an ID: ";
                    cin>>iddeln;
                    if(iddeln>OD||iddeln<1){
                        gotoxy(4, gh+1);
                        cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                        gotoxy(4, gh+2);
                        cout<<"Wait until back to search again ...";
                        delay(3000);
                        srch4ed();
                    }
                    else{
                        if(iddeln!=ID){
                            for(ifor=iddeln; ifor<ID; ifor++){
                                strcpy(name[ifor],name[ifor+1]);
                                strcpy(family[ifor],family[ifor+1]);
                                strcpy(home[ifor],home[ifor+1]);
                                strcpy(phone[ifor],phone[ifor+1]);
                            }
                            strcpy(name[ID], "");
                            strcpy(family[ID], "");
                            strcpy(home[ID], "");
                            strcpy(phone[ID], "");
                        }
                        ID--;
                        a=ID+10;
                        rect(10,a+10,20,a+12);
                        gotoxy(11,a+11);
                        cout<<"D O N E !";
                        gotoxy(4,a+14);
                        cout<<"Back To 1) main menu or 2) list? 1/2 ";
                        int o;
                        cin>>o;
                        switch(o){
                            case 1:
                                fp();
                                break;
                            case 2:
                                list(a);
                                btmm(a+1);
                                break;
                        }
                    }
                }
                else{
                    gotoxy(3,14);
                    cout<<"Sorry! I couldn't find "<<srch<<" in phone number list.";
                    delay(3000);
                    gotoxy(3, 15);
                    srch4dl();
                }
                break;
            case 4:
                for(ifor=1;ifor<=ID;ifor++){
                    k=strcmp(home[ifor],srch);
                    if(k==0){
                        OD++;
                        cpysrch(OD, ifor, gh);
                        gh++;
                    }
                }
                if(OD!=0){
                    rect(2,14,60,gh);
                    gotoxy(3, gh+1);
                    cout<<"Now choose an ID: ";
                    cin>>iddeln;
                    if(iddeln>OD||iddeln<1){
                        gotoxy(4, gh+1);
                        cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                        gotoxy(4, gh+2);
                        cout<<"Wait until back to search again ...";
                        delay(3000);
                        srch4ed();
                    }
                    else{
                        if(iddeln!=ID){
                            for(ifor=iddeln; ifor<ID; ifor++){
                                strcpy(name[ifor],name[ifor+1]);
                                strcpy(family[ifor],family[ifor+1]);
                                strcpy(home[ifor],home[ifor+1]);
                                strcpy(phone[ifor],phone[ifor+1]);
                            }
                            strcpy(name[ID], "");
                            strcpy(family[ID], "");
                            strcpy(home[ID], "");
                            strcpy(phone[ID], "");
                        }
                        ID--;
                        a=ID+10;
                        rect(10,a+10,20,a+12);
                        gotoxy(11,a+11);
                        cout<<"D O N E !";
                        gotoxy(4,a+14);
                        cout<<"Back To 1) main menu or 2) list? 1/2 ";
                        int o;
                        cin>>o;
                        switch(o){
                            case 1:
                                fp();
                                break;
                            case 2:
                                list(a);
                                btmm(a+1);
                                break;
                        }
                    }
                }
                else{
                    gotoxy(3,14);
                    cout<<"Sorry! I couldn't find "<<srch<<" in home number list.";
                    delay(3000);
                    gotoxy(3, 15);
                    srch4dl();
                }
                break;
            default:
                cout<<"Sorry! you have to choose between 1/2/3/4 ...";
                delay(1500);
                srch4dl();
                break;
        }
    }
    else{
        cout<<"Sorry! you have to choose between 1/2/3/4 ...";
        delay(1500);
        srch4dl();
    }
}
void del(){
    system("CLS");
    if(ID==0){
        rect(3,3,31,6);
        gotoxy(4,4);
        cout<<" Nothing is recorded yet!";
        btmm(5);
    }
    else{
        rect(2,2,77,8);
        gotoxy(4,3);
        cout<<"1) I can show you the list and you choose which contact you wanna delete";
        gotoxy(4,4);
        cout<<" OR ";
        gotoxy(4,5);
        cout<<"2) Search in your contacts.";
        gotoxy(4,6);
        cout<<"Which one? ";
        int deln;
        cin>>deln;
        switch(deln){
            case 1:
                a=ID+3;
                list(a);
                rect(2,a+2,30,a+4);
                gotoxy(4,a+3);
                cout<<" Now choose an ID: ";
                cin>>iddeln;
                if(iddeln>ID||iddeln<1){
                    gotoxy(4, a+5);
                    cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                    gotoxy(4, a+6);
                    cout<<"Wait until back to delete again ...";
                    delay(3000);
                    del();
                }
                else
                    iddel(iddeln, a);
                break;
            case 2:
                srch4dl();
                break;
            default:
                gotoxy(4,7);
                cout<<"Sorry! You have to choose between 1/2 ...";
                delay(750);
                del();
                break;
        }
    }
}
void iddel( int iddeln, int a){
    if(iddeln!=ID){
        for(ifor=iddeln; ifor<ID; ifor++){
            strcpy(name[ifor],name[ifor+1]);
            strcpy(family[ifor],family[ifor+1]);
            strcpy(home[ifor],home[ifor+1]);
            strcpy(phone[ifor],phone[ifor+1]);
        }
        strcpy(name[ID], "");
        strcpy(family[ID], "");
        strcpy(home[ID], "");
        strcpy(phone[ID], "");
    }
    ID--;
    a=ID+3;
    rect(10,a+10,20,a+12);
    gotoxy(11,a+11);
    cout<<"D O N E !";
    gotoxy(4,a+14);
    cout<<"Back To 1) main menu or 2) list? 1/2 ";
    int o;
    cin>>o;
    switch(o){
        case 1:
            fp();
            break;
        case 2:
            list(a);
            btmm(a+1);
            break;
    }
}
void edit(){
    system("CLS");
    if(ID==0){
        rect(3,3,31,6);
        gotoxy(4,4);
        cout<<" Nothing is recorded yet!";
        gotoxy(4,5);
        cout<<" Back To main menu? Y/N ";
        cin>>yn;
        switch(yn){
            case 'Y':
            case 'y':
                fp();
                break;
            case 'N':
            case 'n':
                btfp();
                break;
        }
    }
    else{
        rect(2,2,75,8);
        gotoxy(4,3);
        cout<<"1) I can show you the list and you choose which contact you wanna edit";
        gotoxy(4,4);
        cout<<" OR ";
        gotoxy(4,5);
        cout<<"2) search in your contacts.";
        gotoxy(4,6);
        cout<<"Which one? ";
        int edn;
        cin>>edn;
        switch(edn){
            case 1:
                list(a);
                rect(2,a+1,30,a+3);
                gotoxy(4,a+2);
                cout<<" Now choose an ID: ";
                cin>>ided;
                if(ided>ID||ided<1){
                    gotoxy(4, a+4);
                    cout<<"Sorry! There's no "<<ided<<" in IDs!";
                    gotoxy(4, a+5);
                    cout<<"Wait until back to edit again ...";
                    delay(3000);
                    edit();
                }
                else
                    idedt(ided, a);
                break;
            case 2:
                srch4ed();
                break;
            default:
                gotoxy(4,7);
                cout<<"Sorry! You have to choose between 1/2 ...";
                delay(750);
                edit();
                break;
        }
    }
}
void idedt(int ided, int a){
    for(ifor=11;ifor<=13;ifor++){
        gotoxy(2, a+ifor);
        cout<<"                                                 ";
    }
    rect(2, a+4, 33, a+10);
    gotoxy(4, a+5);
    cout<<" You wanna edit 1) Name";
    gotoxy(19, a+6);
    cout<<" 2) Family";
    gotoxy(19, a+7);
    cout<<" 3) Phone";
    gotoxy(19, a+8);
    cout<<" 4) Home";
    gotoxy(4, a+9);
    cout<<" Choose: ";
    int idedc;
    cin>>idedc;
    rect(2, a+11, 50, a+13);
    gotoxy(4, a+12);
    switch(idedc){
        case 1:
            cout<<"New Name: ";
            fflush(stdin);
            cin.get(name[ided], 50);
            break;
        case 2:
            cout<<"New Family: ";
            fflush(stdin);
            cin.get(family[ided], 50);
            break;
        case 3:
            cout<<"New Phone: ";
            fflush(stdin);
            cin.get(phone[ided], 50);
            break;
        case 4:
            cout<<"New Home: ";
            fflush(stdin);
            cin.get(home[ided], 50);
            break;
        default:
            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
            gotoxy(12, a+9);
            cout<<"      ";
            delay(750);
            idedt(ided, a);
            break;
    }
    done();
}
void srch4ed(){
    OD=0;
    system("CLS");
    rect(2,2,48,9);
    gotoxy(4,3);
    cout<<"How do you want to search in your contacts?";
    gotoxy(4,4);
    cout<<"1) Name";
    gotoxy(4,5);
    cout<<"2) Family";
    gotoxy(4,6);
    cout<<"3) Phone";
    gotoxy(4,7);
    cout<<"4) Home";
    gotoxy(4,8);
    cout<<"Tell me: ";
    int srn;
    cin>>srn;
    rect(2,10,43,13);
    gotoxy(4,11);
    cout<<"Let me know what are you looking for: ";
    gotoxy(4,12);
    fflush(stdin);
    cin.get(srch, 50);
    int k=0;
    switch(srn){
        case 1:
            for(ifor=1;ifor<=ID;ifor++){
                k=strcmp(name[ifor],srch);
                if(k==0){
                    OD++;
                    cpysrch(OD, ifor, gh);
                    gh++;
                }
            }
            if(OD!=0){
                rect(2,14,60,gh);
                gotoxy(3, gh+1);
                cout<<"Now choose an ID: ";
                cin>>ided;
                if(ided>OD||ided<1){
                    gotoxy(4, gh+1);
                    cout<<"Sorry! There's no "<<ided<<" in IDs!";
                    gotoxy(4, gh+2);
                    cout<<"Wait until back to search again ...";
                    delay(3000);
                    srch4ed();
                }
                else{
                    rect(2, gh+4, 33, gh+10);
                    gotoxy(4, gh+5);
                    cout<<" You wanna edit 1) Name";
                    gotoxy(19, gh+6);
                    cout<<" 2) Family";
                    gotoxy(19, gh+7);
                    cout<<" 3) Phone";
                    gotoxy(19, gh+8);
                    cout<<" 4) Home";
                    gotoxy(4, gh+9);
                    cout<<" Choose: ";
                    int idedc;
                    cin>>idedc;
                    rect(2, gh+11, 50, gh+13);
                    gotoxy(4, gh+12);
                    switch(idedc){
                        case 1:
                            cout<<"New Name: ";
                            fflush(stdin);
                            cin.get(name[ided], 50);
                            break;
                        case 2:
                            cout<<"New Family: ";
                            fflush(stdin);
                            cin.get(family[ided], 50);
                            break;
                        case 3:
                            cout<<"New Phone: ";
                            fflush(stdin);
                            cin.get(phone[ided], 50);
                            break;
                        case 4:
                            cout<<"New Home: ";
                            fflush(stdin);
                            cin.get(home[ided], 50);
                            break;
                        default:
                            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
                            gotoxy(12, gh+15);
                            cout<<"      ";
                            delay(750);
                            srch4ed();
                            break;
                    }
                    done();
                }
            }
            else{
                gotoxy(3,14);
                cout<<"Sorry! I couldn't find "<<srch<<" in name list.";
                delay(1000);
                gotoxy(3, 15);
                srch4ed();
            }
            break;
        case 2:
            for(ifor=1;ifor<=ID;ifor++){
                k=strcmp(family[ifor],srch);
                if(k==0){
                    OD++;
                    cpysrch(OD, ifor, gh);
                    gh++;
                }
            }
            if(OD!=0){
                rect(2,14,60,gh);
                gotoxy(3, gh+1);
                cout<<"Now choose an ID: ";
                cin>>ided;
                if(ided>OD||ided<1){
                    gotoxy(4, gh+1);
                    cout<<"Sorry! There's no "<<ided<<" in IDs!";
                    gotoxy(4, gh+2);
                    cout<<"Wait until back to search again ...";
                    delay(3000);
                    srch4ed();
                }
                else{
                    rect(2, gh+4, 33, gh+10);
                    gotoxy(4, gh+5);
                    cout<<" You wanna edit 1) Name";
                    gotoxy(19, gh+6);
                    cout<<" 2) Family";
                    gotoxy(19, gh+7);
                    cout<<" 3) Phone";
                    gotoxy(19, gh+8);
                    cout<<" 4) Home";
                    gotoxy(4, gh+9);
                    cout<<" Choose: ";
                    int idedc;
                    cin>>idedc;
                    rect(2, gh+11, 50, gh+13);
                    gotoxy(4, gh+12);
                    switch(idedc){
                        case 1:
                            cout<<"New Name: ";
                            fflush(stdin);
                            cin.get(name[ided], 50);
                            break;
                        case 2:
                            cout<<"New Family: ";
                            fflush(stdin);
                            cin.get(family[ided], 50);
                            break;
                        case 3:
                            cout<<"New Phone: ";
                            fflush(stdin);
                            cin.get(phone[ided], 50);
                            break;
                        case 4:
                            cout<<"New Home: ";
                            fflush(stdin);
                            cin.get(home[ided], 50);
                            break;
                        default:
                            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
                            gotoxy(12, gh+15);
                            cout<<"      ";
                            delay(750);
                            srch4ed();
                            break;
                    }
                    done();
                }
            }
            else{
                gotoxy(3,14);
                cout<<"Sorry! I couldn't find "<<srch<<" in family list.";
                delay(1000);
                gotoxy(3, 15);
                srch4ed();
            }
            break;
        case 3:
            for(ifor=1;ifor<=ID;ifor++){
                k=strcmp(phone[ifor],srch);
                if(k==0){
                    OD++;
                    cpysrch(OD, ifor, gh);
                    gh++;
                }
            }
            if(OD!=0){
                rect(2,14,60,gh);
                gotoxy(3, gh+1);
                cout<<"Now choose an ID: ";
                cin>>ided;
                if(ided>OD||ided<1){
                    gotoxy(4, gh+1);
                    cout<<"Sorry! There's no "<<ided<<" in IDs!";
                    gotoxy(4, gh+2);
                    cout<<"Wait until back to search again ...";
                    delay(3000);
                    srch4ed();
                }
                else{
                    rect(2, gh+4, 33, gh+10);
                    gotoxy(4, gh+5);
                    cout<<" You wanna edit 1) Name";
                    gotoxy(19, gh+6);
                    cout<<" 2) Family";
                    gotoxy(19, gh+7);
                    cout<<" 3) Phone";
                    gotoxy(19, gh+8);
                    cout<<" 4) Home";
                    gotoxy(4, gh+9);
                    cout<<" Choose: ";
                    int idedc;
                    cin>>idedc;
                    rect(2, gh+11, 50, gh+13);
                    gotoxy(4, gh+12);
                    switch(idedc){
                        case 1:
                            cout<<"New Name: ";
                            fflush(stdin);
                            cin.get(name[ided], 50);
                            break;
                        case 2:
                            cout<<"New Family: ";
                            fflush(stdin);
                            cin.get(family[ided], 50);
                            break;
                        case 3:
                            cout<<"New Phone: ";
                            fflush(stdin);
                            cin.get(phone[ided], 50);
                            break;
                        case 4:
                            cout<<"New Home: ";
                            fflush(stdin);
                            cin.get(home[ided], 50);
                            break;
                        default:
                            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
                            gotoxy(12, gh+15);
                            cout<<"      ";
                            delay(750);
                            srch4ed();
                            break;
                    }
                    done();
                }
            }
            else{
                gotoxy(3,14);
                cout<<"Sorry! I couldn't find "<<srch<<" in phone number list.";
                delay(1000);
                gotoxy(3, 15);
                srch4ed();
            }
            break;
        case 4:
            for(ifor=1;ifor<=ID;ifor++){
                k=strcmp(home[ifor],srch);
                if(k==0){
                    OD++;
                    cpysrch(OD, ifor, gh);
                    gh++;
                }
            }
            if(OD!=0){
                rect(2,14,60,gh);
                gotoxy(3, gh+1);
                cout<<"Now choose an ID: ";
                cin>>ided;
                if(ided>OD||ided<1){
                    gotoxy(4, gh+1);
                    cout<<"Sorry! There's no "<<ided<<" in IDs!";
                    gotoxy(4, gh+2);
                    cout<<"Wait until back to search again ...";
                    delay(3000);
                    srch4ed();
                }
                else{
                    rect(2, gh+4, 33, gh+10);
                    gotoxy(4, gh+5);
                    cout<<" You wanna edit 1) Name";
                    gotoxy(19, gh+6);
                    cout<<" 2) Family";
                    gotoxy(19, gh+7);
                    cout<<" 3) Phone";
                    gotoxy(19, gh+8);
                    cout<<" 4) Home";
                    gotoxy(4, gh+9);
                    cout<<" Choose: ";
                    int idedc;
                    cin>>idedc;
                    rect(2, gh+11, 50, gh+13);
                    gotoxy(4, gh+12);
                    switch(idedc){
                        case 1:
                            cout<<"New Name: ";
                            fflush(stdin);
                            cin.get(name[ided], 50);
                            break;
                        case 2:
                            cout<<"New Family: ";
                            fflush(stdin);
                            cin.get(family[ided], 50);
                            break;
                        case 3:
                            cout<<"New Phone: ";
                            fflush(stdin);
                            cin.get(phone[ided], 50);
                            break;
                        case 4:
                            cout<<"New Home: ";
                            fflush(stdin);
                            cin.get(home[ided], 50);
                            break;
                        default:
                            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
                            gotoxy(12, gh+15);
                            cout<<"      ";
                            delay(750);
                            srch4ed();
                            break;
                    }
                    done();
                }
            }
            else{
                gotoxy(3,14);
                cout<<"Sorry! I couldn't find "<<srch<<" in home number list.";
                delay(1000);
                gotoxy(3, 15);
                srch4ed();
            }
            break;
        default:
            cout<<"Sorry! you have to choose between 1/2/3/4 ...";
            delay(750);
            search();
            break;
    }
}
void sort(){
    system("CLS");
    if(ID==0){
        rect(3,3,31,6);
        gotoxy(4,4);
        cout<<" Nothing is recorded yet!";
        gotoxy(4,5);
        cout<<" Back To main menu? Y/N ";
        cin>>yn;
        switch(yn){
            case 'Y':
            case 'y':
                fp();
                break;
            case 'N':
            case 'n':
                btfp();
                break;
        }
    }
    else{
        rect(2,2,48,10);
        gotoxy(4,3);
        cout<<"How do you want to sort your contacts?";
        gotoxy(4,4);
        cout<<"1) Name";
        gotoxy(4,5);
        cout<<"2) Family";
        gotoxy(4,6);
        cout<<"3) Phone";
        gotoxy(4,7);
        cout<<"4) Home";
        gotoxy(4,9);
        cout<<"Tell me: ";
        int srtn;
        cin>>srtn;
        switch(srtn){
            case 1:
                for(jfor=0;jfor<ID/2+1;jfor++)
                    for(ifor=1;ifor<ID;ifor++)
                        if(strcmp(name[ifor],name[ifor+1])>0)
                            sortcpy(ifor);
                a=ID+3;
                list(a);
                btmm(a+1);
                break;
            case 2:
                for(jfor=0;jfor<ID/2+1;jfor++)
                    for(ifor=1;ifor<ID;ifor++)
                        if(strcmp(family[ifor],family[ifor+1])>0)
                            sortcpy(ifor);
                a=ID+3;
                list(a);
                btmm(a+1);
                break;
            case 3:
                for(jfor=0;jfor<ID/2+1;jfor++)
                    for(ifor=1;ifor<ID;ifor++)
                        if(strcmp(phone[ifor],phone[ifor+1])>0)
                            sortcpy(ifor);
                a=ID+3;
                list(a);
                btmm(a+1);
                break;
            case 4:
                for(jfor=0;jfor<ID/2+1;jfor++)
                    for(ifor=1;ifor<ID;ifor++)
                        if(strcmp(home[ifor],home[ifor+1])>0)
                            sortcpy(ifor);
                a=ID+3;
                list(a);
                btmm(a+1);
                break;
            default:
                cout<<"Sorry! you have to choose between 1/2/3/4 ...";
                delay(750);
                sort();
                break;
        }
    }
}
void sortcpy(int ifor){
    strcpy(nameS[ifor],name[ifor]);
    strcpy(name[ifor],name[ifor+1]);
    strcpy(name[ifor+1],nameS[ifor]);
    strcpy(familyS[ifor],family[ifor]);
    strcpy(family[ifor],family[ifor+1]);
    strcpy(family[ifor+1],familyS[ifor]);
    strcpy(phoneS[ifor],phone[ifor]);
    strcpy(phone[ifor],phone[ifor+1]);
    strcpy(phone[ifor+1],phoneS[ifor]);
    strcpy(homeS[ifor],home[ifor]);
    strcpy(home[ifor],home[ifor+1]);
    strcpy(home[ifor+1],homeS[ifor]);
}
void search(){
    system("CLS");
    if(ID==0){
        rect(3,3,31,6);
        gotoxy(4,4);
        cout<<" Nothing is recorded yet!";
        btmm(7);
    }
    else{
        OD=0;
        rect(2,2,48,9);
        gotoxy(4,3);
        cout<<"How do you want to search in your contacts?";
        gotoxy(4,4);
        cout<<"1) Name";
        gotoxy(4,5);
        cout<<"2) Family";
        gotoxy(4,6);
        cout<<"3) Phone";
        gotoxy(4,7);
        cout<<"4) Home";
        gotoxy(4,8);
        cout<<"Tell me: ";
        int srn;
        cin>>srn;
        if(srn==1||srn==2||srn==3||srn==4){
            rect(2,10,43,13);
            gotoxy(4,11);
            cout<<"Let me know what are you looking for: ";
            gotoxy(4,12);
            fflush(stdin);
            cin.get(srch, 50);
            int k=0;
            OD=0;
            gh=15;
            switch(srn){
                case 1:
                    for(ifor=1;ifor<=ID;ifor++){
                        k=strcmp(name[ifor],srch);
                        if(k==0){
                            OD++;
                            cpysrch(OD, ifor, gh);
                            gh++;
                        }
                    }
                    if(OD!=0){
                        rect(2,14,60,gh);
                        gotoxy(3, gh+1);
                        searchagain();
                    }
                    else{
                        gotoxy(3,14);
                        cout<<"Sorry! I couldn't find "<<srch<<" in name list.";
                        delay(3000);
                        gotoxy(3, 15);
                        search();
                    }
                    break;
                case 2:
                    for(ifor=1;ifor<=ID;ifor++){
                        k=strcmp(family[ifor],srch);
                        if(k==0){
                            OD++;
                            cpysrch(OD, ifor, gh);
                            gh++;
                        }
                    }
                    if(OD!=0){
                        rect(2,14,60,gh);
                        gotoxy(3, gh+1);
                        searchagain();
                    }
                    else{
                        gotoxy(3,14);
                        cout<<"Sorry! I couldn't find "<<srch<<" in family list.";
                        delay(3000);
                        gotoxy(3, 15);
                        search();
                    }
                    break;
                case 3:
                    for(ifor=1;ifor<=ID;ifor++){
                        k=strcmp(phone[ifor],srch);
                        if(k==0){
                            OD++;
                            cpysrch(OD, ifor, gh);
                            gh++;
                        }
                    }
                    if(OD!=0){
                        rect(2,14,60,gh);
                        gotoxy(3, gh+1);
                        searchagain();
                    }
                    else{
                        gotoxy(3,14);
                        cout<<"Sorry! I couldn't find "<<srch<<" in phone number list.";
                        delay(3000);
                        gotoxy(3, 15);
                        search();
                    }
                    break;
                case 4:
                    for(ifor=1;ifor<=ID;ifor++){
                        k=strcmp(home[ifor],srch);
                        if(k==0){
                            OD++;
                            cpysrch(OD, ifor, gh);
                            gh++;
                        }
                    }
                    if(OD!=0){
                        rect(2,14,60,gh);
                        gotoxy(3, gh+1);
                        searchagain();
                    }
                    else{
                        gotoxy(3,14);
                        cout<<"Sorry! I couldn't find "<<srch<<" in home number list.";
                        delay(3000);
                        gotoxy(3, 15);
                        search();
                    }
                    break;
                default:
                    gotoxy(4,17);
                    cout<<"Sorry! you have to choose between 1/2/3/4 ...";
                    delay(1500);
                    search();
                    break;
            }
        }
        else{
            gotoxy(4,17);
            cout<<"Sorry! you have to choose between 1/2/3/4 ...";
            delay(1500);
            search();
        }
    }
}
void cpysrch(int o, int i, int gh){
    gotoxy(4,gh);
    cout<<o;
    gotoxy(7,gh);
    cout<<name[i];
    gotoxy(17,gh);
    cout<<family[i];
    gotoxy(32,gh);
    cout<<phone[i];
    gotoxy(47,gh);
    cout<<home[i];
    strcpy(nameS[o], name[i]);
    strcpy(familyS[o], family[i]);
    strcpy(phoneS[o], phone[i]);
    strcpy(homeS[o], home[i]);
}
void searchagain(){
    gotoxy(3, gh+3);
    cout<<"1) Search again ";
    gotoxy(3, gh+4);
    cout<<"2) Edit ";
    gotoxy(3, gh+5);
    cout<<"3) Delete ";
    gotoxy(3, gh+6);
    cout<<"4) Main menu ";
    int k=0;
    gotoxy(3,gh+7);
    cout<<"Which one? ";
    cin>>k;
    switch(k){
        case 1:
            search();
            break;
            //***********************case 2 edit
        case 2:
            gotoxy(3,gh+9);
            cout<<"Now choose an ID: ";
            cin>>ided;
            if(ided>OD||ided<1){
                gotoxy(4, gh+10);
                cout<<"Sorry! There's no "<<ided<<" in IDs!";
                gotoxy(4, gh+11);
                cout<<"Wait until back to search again ...";
                delay(3000);
                search();
            }
            else{
                rect(2, gh+11, 33, gh+17);
                gotoxy(4, gh+12);
                cout<<" You wanna edit 1) Name";
                gotoxy(19, gh+13);
                cout<<" 2) Family";
                gotoxy(19, gh+14);
                cout<<" 3) Phone";
                gotoxy(19, gh+15);
                cout<<" 4) Home";
                gotoxy(4, gh+16);
                cout<<" Choose: ";
                int idedc;
                cin>>idedc;
                rect(2, gh+18, 50, gh+20);
                gotoxy(4, gh+19);
                switch(idedc){
                    case 1:
                        cout<<"New Name: ";
                        fflush(stdin);
                        cin.get(name[ided], 50);
                        break;
                    case 2:
                        cout<<"New Family: ";
                        fflush(stdin);
                        cin.get(family[ided], 50);
                        break;
                    case 3:
                        cout<<"New Phone: ";
                        fflush(stdin);
                        cin.get(phone[ided], 50);
                        break;
                    case 4:
                        cout<<"New Home: ";
                        fflush(stdin);
                        cin.get(home[ided], 50);
                        break;
                    default:
                        cout<<"Sorry! You have to choose between 1/2/3/4 ...";
                        gotoxy(12, gh+22);
                        cout<<"      ";
                        delay(750);
                        idedt(ided, a);
                        break;
                }
                done();
            }
            //***********************case 3 del
        case 3:
            gotoxy(3,gh+9);
            cout<<"Now choose an ID: ";
            cin>>iddeln;
            if(iddeln>OD||iddeln<1){
                gotoxy(4, gh+10);
                cout<<"Sorry! There's no "<<iddeln<<" in IDs!";
                gotoxy(4, gh+11);
                cout<<"Wait until back to search again ...";
                delay(3000);
                search();
            }
            else{
                if(iddeln!=ID){
                    for(ifor=iddeln; ifor<ID; ifor++){
                        strcpy(name[ifor],name[ifor+1]);
                        strcpy(family[ifor],family[ifor+1]);
                        strcpy(home[ifor],home[ifor+1]);
                        strcpy(phone[ifor],phone[ifor+1]);
                    }
                    strcpy(name[ID], "");
                    strcpy(family[ID], "");
                    strcpy(home[ID], "");
                    strcpy(phone[ID], "");
                }
                ID--;
                a=ID+3;
                rect(10,a+10,20,a+12);
                gotoxy(11,a+11);
                cout<<"D O N E !";
                gotoxy(4,a+14);
                cout<<"Back To 1) main menu or 2) list? 1/2 ";
                int o;
                cin>>o;
                switch(o){
                    case 1:
                        fp();
                        break;
                    case 2:
                        list(a);
                        btmm(a+1);
                        break;
                }

            }
            break;
            //***********************case 4 home
        case 4:
            gotoxy(4,17);
            cout<<"Then we back to main menu ...";
            delay(750);
            fp();
            break;
        default:
            gotoxy(4,17);
            cout<<"Sorry! You have to choose between 1/2/3/4 ...";
            delay(750);
            searchagain();
            break;
    }
}
void list(int a){
    if(ID==0){
        system("CLS");
        rect(3,3,31,6);
        gotoxy(4,4);
        cout<<" Nothing is recorded yet!";
        gotoxy(4,5);
        cout<<" Back To main menu? Y/N ";
        cin>>yn;
        switch(yn){
            case 'Y':
            case 'y':
                fp();
                break;
            case 'N':
            case 'n':
                btfp();
                break;
        }
    }
    else{
        system("CLS");
        rect(0,0,60,2);

        gotoxy(7,0);
        cout<<c194;
        gotoxy(7,1);
        cout<<c179;
        gotoxy(7,2);
        cout<<c193;

        gotoxy(17,0);
        cout<<c194;
        gotoxy(17,1);
        cout<<c179;
        gotoxy(17,2);
        cout<<c193;

        gotoxy(32,0);
        cout<<c194;
        gotoxy(32,1);
        cout<<c179;
        gotoxy(32,2);
        cout<<c193;

        gotoxy(47,0);
        cout<<c194;
        gotoxy(47,1);
        cout<<c179;
        gotoxy(47,2);
        cout<<c193;

        gotoxy(2,1);
        cout<<" ID ";
        gotoxy(8,1);
        cout<<" Name";
        gotoxy(18,1);
        cout<<" Family";
        gotoxy(33,1);
        cout<<" Phone";
        gotoxy(48,1);
        cout<<" Home";
        rect(0,3,60,a+1);

        gotoxy(7,3);
        cout<<c194;
        gotoxy(7,a+1);
        cout<<c193;

        gotoxy(17,3);
        cout<<c194;
        gotoxy(17,a+1);
        cout<<c193;

        gotoxy(32,3);
        cout<<c194;
        gotoxy(32,a+1);
        cout<<c193;

        gotoxy(47,3);
        cout<<c194;
        gotoxy(47,a+1);
        cout<<c193;

        for(ifor=1;ifor<=ID;ifor++){
            a= ifor+3;
            gotoxy(3,a);
            cout<<ifor;
            gotoxy(9,a);
            cout<<name[ifor];
            gotoxy(19,a);
            cout<<family[ifor];
            gotoxy(34,a);
            cout<<phone[ifor];
            gotoxy(49,a);
            cout<<home[ifor];

            gotoxy(7,a);
            cout<<c179;
            gotoxy(17,a);
            cout<<c179;
            gotoxy(32,a);
            cout<<c179;
            gotoxy(47,a);
            cout<<c179;
        }
    }
}
void addview(){
    for(ifor=0;ifor<8;ifor++){
        gotoxy(0,ifor);
        cout<<c179;
        gotoxy(63,ifor);
        cout<<c179;
        gotoxy(10,ifor);
        cout<<c186;
    }
    for(jfor=0;jfor<9;jfor+=2){
        for(ifor=1;ifor<63;ifor++){
            gotoxy(ifor,jfor);
            cout<<c196;
            gotoxy(0,jfor);
            cout<<c195;
            gotoxy(63,jfor);
            cout<<c180;
            if(jfor!=8&&jfor!=0){
                gotoxy(10,jfor);
                cout<<c215;
            }
        }
        if(jfor!=10){
            gotoxy(2, jfor+1);
            switch(jfor+1){
                case 1: cout<<"Name";
                    break;
                case 3: cout<<"Family";
                    break;
                case 5: cout<<"Phone";
                    break;
                case 7: cout<<"Home";
                    break;
            }
        }
    }
    gotoxy(0,0);
    cout<<c218;
    gotoxy(63,0);
    cout<<c191;
    gotoxy(63,8);
    cout<<c217;
    gotoxy(0,8);
    cout<<c192;
    gotoxy(10,0);
    cout<<c210;
    gotoxy(10,8);
    cout<<c208;
}
void add(){
    system("CLS");
    ID++;
    a=ID+4;
    addview();
    fflush(stdin);
    get(12, 1, ID);
    rusure();
}
void rusure(){
    gotoxy(17, 18);
    cout<<"                                                ";
    rect(15,15,39,17);
    gotoxy(17,16);
    cout<<"Are you sure? Y/N   ";
    gotoxy(35,16);
    cin>>yn;
    switch(yn){
        case 'Y':
        case 'y':
            done();
            break;
        case 'N':
        case 'n':
            get(12, 1, ID);
            break;
        default:
            gotoxy(17, 18);
            cout<<"You have to choose between Y an N, Try again ...";
            delay(500);
            rusure();
            break;
    }
}
void fp(){
    system("CLS");
    system("color 1b");
    gotoxy(1, 11);
    cout<<"                                                 ";
    for(ifor=0;ifor<10;ifor++){
        gotoxy(0,ifor);
        cout<<c179;
        gotoxy(22,ifor);
        cout<<c179;
    }
    for(ifor=0;ifor<22;ifor++){
        gotoxy(ifor,0);
        cout<<c196;
        gotoxy(ifor,10);
        cout<<c196;
    }
    gotoxy(0,0);
    cout<<c218;
    gotoxy(22,0);
    cout<<c191;
    gotoxy(22,10);
    cout<<c217;
    gotoxy(0,10);
    cout<<c192;
    gotoxy(4,0);
    cout<<c210;
    gotoxy(0,8);
    cout<<c198;
    for(ifor=1;ifor<22;ifor++){
        gotoxy(ifor,8);
        cout<<c205;
    }
    gotoxy(22,8);
    cout<<c181;
    gotoxy(4,8);
    cout<<c202;
    gotoxy(1,1);
    cout<<" 1 "<<c186<<" Add New";
    gotoxy(1,2);
    cout<<" 2 "<<c186<<" List";
    gotoxy(1,3);
    cout<<" 3 "<<c186<<" Search";
    gotoxy(1,4);
    cout<<" 4 "<<c186<<" Edit";
    gotoxy(1,5);
    cout<<" 5 "<<c186<<" Sort";
    gotoxy(1,6);
    cout<<" 6 "<<c186<<" Delete";
    gotoxy(1,7);
    cout<<" 9 "<<c186<<" Exit";
    gotoxy(1,9);
    cout<<" Press Selection: ";
    int fpps;
    cin>>fpps;
    switch(fpps){
        case 1:
            system("color 0b");
            add();
            break;
        case 2:
            system("color 0d");
            a=ID+3;
            list(a);
            btmm(a+1);
            break;
        case 3:
            system("color 0e");
            search();
            break;
        case 4:
            system("color 6f");
            edit();
            break;
        case 5:
            system("color 30");
            sort();
            break;
        case 6:
            system("color 3f");
            del();
            break;
        case 9: exit(0);
            break;
        default:
            gotoxy(1, 11);
            cout<<"You have to choose a number which is in the menu!";
            delay(2000);
            fp();
            break;
    }
}
//
