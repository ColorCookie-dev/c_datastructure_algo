#include <stdio.h>

int main() {
	int n, m, i, j, k;

	// Number of processes
	n = 5;
	
	// Number of resources
	m = 3;

	// Already allocated
	int alloc[5][3] = {
		{ 0, 1, 0 },
		{ 2, 0, 0 },
		{ 3, 0, 1 },
		{ 2, 1, 1 },
		{ 0, 0, 2 },
	};

	// Maximum to be allocated for each process
	int max[5][3] = {
		{ 7, 5, 3 },
		{ 3, 2, 2 },
		{ 9, 0, 2 },
		{ 2, 2, 2 },
		{ 4, 3, 3 },
	};

	// Currently available resources
	int avail[3] = { 3, 3, 2 };

	// ans stores the sequence of execution
	// f signifies if process ran or not
	int f[n], ans[n], idx = 0;

	// Initializing f with zeros
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	
	// Creating and calcuating the need matrix
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}

	int y = 0;

	// Runs for each process in case of one process ends up running
	// in each iteration, to have enough iteration to make sure each process
	// has enough time to run
	for (k = 0; k < 5; k++) {

		// Runs for each process
		for (i = 0; i < n; i++) {

			// f can be changed once for each process
			if (f[i] == 0) {
				int resources_are_available = 1;

				// Runs for each resources
				// All resources required by process is
				// available
				for (j = 0; j < m; j++) {
					// If Process requires more resources
					// than available
					if (need[i][j] > avail[j]) {
						resources_are_available = 0;
						break;
					}
				}

				if (resources_are_available == 1) {
					// Process is allowed to run
					ans[idx++] = i;

					// Adding resources to allocations
					for (y = 0; y < m; y++) {
						avail[y] += alloc[i][y];
					}
					
					// Indicating process ran
					f[i] = 1;
				}
			}
		}
	}

	// Check if any process failed to run
	for (int i = 0; i < n; i++) {
		if (f[i] == 0) {
			printf("The following is not safe\n");
			return 0;
		}
	}

	printf("Following is a safe sequence\n");
	for (i = 0; i < n - 1; i++) {
		printf(" P%d ->", ans[i]);
	}
	printf(" P%d\n", ans[n - 1]);

	return 0;
}
