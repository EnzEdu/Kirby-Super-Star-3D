/*  GIMP header image file format (RGB): /home/enzo/Desktop/CG/CG.aGame_EnzoEduardo/img/texturaHud.h */

static unsigned int hudWidth = 16;
static unsigned int hudHeight = 16;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}

static const char *header_data_hud =
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\W;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GW;\"GDV9\\"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"";
