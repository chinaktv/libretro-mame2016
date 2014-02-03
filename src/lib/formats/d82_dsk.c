// license:BSD-3-Clause
// copyright-holders:Curt Coder
/*********************************************************************

    formats/d82_dsk.c

    Commodore 8250/SFD-1001 sector disk image format

*********************************************************************/

#include "emu.h"
#include "formats/d82_dsk.h"

d82_format::d82_format() : d80_format(formats)
{
}

const char *d82_format::name() const
{
	return "d82";
}

const char *d82_format::description() const
{
	return "Commodore 8250/SFD-1001 disk image";
}

const char *d82_format::extensions() const
{
	return "d82";
}

const d82_format::format d82_format::formats[] = {
	{ // d82, dos 2.5, 77 tracks, 2 heads, head/stepper 100 tpi
		floppy_image::FF_525, floppy_image::DSQD, 2083, 77, 2, 256, 9, 8
	},
	{}
};

const floppy_format_type FLOPPY_D82_FORMAT = &floppy_image_format_creator<d82_format>;