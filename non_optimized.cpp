
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void LUdecomposition(vector<vector<float>>& a, vector<vector<float>>& l, vector<vector<float>>& u, int n) {
    int i = 0, j = 0, k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i)
                l[j][i] = 0;
            else {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++) {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++) {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++) {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}

int main() 
{
	int i = 0, j = 0;

	int n = 4000;

    vector<vector<float>> a(n, vector<float>(n)), l(n, vector<float>(n)), u(n, vector<float>(n));

	std::srand(static_cast<unsigned>(std::time(nullptr)));

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			a[i][j] = static_cast<double>(rand()) / RAND_MAX;
		}
	}

	auto start = std::chrono::high_resolution_clock::now();


    LUdecomposition(a, l, u, n);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
