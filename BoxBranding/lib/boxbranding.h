#ifndef __BRANDING_H__
#define __BRANDING_H__

bool startsWith (char* base, char* str);
bool endsWith (char* base, char* str);
int fileExist(const char* filename);

/* The caller is always responsible for calling free() on the returned
 * string from all the functions that follow. */

char *ReadProcEntry(char *filename);

char *_getBoxType();
char *_getMachineName();
char *_getMachineBrand();
char *_getBrandOEM();
char *_getDriverDate();
char *_getImageVersion();
char *_getImageBuild();
char *_getImageDevBuild();
char *_getImageType();
char *_getImageDistro();
char *_getFeedsUrl();
char *_getImageFolder();
char *_getImageFileSystem();
char *_getOEVersion();
char *_getMachineBuild();
char *_getMachineMake();
char *_getMachineMtdRoot();
char *_getMachineRootFile();
char *_getMachineMtdKernel();
char *_getMachineKernelFile();
char *_getMachineMKUBIFS();
char *_getMachineUBINIZE();
char *_getMachineProcModel();
char *_getImageArch();

#endif
