#include <stdbool.h>

struct time__t;
struct time__t* time_malloc();
//constructor
void time__init(struct time__t*);

//public functions
void zeroed(struct time__t*);
double get_hours(struct time__t*);


struct sun_t;
struct sun_t* sun_malloc();
//constructor
void sun_init(struct sun_t*);

//public functions
bool is_lightening(struct sun_t*);
void set_light(struct sun_t*, struct time__t*);


struct tree_t;
struct tree_t* tree_malloc();
//constructor
void tree_init(struct tree_t*);

//public functions
int get_quantity_of_air(struct tree_t*);
void set_quantity_of_air(struct tree_t*, int);
bool is_producing(struct tree_t*, struct sun_t*);


struct frog_t;
struct frog_t* frog_malloc();
//constructor
void frog_init(struct frog_t*);

//public functions
int get_quantity_of_grass_in_stomach(struct frog_t*);
bool get_is_awake(struct frog_t*);
void set_is_awake(struct frog_t*, bool);
void breathing_air(struct frog_t*, struct tree_t*);
void set_quantity_of_grass_in_stomach(struct frog_t*, int);
void is_walking_to_right(struct frog_t*);
void is_walking_down(struct frog_t*);


struct grass_t;
struct grass_t* grass_malloc();
//constructor
void grass_init(struct grass_t*);

//public functions
long long int get_quantity(struct grass_t*);
void frog_is_eating(struct grass_t*, struct frog_t*);