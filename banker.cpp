#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

bool LittleOrEqual(const int *need, const int *work, int m)
{
    for(int i = 1; i <= m; i++)
    {
        if(need[i] > work[i])
            return false;
    }
    return true;
}
void Add(int *work, const int *allocation, int m)
{
    for(int i = 1; i <= m; i++)
        work[i] += allocation[i];
}
void Sub(int *des, const int *src, int m)
{
    for(int i = 1; i <= m; i++)
        des[i] -= src[i];
}
bool IsZero(const int *need, int m)
{
    for(int i = 1; i <= m; i++)
    {
        if(need[i] != 0)
            return false;
    }
    return true;
}
/*bool AllTrue(bool *finish, int n)
{
    for(int i = 1; i <= n; i++)
        if(finish[i] == false)
            return false;
    return true;
}*/
// BankerAlgrithm
bool SecurityDetection(int *&avaliable, int **allocation, int **&need, int m, int n)
{
	HANDLE h =GetStdHandle( STD_OUTPUT_HANDLE );
    int i;
    int alltrue, find;
    
    int *work = new int[m+1];
    int *seq, end = 0;
    seq = new int[n];
    bool *finish;
    finish = new bool[n+1];
    for(i = 1; i <= n; i++)
        finish[i] = false;

    for(i = 1; i <= m; i++)    
        work[i] = avaliable[i];
    
    while(1)
    {
        find = 0;
        alltrue = 1;
        for(i = 1; i <= n; i++)
        {
            if(finish[i] == false)
            {
//                if(IsZero(need[i], m))
//                {
//                    finish[i] = true;
//                }
                if(LittleOrEqual(need[i], work, m))
                {
                	cout<<"Chon: P"<<i<<" Vi Need( ";
                	for(int k = 1; k <= m; k++){
                    	
                        cout<<need[i][k]<<" ";
					}
					cout<<") <= Work( ";
                	for(int k = 1; k <= m; k++){
                        cout<<work[k]<<" ";
					}
					cout<<")"<<endl;
					cout<<"Work = Work + Allocation = ( ";
                    for(int k = 1; k <= m; k++){
                    	work[k] += allocation[i][k];
                        cout<<work[k]<<" ";
					}
					cout<<")"<<endl;
					cout<<endl;
                        
                    finish[i] = true;
                    find = 1;
                    seq[end++] = i;
                }
                else
                {
                    alltrue = 0;
                }
            }
        }
        if(alltrue == 1)
        {
            cout <<endl <<"Tim duoc trang thai an toàn" << endl;
            cout << "trang thai la: ";
            for(int k = 0; k < end; k++)
                cout <<"P"<< seq[k] << ' ';
            cout << endl;
            delete work;
            delete seq;
            delete finish;
            return true;
        }
        else if(find == 0)
        {
            cout << "Khong co trang thai an toan DEADLOCK" << endl;
            delete work;
            delete seq;
            delete finish;
            return false;
        }
    }

}
// Initial
void InitEnv(int *&avaliable, int **&max, int **&allocation, int **&need, int m, int n)
{
	
    int i;
    int j;
    try
    {
        avaliable = new int[m+1];
        max = new int*[n+1];
        allocation = new int*[n+1];
        need = new int*[n+1];
        for(i = 1; i <= n; i++)
        {
            max[i] = new int[m+1];
            allocation[i] = new int[m+1];
            need[i] = new int[m+1];
        }
    }
    catch(...)
    {
        cout << "Memory Error!" << endl;
        exit(0);
    }
    cout << endl << "nhap trang thai ban dau cua " << m << " tai nguyen (AVAILABLE) : " ;
    for(i = 1; i <= m; i++)
        cin >> avaliable[i];
    cout << endl <<"Nhap ma tran MAX : " << endl;
    for(i = 1; i <= n; i++)
    {
        cout << "Process " << i << " : ";
        for(j = 1; j <= m; j++)
            cin >> max[i][j];
    }
    cout << endl << "Nhap ma tran ALLOCATION: " << endl;
    for(i = 1; i <= n; i++)
    {
        cout << "Process " << i << " : ";
        for(j = 1; j <= m; j++)
            cin >> allocation[i][j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }
    cout <<endl;
}

// Print Status
void PrintStatus(int *avaliable, int **max, int **allocation, int **need, int m, int n)
{
	HANDLE h =GetStdHandle( STD_OUTPUT_HANDLE );
    int i, j;
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << endl << "Avaliable : ";
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for(i = 1; i <= m; i++)
        cout << avaliable[i] << ' ';
    cout << endl;
    //cout << "PROCESS    " << "    MAX    " << "    ALLOCATION    " << "    NEED    " << endl;
    for(i = 1; i <= n; i++)
    {
    	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "PROCESS : " ;
        SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<< i << "  ";
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "MAX : ";
        SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(j = 1; j <= m; j++)
            cout << max[i][j] <<' ';
        cout << "  ";
        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "ALLOCATION : ";
        SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(j = 1; j <= m; j++)
            cout << allocation[i][j] << ' ';
        cout << "  ";
        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "NEED : ";
        SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(j = 1; j <= m; j++)
            cout << need[i][j] << ' ';
        cout << "  ";
        cout << endl;
    }
    cout<<endl;
}
void Destroy(int *avaliable, int **max, int **allocation, int **need, int n)
{
    int i;
    delete avaliable;
    for(i = 0; i <= n; i++)
    {
        delete max[i];
        delete allocation[i];
        delete need[i];
    }
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main()
{
	
	
	int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
    int counter = 0;
    char key;
	while(true){
		
    int *avaliable;
    int **max, **allocation, **need;
    int m, n, i;
    int select;
    //bool torf;
    cout << "Nhap so luong tai nguyen (R) : ";    cin >> m;
    cout << "Nhap so luong tien trinh (P) : ";     cin >> n;
    InitEnv(avaliable, max, allocation, need, m, n);
    system("cls");
    PrintStatus(avaliable, max, allocation, need, m, n);
    if(!SecurityDetection(avaliable, allocation, need, m, n)){
    	
        exit(1); 
        
    }
    
    
    
    while(1)
    {
    	gotoxy(90,6);
        color(11);
        cout<<"----->MENU<-----";
    	gotoxy(80,7);
        color(6);
        cout<<"***********************************";
    	if(counter == 0)
        {
            Set[0] = 23;
        }
        gotoxy(80,8);
        color(6);
        cout<<"*";
        gotoxy(81,8);
        color(Set[0]);
        cout<<" 1.yeu cau tai nguyen ( REQUEST ) ";
        gotoxy(114,8);
        color(6);
        cout<<"*";

        gotoxy(80,9);
        color(6);
        cout<<"*";
		gotoxy(81,9);
        color(Set[1]);
        cout<<"          2.Lam bai khac          ";
        gotoxy(114,9);
        color(6);
        cout<<"*";

        gotoxy(80,10);
        color(6);
        cout<<"*";
		gotoxy(81,10);
        color(Set[2]);
        cout<<"             3.Exit              ";
        gotoxy(114,10);
        color(6);
        cout<<"*";
        
        gotoxy(80,11);
        color(6);
        cout<<"***********************************";
        color(7);
        int request[m+1];
        int proc;
        key = _getch();

        if(key == 72 && (counter >=1 && counter <= 2))
        {
            counter--;
        }
        if(key == 80 && (counter >=0 && counter <= 1))
        {
            counter++;
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;

        if(counter == 0)
        {
            Set[0] = 23;
        }
        if(counter == 1)
        {
            Set[1] = 23;
        }
        if(counter == 2)
        {
            Set[2] = 23;
        }
        
        if(key == '\r')//carriage return
        {
        if(counter == 0)
        {
        	system("cls");
        	PrintStatus(avaliable, max, allocation, need, m, n);
            cout  << "Yeu cau tien trinh (Process): ";   cin >> proc;
            while(proc > n || proc < 0)
            {
                cout << "khong co tien trinh nay (no process)" << proc << endl;
                cout << "Yeu cau tien trinh (Process): ";   cin >> proc;
            }
            cout <<"Nhap "<< m << " Tai nguyen yeu cau cua P"<<proc<<" (Request resources): ";
            for(i = 1; i <=m; i++)
                cin >> request[i];
            cout<<endl;
            
//			system("cls");
            if(LittleOrEqual(request, need[proc], m) && LittleOrEqual(request, avaliable, m))
            {
            	system("cls");
                Add(allocation[proc], request, m);
                Sub(need[proc], request, m);
                Sub(avaliable, request, m);
                cout<<"Tien trinh P"<<proc<<" co yeu cau tai nguyen la: ( ";
                for(i = 1; i <=m; i++)
                	cout << request[i] <<" ";
                cout<<")"<<endl;
                cout<<"trang thai moi la"<<endl;
//                if(IsZero(need[proc], m))
//                {
//                    cout << "Processing " << proc << " done" << endl;
//                    Add(avaliable, allocation[proc], m);
//                    Sub(allocation[proc], allocation[proc], m);
//                }
				PrintStatus(avaliable, max, allocation, need, m, n);
//                if(SecurityDetection(avaliable, allocation, need, m, n))
//                {
//                    PrintStatus(avaliable, max, allocation, need, m, n);
//                }
                if(!SecurityDetection(avaliable, allocation, need, m, n))
                {   
                    cout << "Trang thai khong an toan" << endl;
                    cout << "Doi de phuc hoi trang thai ......" << endl;
                    Sub(allocation[proc], request, m);
                    Add(need[proc], request, m);
                    Add(avaliable, request, m);
                    cout << "Phuc hoi trang thai :" << endl;
                    PrintStatus(avaliable, max, allocation, need, m, n);
                }
            }
            else
            {
                cout << "Tai nguyen cap phat qua lon (Request resource > Need or Available)" << endl;
            }
        }
        else if(counter == 1)
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
