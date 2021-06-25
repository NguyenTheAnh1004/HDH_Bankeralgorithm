#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

/*color begin*/
void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*color end*/

/*xy for menu begin*/
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*xy for menu end*/

/*compare begin*/
bool LessEqual(const int* need, const int* work, int m)
{
    for (int i = 1; i <= m; i++)
    {
        if (need[i] > work[i]){
            return false;
        }
    }
    return true;
}
/*compare end*/

/*calculation begin*/
void Add(int* work, const int* allo, int m)
{
    for (int i = 1; i <= m; i++){
        work[i] += allo[i];
    }
}
void Sub(int* des, const int* src, int m)
{
    for (int i = 1; i <= m; i++){
        des[i] -= src[i];
    }
}
/*calculation end*/

/*BankerAlgrithm begin*/
bool Banker(int*& aval, int** allo, int**& need, int m, int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int i;
    int correct, find;

    int* work = new int[m + 1];
    int* seq, end = 0;
    seq = new int[n];
    bool* finish;
    finish = new bool[n + 1];
    for (i = 1; i <= n; i++)
        finish[i] = false;

    for (i = 1; i <= m; i++){
        work[i] = aval[i];
    }

    while (true)
    {
        find = 0;
        correct = 1;
        for (i = 1; i <= n; i++)
        {
            if (finish[i] == false)
            {
                if (LessEqual(need[i], work, m))
                {
                    cout << "Chon: P" << i << " Vi Need( ";
                    for (int k = 1; k <= m; k++) {

                        cout << need[i][k] << " ";
                    }
                    cout << ") <= Work( ";
                    for (int k = 1; k <= m; k++) {
                        cout << work[k] << " ";
                    }
                    cout << ")" << endl;
                    cout << "Work = Work + Allocation = ( ";
                    for (int k = 1; k <= m; k++) {
                        work[k] += allo[i][k];
                        cout << work[k] << " ";
                    }
                    cout << ")" << endl;
                    cout << endl;

                    finish[i] = true;
                    find = 1;
                    seq[end++] = i;
                }
                else
                {
                    correct = 0;
                }
            }
        }
        if (correct == 1)
        {
            cout << endl << "Tim duoc trang thai an toàn" << endl;
            cout << "trang thai la: ";
            for (int k = 0; k < end; k++)
                cout << "P" << seq[k] << ' ';
            cout << endl;
            delete work;
            delete seq;
            delete finish;
            return true;
        }
        else if (find == 0)
        {
            cout << "Khong co trang thai an toan xay ra DEADLOCK" << endl;
            delete work;
            delete seq;
            delete finish;
            return false;
        }
    }

}
/*BankerAlgrithm end*/

/*Import Status begin */
void ImportStatus(int*& aval, int**& max, int**& allo, int**& need, int m, int n){

    int i;
    int j;
    try
    {
        aval = new int[m + 1];
        max = new int* [n + 1];
        allo = new int* [n + 1];
        need = new int* [n + 1];
        for (i = 1; i <= n; i++)
        {
            max[i] = new int[m + 1];
            allo[i] = new int[m + 1];
            need[i] = new int[m + 1];
        }
    }
    catch (...)
    {
        cout << "Memory Error!" << endl;
        exit(0);
    }
    cout << endl << "nhap trang thai ban dau cua " << m << " tai nguyen (AVAILABLE) : ";
    for (i = 1; i <= m; i++)
        cin >> aval[i];
    cout << endl << "Nhap bang MAX : " << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "P" << i << " : ";
        for (j = 1; j <= m; j++)
            cin >> max[i][j];
    }
    cout << endl << "Nhap bang ALLOCATION: " << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "P" << i << " : ";
        for (j = 1; j <= m; j++)
            cin >> allo[i][j];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            need[i][j] = max[i][j] - allo[i][j];
    }
    cout << endl;
}
/*Import Status end */

/* Print Status begin */
void Print(int* aval, int** max, int** allo, int** need, int m, int n){
	
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << endl << "Avaliable : ";
    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (i = 1; i <= m; i++)
        cout << aval[i] << ' ';
    cout << endl;
    //cout << "PROCESS    " << "    MAX    " << "    ALLOCATION    " << "    NEED    " << endl;
    for (i = 1; i <= n; i++)
    {
        color(12);
        cout << "PROCESS : ";
        color(7);
        cout << i << "  ";
        color(12);
        cout << "MAX : ";
        color(7);
        for (j = 1; j <= m; j++){
            cout << max[i][j] << ' ';
        }
        cout << "  ";
        color(12);
        cout << "ALLOCATION : ";
        color(7);
        for (j = 1; j <= m; j++){
            cout << allo[i][j] << ' ';
        }
        cout << "  ";
        color(12);
        cout << "NEED : ";
        color(7);
        for (j = 1; j <= m; j++){
            cout << need[i][j] << ' ';
        }
        cout << "  ";
        cout << endl;
    }
    cout << endl;
}
/* Print Status end */

