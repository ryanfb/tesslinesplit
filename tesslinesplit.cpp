#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
#include <libgen.h>

int main(int argc, char *argv[]) {
  std::string input_filename = std::string(argv[1]);
  std::string input_basename = std::string(basename(argv[1]));
  Pix *image = pixRead(input_filename.c_str());
  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  api->Init(NULL, "eng");
  api->SetImage(image);
  Boxa* boxes = api->GetComponentImages(tesseract::RIL_TEXTLINE, true, NULL, NULL);
  printf("Found %d textline image components.\n", boxes->n);
  for (int i = 0; i < boxes->n; i++) {
    BOX* box = boxaGetBox(boxes, i, L_CLONE);
    PIX* pixd= pixClipRectangle(image, box, NULL);
    int lastindex = input_basename.find_last_of(".");
    std::string basename = input_basename.substr(0, lastindex);
    std::string extension = input_basename.substr(lastindex + 1, 3);
    char* linefilename = (char*)malloc((basename.length()+strlen("-line_extract-00000.ext")+1)*sizeof(char));
    sprintf(linefilename, "%s-line_extract-%05d.%s", basename.c_str(), i, extension.c_str());
    pixWrite(linefilename, pixd, IFF_DEFAULT);
    pixDestroy(&pixd);
    boxDestroy(&box);
    free(linefilename);
  }
  return 0;
}
