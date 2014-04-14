#ifndef __BRANDING_H__
#define __BRANDING_H__

bool startsWith (char* base, char* str);
bool endsWith (char* base, char* str); 
int fileExist(const char* filename);
char* ReadProcEntry(char *filename);

const char *_getBoxType();
const char *_getMachineName();
const char *_getMachineBrand();
const char *_getBrandOEM();
const char *_getDriverDate();
const char *_getImageVersion();
const char *_getImageBuild();
const char *_getImageDistro();
const char *_getImageFolder();
const char *_getImageFileSystem();
const char *_getOEVersion();
const char *_getMachineBuild();
const char *_getMachineMake();
const char *_getMachineMtdRoot();
const char *_getMachineRootFile();
const char *_getMachineMtdKernel();
const char *_getMachineKernelFile();
const char *_getMachineMKUBIFS();
const char *_getMachineUBINIZE();
const char *_getMachineProcModel();

#endif
