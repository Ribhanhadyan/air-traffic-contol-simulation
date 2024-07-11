#include<iostream>
#include<windows.h>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#define MAXAtrian 6
#define MAXParkir 4
#define MAXTerbang 5
using namespace std;
// struct untuk database
struct pesawat{
    string namaPesawat;
    string kodePesawat;
    string jenisPesawat;
};
struct user{
    string nama;
    time_t lamaSimulasi;
    int score;
};
struct database{
    pesawat dataPesawat;
    user dataUser;
};
typedef database dtbs[10];
//struct untuk Mencatat nama user, score dan waktu
struct doubly{
    user dataUser;
    doubly* next;
    doubly* prev;
};
typedef doubly* pointerDoubly;
typedef pointerDoubly listDoubly;

//struct multilist untuk parkiran sementara dan antrian penerbangan
struct anak{
    pesawat dataPesawat;
    anak* nextAnak;
};
struct induk{
    string jenis;
    induk* next;
    induk* prev;
    anak* firstAnak;
};
typedef anak* pointerAnak;
typedef induk* pointerInduk;
typedef pointerInduk listInduk;

//struct Antrian untuk pesawat yang ingin mendarat
struct elemenQueue{
    pesawat dataPesawat;
    elemenQueue* next;
};
typedef elemenQueue* pointerQueue;
struct Queue{
    pointerQueue head;
    pointerQueue tail;
};
typedef Queue queue;

//buat Database
void createDatabase(dtbs& dt){
    dt[1].dataPesawat.namaPesawat="Lion Air";
    dt[2].dataPesawat.namaPesawat="Emirates";
    dt[3].dataPesawat.namaPesawat="Garuda";
    dt[4].dataPesawat.namaPesawat="Citilink";
    dt[5].dataPesawat.namaPesawat="Lufthansa";

    dt[1].dataPesawat.kodePesawat="JT768";
    dt[2].dataPesawat.kodePesawat="EK385";
    dt[3].dataPesawat.kodePesawat="GA600";
    dt[4].dataPesawat.kodePesawat="QG212";
    dt[5].dataPesawat.kodePesawat="LH173";

    dt[1].dataPesawat.jenisPesawat="jenis 1";
    dt[2].dataPesawat.jenisPesawat="jenis 2";
    dt[3].dataPesawat.jenisPesawat="jenis 3";
    dt[4].dataPesawat.jenisPesawat="jenis 4";
    dt[5].dataPesawat.jenisPesawat="jenis 5";

}

void Logo(){

cout << setw(62)<<" " <<" ¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"  ¶  ¶¶¶" << endl;
cout << setw(62)<<" " <<"  ¶¶   ¶¶¶" << endl;
cout << setw(62)<<" " <<"   ¶¶    ¶¶" << endl;
cout << setw(62)<<" " <<"    ¶¶     ¶¶" << endl;
cout << setw(62)<<" " <<"      ¶¶    ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"       ¶¶                               ¶¶" << endl;
cout << setw(62)<<" " <<"         ¶¶                             ¶¶¶" << endl;
cout << setw(62)<<" " <<"          ¶                       ¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"         ¶                   ¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"         ¶              ¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"         ¶           ¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"         ¶            ¶¶" << endl;
cout << setw(62)<<" " <<"        ¶¶       ¶¶¶   ¶¶¶" << endl;
cout << setw(62)<<" " <<"        ¶        ¶¶¶¶    ¶¶" << endl;
cout << setw(62)<<" " <<"        ¶       ¶¶  ¶¶¶   ¶¶¶" << endl;
cout << setw(62)<<" " <<"        ¶      ¶¶     ¶¶    ¶¶" << endl;
cout << setw(62)<<" " <<"       ¶¶     ¶¶       ¶¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"       ¶¶     ¶¶         ¶¶¶   ¶        ¶¶" << endl;
cout << setw(62)<<" " <<"       ¶     ¶¶           ¶¶¶            ¶¶¶" << endl;
cout << setw(62)<<" " <<"       ¶    ¶¶             ¶¶     ¶¶¶¶¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"      ¶¶    ¶              ¶¶    ¶¶¶¶" << endl;
cout << setw(62)<<" " <<"      ¶¶   ¶¶             ¶¶    ¶¶¶¶¶" << endl;
cout << setw(62)<<" " <<"      ¶   ¶¶              ¶¶   ¶¶ ¶¶¶¶" << endl;
cout << setw(62)<<" " <<"      ¶¶ ¶¶               ¶¶  ¶¶" << endl;
cout << setw(62)<<" " <<"       ¶¶¶                 ¶¶ ¶¶" << endl;
cout << setw(62)<<" " <<"                            ¶¶¶" << endl;
cout << setw(62)<<" " <<"                             ¶" << endl;

}
void judul(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   __   __  ____    ____  ____   __   ____  ____  __  ___     ___  __   __ _  ____  ____   __   __      "              << endl;
    cout << "\t\t\t\t  / _\\ (  )(  _ \\  (_  _)(  _ \\ / _\\ (  __)(  __)(  )/ __)   / __)/  \\ (  ( \\(_  _)(  _ \\ /  \\ (  )     "      << endl;
    cout << "\t\t\t\t /    \\ )(  )   /    )(   )   //    \\ ) _)  ) _)  )(( (__   ( (__(  O )/    /  )(   )   /(  O )/ (_/\\   "           << endl;
    cout << "\t\t\t\t \\_/\\_/(__)(__\\_)   (__) (__\\_)\\_/\\_/(__)  (__)  (__)\\___)   \\___)\\__/ \\_)__) (__) (__\\_) \\__/ \\____/   " << endl;
    cout << "\t\t\t\t\t\t       ____  __  _  _  _  _  __     __  ____  __  __   __ _ "  << endl;
    cout << "\t\t\t\t\t\t      / ___)(  )( \\/ )/ )( \\(  )   / _\\(_  _)(  )/  \\ (  ( \\ " << endl;
    cout << "\t\t\t\t\t\t      \\___ \\ )( / \\/ \\) \\/ (/ (_/\\/    \\ )(   )((  O )/    /"  << endl;
    cout << "\t\t\t\t\t\t      (____/(__)\\_)(_/\\____/\\____/\\_/\\_/(__) (__)\\__/ \\_)__)"  << endl;
}

