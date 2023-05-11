#include <stddef.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_PROC 3

int accumulate_vec(int *vec, size_t n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += vec[i];
	}
	return s;
}

void sub_vec(int *res, int *vec1, int *vec2, size_t n) {
	for (int i = 0; i < n; i++) {
		res[i] = vec1[i] - vec2[i];
	}
}

void print_vec(int *vec, size_t n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", vec[i]);
	}
	puts("");
}

int main() {
	int no_of_proc = NO_OF_PROC;
	int time_slice = 5;

	// Assuming non-zero execution time
	int burst_time[NO_OF_PROC] = { 10, 30, 14 };
	int burst_time_copy[no_of_proc];
	memcpy(burst_time_copy, burst_time, sizeof(burst_time));

	int wait_time[no_of_proc], turnaround_time[no_of_proc];
	memset(turnaround_time, 0, sizeof(turnaround_time));
	memset(wait_time, 0, sizeof(wait_time));

	int max_time = accumulate_vec(burst_time, no_of_proc);
	int time_passed = 0;
	while (time_passed < max_time) {
		for (int i = 0; i < no_of_proc; i++) {
			if (burst_time[i] != 0) {
				int exec_time = 0;
				if (burst_time[i] <= time_slice) {
					exec_time = burst_time[i];
				} else {
					exec_time = time_slice;
				}
				burst_time[i] -= exec_time;
				time_passed += exec_time;
				turnaround_time[i] = time_passed;
			}
		}
	}

	printf("time_passed: %d\n", time_passed);

	puts("Turnaround Time");
	print_vec(turnaround_time, no_of_proc);
	printf("Average Turnaround Time: %.2f\n",
			(double)accumulate_vec(turnaround_time,no_of_proc)
			/ no_of_proc);

	sub_vec(wait_time, turnaround_time, burst_time_copy, no_of_proc);

	puts("Turnaround Time");
	print_vec(wait_time, no_of_proc);
	printf("Average Waiting Time: %.2f\n",
			(double)accumulate_vec(wait_time, no_of_proc)
			/ no_of_proc);

	return 0;
}
