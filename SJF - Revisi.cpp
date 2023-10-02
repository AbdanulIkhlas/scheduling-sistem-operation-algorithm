#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int i, j, n, burst_time[10], start_time[10], end_time[10], wait_time[10], temp, total;
    float avg;

    cout << "+-------------------------------------+" << endl;
    cout << "| Nama    : Muhammad Abdanul Ikhlas   |" << endl;
    cout << "| NIM     : 123210009                 |" << endl;
    cout << "| Kelas   : IF - C                    |" << endl;
    cout << "+-------------------------------------+" << endl;

    cout << "Enter the No. of jobs: ";
    cin >> n;
    cout << endl;

    for (i = 1; i <= n; i++) {
        cout << "Enter process " << i << " burst time: ";
        cin >> burst_time[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (burst_time[i] > burst_time[j]) {
                swap(burst_time[i], burst_time[j]);
            }
        }

        if (i == 1) {
            start_time[1] = 0;
            end_time[1] = burst_time[1];
            wait_time[1] = 0;
        } else {
            start_time[i] = end_time[i - 1];
            end_time[i] = start_time[i] + burst_time[i];
            wait_time[i] = start_time[i];
        }
    }

    cout << "\n +------------------------------------------------------+" << endl;
    cout << " | BURST TIME  |  STARTING TIME | END TIME  | WAIT TIME |" << endl;
    cout << " +------------------------------------------------------+" << endl;

    for (i = 1; i <= n; i++) {
        cout << " |      " << setiosflags(ios::left) << setw(3) << burst_time[i] << "    |       " << setw(7) << start_time[i] << "  |     " << setw(4) << end_time[i] << "  |    " << setw(5) << wait_time[i] << "  |" << endl;
    }

    cout << " +------------------------------------------------------+" << endl;

    for (i = 1, total = 0; i <= n; i++) {
        total += wait_time[i];
    }

    avg = (float)total / n;
    cout << "\n\n AVERAGE WAITING TIME=" << avg << endl;

    for (i = 1, total = 0; i <= n; i++) {
        total += end_time[i];
    }

    avg = (float)total / n;
    cout << "\n AVERAGE TURNAROUND TIME=" << avg << endl;

    for (i = 1, total = 0; i <= n; i++) {
        total += start_time[i];
    }

    avg = (float)total / n;
    cout << "\n AVERAGE RESPONSE TIME=" << avg << endl;

    return 0;
}
