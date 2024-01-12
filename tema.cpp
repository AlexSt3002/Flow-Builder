#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;
template <class T>
float adunar(T vect[100], int vect1[100], int n)
{
    float n1 = 0;
    for (int j = 0; j < n; j++)
        n1 = n1 + vect[vect1[j] - 1];
    return n1;
}
template <class T>
float scader(T vect[100], int vect1[100], int n)
{
    float n1 = vect[vect1[0] - 1];
    for (int j = 1; j < n; j++)
        n1 = n1 - vect[vect1[j] - 1];
    return n1;
}
template <class T>
float inmultir(T vect[100], int vect1[100], int n)
{
    float n1 = 1;
    for (int j = 1; j < n; j++)
        n1 = n1 * vect[vect1[j] - 1];
    return n1;
}
template <class T>
float impartir(T vect[100], int vect1[100], int n)
{
    float n1 = vect[vect1[0] - 1];
    for (int j = 1; j < n; j++)
        n1 = n1 / vect[vect1[j] - 1];
    return n1;
}
template <class T>
float max(T vect[100], int vect1[100], int n)
{
    float n1 = vect[vect1[0] - 1];
    for (int j = 1; j < n; j++)
        if (vect[vect1[j] - 1] > n1)
            n1 = vect[vect1[j] - 1];
    return n1;
}
template <class T>
float min(T vect[100], int vect1[100], int n)
{
    float n1 = vect[vect1[0] - 1];
    for (int j = 1; j < n; j++)
        if (vect[vect1[j] - 1] < n1)
            n1 = vect[vect1[j] - 1];
    return n1;
}
class Flow
{
private:
    string date;

public:
    float start;
    float complete;
    float skip;
    float error = 0;
    float average;
    char steps[100][100];
    void setdate(string line)
    {
        this->date = line;
    }
    string getdate()
    {
        return this->date;
    }
    Flow()
    {
    }
    Flow(string message)
    {
        cout << message;
    }
    ~Flow()
    {
        cout << "Object is being deleted\n";
    }
    void adauga(string nume, char y3[100][100], int i);
    void output(char nume[100], char descriere[100]);
    void calcul(char nume[100], char operatie[100], int vect1[100], int n);
    void textfile(char y[100], char nume[100]);
    void csvfile(char y[100], char nume[100]);
    void displaytxt(char y[100]);
    void displaycsv(char y[100]);
    void titlu(char y[100], char nume[100])
    {
        for (int j = 0; j < strlen(y); j++)
            if (y[j] < 'A' || y[j] > 'Z')
                throw "Titlul trebuie scris cu litere mari";
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << y;
    }
    void titlu(char y[100], char descriere[100], char nume[100])
    {
        for (int j = 0; j < strlen(y); j++)
            if (y[j] < 'A' || y[j] > 'Z')
                throw "Titlul trebuie scris cu litere mari";
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << y << endl
             << descriere;
    }
    void text(char y[100], char nume[100])
    {
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << y;
    }
    void text(char y[100], char descriere[100], char nume[100])
    {
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << descriere << endl
             << y;
    }

