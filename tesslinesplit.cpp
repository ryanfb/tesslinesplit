#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
#include <libgen.h>

int main(int argc, char *argv[]) {
  if(argc != 3) { printf("USAGE: %s imagefile outputdir\n", argv[0]); return 1; }

  std::string input_filename = std::string(argv[1]);
  std::string input_basename = std::string(basename(argv[1]));

  std::string output_dir = std::string(argv[2]);

  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  api->Init(NULL, "eng");
  Pix *image0 = pixRead(input_filename.c_str());
  api->SetImage(image0);
  l_int32 input_format = pixGetInputFormat(image0);
  Pix* image = api->GetThresholdedImage();
  api->SetImage(image);
  Boxa* boxes = api->GetComponentImages(tesseract::RIL_TEXTLINE, true, false, 0, NULL, NULL, NULL);

  printf("Found %d textline image components.\n", boxes->n);

  int lastindex = input_basename.find_last_of(".");
  std::string basename = input_basename.substr(0, lastindex).c_str();
  std::string extension = input_basename.substr(lastindex + 1).c_str();

  std::string outdir = output_dir.c_str();
  int linedirLen = outdir.length()+1+basename.length()+strlen("-line_extract_")+extension.length();
  char* linedir = (char*)malloc((linedirLen+1)*sizeof(char));
  sprintf(linedir, "%s/%s-line_extract_%s", output_dir.c_str(), basename.c_str(), extension.c_str());
  printf("Writing to directory [%s].  If this fails, try:\n    mkdir -p %s\n\n\n", linedir, linedir);
  std::string mkdir_cmd = "mkdir -p " + std::string(linedir);
  system(mkdir_cmd.c_str());

  for (int i = 0; i < boxes->n; i++) {
    BOX* box = boxaGetBox(boxes, i, L_CLONE);
    PIX* pixd= pixClipRectangle(image, box, NULL);

    char* linefilename = (char*)malloc((linedirLen+strlen("/line00.")+extension.length()+1)*sizeof(char));
    sprintf(linefilename, "%s/line%02d.%s", linedir, i, extension.c_str());
    printf("  Writing %s\n", linefilename);
    pixWrite(linefilename, pixd, input_format);
    pixDestroy(&pixd);
    boxDestroy(&box);
    free(linefilename);
  }

  free(linedir);
  return 0;
}
