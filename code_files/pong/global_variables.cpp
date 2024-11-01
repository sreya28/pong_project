//  --------------------------------------------------------------- Boolean to know if game is running
bool running = true;

// --------------------------------------------------------------- Window Information 
struct Render_State
{
	int height, width;
	int orig_height = 720;
	int orig_width = 1280;

	float render_scale = 0.01f;

	unsigned int bg_colour = 0xffffff; // 0xccffcc; // light green

	void* memory;
	BITMAPINFO bitmap_info;
};
Render_State render_state;

// --------------------------------------------------------------- Button Information
struct Button_State 
{
	bool is_down;
	bool changed;
};

enum
{
	BUTTON_P1_UP,
	BUTTON_P1_DOWN,
	BUTTON_P2_UP,
	BUTTON_P2_DOWN,
	BUTTON_RIGHT,
	BUTTON_LEFT,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_ENTER,
	BUTTON_RESET,
	BUTTON_EXIT,

	BUTTON_COUNT
};

struct Input
{
	Button_State buttons[BUTTON_COUNT];
};

// --------------------------------------------------------------- Game Details 
int round_num = 5;

float delta_time = 0.016666f;

float arena_x = 87;
float arena_y = 45;
float snow_arena_x = 40;
unsigned int arena_colour = 0xff0000; // 0x99cc00;

bool reset_game_check = false;
int reset_counter = 0;

int snow_battle_highscore = 0;
int snow_battle_score = 0;
int snow_level = 1;

float snowman_speed_easy = 40; 
float snowman_speed_medium = 100; 
float snowman_speed_hard = 200;

bool snow_level_2 = false;
bool snow_level_3 = false;

unsigned int snowman_body_colour = 0xffffff;
 
float AI_acc_const_easy = 720;
float AI_acc_const_medium = 900;
float AI_acc_const_hard = 1160;
float AI_acc_const = AI_acc_const_easy;


float ball_speed_easy = 80; 
float ball_speed_medium = 130; 
float ball_speed_hard = 250; 
float ball_y_const_2_hard = 0.5f;

float ball_y_const_1 = 2.f;
float ball_y_const_2 = 0.35f;

unsigned int score_colour = 0x000000; //0x99cc00;

int score_pos_x = 25;
int score_pos_y = 40;
float score_width = 1.6f;

int colour_count = 0;
unsigned int win_banner_colour = 0xff0000;
unsigned int light_c1 = 0xffd11a; // yellow 
unsigned int light_c2 = 0x00ff00; // lime 
unsigned int light_c3 = 0xff3300; // red 

unsigned int select_colour = 0xb3d9ff;
unsigned int unselected_colour = 0x0099ff;

unsigned int selection_AI = 0x0099ff;
unsigned int selection_M = 0x66b3ff;
unsigned int selection_S = 0x0099ff;
unsigned int selection_D = 0x0099ff;

unsigned int select_Easy = 0x66b3ff;
unsigned int select_Medium = 0x0099ff;
unsigned int select_Hard = 0x0099ff;
unsigned int selected_diff = 0x00cc00;

unsigned int select_Home = 0x0099ff;
unsigned int selected_Home = 0xffcc00;

int select_val = 1;

float select_arrow_y = 20;
unsigned int arrow_colour = 0x66b3ff;
unsigned int arrow_on = 0x66b3ff;
unsigned int arrow_off = 0xffffff;

bool right_pressed = false; 
bool left_pressed = false; 

bool no_selection = true; 
bool AI_verse = false; 
bool snow_mode = false;
bool settings_mode = false; 
bool game_mode = false; 

// ---------------------------------------------------------------------------------- Macros
// set macros for button states
#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

// set macro for friction constant
#define f_const 10.f 