#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n, ar[100], b[100], i, j, tmp, wt[100], ta[100], time[100];
    int totWT = 0, totTA = 0;
    float AvWT, AvTA;
    string name[20], tmpName;

    cout << "+-------------------------------------+" << endl;
    cout << "| Nama    : Muhammad Abdanul Ikhlas   |" << endl;
    cout << "| NIM     : 123210009                 |" << endl;
    cout << "| Kelas   : IF - C                    |" << endl;
    cout << "+-------------------------------------+" << endl;

    cout << endl << "   Program Penjadwalan CPU FIFO" << endl << endl;
    cout << "Banyak Proses = ";
    cin >> n;
    cout << endl;

    for (i = 0; i < n; i++) {
        cin.ignore(); // Membersihkan newline sebelumnya
        cout << "Nama Proses   = ";
        getline(cin, name[i]);
        cout << "Arrival time  = ";
        cin >> ar[i];
        cout << "Burst time    = ";
        cin >> b[i];
        cout << endl;
    }

    // SORTING Data berdasarkan arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ar[i] > ar[j]) {
                // Tukar nama
                tmpName = name[i];
                name[i] = name[j];
                name[j] = tmpName;

                // Tukar arrival time
                tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;

                // Tukar burst time
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    time[0] = ar[0];
    cout << "--------------------- PROSES TABEL ------------------------"<<endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << left << setw(5) << "| NO" << setw(16) << "|       PROSES   "  << setw(20) << "|    time arrival  " << setw(14) << "|      burst     |" << endl;
    cout << "+----------------------------------------------------------+" << endl;

    for (i = 0; i < n; i++) {
        cout << left << setw(2) << "|  " << i + 1  << " |       " << setw(8) << name[i] << " |        " << setw(10) << ar[i]  << " |        " << setw(7) << b[i] << " |" << endl;
        time[i + 1] = time[i] + b[i];
        wt[i] = time[i] - ar[i];
        ta[i] = time[i + 1] - ar[i];
        totWT += wt[i];
        totTA += ta[i];
    }
    cout << "+----------------------------------------------------------+" << endl << endl;

    cout << "\tTotal waiting time\t= " << totWT << endl;
    cout << "\tTurn around time\t= " << totTA << endl << endl;

    cout <<"\n-------------------- TIME PROSES TABEL ------------------- " <<endl;
    cout << "+----------------------------------------------------------+" << endl;
    cout << "| NO |      PROSES     |    WAITING TIME   |  TURN AROUND  |" << endl;
    cout << "+----------------------------------------------------------+" << endl;

    for (i = 0; i < n; i++) {
        cout << left << "| " << setw(2) << i + 1  << " |        " << setw(8) << name[i] << " |          " << setw(9) << wt[i] << "|        " << setw(7) << ta[i] << "|" << endl;
    }

    cout << "+----------------------------------------------------------+" << endl << endl;

    cout << endl <<"---------------------- Gantt Chart -----------------------" << endl;
    
    for (i = 0; i < n; i++) {
        cout << name[i] << "         ";
    }
    cout << endl;
    
    for (i = 0; i < n; i++) {
        cout << "|=========";
    }
    cout << "|" << endl;
    
    for (i = 0; i <= n; i++) {
        cout << time[i] << "         ";
    }
    
    cout << endl << endl;
    
    AvWT = (float)totWT / n; // Rata-rata waiting time
    AvTA = (float)totTA / n; // Rata-rata turn around time
    cout << "\tAverage Waiting Time : " << AvWT << endl;
    cout << "\tAverage Turn Around Time : " << AvTA << endl;

    return 0;
}
