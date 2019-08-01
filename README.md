tesslinesplit
=============

This is a standalone program for using Tesseract's line segmentation algorithm to split up document images.

* `tesslinesplit-ocular` - Outputs detected lines as cropped images. The default output filenames are designed to be suitable for feeding into [Ocular](https://github.com/tberg12/ocular).
* `tesslinesplit-kraken` - Outputs detected lines as JSON. Output is designed to be suitable for feeding into [Kraken](https://kraken.re/).

Requirements:

 * `tesseract`
 * `leptonica`

Requirements are handled in the `Makefile` via `pkg-config`. You may need the `-dev` versions of the `lib` packages for these requirements, depending on your system and package manager.

Usage:

 * `make`
 * `./tesslinesplit-ocular imagefile.ext outputdir`
 * `./tesslinesplit-kraken imagefile.ext outputfile.json`

[Docker usage](https://hub.docker.com/r/ryanfb/tesslinesplit):

    docker run -ti -v $(pwd):/data ryanfb/tesslinesplit tesslinesplit-kraken inputimage.png outputsegmentation.json
