#include <stdio.h>
#include <stdbool.h>
#include "declarations.h"

int main(int argc, char** argv) {
	struct time__t* time = time_malloc();
	time__init(time);
	const double hours_in_a_day = 10;
	int count_of_days = 2;
	while (count_of_days) {
		struct sun_t* sun = sun_malloc();
		sun_init(sun);
		struct frog_t* frog = frog_malloc();
		frog_init(frog);
		struct tree_t* tree = tree_malloc();
		tree_init(tree);
		struct grass_t* grass = grass_malloc();
		grass_init(grass);
		if (is_lightening(sun)) {
			printf("The sun is shining brightly!\n");
		}
		if (get_is_awake(frog)) {
			printf("The frog is awake and is breathing air.\n");
		}
		while (get_hours(time) <= hours_in_a_day - 1) {
			set_light(sun, time);
			if (is_lightening(sun)) {
				if (is_producing(tree, sun)) {
					printf("The tree is producing some air.\n");
				}
				if (get_is_awake(frog)) {
					is_walking_to_right(frog);
					printf("The frog is walking to the right.\n");
					frog_is_eating(grass, frog);
					printf("The frog is eating some grass.\n");
					is_walking_down(frog);
					printf("The frog is walking down.\n");
					printf("The frog is eating some grass again.\n");
				}
			}
			else {
				printf("The sun isn't shining anymore.\n");
				set_is_awake(frog, false);
				printf("It's already night. The frog is sleeping peacefully.\n");
				if (!is_producing(tree, sun)) {
					printf("The tree is not producing air anymore.\n");
				}
			}
		}
		zeroed(time); 
		--count_of_days;
	}
	return 0;
}