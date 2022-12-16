#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//time
typedef struct {
	double time;
} time__t;

time__t* time_malloc() {
	return (time__t*)malloc(sizeof(time__t));
}

void time__init(time__t* t) {
	t->time = 0;
}

void zeroed(time__t* t) {
	t->time = clock();
}

double get_hours(time__t* t) {
	return (clock() - t->time) / 3600000.0;
}

//sun
typedef struct {
	bool light;
} sun_t;

sun_t* sun_malloc() {
	return (sun_t*)malloc(sizeof(sun_t));
}

void sun_init(sun_t* sun) {
	sun->light = 1;
}

bool is_lightening(sun_t* sun) {
	return sun->light;
}

void set_light(sun_t* sun, time__t* t) {
	sun->light = (get_hours(t) <= 4);
}

//tree
typedef struct {
	int air;
} tree_t;

tree_t* tree_malloc() {
	return (tree_t*)malloc(sizeof(tree_t));
}

void tree_init(tree_t* tree) {
	tree->air = 5;
}

int get_quantity_of_air(tree_t* tree) {
	printf("The tree is producing %d air.", tree->air);
	return tree->air;
}

void set_quantity_of_air(tree_t* tree, int q) {
	tree->air = q;
}

bool is_producing(tree_t* tree, sun_t* sun) {
	tree->air += 5;
	return is_lightening(sun);
}

//frog
typedef struct {
	int quantity_of_grass_in_stomach;
	bool is_awake;
	int quantity_of_breathing_air;
	int x_coord;
	int y_coord;
} frog_t;

frog_t* frog_malloc() {
	return (frog_t*)malloc(sizeof(frog_t));
}

void frog_init(frog_t* frog) {
	frog->quantity_of_grass_in_stomach = 0;
	frog->is_awake = 1;
	frog->quantity_of_breathing_air = 0;
	frog->x_coord = 0;
	frog->y_coord = 0;
}

int get_quantity_of_grass_in_stomach(frog_t* frog) {
	return frog->quantity_of_grass_in_stomach;
}

bool get_is_awake(frog_t* frog) {
	return frog->is_awake;
}

void set_is_awake(frog_t* frog, bool b) {
	frog->is_awake = b;
}
void breathing_air(frog_t* frog, tree_t* tree) {
	frog->quantity_of_breathing_air += get_quantity_of_air(tree);
}
void set_quantity_of_grass_in_stomach(frog_t* frog, int q) {
	frog->quantity_of_grass_in_stomach = q;
}
void is_walking_to_right(frog_t* frog) {
	int i = 15;
	frog->x_coord = i;
}
void is_walking_down(frog_t* frog) {
	int i = 15;
	frog->y_coord = i;
}

//grass
typedef struct {
	int quantity;
} grass_t;

grass_t* grass_malloc() {
	return (grass_t*)malloc(sizeof(grass_t));
}

void grass_init(grass_t* grass) {
	grass->quantity = INT_MAX;
}

long long int get_quantity(grass_t* grass) {
	return grass->quantity;
}

void frog_is_eating(grass_t* grass, frog_t* frog) {
	grass->quantity -= 5;
	set_quantity_of_grass_in_stomach(frog, get_quantity_of_grass_in_stomach(frog) + 5);
}