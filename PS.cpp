#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n, ar[100], b[100], i, j, tmp, wt[100], ta[100], time[100];
    int totWT = 0, totTA = 0;
    float AvWT, AvTA;
    string name[20], tmpName;

    cout << "+-----------------------------------+" << endl;
    cout << "| Nama    : Muhammad Abdanul Ikhlas   |" << endl;
    cout << "| NIM     : 123210009                 |" << endl;
    cout << "| Kelas   : IF - C                    |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << endl <<"Program Penjadwalan Priority Scheduling" << endl;
    cout << "Banyak Proses\t = ";
    cin >> n;
    cout << endl;

    // Masukkan data yang diproses
    for (i = 0; i < n; i++) {
        cin.ignore();
        cout << "Nama Proses\t= ";
        getline(cin, name[i]);
        cout << "Burst time\t= ";
        cin >> b[i];
        cout << endl;
    }

    // SORTING Data
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                //tukar nama
                tmpName = name[i];
                name[i] = name[j];
                name[j] = tmpName;

                //tukar burst
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    time[0] = ar[0];
    cout << "--------------- Process Table --------------" << endl;
    cout << "+====+==========+================+==========+" << endl;
    cout << "| NO |  PROSES  |   TIME ARIVAL  |  BURST   |" << endl;
    cout << "+====+==========+================+==========+" << endl;

    for (i = 0; i < n; i++) {
        cout << left << "| " 
        << setw(2) << i + 1 << " |     "
        << setw(4) << name[i] << " |        " 
        << setw(7) << ar[i] << " |     " 
        << setw(4) << b[i] << " | "<< endl;
        time[i + 1] = time[i] + b[i]; //menghitung time pada ganchart
        wt[i] = time[i] - ar[i];
        ta[i] = time[i + 1] - ar[i];
        totWT += wt[i];
        totTA += ta[i];
    }

    cout << "+====+==========+================+==========+" << endl;

    cout << "\tTotal waiting time\t= " << totWT << endl;
    cout << "\tTurn around time\t= " << totTA << endl;
    cout <<endl<<endl;

    cout << "----------------- Time Process Table -------------" << endl;
    cout << "+====+==========+================+===============+" << endl;
    cout << "| NO |  PROSES  |  WAITING TIME  |  TURN AROUND  |" << endl;
    cout << "+====+==========+================+===============+" << endl;

    for (i = 0; i < n; i++) {
        cout << left << "| " 
        << setw(2) << i + 1 << " |     "  
        << setw(4) << name[i] << " |       "  
        << setw(7) << wt[i] << " |        " 
        << setw(7)<< ta[i] << " |"<<endl;
    }

    cout << "+====+==========+================+===============+" << endl;
    cout <<endl<<endl;

    //untuk Gant Chart
    cout << "--------------------- Gant Chart -----------------" << endl;
    for (i = 0; i < n; i++) {
        cout << name[i] << "         ";
    }
    cout << endl;

    for (i = 0; i < n; i++) {
        cout << "|=========";
    }
    cout << "|" << endl;

    for (i = 0; i <= n; i++) {
        cout << " " << time[i] << "          ";
    }

    cout << "\tdiperoleh dari penjumlahan Burst" << endl << endl;
    AvWT = (float)totWT / n; //average waiting time
    AvTA = (float)totTA / n; //average turn arround time
    cout << "\tAverage Waiting Time : " << AvWT << endl;
    cout << "\tAverage Turn Arround Time : " << AvTA << endl;

    return 0;
}
