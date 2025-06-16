#include<iostream>
using namespace std;

int main() {
    int n = 5;
    int r = 3;

    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int maxi[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[3] = {3, 3, 2};

    int need[n][r];

    cout << "Need Matrix:\nABC\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = maxi[i][j] - alloc[i][j];
            cout << need[i][j];
        }
        cout << endl;
    }


    int f[n], ans[n], ind = 0;
    for(int k = 0; k < n; k++) f[k] = 0;

    for(int k = 0; k < 5; k++) {
        for(int i = 0; i < n; i++) {
            if(f[i] == 0) {
                int flag = 0;
                for(int j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    ans[ind++] = i;
                    for(int y = 0; y < r; y++) avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    cout << "Initial Safe Sequence:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << ans[i];
        if(i != n - 1) cout << " -> ";
    }
    cout << endl;


    int request[3] = {1, 0, 2};
    int process = 1; // P1
    bool canGrant = true;


    for(int i = 0; i < r; i++) {
        if(request[i] > need[process][i]) {
            canGrant = false;
            break;
        }
    }


    if(canGrant) {
        for(int i = 0; i < r; i++) {
            if(request[i] > avail[i]) {
                canGrant = false;
                break;
            }
        }
    }

    if(canGrant) {
        cout << "\nRequest {1, 0, 2} from P1 can be granted.\n";


        for(int i = 0; i < r; i++) {
            avail[i] -= request[i];
            alloc[process][i] += request[i];
            need[process][i] -= request[i];
        }


        int f2[n], ans2[n], ind2 = 0;
        for(int i = 0; i < n; i++) f2[i] = 0;

        for(int k = 0; k < 5; k++) {
            for(int i = 0; i < n; i++) {
                if(f2[i] == 0) {
                    int flag = 0;
                    for(int j = 0; j < r; j++) {
                        if(need[i][j] > avail[j]) {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0) {
                        ans2[ind2++] = i;
                        for(int y = 0; y < r; y++) avail[y] += alloc[i][y];
                        f2[i] = 1;
                    }
                }
            }
        }

        bool isSafe = true;
        for(int i = 0; i < n; i++) {
            if(f2[i] == 0) {
                isSafe = false;
                break;
            }
        }

        if(isSafe) {
            cout << "Safe Sequence after granting request:\n";
            for(int i = 0; i < n; i++) {
                cout << "P" << ans2[i];
                if(i != n - 1) cout << " -> ";
            }
            cout << endl;
        } else {
            cout << "System would be in an unsafe state after granting request.\n";
        }
    } else {
        cout << "\nRequest {1, 0, 2} from P1 cannot be granted immediately.\n";
    }

    return 0;
}
