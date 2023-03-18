/*  GIMP header image file format (RGB): /home/enzo/Desktop/CG/CG.aGame_EnzoEduardo/img/grass2.h  */

static unsigned int width = 64;
static unsigned int height = 48;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *header_data =
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	":DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\DV9\\"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	":DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER:DER"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQG?61G?61G?61;LYQ;LYQG?61G?61G?61;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQG?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"G?61G?61G?61G?61VXO[VXO[VXO[G?61G?61VXO[VXO[VXO[G?61G?61G?61G?61"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"G?61G?61VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[G?61G?61"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO["
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO["
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO[VXO["
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"VXO[VXO[VXO[VXO[G?61G?61G?61VXO[VXO[G?61G?61G?61VXO[VXO[VXO[VXO["
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"VXO[VXO[G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61VXO[VXO["
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"G?61G?61G?61G?61;LYQ;LYQ;LYQG?61G?61;LYQ;LYQ;LYQG?61G?61G?61G?61"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"G?61G?61;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQG?61G?61"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	";LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ;LYQ"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"76:376:376:376:376:376:376:376:376:376:376:376:376:376:376:376:3"
	"````````````````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````````````"
	"";