    void numar(float
                   vect[100],
               char nume[100], int j)
    {
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << vect[j];
    }
    void numar(float vect[100], char descriere[100], char nume[100], int j)
    {
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        fout << endl
             << descriere << endl
             << vect[j];
    }
};
void Flow::adauga(string name, char y3[100][100], int i)
{
    int o = 0;
    string nume;
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\", y2[100][100];
    ifstream fin;
    fin.open("C:\\Users\\alex_\\Documents\\POO\\tema\\flow.txt");
    while (!fin.fail() && !fin.eof())
    {
        getline(fin, nume);
        strcpy(y2[o], &nume[0]);
        o++;
        if (strstr(&name[0], "flow") == NULL)
            throw "Numele flow-ului nu contine denumirea \"flow\"";
        if (nume == name)
            throw "Flow-ul exista deja";
    }
    if (strcmp(y3[0], "output") != 0)
        throw "Primul pas nu este cel de output";
    for (int j = 1; j < i; j++)
    {
        if (strcmp(y3[j], "titlu") != 0 && strcmp(y3[j], "text") != 0 && strcmp(y3[j], "numar") != 0 && strcmp(y3[j], "calcul") != 0 && strcmp(y3[j], "textfile") != 0 && strcmp(y3[j], "csvfile") != 0 && strcmp(y3[j], "end") != 0 && strcmp(y3[j], "displaytxt") != 0 && strcmp(y3[j], "displaycsv") != 0)
            throw "Numele pasilor este incorect sau ati introdus inca un pas de output";
    }
    ofstream fout;
    strcat(y1, &name[0]);
    strcat(y1, ".txt");
    fout.open(y1);
    for (int j = 0; j < i; j++)
        fout << y3[j] << ",";
    fout << endl;
    fout << "start:0" << endl;
    fout << "complete:0" << endl;
    fout << "skip:0" << endl;
    fout << "error:0" << endl;
    fout << "average:0" << endl;
    time_t now = time(0);
    char *dt = ctime(&now);
    fout << dt;
    fin.close();
    fout.close();
    fout.open("C:\\Users\\alex_\\Documents\\POO\\tema\\flow.txt", ios::app);
    fout << endl;
    fout << name;
}
void Flow::output(char nume[100], char descriere[100])
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
    ofstream fout;
    strcat(y1, nume);
    strcat(y1, ".txt");
    fout.open(y1);
    fout << descriere;
}

void Flow::calcul(char nume[100], char y[100], int vect1[100], int n)
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
    ofstream fout;
    strcat(y1, nume);
    strcat(y1, ".txt");
    fout.open(y1, ios::app);
    fout << endl
         << y << "a numerelor de la pasii:";
    for (int j = 0; j < n; j++)
        fout << vect1[j] << ",";
}
void Flow::textfile(char y[100], char nume[100])
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\", y2[100] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
    string y3;
    ifstream fin;
    ofstream fout;
    strcat(y1, nume);
    strcat(y1, ".txt");
    strcat(y2, y);
    strcat(y2, ".txt");
    fout.open(y1, ios::app);
    fin.open(y2);
    if (fin.fail())
        throw "Fisierul selectat nu exista";
    while (!fin.fail() && !fin.eof())
    {
        getline(fin, y3);
        fout << endl
             << y3;
    }
}
void Flow::csvfile(char y[100], char nume[100])
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\", y2[100] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
    string y3;
    ifstream fin;
    ofstream fout;
    strcat(y1, nume);
    strcat(y1, ".txt");
    strcat(y2, y);
    strcat(y2, ".csv");
    fout.open(y1, ios::app);
    fin.open(y2);
    if (fin.fail())
        throw "Fisierul selectat nu exista";
    while (!fin.fail() && !fin.eof())
    {
        getline(fin, y3);
        fout << endl
             << y3;
    }
}
void Flow::displaytxt(char y[100])
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";

    ifstream fin;
    string y3;
    strcat(y1, y);
    strcat(y1, ".txt");
    fin.open(y1);
    if (fin.fail())
        throw "Fisierul selectat nu exista";

    while (!fin.fail() && !fin.eof())
    {
        getline(fin, y3);
        cout << y3 << endl;
    }
}
void Flow::displaycsv(char y[100])
{
    char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
    string y3;
    ifstream fin;

    strcat(y1, y);
    strcat(y1, ".csv");
    fin.open(y1);
    if (fin.fail())
        throw "Fisierul selectat nu exista";

    while (!fin.fail() && !fin.eof())
    {
        getline(fin, y3);
        cout << y3 << endl;
    }
}
class Flow1 : public Flow
{
public:
    void adunare(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = adunar(vect, vect1, n);
        fout << endl
             << n1;
    };

