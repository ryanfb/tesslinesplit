tesslinesplit
=============

This is a standalone program for using Tesseract's line segmentation algorithm to split up document images. The default output filenames are designed to be suitable for feeding into [Ocular](https://github.com/tberg12/ocular).

Requirements:

 * `tesseract`
 * `leptonica`

Requirements are handled in the `Makefile` via `pkg-config`. You may need the `-dev` versions of the `lib` packages for these requirements, depending on your system and package manager.

Usage:

 * `make tesslinesplit-ocular`
 * `./tesslinesplit-ocular imagefile.ext outputdir`
