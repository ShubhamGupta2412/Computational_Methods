#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double largest_Eigen(double A[3][3]) {
    double x[3] = {1, 1, 1};
    double tol = 0.00001;
    int max_iter = 100;

    double lambda_old, lambda_new;
    lambda_old = x[0];
    int n = 0;

    for (int i = 0; i < max_iter; i++) {
        double y[3] = {0, 0, 0};
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                y[j] += A[j][k] * x[k];
            }
        }

        lambda_new = y[0];
        for (int j = 1; j < 3; j++) {
            if (fabs(y[j]) > fabs(lambda_new)) {
                lambda_new = y[j];
            }
        }

        for (int j = 0; j < 3; j++) {
            x[j] = y[j] / lambda_new;
        }

        if (fabs(lambda_new - lambda_old) < tol) {
            break;
        }
        lambda_old = lambda_new;
        n++;
    }
    cout << "\nNumber of iterations required = " << n << endl;
    return lambda_new;
}

double determinant(double A[3][3]) {
    double result = 0;
    result += A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]);
    result -= A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]);
    result += A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
    return result;
}

void adjugate(double A[3][3], double adj[3][3]) {
    adj[0][0] = A[1][1] * A[2][2] - A[2][1] * A[1][2];
    adj[0][1] = A[0][2] * A[2][1] - A[0][1] * A[2][2];
    adj[0][2] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
    adj[1][0] = A[1][2] * A[2][0] - A[1][0] * A[2][2];
    adj[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
    adj[1][2] = A[1][0] * A[0][2] - A[0][0] * A[1][2];
    adj[2][0] = A[1][0] * A[2][1] - A[2][0] * A[1][1];
    adj[2][1] = A[2][0] * A[0][1] - A[0][0] * A[2][1];
    adj[2][2] = A[0][0] * A[1][1] - A[1][0] * A[0][1];
}

void inverse_matrix(double A[3][3], double inv_A[3][3]) {
    double det = determinant(A);
    if (det == 0) {
        cout << "\nDeterminant is 0. Inverse can't be found\n";
        exit(0);
    }
    double adj[3][3];
    adjugate(A, adj);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inv_A[i][j] = adj[i][j] / det;
        }
    }
}

int main() {
    double A[3][3] = {{-57, 192, 148}, {20, -53, -44}, {-48, 144, 115}};
    cout << "\nGiven Matrix : \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    
    double largestEigen = largest_Eigen(A);
    cout << "The largest eigenvalue of the matrix is : " << largestEigen << endl;

    double inv_A[3][3];
    inverse_matrix(A, inv_A);
    double smallestEigen = 1 / largest_Eigen(inv_A);
    cout << "The smallest eigenvalue of the matrix is : " << smallestEigen << endl;

    cout << endl;
    return 0;
}

