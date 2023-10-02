#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int st[10], bt[10], wt[10], tat[10], n, tq;
    int i, count = 0, swt = 0, stat = 0, temp, sq = 0;
    float awt = 0.0, atat = 0.0;

    cout << "+-----------------------------------+" << endl;
    cout << "| Nama    : Muhammad Abdanul Ikhlas   |" << endl;
    cout << "| NIM     : 123210009                 |" << endl;
    cout << "| Kelas   : IF - C                    |" << endl;
    cout << "+-----------------------------------+" << endl;

    cout << endl << "Enter number of processes: ";
    cin >> n;
    cout << endl;

    for (i = 0; i < n; i++) {
        cout << "Proses P=" << i + 1 << endl;
        cout << "Burst Time P" << i + 1 << " = ";
        cin >> bt[i];
        st[i] = bt[i];
        cout << endl;
    }

    cout << "Enter time quantum: ";
    cin >> tq;
    cout << endl;

    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            temp = tq;
            if (st[i] == 0) {
                count++;
                continue;
            }
            if (st[i] > tq)
                st[i] = st[i] - tq;
            else if (st[i] >= 0) {
                temp = st[i];
                st[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }

    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        swt = swt + wt[i];
        stat = stat + tat[i];
    }

    awt = (float)swt / n;
    atat = (float)stat / n;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "| NO PROSES |   Burst time   |    Wait time   |     Turn around time     |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    for (i = 0; i < n; i++) {
        cout << left << "|      " 
        << setw(4) << i + 1 << " |        " 
        << setw(7) << bt[i] << " |        " 
        << setw(7) << wt[i] << " |             "
        << setw(12) << tat[i] << " |"<< endl;
    }

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "Avg wait time is " << awt << endl;
    cout << "Turn around time is " << atat << endl;

    return 0;
}