    void scadere(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = scader(vect, vect1, n);
        fout << endl
             << n1;
    };
    void inmultire(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = inmultir(vect, vect1, n);
        fout << endl
             << n1;
    };
    void impartire(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = impartir(vect, vect1, n);
        fout << endl
             << n1;
    };
    void maxim(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = max(vect, vect1, n);
        fout << endl
             << n1;
    };
    void minim(char nume[100], float vect[100], int vect1[100], int n)
    {
        float n1 = 0;
        char y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\";
        ofstream fout;
        strcat(y1, nume);
        strcat(y1, ".txt");
        fout.open(y1, ios::app);
        n1 = min(vect, vect1, n);
        fout << endl
             << n1;
    };
};
int main()
{
    float vect[100];
    Flow p("Doriti sa utilizati un flow existent sau sa creati unul nou?\n");
    Flow1 p1;
    int r, ok = 0, k = 0, vect1[100], n;
    string name, name1;
    char y[100], y1[200] = "C:\\Users\\alex_\\Documents\\POO\\tema\\", y2[100][100], y3[100][100], nume[100], descriere[100], y4[100];
    char *token1;
    ifstream fi;
    ofstream fout;
    int i = 0;
    string line;

    cout << "Pentru a utiliza un flow existent apasati 1, pentru a crea unul apasati 2 iar pentru a sterge un flow apasati 3" << endl;
    cin >> r;
start:
    if (r == 1)
    {
        strcpy(y1, "C:\\Users\\alex_\\Documents\\POO\\tema\\");
        i = 0;
        ifstream fin;
        fin.open("C:\\Users\\alex_\\Documents\\POO\\tema\\flow.txt");
        cout << "Urmatoarele flow-uri sunt disponibile:" << endl;
        while (!fin.fail() && !fin.eof())
        {
            getline(fin, name);
            cout << name << endl;
        }
        r = 0;
        cin.getline(y, 50);
        while (r == 0)
        {
            r = 1;
            cout << "Alegeti un flow:";
            cin.getline(y, 50);
            strcat(y1, y);
            strcat(y1, ".txt");
            fi.open(y1);
            if (fi.fail())
            {
                p.error = p.error + 1;
                cout << "Fisierul selectat nu exista" << endl;
                r = 0;
                strcpy(y1, "C:\\Users\\alex_\\Documents\\POO\\tema\\");
            }
        }

        getline(fi, line);
        token1 = strtok(&line[0], ",");

        while (token1 != NULL)
        {
            strcpy(y2[i], token1);
            i++;
            token1 = strtok(NULL, ",");
        }
        getline(fi, line);
        token1 = strtok(&line[0], ":");
        token1 = strtok(NULL, ":");
        p.start = atof(token1) + 1;
        getline(fi, line);
        token1 = strtok(&line[0], ":");
        token1 = strtok(NULL, ":");
        p.complete = atof(token1);
        getline(fi, line);
        token1 = strtok(&line[0], ":");
        token1 = strtok(NULL, ":");
        p.skip = atof(token1);
        getline(fi, line);
        token1 = strtok(&line[0], ":");
        token1 = strtok(NULL, ":");
        p.error = p.error + atof(token1);
        getline(fi, line);
        getline(fi, line);
        p.setdate(line);
        fi.close();
        fout.open(y1);
        for (int j = 0; j < i; j++)
            fout << y2[j] << ",";
        fout << endl
             << "start:" << p.start << endl;
        fout << "complete:" << p.complete << endl;
        fout << "skip:" << p.skip << endl;
        fout << "error:" << p.error << endl;
        fout << "average:" << (float)p.skip / p.complete << endl
             << p.getdate() << endl;
        for (int j = 0; j < i; j++)
        {
        pas:
            if (strcmp(y2[j], "output") == 0)
            {
                cout << "Introduceti numele fisierului:" << endl;
                cin.getline(nume, 50);
                cout << "Introduceti descrierea fisierului:" << endl;
                cin.getline(descriere, 50);
                p.output(nume, descriere);
            }
            if (strcmp(y2[j], "textfile") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    try
                    {
                        cout << "Introduceti numele fisierului pe care doriti sa il adaugati:" << endl;
                        cin.getline(y, 50);
                        p.textfile(y, nume);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                        ok = 0;
                        p.error = p.error + 1;
                    }
                }
            }
            if (strcmp(y2[j], "displaytxt") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    try
                    {
                        cout << "Introduceti numele fisierului pe care doriti sa il vedeti:" << endl;
                        cin.getline(y, 50);
                        p.displaytxt(y);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                        ok = 0;
                        p.error = p.error + 1;
                    }
                }
            }
            if (strcmp(y2[j], "displaycsv") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    try
                    {
                        cout << "Introduceti numele fisierului pe care doriti sa il vedeti:" << endl;
                        cin.getline(y, 50);
                        p.displaycsv(y);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                        ok = 0;
                        p.error = p.error + 1;
                    }
                }
            }
            if (strcmp(y2[j], "csvfile") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    try
                    {
                        cout << "Introduceti numele fisierului pe care doriti sa il adaugati:" << endl;
                        cin.getline(y, 50);
                        p.csvfile(y, nume);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                        ok = 0;
                        p.error = p.error + 1;
                    }
                }
            }
            if (strcmp(y2[j], "titlu") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    cout << "Introduceti titlul:";
                    cin.getline(y, 50);
                    cout << "Doriti sa introduceti si un subtitlu?(da/nu)";
                    cin.getline(y4, 50);
                    try
                    {
                        if (strcmp(y4, "da") == 0)
                        {
                            cout << "Introduceti subtitlul:";
                            cin.getline(descriere, 50);
                            p.titlu(y, descriere, nume);
                        }
                        else
                            p.titlu(y, nume);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                        ok = 0;
                        p.error = p.error + 1;
                    }
                }
            }
            if (strcmp(y2[j], "text") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                cout << "Introduceti textul:";
                cin.getline(y, 50);
                cout << "Doriti sa introduceti si o descriere a textului?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    cout << "Introduceti descrierea:";
                    cin.getline(descriere, 50);
                    p.text(y, descriere, nume);
                }
                else
                    p.text(y, nume);
            }

            if (strcmp(y2[j], "numar") == 0)
            {
                ok = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                cout << "Introduceti numarul:";
                cin >> vect[j];
                cout << "Doriti sa introduceti si o descriere a numarului?(da/nu)";
                cin.getline(y4, 50);
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    cout << "Introduceti descrierea:";
                    cin.getline(descriere, 50);
                    p.numar(vect, descriere, nume, j);
                }
                else
                    p.numar(vect, nume, j);
            }
            if (strcmp(y2[j], "calcul") == 0)
            {
                ok = 0;
                n = 0;
                cout << "Doriti sa dati skip acestui pas " << y2[j] << "?(da/nu)";
                cin.getline(y4, 50);
                if (strcmp(y4, "da") == 0)
                {
                    p.skip = p.skip + 1;
                    j++;
                    goto pas;
                }
                while (ok == 0)
                {
                    ok = 1;
                    cout << "Introduceti numele operatiei pe care doriti sa o efectuati(adunare,scadere,inmultire,impartire,minim,maxim):";
                    cin.getline(y, 50);
                    if (strcmp(y, "adunare") != 0 && strcmp(y, "scadere") != 0 && strcmp(y, "inmultire") != 0 && strcmp(y, "impartire") != 0 && strcmp(y, "minim") != 0 && strcmp(y, "maxim") != 0)
                    {
                        cout << "Ati introdus o operatie care nu poate fi efectuata" << endl;
                        p.error = p.error + 1;
                        ok = 0;
                    }
                }
                ok = 0;
                while (ok == 0)
                {
                    n = 0;
                    cout << "Introduceti numarul pasului la care ati introdus numarul:";
                    cin >> vect1[n];
                    n++;
                    cout << "Introduceti numarul pasului la care ati introdus numarul:";
                    cin >> vect1[n];
                    n++;

                    while (ok == 0)
                    {
                        ok = 1;
                        cout << "Doriti sa mai introduceti si alte numere?(da/nu)";
                        cin.getline(y4, 50);
                        cin.getline(y4, 50);
                        if (strcmp(y4, "da") == 0)
                        {
                            cout << "Introduceti numarul pasului la care ati introdus numarul:";
                            cin >> vect1[n];
                            n++;
                            ok = 0;
                        }
                    }
                    for (int m = 0; m < n; m++)
                        if (strcmp(y2[vect1[m] - 1], "numar") != 0)
                        {
                            cout << "Nu ati introdus numere la pasul:" << vect1[m] << endl;
                            p.error = p.error + 1;
                            ok = 0;
                        }
                }
                p1.calcul(nume, y, vect1, n);
                if (strcmp(y, "adunare") == 0)
                    p1.adunare(nume, vect, vect1, n);
                if (strcmp(y, "scadere") == 0)
                    p1.scadere(nume, vect, vect1, n);
                if (strcmp(y, "inmultire") == 0)
                    p1.inmultire(nume, vect, vect1, n);
                if (strcmp(y, "impartire") == 0)
                    p1.impartire(nume, vect, vect1, n);
                if (strcmp(y, "maxim") == 0)
                    p1.maxim(nume, vect, vect1, n);
                if (strcmp(y, "minim") == 0)
                    p1.minim(nume, vect, vect1, n);
            }
        }

        fout.close();
        fout.open(y1);
        for (int j = 0; j < i; j++)
            fout << y2[j] << ",";
        fout << endl
             << "start:" << p.start << endl;
        fout << "complete:" << p.complete + 1 << endl;
        p.complete = p.complete + 1;
        fout << "skip:" << p.skip << endl;
        fout << "error:" << p.error << endl;
        fout << "average:" << (float)p.skip / p.complete << endl
             << p.getdate() << endl;
    }
    if (r == 2)
    {
        cin.getline(y, 50);
        while (k == 0)
        {
            ok = 0;
            i = 0;
            cout << "Introduceti numele flow-ului:";
            cin.getline(y, 50);
            name = y;
            cout << "Introduceti pasii doriti(pentru a finaliza introducerea pasilor tastati end)" << endl;
            cout << "Pasii disponibili sunt: titlu,text,numar,calcul,textfile,csvfile,output,displaytxt,displaycsv,end" << endl;
            cout << "Primul pas trebuie sa fie output pentru a putea crea fisierul:";
            while (ok == 0)
            {
                cin.getline(y3[i], 50);
                if (strcmp(y3[i], "end") == 0)
                    ok = 1;
                i++;
            }
            k = 1;
            try
            {
                p.adauga(name, y3, i);
            }
            catch (const char *msg)
            {
                cout << msg << endl;
                k = 0;
            }
        }
        cout << "Doriti sa alegeti flow-ul?(da/nu):";
        char t[100];
        cin >> t;
        if (strcmp(t, "da") == 0)
        {
            r = 1;
            goto start;
        }
    }

    if (r == 3)
    {
        cin.getline(y, 50);
        while (k == 0)
        {
            ok = 0;
            i = 0;
            cout << "Introduceti numele flow-ului:";
            cin.getline(y, 50);
            ifstream fin1;
            ofstream fout1;
            fin1.open("C:\\Users\\alex_\\Documents\\POO\\tema\\flow.txt");
            while (!fin1.fail() && !fin1.eof())
            {
                getline(fin1, name1);
                if (strcmp(y, &name1[0]) != 0)
                {
                    strcpy(y2[i], &name1[0]);
                    i++;
                }
            }
            fin1.close();
            fout1.open("C:\\Users\\alex_\\Documents\\POO\\tema\\flow.txt");
            for (int j = 0; j < i; j++)
                fout1 << y2[j] << endl;
            strcat(y1, y);
            strcat(y1, ".txt");
            remove(y1);
            cout << "Doriti sa alegeti flow-ul?(da/nu):";
            char t[100];
            cin >> t;
            if (strcmp(t, "da") == 0)
            {
                r = 1;
                goto start;
            }
        }
    }
    return 0;
}
