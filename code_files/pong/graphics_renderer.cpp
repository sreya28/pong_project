// clear the screen and set window colour 
static void clear_screen(unsigned int colour)
{
	unsigned int* pixel = (unsigned int*)render_state.memory;
	for (int y = 0; y < render_state.height; y++)
	{
		for (int x = 0; x < render_state.width; x++)
		{
			*pixel++ = colour;
		}
	}
}

// clamp rectangle coordinates so it does not go off the window
static inline int clamp(int min, int val, int max)
{
	if (val < min) return min; 
	if (val > max) return max; 
	return val;
}

// draw the rectangle based on pixel coordinates
static void draw_rect_in_pixels(int x0, int y0, int x1, int y1, unsigned int colour)
{
	// clamp the coordinates so it does not go out of the window
	x0 = clamp(0, x0, render_state.width);
	x1 = clamp(0, x1, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	y1 = clamp(0, y1, render_state.height);

	// draw rectangle 
	for (int y = y0; y < y1; y++)
	{
		unsigned int* pixel = (unsigned int*)render_state.memory + x0 + y*render_state.width;
		for (int x = x0; x < x1; x++)
		{
			*pixel++ = colour; 
		}
	}
}

// draw arena boarders in window
static void draw_arena_borders(float arena_x, float arena_y, unsigned int color) {
	// scale the percentage inputs using window height and render scaler
	arena_x *= render_state.height * render_state.render_scale;
	arena_y *= render_state.height * render_state.render_scale;

	// scale based on width and height of screen
	int x0 = (int)((float)render_state.width * .5f - arena_x);
	int x1 = (int)((float)render_state.width * .5f + arena_x);
	int y0 = (int)((float)render_state.height * .5f - arena_y);
	int y1 = (int)((float)render_state.height * .5f + arena_y);

	// draw the arena
	draw_rect_in_pixels(0, 0, render_state.width, y0, color);
	draw_rect_in_pixels(0, y1, x1, render_state.height, color);
	draw_rect_in_pixels(0, y0, x0, y1, color);
	draw_rect_in_pixels(x1, y0, render_state.width, render_state.height, color);
}

// draw a rectangle with given dimensions and colour. Dimensions are as a percentage of screen dimensions
static void draw_rect(float x, float y, float width, float height, unsigned int colour)
{
	// scale the percentage inputs using window height and render scaler
	x *= render_state.height * render_state.render_scale;
	y *= render_state.height * render_state.render_scale;
	width *= render_state.height * render_state.render_scale;
	height *= render_state.height * render_state.render_scale;

	// scale based on width and height of screen
	x += render_state.width / 2.f;
	y += render_state.height / 2.f;

	// change values to pixels
	int x0 = x - width/2;
	int y0 = y - height/2;
	int x1 = x + width/2;
	int y1 = y + height/2;

	// draw the rectangle 
	draw_rect_in_pixels(x0,y0,x1,y1,colour);
}

// draw a number 
static void draw_number(int number, float x, float y, float size, unsigned int color) {
	float half_size = size * .5f;

	bool drew_number = false;
	while (number || !drew_number) {
		drew_number = true;

		int digit = number % 10;
		number = number / 10;

		switch (digit) {
			case 0: {
				draw_rect(x - size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x + size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x, y + size, half_size, half_size, color);
				draw_rect(x, y - size, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 1: {
				draw_rect(x + size, y, half_size, 2.5f * size, color);
				x -= size * 2.f;
			} break;

			case 2: {
				draw_rect(x, y + size, 1.5f * size, half_size, color);
				draw_rect(x, y, 1.5f * size, half_size, color);
				draw_rect(x, y - size, 1.5f * size, half_size, color);
				draw_rect(x + size / 2.f, y + size / 2.f, half_size, half_size, color);
				draw_rect(x - size / 2.f, y - size / 2.f, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 3: {
				draw_rect(x - half_size, y + size, size, half_size, color);
				draw_rect(x - half_size, y, size / 2.f, half_size, color);
				draw_rect(x - half_size, y - size, size, half_size, color);
				draw_rect(x, y, half_size, 2.5f * size, color);
				x -= size * 3.f;
			} break;

			case 4: {
				draw_rect(x + size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x - size / 2.f, y + size / 2.f, half_size, 1.5f * size, color);
				draw_rect(x, y, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 5: {
				draw_rect(x, y + size, 1.5f * size, half_size, color);
				draw_rect(x, y, 1.5f * size, half_size, color);
				draw_rect(x, y - size, 1.5f * size, half_size, color);
				draw_rect(x - size / 2.f, y + size / 2.f, half_size, half_size, color);
				draw_rect(x + size / 2.f, y - size / 2.f, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 6: {
				draw_rect(x + half_size / 2.f, y + size, size, half_size, color);
				draw_rect(x + half_size / 2.f, y, size, half_size, color);
				draw_rect(x + half_size / 2.f, y - size, size, half_size, color);
				draw_rect(x - size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x + size / 2.f, y - size / 2.f, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 7: {
				draw_rect(x + size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x - half_size / 2.f, y + size, size, half_size, color);
				x -= size * 3.f;
			} break;

			case 8: {
				draw_rect(x - size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x + size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x, y + size, half_size, half_size, color);
				draw_rect(x, y - size, half_size, half_size, color);
				draw_rect(x, y, half_size, half_size, color);
				x -= size * 3.f;
			} break;

			case 9: {
				draw_rect(x - half_size / 2.f, y + size, size, half_size, color);
				draw_rect(x - half_size / 2.f, y, size, half_size, color);
				draw_rect(x - half_size / 2.f, y - size, size, half_size, color);
				draw_rect(x + size / 2.f, y, half_size, 2.5f * size, color);
				draw_rect(x - size / 2.f, y + size / 2.f, half_size, half_size, color);
				x -= size * 3.f;
			} break;
		}

	}
}

const char* letters[][7] = {
	" 00",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"000",

	" 000",
	"0",
	"0",
	"0",
	"0",
	"0",
	" 000",

	"000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0",

	" 000",
	"0",
	"0",
	"0 00",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	"000",

	" 000",
	"   0",
	"   0",
	"   0",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0 0",
	"00",
	"0 0",
	"0  0",
	"0  0",

	"0",
	"0",
	"0",
	"0",
	"0",
	"0",
	"0000",

	"00 00",
	"0 0 0",
	"0 0 0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",

	"00  0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0  00",

	"0000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0000",

	" 000",
	"0  0",
	"0  0",
	"000",
	"0",
	"0",
	"0",

	" 000 ",
	"0   0",
	"0   0",
	"0   0",
	"0 0 0",
	"0  0 ",
	" 00 0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"0  0",

	" 000",
	"0",
	"0 ",
	" 00",
	"   0",
	"   0",
	"000 ",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",

	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	" 00",

	"0   0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",
	" 0 0",
	"  0",

	"0   0 ",
	"0   0",
	"0   0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	" 0 0 ",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	" 0 0",
	"0   0",
	"0   0",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	"  0",
	"  0",
	"  0",

	"0000",
	"   0",
	"  0",
	" 0",
	"0",
	"0",
	"0000",

	"",
	"",
	"",
	"",
	"",
	"",
	"0",

	"   0",
	"  0",
	"  0",
	" 0",
	" 0",
	"0",
	"0",

	"    0   ",
	"  0   0",
	"   0 0",
	"0 0 0 0 0",
	"   0 0",
	"  0   0",
	"    0   ",
	
	"        ",
	"  00",
	" 0  0",
	"0    0    0",
	"      0  0",
	"       00",
	"        ",
		
	"    0",
	"     0",
	"      0",
	"00000000",
	"      0",
	"     0 ",
	"    0",

	"      ",
	"   0",
	"  000",
	" 00000",
	" 0   0",
	" 0   0",
	" 00000",
};

static void draw_text(const char* text, float x, float y, float size, unsigned int colour) {
	float half_size = size * .5f;
	float original_y = y;

	while (*text) {
		if (*text != 32) {
			const char** letter;
			if (*text == 47) letter = letters[27];
			else if (*text == 46) letter = letters[26];
			else if (*text == 42) letter = letters[28];
			else if (*text == 126) letter = letters[29];
			else if (*text == 62) letter = letters[30];
			else if (*text == 104) letter = letters[31];
			else letter = letters[*text - 'A'];
			float original_x = x;

			for (int i = 0; i < 7; i++) {
				const char* row = letter[i];
				while (*row) {
					if (*row == '0') {
						draw_rect(x, y, half_size, half_size, colour);
					}
					x += size / 3.f;
					row++;
				}
				y -= size / 3.f;
				x = original_x;
			}
		}
		text++;
		x += size * 3.f;
		y = original_y;
	}
}

// render the game graphics 
void render_game(HDC hdc)
{
	StretchDIBits(
		hdc,
		0,
		0,
		render_state.width,
		render_state.height,
		0,
		0,
		render_state.width,
		render_state.height,
		render_state.memory,
		&render_state.bitmap_info,
		DIB_RGB_COLORS,
		SRCCOPY);
}