void art1(){
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << setw(40)<<" " <<"                           (   )"      << endl;
cout << setw(40)<<" " <<"                          (    )"      << endl;
cout << setw(40)<<" " <<"                           (    )"      << endl;
cout << setw(40)<<" " <<"                          (    )"      << endl;
cout << setw(40)<<" " <<"                            )  )"      << endl;
cout << setw(40)<<" " <<"                           (  (                  /\\"      << endl;
cout << setw(40)<<" " <<"                            (_)                 /  \\  /\\"      << endl;
cout << setw(40)<<" " <<"                    ________[_]________      /\\/    \\/  \\"      << endl;
cout << setw(40)<<" " <<"           /\\      /\\        ______    \\    /   /\\/\\  /\\/\\"      << endl;
cout << setw(40)<<" " <<"          /  \\    //_\\       \\    /\\    \\  /\\/\\/    \\/    \\"      << endl;
cout << setw(40)<<" " <<"   /\\    / /\\/\\  //___\\       \\__/  \\    \\/"      << endl;
cout << setw(40)<<" " <<"  /  \\  /\\/    \\//_____\\       \\ |[]|     \\"      << endl;
cout << setw(40)<<" " <<" /\\/\\/\\/       //_______\\       \\|__|      \\"      << endl;
cout << setw(40)<<" " <<"/      \\      /XXXXXXXXXX\\                  \\"      << endl;
cout << setw(40)<<" " <<"        \\    /_I_II  I__I_\\__________________\\"      << endl;
cout << setw(40)<<" " <<"               I_I|  I__I_____[]_|_[]_____I"      << endl;
cout << setw(40)<<" " <<"               I_II  I__I_____[]_|_[]_____I"      << endl;
cout << setw(40)<<" " <<"               I II__I  I     XXXXXXX     I"      << endl;
cout << setw(40)<<" " <<"            ~~~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~"      << endl;
}