//Destroy
void Destroy(int* aval, int** max, int** allo, int** need, int n)
{
    int i;
    delete aval;
    for (i = 0; i <= n; i++)
    {
        delete max[i];
        delete allo[i];
        delete need[i];
    }
}

int main()
{


    int Set[] = { 7,7,7,7,7 }; // DEFAULT COLORS
    int counter = 0;
    char key;
    while (true) {

        int* aval;
        int** max, ** allo, ** need;
        int m, n, i;
        
        color(12);
        cout<<setw(30)<<right<<"banker algorithm"<<endl;
        color(7);
        cout << "Nhap so luong tai nguyen (R) : ";    cin >> m;
        cout << "Nhap so luong tien trinh (P) : ";     cin >> n;
        ImportStatus(aval, max, allo, need, m, n);
        system("cls");
        Print(aval, max, allo, need, m, n);
        Banker(aval, allo, need, m, n);

        while (true)
        {
            gotoxy(90, 6);
            color(11);
            cout << "----->MENU<-----";
            gotoxy(80, 7);
            color(6);
            cout << "***********************************";
            if (counter == 0)
            {
                Set[0] = 23;
            }
            gotoxy(80, 8);
            color(6);
            cout << "*";
            gotoxy(81, 8);
            color(Set[0]);
            cout << " 1.yeu cau tai nguyen ( REQUEST ) ";
            gotoxy(114, 8);
            color(6);
            cout << "*";

            gotoxy(80, 9);
            color(6);
            cout << "*";
            gotoxy(81, 9);
            color(Set[1]);
            cout << "          2.Lam bai khac          ";
            gotoxy(114, 9);
            color(6);
            cout << "*";

            gotoxy(80, 10);
            color(6);
            cout << "*";
            gotoxy(81, 10);
            color(Set[2]);
            cout << "             3.Exit              ";
            gotoxy(114, 10);
            color(6);
            cout << "*";

            gotoxy(80, 11);
            color(6);
            cout << "***********************************";
            color(7);
            int request[100];
            int proc;
            key = _getch();

            if (key == 72 && (counter >= 1 && counter <= 2))
            {
                counter--;
            }
            if (key == 80 && (counter >= 0 && counter <= 1))
            {
                counter++;
            }
            Set[0] = 7;
            Set[1] = 7;
            Set[2] = 7;
            Set[3] = 7;
            Set[4] = 7;

            if (counter == 0)
            {
                Set[0] = 23;
            }
            if (counter == 1)
            {
                Set[1] = 23;
            }
            if (counter == 2)
            {
                Set[2] = 23;
            }

            if (key == '\r')//carriage return
            {
                if (counter == 0)
                {
                    system("cls");
                    Print(aval, max, allo, need, m, n);
                    cout << "Yeu cau tien trinh (Process): ";   cin >> proc;
                    while (proc > n || proc < 0)
                    {
                        cout << "khong co tien trinh nay (no process)" << proc << endl;
                        cout << "Yeu cau tien trinh (Process): ";   cin >> proc;
                    }
                    cout << "Nhap " << m << " Tai nguyen yeu cau cua P" << proc << " (Request resources): ";
                    for (i = 1; i <= m; i++)
                        cin >> request[i];
                    cout << endl;

                    //			system("cls");
                    if (LessEqual(request, need[proc], m) && LessEqual(request, aval, m))
                    {
                        system("cls");
                        Add(allo[proc], request, m);
                        Sub(need[proc], request, m);
                        Sub(aval, request, m);
                        cout << "Tien trinh P" << proc << " co yeu cau tai nguyen la: ( ";
                        for (i = 1; i <= m; i++)
                            cout << request[i] << " ";
                        cout << ")" << endl;
                        cout << "trang thai moi la : " << endl;
        
                        Print(aval, max, allo, need, m, n);

                        if (!Banker(aval, allo, need, m, n))
                        {
                            cout << "Tien trinh yeu cau tai nguyen khong duoc dap ung" << endl;
                            cout << "Doi de phuc hoi trang thai ......" << endl;
                            Sub(allo[proc], request, m);
                            Add(need[proc], request, m);
                            Add(aval, request, m);
                            cout << "Phuc hoi trang thai :" << endl;
                            Print(aval, max, allo, need, m, n);
                        }
                    }
                    else
                    {
                        cout << "Tai nguyen cap phat qua lon (Request resource > Need or Available)" << endl;
                    }
                }
                else if (counter == 1)
                {
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    exit(1);
                }
            }

        }

    }
}

