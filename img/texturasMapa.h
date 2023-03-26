/*  GIMP header image file format (RGB): /home/enzo/Desktop/kirby/texturasMapa.h  */

static unsigned int tilesWidth = 48;
static unsigned int tilesHeight = 32;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static const char *header_data_tiles =
	".9!#G?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61G?61.9!#"
	"'T=).9!#;LYQ.9!#FJMZFJMZFJMZFJMZFJMZFJMZFJMZFJMZ.9!#.9!#.9!#'T=)"
	"``)!``)!``)!``)!``)!``)!``)!`Y9!`Y9!``)!``)!``)!``)!``)!``)!``)!"
	"G?61G?61.9!#G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQ.9!#G?61"
	".9!#.9!#Q-A=.9!#DV9\\FJMZDV9\\<7NLFJMZFJMZDV9\\FJMZ.9!#;LYQ'T=).9!#"
	"``)!``)!``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!``)!``)!"
	".9!#G?61;LYQG?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DER.9!#.9!#G?61G?61"
	"'T=)Q-A=Q-A=Q-A=FJMZFJMZDV9\\FJMZFJMZ<7NLFJMZFJMZ'T=)'T=).9!#;LYQ"
	"``)!``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!``)!"
	";LYQG?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61G?61G?61"
	".9!#.9!#Q-A=.9!#FJMZFJMZ<7NLFJMZFJMZFJMZFJMZDV9\\.9!#;LYQ.9!#.9!#"
	"``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!"
	"G?61G?61.9!#G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQG?61G?61"
	";LYQ;LYQ'T=).9!#FJMZDV9\\<7NLFJMZFJMZ<7NLFJMZFJMZ.9!#Q-A=.9!#;LYQ"
	"`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!"
	"G?61;LYQG?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQG?61.9!#"
	";LYQ.9!#.9!#;LYQFJMZFJMZFJMZFJMZFJMZ<7NLFJMZFJMZQ-A=Q-A=Q-A='T=)"
	"`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!"
	"G?61;LYQG?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DER.9!#G?61G?61G?61"
	".9!#;LYQ.9!#.9!#<7NLFJMZFJMZDV9\\FJMZFJMZFJMZFJMZ'T=)Q-A=.9!#.9!#"
	"``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!"
	"G?61G?61.9!#G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61.9!#G?61"
	".9!#.9!#'T=).9!#FJMZ<7NLFJMZFJMZDV9\\DV9\\FJMZFJMZ;LYQ.9!#'T=).9!#"
	"``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!"
	".9!#G?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61;LYQG?61"
	"'T=).9!#Q-A=.9!#FJMZ<7NL<7NLFJMZFJMZFJMZFJMZFJMZ.9!#.9!#.9!#.9!#"
	"``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!"
	"G?61;LYQ;LYQG?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQG?61G?61"
	".9!#Q-A=Q-A=Q-A=FJMZFJMZFJMZFJMZ<7NLFJMZFJMZFJMZ.9!#;LYQ.9!#.9!#"
	"``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!"
	"G?61;LYQ.9!#G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61;LYQG?61"
	".9!#.9!#Q-A=.9!#FJMZDV9\\FJMZFJMZ<7NLFJMZFJMZDV9\\.9!#.9!#;LYQ.9!#"
	"``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!"
	"G?61G?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61.9!#;LYQG?61"
	";LYQ.9!#.9!#.9!#FJMZFJMZFJMZFJMZFJMZFJMZ<7NLFJMZ.9!#Q-A=.9!#.9!#"
	"``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!"
	"G?61G?61;LYQ;LYQ:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQ;LYQG?61"
	".9!#.9!#.9!#.9!#<7NLFJMZFJMZ<7NLFJMZFJMZFJMZFJMZQ-A=Q-A=Q-A=;LYQ"
	"``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!"
	";LYQG?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61G?61G?61G?61"
	".9!#;LYQ;LYQ.9!#FJMZFJMZFJMZFJMZFJMZDV9\\FJMZFJMZ.9!#Q-A=.9!#.9!#"
	"``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!"
	"G?61.9!#;LYQG?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DERG?61;LYQG?61.9!#"
	".9!#'T=).9!#.9!#FJMZ<7NLFJMZFJMZFJMZFJMZ<7NLFJMZ.9!#;LYQ.9!#'T=)"
	"`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!`Y9!"
	"G?61G?61G?61G?61:DERDV9\\DV9\\DV9\\DV9\\DV9\\DV9\\:DER.9!#G?61;LYQG?61"
	";LYQ.9!#.9!#;LYQ<7NLFJMZFJMZFJMZ<7NLFJMZFJMZFJMZ'T=).9!#;LYQ.9!#"
	"`Y9!`Y9!`Y9!`Y9!`Y9!``)!``)!``)!``)!``)!``)!`Y9!`Y9!`Y9!`Y9!`Y9!"
	";,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E"
	".RU:.RU:.RU:'RI;'RI;'RI;'RI;'RI;'RI;'RI;'RI;'RI;'RI;.RU:.RU::DER"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	";,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E````````````;,<E;,<E"
	".RU:.RU:.RU:.RU:.RU:'RI;'RI;'RI;'RI;'RI;'RI;'RI;.RU:.RU::DER.RU:"
	"!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	";,<E;,<E````````````;,<E;,<E;,<E;,<E;,<E````````````````````;,<E"
	".RU:.RU:.RU:.RU:.RU:.RU:.RU:'RI;'RI;'RI;'RI;'RI;'RI;'RI;.RU::DER"
	"!!!!`[%!`[%!`[%!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`[%!`[%!!!!!"
	";,<E````````````````````;,<E;,<E;,<E;,<E````````````````````;,<E"
	".RU:.RU:.RU:.RU:.RU:.RU:.RU:.RU:.RU:'RI;'RI;'RI;'RI;'RI;.RU:.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!`[%!`[%!!!!!"
	";,<E````````````````````;,<E;,<E;,<E;,<E;,<E````````````;,<E;,<E"
	".RU:.RU:.RU:.RU:.RU:.RU:.RU:'RI;'RI;'RI;*#-D*#-D*#-D'RI;'RI;.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!`[%!`[%!!!!!"
	";,<E;,<E````````````;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E"
	".RU:.RU:.RU:.RU:.RU:'RI;'RI;'RI;'RI;*#-D*#-D*#-D*#-D*#-D*#-D.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!`[%!`[%!!!!!"
	".9!#;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E.9!#"
	".RU:.RU:.RU::DER.RU:'RI;'RI;*#-D*#-D*#-D76:376:376:376:3*#-D.RU:"
	"!!!!`[%!`[%!`[%!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!`[%!`[%!!!!!"
	".9!#;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E.9!#G?61"
	".RU:.RU::DER.RU::DER*#-D*#-D1%\"!1%\"!76:376:376:376:376:376:3.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	".9!#;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E;,<E.9!#.9!#G?61"
	".RU:.RU:.RU::DER.RU:*#-D1%\"!76:376:376:376:376:376:376:376:3.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61.9!#;,<E;,<E;,<E.9!#.9!#;,<E;,<E;,<E;,<E;,<E;,<E.9!#.9!#G?61"
	".RU:.RU:.RU:.RU:.RU:1%\"!A)#!76:3A)#!A)#!A)#!76:376:376:3A)#!.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61.9!#;,<E;,<E.9!#G?61G?61.9!#;,<E;,<E;,<E;,<E.9!#.9!#G?61G?61"
	".RU:.RU:.RU:.RU:.RU:A)#!A)#!A)#!A)#!A)#!A)#!76:376:376:3A)#!.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61.9!#;,<E.9!#.9!#.9!#G?61G?61.9!#.9!#;,<E.9!#.9!#.9!#G?61G?61"
	".RU:.RU:.RU:.RU:.RU:A)#!A)#!A)#!A)#!A)#!A)#!76:376:376:3A)#!.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61.9!#;,<E.9!#.9!#G?61G?61.9!#.9!#.9!#;,<E.9!#.9!#G?61G?61G?61"
	".RU:.RU:.RU:.RU:.RU:A)#!A)#!76:3A)#!A)#!76:376:376:376:3A)#!.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61.9!#;LYQ.9!#.9!#.9!#.9!#.9!#.9!#.9!#;LYQ.9!#.9!#G?61G?61G?61"
	".RU:.RU:.RU:.RU:.RU:A)#!76:376:376:3A)#!76:376:376:376:3A)#!.RU:"
	"!!!!`[%!`[%!`[%!!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	".9!#.9!#;LYQ;LYQ.9!#.9!#.9!#.9!#.9!#;LYQ;LYQ.9!#.9!#.9!#.9!#.9!#"
	".RU:.RU:.RU:.RU:.RU:76:376:376:376:376:376:376:376:3A)#!76:3.RU:"
	"!!!!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!`[%!!!!!"
	"G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61G?61"
	".9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#.9!#"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"";