void art2(){
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << setw(62)<<" " <<"      ___                            ___"      << endl;
cout << setw(62)<<" " <<" ||  |   ___         ___        ||  |"      << endl;
cout << setw(62)<<" " <<" || _|__/  _\\_______/  _\\_______|| _|"      << endl;
cout << setw(62)<<" " <<" ||(___(  (________(  (_________||((_)"      << endl;
cout << setw(62)<<" " <<" ||  |  \\___/       \\___/       ||  |"      << endl;
cout << setw(62)<<" " <<" ||  |         ___              ||  |"      << endl;
cout << setw(62)<<" " <<" || _|________/  _\\_____________|| _|"      << endl;
cout << setw(62)<<" " <<"||(_________(  (_______________||((_)"      << endl;
cout << setw(62)<<" " <<"||  |        \\___/             ||  |"      << endl;
cout << setw(62)<<" " <<"||  |                          ||  |"      << endl;
cout << setw(62)<<" " <<"||  |                          ||  | "      << endl;
cout << setw(62)<<" " <<"||  |                          ||  |"      << endl;
}
void art3(){
cout << endl;
cout << setw(55)<<" " <<"                                                    __________"      << endl;
cout << setw(55)<<" " <<"             _,---.                          _..--'/          \\"      << endl;
cout << setw(55)<<" " <<"          ,-'      )                    _,-,'     /            \\"      << endl;
cout << setw(55)<<" " <<"         (          )               _,-'  /      /              \\"      << endl;
cout << setw(55)<<" " <<"          `-.__, -'             _,-/     /     _/ ,------------. \\"      << endl;
cout << setw(55)<<" " <<"     ,--._,---.             _,-'  /     /_,--'' | |    Hier    | |"      << endl;
cout << setw(55)<<" " <<"   _(_,-'      )        _,-'/    /_, - '|       | |   koennte  | |"      << endl;
cout << setw(55)<<" " <<" ,'  (        )      ,'/   /_, -'|      ||_  -  | |    IRRE    | |"      << endl;
cout << setw(55)<<" " <<"(     `--._,-'    _,' /_,-'|     ||_  - |       | |   Werbung  | |"      << endl;
cout << setw(55)<<" " <<" `--.__,-'     _,'/,-'|  - ||_ - |      ||_  -  | |   stehen!  | |"      << endl;
cout << setw(55)<<" " <<"            _,'/,'|  - ___ |     ||_  - |       | `------------' |"      << endl;
cout << setw(55)<<" " <<"        _ ,' |_' -|- _(   ) |_   |      ||_  -  |                |"      << endl;
cout << setw(55)<<" " <<"       ( ): ((`) -| (. `-/ )   - ||_  - |       |                |"      << endl;
cout << setw(55)<<" " <<"      ` | '(-.,') '( _\\`/-') _ - |      | _   - |                |"      << endl;
cout << setw(55)<<" " <<"        `   (_.) -(_._ \\|,-_)    ||_  - |       |                |"      << endl;
cout << setw(55)<<" " <<" .        `. || ` | (_\\||_)  _ - |      ||_  -  |                |"      << endl;
cout << setw(55)<<" " <<"             `.    ` . ||  |   - ||_  - |       |                |"      << endl;
cout << setw(55)<<" " <<"                `.     ||-.|  :  |  _   ||_   - |     __________ |"      << endl;
cout << setw(55)<<" " <<"                   `.  ||    ` -.|   |  |   _   |    | _Doener_ |`'--.._"      << endl;
cout << setw(55)<<" " <<"                      `.           ` - .|  | |  |    || ()._o  ||   __ |"      << endl;
cout << setw(55)<<" " <<"\\           `            `.   `           ` -' .|____|`'---.|>_||  |. ||"      << endl;
cout << setw(55)<<" " <<"                            `.                         `' -- .._|__|__||"      << endl;
cout << setw(55)<<" " <<"                      ,----.---------- .                            .-_."      << endl;
cout << setw(55)<<" " <<"   _                 |.`.,' `.           `.                         || |"      << endl;
cout << setw(55)<<" " <<"    \\                \\ _|`. / `.            `.                      \\|_o"      << endl;
cout << setw(55)<<" " <<"     \\                | \\  `.   \\.-----_-----.\\     `"      << endl;
cout << setw(55)<<" " <<"      \\               `.|.`| `./ \\\\  c__)___/ \\\\             ."      << endl;
cout << setw(55)<<" " <<"       \\        `         `.   `. \\\\____\\___)__\\\\"      << endl;
cout << setw(55)<<" " <<"                            `. _ `.\\`____________\\"      << endl;
cout << setw(55)<<" " <<"                              | \\  |_|   ____   |_|"      << endl;
cout << setw(55)<<" " <<"          _                   `.|\\ |#|__[jrei]__|_|`."      << endl;
cout << setw(55)<<" " <<"           \\                      `================'  `."      << endl;

}
void art4(){
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << setw(45)<<" " <<"                                    .---."      << endl;
cout << setw(45)<<" " <<"                                    |[X]|"      << endl;
cout << setw(45)<<" " <<"                             _.==._.''''''.___n__"<< endl;
cout << setw(45)<<" " <<"                            d __ ___.-''-. _____b"      << endl;
cout << setw(45)<<" " <<"                            |[__]  /."""".\\ _       |"      << endl;
cout << setw(45)<<" " <<"                            |     // /""\\ \\\\_)    |"      << endl;
cout << setw(45)<<" " <<"                            |     \\\\ \\__/ //    |"      << endl;
cout << setw(45)<<" " <<"                            |pentax\\`.__.'/     |"      << endl;
cout << setw(45)<<" " <<"                            \\=======`-..-'======/"      << endl;
cout << setw(45)<<" " <<"                             `-----------------'   hjw"      << endl;
}
void art5(){
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << setw(50)<<" " <<"                                                        \\  /"      << endl;
cout << setw(50)<<" " <<"                  __                                     \\/"      << endl;
cout << setw(50)<<" " <<"     _   ---===##===---_________________________--------------  _"      << endl;
cout << setw(50)<<" " <<"    [ ~~~=================###=###=###=###=###=================~~ ]"      << endl;
cout << setw(50)<<" " <<"    /  ||  | |~\\  ;;;;     PKP    ;;;  ET22-689  ;;;;  /~| |  ||  \\"      << endl;
cout << setw(50)<<" " <<"   /___||__| |  \\ ;;;;            [_]            ;;;; /  | |__||___\\"      << endl;
cout << setw(50)<<" " <<"   [\\        |__| ;;;;  ;;;; ;;;; ;;; ;;;; ;;;;  ;;;; |__|        /]"      << endl;
cout << setw(50)<<" " <<"  (=|    ____[-]_______________________________________[-]____Kraq|=)"      << endl;
cout << setw(50)<<" " <<"  /  /___/|#(__)=o########o=(__)#||___|#(__)=o#########o=(__)#|\\___\\"      << endl;
cout << setw(50)<<" " <<" _________-=\\__/=--=\\__/=--=\\__/=-_____-=\\__/=--=\\__/=--=\\__/=-______"      << endl;
}
//fungsi Random
int random1(){
    return (rand()%2)*(rand()%2)*(rand()%2);
}

int random2(){
    return (rand()%2)*(rand()%2);
}
int random3(){
    return (rand()%2);
}

int random4(){
    return 1+((rand()*rand()+rand()))%5;
}


//Queue
void createQueue(Queue& Q){
    Q.head=NULL;
    Q.tail=NULL;
}
bool isFullQueue(Queue Q){
    int count=0;
    Queue hitung;
    hitung.head=Q.head;
    while(hitung.head!=NULL){
        hitung.head=hitung.head->next;
        count++;
    }
    return count==MAXAtrian;
}
void createElementQueue(pointerQueue& pBaruQueue,dtbs dt,int i){
    pBaruQueue=new elemenQueue;
    pBaruQueue->dataPesawat.kodePesawat=dt[i].dataPesawat.kodePesawat;
    pBaruQueue->dataPesawat.namaPesawat=dt[i].dataPesawat.namaPesawat;
    pBaruQueue->dataPesawat.jenisPesawat=dt[i].dataPesawat.jenisPesawat;
    pBaruQueue->next=NULL;
}
void insertQueue(Queue& Q,pointerQueue pBaruQueue){
    if(Q.head==NULL){
        Q.head=pBaruQueue;
        Q.tail=pBaruQueue;
    }else{
        Q.tail->next=pBaruQueue;
        Q.tail=Q.tail->next;
    }
}
void deleteQueue(Queue& Q){
    pointerQueue pHapus;
    if(Q.head==NULL&&Q.tail==NULL){
        pHapus=NULL;
    }else if(Q.head->next==NULL){
        pHapus=Q.head;
        Q.head=NULL;
        Q.tail=NULL;
    }else{
        pHapus=Q.head;
        Q.head=Q.head->next;
        pHapus->next=NULL;
    }
}

void tambahQueue(Queue& Q,pointerQueue pBaruQueue,dtbs dt,int Random1,int& gameOver){
    if(Random1==1){
        if(isFullQueue(Q)==1){
            gameOver=1;
        }else{
            createElementQueue(pBaruQueue,dt,random4());
            insertQueue(Q,pBaruQueue);
        }
    }
}

//hitungan Mundur
void hitunganMundurMendarat(){
    for(int i=3;i>0;i--){
        system("cls");
        Logo();
        cout << setiosflags(ios::left)<<setw(65) << " ";
        cout << "Pesawat Akan Mendarat dalam Hitungan : " << i;
        Sleep(1);
        system("cls");
    }
}

void hitunganMundurTerbang(){
    for(int i=3;i>0;i--){
        system("cls");
        Logo();
        cout << setiosflags(ios::left)<<setw(65) << " ";
        cout << "Pesawat Akan Terbang dalam Hitungan : " << i;
        Sleep(1);
        system("cls");
    }
}


//Multilist
void createListInduk(listInduk& first){
    first=NULL;
}
void createInduk(pointerInduk& pBaru,dtbs dt,int i){
    pBaru = new induk;
    if(i==1){
        pBaru->jenis="parkiran";
    }else if(i==2){
        pBaru->jenis="jenis 1";
    }else if(i==3){
        pBaru->jenis="jenis 2";
    }else if(i==4){
        pBaru->jenis="jenis 3";
    }else if(i==5){
        pBaru->jenis="jenis 4";
    }else if(i==6){
        pBaru->jenis="jenis 5";
    }
    pBaru->firstAnak=NULL;
    pBaru->next=NULL;
    pBaru->prev=NULL;
}
void insertLastInduk(listInduk& first,pointerInduk pBaru){
    pointerInduk last;
    if(first==NULL){
        first=pBaru;
    }else{
        last=first;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
        pBaru->prev=last;
    }
}
void linearSearchInduk(listInduk first,pointerInduk& pCari,string key){
    pCari=first;
    int found=0;
    while(pCari!=NULL&&found==0){
        if(pCari->jenis==key){
            found=1;
        }else{
            pCari=pCari->next;
        }
    }
}
void createAnakParkiran(Queue Q,pointerAnak& pBaruAnak){
    pBaruAnak=new anak;
    pBaruAnak->dataPesawat.kodePesawat=Q.head->dataPesawat.kodePesawat;
    pBaruAnak->dataPesawat.namaPesawat=Q.head->dataPesawat.namaPesawat;
    pBaruAnak->dataPesawat.jenisPesawat=Q.head->dataPesawat.jenisPesawat;
    pBaruAnak->nextAnak=NULL;
}
void createAnakTerbang(listInduk first,pointerAnak& pBaruAnak){
    if(first->firstAnak!=NULL){
        pBaruAnak=new anak;
        pBaruAnak->dataPesawat.namaPesawat=first->firstAnak->dataPesawat.namaPesawat;
        pBaruAnak->dataPesawat.kodePesawat=first->firstAnak->dataPesawat.kodePesawat;
        pBaruAnak->dataPesawat.jenisPesawat=first->firstAnak->dataPesawat.jenisPesawat;
        pBaruAnak->nextAnak=NULL;
    }
}
void insertLastAnak(pointerInduk& pInduk,pointerAnak pBaruAnak){
    pointerAnak last;
    if(pInduk->firstAnak==NULL){
        pInduk->firstAnak=pBaruAnak;
    }else{
        last=pInduk->firstAnak;
        while(last->nextAnak!=NULL){
            last=last->nextAnak;
        }
        last->nextAnak=pBaruAnak;
    }
}

void deleteFirstAnak(pointerInduk& pInduk){
    if(pInduk->firstAnak!=NULL){
        pInduk->firstAnak=pInduk->firstAnak->nextAnak;
    }
}

bool isFullAnak(pointerInduk pInduk,int MAX){
    int count=0;
    pointerAnak hitung;
    hitung=pInduk->firstAnak;
    while(hitung!=NULL){
        hitung=hitung->nextAnak;
        count++;
    }
    return count==MAX;
}

// Doubly
void createlistDoubly(listDoubly& first){
    first=NULL;
}
void createElementDoubly(pointerDoubly& pBaru,dtbs dt,int i){
    pBaru=new doubly;
    pBaru->dataUser.nama=dt[i].dataUser.nama;
    pBaru->dataUser.lamaSimulasi=dt[i].dataUser.lamaSimulasi;
    pBaru->dataUser.score=dt[i].dataUser.score;
    pBaru->next=NULL;
    pBaru->prev=NULL;
}
void insertFirstDoubly(listDoubly& first,pointerDoubly pBaru){
    if(first==NULL){
        first=pBaru;
    }else{
        pBaru->next=first;
        first->prev=pBaru;
        first=pBaru;
    }
}
void tranversalParsial1(pointerAnak bantu){
    cout << setiosflags(ios::left)<<setw(12) << bantu->dataPesawat.namaPesawat;
    cout << setiosflags(ios::left)<<setw(1)  << ":";
}

void tranversalParsial2(pointerAnak bantu){
    cout << setiosflags(ios::left)<<setw(12) << " ";
    cout << setiosflags(ios::left)<<setw(1)  << ":";
}
void traversal(Queue Q,listInduk firstInduk){
    Queue bantu1;
    pointerAnak bantu2,bantu3,bantu4,bantu5,bantu6,bantu7;
    bantu1=Q;
    bantu2=firstInduk->firstAnak;
    bantu3=firstInduk->next->firstAnak;
    bantu4=firstInduk->next->next->firstAnak;
    bantu5=firstInduk->next->next->next->firstAnak;
    bantu6=firstInduk->next->next->next->next->firstAnak;
    bantu7=firstInduk->next->next->next->next->next->firstAnak;
    int no=0;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << ":    Antrian Izin Mendarat (6 MAX)   :    :             Parkiran Sementara (4 MAX)            ::                       Antrian Terbang (5 MAX)                  :" << endl;
    cout << ": No Nama Pesawat       Kode Pesawat :    : No Nama Pesawat       Kode Pesawat  Jenis Pesawat ::   Jenis 1  :   Jenis 2  :   Jenis 3  :   Jenis 4  :   Jenis 5  :" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    while(bantu1.head!=NULL||bantu2!=NULL||bantu3!=NULL||bantu4!=NULL||bantu5!=NULL||bantu6!=NULL||bantu7!=NULL){
        no++;
        if(bantu1.head!=NULL){
            cout << setiosflags(ios::left)<<setw(2)  << ":";
            cout << setiosflags(ios::left)<<setw(3)  << no;
            cout << setiosflags(ios::left)<<setw(19) << bantu1.head->dataPesawat.namaPesawat;
            cout << setiosflags(ios::left)<<setw(13) << bantu1.head->dataPesawat.kodePesawat;
            cout << setiosflags(ios::left)<<setw(5)  << ":";
            bantu1.head=bantu1.head->next;
            if(bantu2!=NULL){
                cout << setiosflags(ios::left)<<setw(2)  << ":";
                cout << setiosflags(ios::left)<<setw(3)  << no;
                cout << setiosflags(ios::left)<<setw(19) << bantu2->dataPesawat.namaPesawat;
                cout << setiosflags(ios::left)<<setw(14) << bantu2->dataPesawat.kodePesawat;
                cout << setiosflags(ios::left)<<setw(14) << bantu2->dataPesawat.jenisPesawat;
                cout << setiosflags(ios::left)<<setw(1)  << ":";
                bantu2=bantu2->nextAnak;
                if(bantu3!=NULL){
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << bantu3->dataPesawat.namaPesawat;
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    bantu3=bantu3->nextAnak;
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }else{ //sudah
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << " ";
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
            }else{ //sudah
                cout << setiosflags(ios::left)<<setw(52)  << ":";
                cout << setiosflags(ios::left)<<setw(1)  << ":";
                if(bantu3!=NULL){
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << bantu3->dataPesawat.namaPesawat;
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    bantu3=bantu3->nextAnak;
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }else{
                    cout << setiosflags(ios::left)<<setw(1) << ":";
                    cout << setiosflags(ios::left)<<setw(12) << " ";
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }else{
            cout << setiosflags(ios::left)<<setw(37)  << ":";
            cout << setiosflags(ios::left)<<setw(5)  << ":";
            if(bantu2!=NULL){
                cout << setiosflags(ios::left)<<setw(2)  << ":";
                cout << setiosflags(ios::left)<<setw(3)  << no;
                cout << setiosflags(ios::left)<<setw(19) << bantu2->dataPesawat.namaPesawat;
                cout << setiosflags(ios::left)<<setw(14) << bantu2->dataPesawat.kodePesawat;
                cout << setiosflags(ios::left)<<setw(14) << bantu2->dataPesawat.jenisPesawat;
                cout << setiosflags(ios::left)<<setw(1)  << ":";
                bantu2=bantu2->nextAnak;
                if(bantu3!=NULL){
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << bantu3->dataPesawat.namaPesawat;
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    bantu3=bantu3->nextAnak;
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }else{ //sudah
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << " ";
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
            }else{ //sudah
                cout << setiosflags(ios::left)<<setw(52)  << ":";
                cout << setiosflags(ios::left)<<setw(1)  << ":";
                if(bantu3!=NULL){
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    cout << setiosflags(ios::left)<<setw(12) << bantu3->dataPesawat.namaPesawat;
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    bantu3=bantu3->nextAnak;
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }else{
                    cout << setiosflags(ios::left)<<setw(1) << ":";
                    cout << setiosflags(ios::left)<<setw(12) << " ";
                    cout << setiosflags(ios::left)<<setw(1)  << ":";
                    if(bantu4!=NULL){
                        tranversalParsial1(bantu4);
                        bantu4=bantu4->nextAnak;
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }else{ //sudah
                        tranversalParsial2(bantu4);
                        if(bantu5!=NULL){
                            tranversalParsial1(bantu5);
                            bantu5=bantu5->nextAnak;
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }else{ //sudah
                            tranversalParsial2(bantu5);
                            if(bantu6!=NULL){
                                tranversalParsial1(bantu6);
                                bantu6=bantu6->nextAnak;
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }else{ //sudah
                                tranversalParsial2(bantu6);
                                if(bantu7!=NULL){
                                    tranversalParsial1(bantu7);
                                    cout<<endl;
                                    bantu7=bantu7->nextAnak;
                                }else{
                                    tranversalParsial2(bantu7);
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

void traversalScore(int score){
    cout << "Score Anda : " << score<< endl;
}


void berhasil(Queue Q,listInduk first,int& Berhasil,int& gameOver){
    pointerInduk bantu;
    bantu=first;
    if(Q.head==NULL){
        if(bantu->firstAnak==NULL){
            bantu=bantu->next;
            if(bantu->firstAnak==NULL){
                bantu=bantu->next;
                if(bantu->firstAnak==NULL){
                    bantu=bantu->next;
                    if(bantu->firstAnak==NULL){
                        bantu=bantu->next;
                        if(bantu->firstAnak==NULL){
                            bantu=bantu->next;
                            if(bantu->firstAnak==NULL){
                                gameOver=1;
                                Berhasil=1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void traversalUser(listDoubly first){
    cout << endl << endl;
    cout << setw(60)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << setw(60)<<" "<<":::::::::::::::::PAPAN SCORE USER::::::::::::::::" << endl;
    cout << setw(60)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << setw(60)<<" "<<":: NAMA USER           SCORE     WAKTU-(detik) ::" << endl;
    cout << setw(60)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    pointerDoubly bantu;
    bantu=first;
    while(bantu!=NULL){
        cout << setw(60)<<" ";
        cout << setiosflags(ios::left) << setw(3) << "::";
        cout << setiosflags(ios::left) << setw(20) << bantu->dataUser.nama;
        cout << setiosflags(ios::left) << setw(10) << bantu->dataUser.score;
        cout << setiosflags(ios::left) << setw(14) << bantu->dataUser.lamaSimulasi;
        cout << setiosflags(ios::left) << setw(1) << "::"<<endl;
        bantu=bantu->next;
    }
    if(first==NULL){
        cout << setw(60)<<" ";
        cout << setiosflags(ios::left) << setw(2) << "::";
        cout << setiosflags(ios::left) <<setw(45)<<"    BELUM ADA USER YANG MEMAINKAN SIMULASI";
        cout << setiosflags(ios::left) << setw(2) << "::"<<endl;
    }
    cout << setw(60)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

void menu1(){
cout << "\n\n\n"<< setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::           MENU             ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    1. Mulai Simulasi       ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    2. Lihat Score User     ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    3. Tema                 ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    4. Akhiri Program       ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}



void menu2(){
cout << "\n"<< setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::           MENU             ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    1. Light Mode           ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    2. Dark Mode            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    3. Custom               ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    4. Kembali              ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}
void menu2Anak(){
cout << "\n"<< setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::           MENU             ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    Warna Tulisan:          ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    1. Black                ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    2. Blue                 ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    3. Green                ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    Warna Background:       ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    1. Light Blue           ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    2. Light Aqua           ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::    3. Light Yellow         ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::                            ::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(50)<<" "<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}

void menu3(){
cout << "\n"<< setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                        MENU                         ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                1. Izinkan Mendarat                  ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                2. Izinkan Terbang                   ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                3. Masukan ke Antrian                ::" <<endl;
cout << setw(55)<<" "<<"::                   Penerbangan                       ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                4. Menyerah                          ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;

}

void menu4(){
cout << "\n"<< setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::          Jenis Apa yang diIzinkan terbang           ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                    1. Jenis 1                       ::" <<endl;
cout << setw(55)<<" "<<"::                    2. Jenis 2                       ::" <<endl;
cout << setw(55)<<" "<<"::                    3. Jenis 3                       ::" <<endl;
cout << setw(55)<<" "<<"::                    4. Jenis 4                       ::" <<endl;
cout << setw(55)<<" "<<"::                    5. Jenis 5                       ::" <<endl;
cout << setw(55)<<" "<<"::                    6. Kembali                       ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}

void menu5(){
cout << "\n"<< setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::          Pindahkan Pesawat ke Antrian ...           ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                    1. Jenis 1                       ::" <<endl;
cout << setw(55)<<" "<<"::                    2. Jenis 2                       ::" <<endl;
cout << setw(55)<<" "<<"::                    3. Jenis 3                       ::" <<endl;
cout << setw(55)<<" "<<"::                    4. Jenis 4                       ::" <<endl;
cout << setw(55)<<" "<<"::                    5. Jenis 5                       ::" <<endl;
cout << setw(55)<<" "<<"::                    6. Kembali                       ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}

void menu6(){
cout << "\n"<< setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                    Pilih Level                      ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<"::                    1. Easy                          ::" <<endl;
cout << setw(55)<<" "<<"::                    2. Medium                        ::" <<endl;
cout << setw(55)<<" "<<"::                    3. Hard                          ::" <<endl;
cout << setw(55)<<" "<<"::                                                     ::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}

void credit(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n"<< setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
    cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
    cout << setw(55)<<" "<<"::                                                     ::" <<endl;
    cout << setw(55)<<" "<<"::     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI      ::" <<endl;
    cout << setw(55)<<" "<<"::                                                     ::" <<endl;
    cout << setw(55)<<" "<<"::       Muhammad Ribhan Hadiyan - 140110200003        ::" <<endl;
    cout << setw(55)<<" "<<"::       ValdaAzka Nadhira       - 140110200010        ::" <<endl;
    cout << setw(55)<<" "<<"::       Arthamevia Najwa Soraya - 140110200012        ::" <<endl;
    cout << setw(55)<<" "<<"::       Dila Nur Fadhilah       - 140110200018        ::" <<endl;
    cout << setw(55)<<" "<<"::       Wibi Anto               - 140110200025        ::" <<endl;
    cout << setw(55)<<" "<<"::                                                     ::" <<endl;
    cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
    cout << setw(55)<<" "<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::" <<endl;
}

void tutorial(){
    char pilih;
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<setw(70)<<" "<<"Ingin melihat Tutorial?(y/n) : ";cin>>pilih;
    if(pilih=='Y'||pilih=='y'){
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    cout << setw(65)<<" "<<"Tampilan Awal Akan Seperti dibawah ini" << endl;
    menu1();
    cout << endl;
    cout << setw(60)<<" "<<"Untuk memulai Simulasi Silahkan Pilih Menu No 1" << endl;
    cout << setw(60)<<" "<<system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    cout << setw(55)<<" "<<"Jika Sudah Maka diharuskan untuk mengisi nama terlebih dahulu" << endl;
    cout << setw(70)<<" "<< system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    cout << setw(65)<<" "<<"Kemudian Pilih Level yang anda inginkan " << endl;
    menu6();
    cout << setw(45)<<" "<<"Semakin tinggi levelnya maka simulasi akan semakin lama untuk diselesaikan" << endl;
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    cout << setw(55)<<" "<<"Setelah itu Maka Akan ditampilkan sebuah tabel dan menu " << endl;
    menu3();
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    menu3();
    cout << setw(70)<<" "<<"Menu Izinkan Pesawat Mendarat" << endl;
    cout << setw(50)<<" "<<"Menu Ini berguna untuk memasukan Pesawat dari Antrian Pesawat yang ingin" << endl;
    cout << setw(65)<<" "<<"Mendarat ke parkiran Sementara pesawat\n" << endl;
    cout << setw(40)<<" "<<"dan juga secara random Antrian pesawat yang ingin mendarat akan bertambah atau tetap" << endl;
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    menu3();
    cout << setw(70)<<" "<<"Menu Izinkan Terbang" << endl;
    cout << setw(40)<<" "<<"Menu Ini akan menghapus data pertama di antrian penerbangan sesuai jenis yang dipilih\n" << endl;
    cout << setw(40)<<" "<<"dan juga secara random Antrian pesawat yang ingin mendarat akan bertambah atau tetap" << endl;
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout << setw(80)<<" "<<"TUTORIAL" << endl;
    menu3();
    cout << setw(70)<<" "<<"Menu Masukan ke antrian penerbangan" << endl;
    cout << setw(40)<<" "<<"Menu Ini akan memindahkan data pertama dari parkiran sementara ke antrian penerbangan" << endl;
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<setw(80)<<" "<<"TUTORIAL" << endl;
    cout << setw(50)<<" "<<"- JIKA ANTRIAN MELEBIHI BATAS MAKSIMUM MAKA SIMULASI AKAN BERAKHIR" << endl;
    cout << setw(50)<<" "<<"- JIKA USER SALAH MEMASUKAN KE ANTRIAN TERBANG MAKA SIMULASI BERAKHIR" << endl;
    cout << setw(50)<<" "<<"- JIKA USER BERHASIL MENYELESAIKAN SIMULASI MAKA USER NANTI AKAN DAPAT MELIHAT" << endl;
    cout << setw(50)<<" "<<"  SEBUAH GAMBAR YANG MENARIK SECARA RANDOM" << endl;
    cout << setw(70)<<" "<<system("pause");
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<setw(65)<<" "<<"SELAMAT MENJALANKAN PROGRAM INI" << endl;
    cout << setw(65)<<" "<<system("pause");
    system("cls");
    }else{
        system("cls");
    }

}
void level(int pillevel,int& Random){
    if(pillevel==1){
        Random=random1();
    }else if(pillevel==2){
        Random=random2();
    }else if(pillevel==3){
        Random=random3();
    }
}
int main(){
    system("color f0");
    //waktu
    time_t waktuMulai;
    time_t waktuSelesai;
    //score
    int scoreBantu;
    //untuk switch
    char pil1,pil2,pil3,pil4,pil5,pil6,pil7;
    //bilangan Random
    int Random1;
    //untuk database
    dtbs dt;
    createDatabase(dt);
    //untuk multilist
    listInduk firstInduk;
    pointerInduk pBaruInduk,pCari;
    pointerAnak pBaruAnak;
    //untuk Doubly
    pointerDoubly pBaruDoubly;
    listDoubly firstDoubly;
    //untuk Antrian Pesawat yang ingin mendarat
    queue Q;
    pointerQueue pBaruQueue;
    //user ke
    int ke=0;
    //Pilih Level
    int pillevel=1;
    //create Doubly
    createlistDoubly(firstDoubly);
    //Halaman Depan
    judul();
    cout << setw(70)<<" " <<system("pause");
    tutorial();
    do{
        //game over
        int gameOver=0;
        int Berhasil=0;
        //akses menu 3
        int aksesMenu3=0;
        system("cls");
        //buat multilist
        createListInduk(firstInduk);
        for(int i=1;i<=7;i++){
            createInduk(pBaruInduk,dt,i);
            insertLastInduk(firstInduk,pBaruInduk);
        }
        //create Queue
        createQueue(Q);
        for(int i=1;i<=6;i++){
            createElementQueue(pBaruQueue,dt,random4());
            insertQueue(Q,pBaruQueue);
        }
        system("cls");

        menu1();
        cout<< setw(80)<<" " <<"pilihan : ";cin>>pil1;
        system("cls");
        switch(pil1){
        case '1':
            ke++;
            scoreBantu=0;
            fflush(stdin);
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<setw(70)<<" " <<"Masukan Nama   : ";getline(cin,dt[ke].dataUser.nama);
            system("cls");
            menu6();
            cout << setw(75)<<" " <<"Pilih Level   : ";cin>>pillevel;
            waktuMulai=time(0);
            do{
                system("cls");
                traversalScore(scoreBantu);
                traversal(Q,firstInduk);
                menu3();
                cout << setw(78)<<" " <<"pilihan : ";cin>>pil2;
                switch(pil2){
                case '1':
                    if(isFullAnak(firstInduk,MAXParkir)==1){
                        gameOver=1;
                    }else{
                        if(Q.head!=NULL){
                            level(pillevel,Random1);
                            scoreBantu=scoreBantu+5;
                            hitunganMundurMendarat();
                            createAnakParkiran(Q,pBaruAnak);
                            linearSearchInduk(firstInduk,pCari,"parkiran");
                            insertLastAnak(pCari,pBaruAnak);
                            deleteQueue(Q);
                            tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                            berhasil(Q,firstInduk,Berhasil,gameOver);
                            aksesMenu3=1;
                        }else{
                            level(pillevel,Random1);
                            tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                            cout <<"\n\n" <<setw(65)<<" " <<"Tidak ada pesawat yang mendarat" << endl;
                            cout <<setw(70)<<" " <<system("pause");
                        }
                    }
                    break;
                case '2':
                    do{
                        system("cls");
                        traversalScore(scoreBantu);
                        traversal(Q,firstInduk);
                        menu4();
                        cout << setw(78)<<" " <<"pilihan : ";cin>>pil4;
                        level(pillevel,Random1);
                        switch(pil4){
                        case '1':
                            linearSearchInduk(firstInduk,pCari,"jenis 1");
                            if(pCari->firstAnak!=NULL){
                                deleteFirstAnak(pCari);
                                scoreBantu=scoreBantu+10;
                                hitunganMundurTerbang();
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                berhasil(Q,firstInduk,Berhasil,gameOver);
                            }else{
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                cout <<"\n\n" <<setw(68)<<" " <<"Tidak ada pesawat yang terbang" << endl;
                                cout <<setw(70)<<" " <<system("pause");
                            }
                            break;
                        case '2':
                            linearSearchInduk(firstInduk,pCari,"jenis 2");
                            if(pCari->firstAnak!=NULL){
                                deleteFirstAnak(pCari);
                                scoreBantu=scoreBantu+10;
                                hitunganMundurTerbang();
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                berhasil(Q,firstInduk,Berhasil,gameOver);
                            }else{
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                cout <<"\n\n" <<setw(68)<<" " <<"Tidak ada pesawat yang terbang" << endl;
                                cout <<setw(70)<<" " <<system("pause");
                            }
                            break;
                        case '3':
                            linearSearchInduk(firstInduk,pCari,"jenis 3");
                            if(pCari->firstAnak!=NULL){
                                deleteFirstAnak(pCari);
                                scoreBantu=scoreBantu+10;
                                hitunganMundurTerbang();
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                berhasil(Q,firstInduk,Berhasil,gameOver);
                            }else{
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                cout <<"\n\n" <<setw(68)<<" " <<"Tidak ada pesawat yang terbang" << endl;
                                cout <<setw(70)<<" " <<system("pause");
                            }
                            break;
                        case '4':
                            linearSearchInduk(firstInduk,pCari,"jenis 4");
                            if(pCari->firstAnak!=NULL){
                                deleteFirstAnak(pCari);
                                scoreBantu=scoreBantu+10;
                                hitunganMundurTerbang();
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                berhasil(Q,firstInduk,Berhasil,gameOver);
                            }else{
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                cout <<"\n\n" <<setw(68)<<" " <<"Tidak ada pesawat yang terbang" << endl;
                                cout <<setw(70)<<" " <<system("pause");
                            }
                            break;
                        case '5':
                            linearSearchInduk(firstInduk,pCari,"jenis 5");
                            if(pCari->firstAnak!=NULL){
                                deleteFirstAnak(pCari);
                                scoreBantu=scoreBantu+10;
                                hitunganMundurTerbang();
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                berhasil(Q,firstInduk,Berhasil,gameOver);
                            }else{
                                tambahQueue(Q,pBaruQueue,dt,Random1,gameOver);
                                cout <<"\n\n" <<setw(68)<<" " <<"Tidak ada pesawat yang terbang" << endl;
                                cout <<setw(70)<<" " <<system("pause");
                            }
                            break;
                        default:
                            break;
                        }
                    }while(pil4!='6'&&gameOver==0);
                    break;
                case '3':
                    do{
                        system("cls");
                        traversalScore(scoreBantu);
                        traversal(Q,firstInduk);
                        if(firstInduk->firstAnak==NULL){
                            aksesMenu3=0;
                        }
                        if(aksesMenu3==1){
                            menu5();
                            cout << setw(78)<<" " <<"pilihan : ";cin>>pil3;
                            switch(pil3){
                            case '1':
                                if(firstInduk->firstAnak->dataPesawat.jenisPesawat!="jenis 1"||isFullAnak(firstInduk->next,MAXTerbang)==1){
                                    gameOver=1;
                                }else{
                                    scoreBantu=scoreBantu+5;
                                    linearSearchInduk(firstInduk,pCari,"jenis 1");
                                    createAnakTerbang(firstInduk,pBaruAnak);
                                    insertLastAnak(pCari,pBaruAnak);
                                    linearSearchInduk(firstInduk,pCari,"parkiran");
                                    deleteFirstAnak(pCari);
                                }
                                break;
                            case '2':
                                if(firstInduk->firstAnak->dataPesawat.jenisPesawat!="jenis 2"||isFullAnak(firstInduk->next->next,MAXTerbang)==1){
                                    gameOver=1;
                                }else{
                                    scoreBantu=scoreBantu+5;
                                    linearSearchInduk(firstInduk,pCari,"jenis 2");
                                    createAnakTerbang(firstInduk,pBaruAnak);
                                    insertLastAnak(pCari,pBaruAnak);
                                    linearSearchInduk(firstInduk,pCari,"parkiran");
                                    deleteFirstAnak(pCari);
                                }
                                break;
                            case '3':
                                if(firstInduk->firstAnak->dataPesawat.jenisPesawat!="jenis 3"||isFullAnak(firstInduk->next->next->next,MAXTerbang)==1){
                                    gameOver=1;
                                }else{
                                    scoreBantu=scoreBantu+5;
                                    linearSearchInduk(firstInduk,pCari,"jenis 3");
                                    createAnakTerbang(firstInduk,pBaruAnak);
                                    insertLastAnak(pCari,pBaruAnak);
                                    linearSearchInduk(firstInduk,pCari,"parkiran");
                                    deleteFirstAnak(pCari);
                                }
                                break;
                            case '4':
                                if(firstInduk->firstAnak->dataPesawat.jenisPesawat!="jenis 4"||isFullAnak(firstInduk->next->next->next->next,MAXTerbang)==1){
                                    gameOver=1;
                                }else{
                                    scoreBantu=scoreBantu+5;
                                    linearSearchInduk(firstInduk,pCari,"jenis 4");
                                    createAnakTerbang(firstInduk,pBaruAnak);
                                    insertLastAnak(pCari,pBaruAnak);
                                    linearSearchInduk(firstInduk,pCari,"parkiran");
                                    deleteFirstAnak(pCari);
                                }
                                break;
                            case '5':
                                if(firstInduk->firstAnak->dataPesawat.jenisPesawat!="jenis 5"||isFullAnak(firstInduk->next->next->next->next->next,MAXTerbang)==1){
                                    gameOver=1;
                                }else{
                                    scoreBantu=scoreBantu+5;
                                    linearSearchInduk(firstInduk,pCari,"jenis 5");
                                    createAnakTerbang(firstInduk,pBaruAnak);
                                    insertLastAnak(pCari,pBaruAnak);
                                    linearSearchInduk(firstInduk,pCari,"parkiran");
                                    deleteFirstAnak(pCari);
                                }
                                break;
                            case '6':
                                break;
                            default:
                                cout << "\n\n\n\n\n\n" <<setw(70)<<" "<<"Pilihan tidak tersedia" << endl;
                                break;
                            }
                        }else{
                            cout << "\n\n\n\n\n\n" <<setw(70)<<" "<<"Anda belum bisa mengakses Menu ini";
                            getch();
                            pil3='6';
                        }

                    }while(pil3!='6'&&gameOver==0);
                    break;
                case '4':
                    gameOver=1;
                    break;
                default :
                    cout <<"\n\n\n\n\n\n" <<setw(60)<<"Pilihan tidak tersedia" << endl;
                }cin.get();
            }while(pil2!='4'&&gameOver==0);
            waktuSelesai=time(0);
            dt[ke].dataUser.lamaSimulasi=difftime(waktuSelesai,waktuMulai);
            dt[ke].dataUser.score=scoreBantu;
            createElementDoubly(pBaruDoubly,dt,ke);
            insertFirstDoubly(firstDoubly,pBaruDoubly);
            if(Berhasil==1){
                system("cls");
                Random1=random4();
                if(Random1==1)
                    art1();
                else if(Random1==2)
                    art2();
                else if(Random1==3)
                    art3();
                else if(Random1==4)
                    art4();
                else if(Random1==5)
                    art5();
                cout <<"\n\n\n\n\n\n" <<setw(60)<<" " <<"KEREN ANDA DAPAT BERHASIL MENYELESAIKAN SIMULASI" << endl;
            }else{
                cout <<"\n\n\n\n\n\n" <<setw(60)<<" " <<"YAHH ANDA BELUM BERHASIL MENYELESAIKAN MISI :)" <<endl;
            }
            break;
        case '2':
            traversalUser(firstDoubly);
            break;
        case '3':
            do{
                system("cls");
                menu2();
                cout << setw(78)<<" " <<"pilihan : ";cin>>pil5;

                if (pil5=='1'){
                    system("color  f0");
                }else if(pil5=='2'){
                    system("color 7");
                }else if(pil5=='3'){
                    do{
                        system("cls");
                        menu2Anak();
                        cout << setw(70) << " " << "Pilihan Warna Huruf     : ";cin>>pil6;
                        cout << setw(70) << " " << "Pilihan Warna Background: ";cin>>pil7;

                        if(pil6=='1'&&pil7=='1'){
                            system("color 90");
                        }else if(pil6=='1'&&pil7=='2'){
                            system("color B0");
                        }else if(pil6=='1'&&pil7=='3'){
                            system("color E0");
                        }else if(pil6=='2'&&pil7=='1'){
                            system("color 91");
                        }else if(pil6=='2'&&pil7=='2'){
                            system("color B1");
                        }else if(pil6=='2'&&pil7=='3'){
                            system("color E1");
                        }else if(pil6=='3'&&pil7=='1'){
                            system("color 92");
                        }else if(pil6=='3'&&pil7=='2'){
                            system("color B2");
                        }else if(pil6=='3'&&pil7=='3'){
                            system("color E2");
                        }
                        pil6='0';
                    } while (pil6!='0');
                }
            } while (pil5!='4');
            break;
        case '4':
            system("cls");
            credit();
            break;
        default :
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }cout<<setw(70)<<" " <<system("pause");
    }while(pil1!='4');
}
