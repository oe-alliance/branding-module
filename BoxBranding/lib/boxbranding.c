#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "boxbranding.h"

/** detecting whether base is starts with str
 */
bool startsWith (char* base, char* str) 
{
    return (strstr(base, str) - base) == 0;
}

/** detecting whether base is ends with str
 */
bool endsWith (char* base, char* str) 
{
    int blen = strlen(base);
    int slen = strlen(str);
    return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

/**
* Check if a file exist using stat() function
* return 1 if the file exist otherwise return 0
*/
int fileExist(const char* filename){
	struct stat buffer;
	int exist = stat(filename,&buffer);
	if(exist == 0)
	    return 1;
	else // -1
	    return 0;
}

/** reading file and return value from it
 * */
char* ReadProcEntry(char *filename)
{
	FILE *boxtype_file = fopen(filename,"r");
	char boxtype_name[20];
	char *real_boxtype_name = NULL;
	char c;
	int i = 0;
	
	if(boxtype_file)
	{
		while ((c = fgetc(boxtype_file)) != EOF && i < sizeof(boxtype_name) - 2)
		{
			if (c == '\n')
			{
				i--;
				break;
			}
			boxtype_name[i] = c;
			i++;
		}
		boxtype_name[i+1] = '\0';
		real_boxtype_name = malloc(strlen(boxtype_name) + 1);
		if (real_boxtype_name)
			strcpy(real_boxtype_name, boxtype_name);
		
		fclose(boxtype_file);
	}
	else
		puts("[BRANDING] Can not open this proc entry!\n");
	
	return real_boxtype_name;
}

const char *_getBoxType()	// this will try to find the correct BOX MACHINE e.x MACHINE=ventonhdx DISTRO=openvix -> it will return uniboxhd1   for a UniBox HD1
{
	// this ugly code will be removed after we will switch tottaly to OE-A 2.0
	char *boxtype_name = NULL;
	char *vu_boxtype_name = NULL;
	
	if(strcmp(BOXTYPE, "xpeedlx") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		if(strcmp(boxtype_name, "ini-1000lx") == 0) 
		{
			return "xpeedlx2t";
		}
		else if(strcmp(boxtype_name, "ini-1000de") == 0) 
		{
			boxtype_name = ReadProcEntry("/proc/stb/fp/version");
			if(startsWith(boxtype_name, "2"))
			{
				return "xpeedlx2";
			}
			else
			{
				return "xpeedlx1";
			}
		}
	}  
	else if(strcmp(BOXTYPE, "ventonhdx") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		if(strcmp(boxtype_name, "ini-3000") == 0) 
		{
			return "uniboxhd1";
		}
		else if(strcmp(boxtype_name, "ini-5000") == 0) 
		{
			return "uniboxhd2";
		}
		else if(strcmp(boxtype_name, "ini-7000") == 0) 
		{
			return "uniboxhd3";
		}
		else if(strcmp(boxtype_name, "ini-7012") == 0) 
		{
			return "uniboxhd3";
		}
	}
	else if(strcmp(BOXTYPE, "et6x00") == 0 || strcmp(BOXTYPE, "et9x00") == 0 || strcmp(BOXTYPE, "et7x00") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		return boxtype_name;
	}
	else
	{
		return BOXTYPE;  
	}
}

/** detecting real Box Name for OSD Translations
 */
const char *_getMachineName()
{
	char *boxtype_name = NULL;
	if(fileExist("/proc/stb/info/boxtype"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		/** INI DETECTION */
		if(strcmp(boxtype_name, "ini-3000") == 0) 
		{
			return "HD-1";
		}
		else if(strcmp(boxtype_name, "ini-5000") == 0) 
		{
			return "HD-2";
		}
		else if(strcmp(boxtype_name, "ini-7000") == 0) 
		{
			return "HD-3";
		}
		else if(strcmp(boxtype_name, "ini-7012") == 0) 
		{
			return "HD-3";
		}
		else if(strcmp(boxtype_name, "ini-1000lx") == 0) 
		{
			return "LX-2T";
		}
		/** XTREND DETECTION */
		else if(strcmp(boxtype_name, "et4x00") == 0) 
		{
			return "ET4x00";
		}
		else if(strcmp(boxtype_name, "et4000") == 0) 
		{
			return "ET4000";
		}
		else if(strcmp(boxtype_name, "et5x00") == 0) 
		{
			return "ET5x00";
		}
		else if(strcmp(boxtype_name, "et5000") == 0) 
		{
			return "ET5000";
		}		
		else if(strcmp(boxtype_name, "et6000") == 0) 
		{
			return "ET6000";
		}
		else if(strcmp(boxtype_name, "et6500") == 0) 
		{
			return "ET6500";
		}
		else if(strcmp(boxtype_name, "et7000") == 0) 
		{
			return "ET7000";
		}
		else if(strcmp(boxtype_name, "et7500") == 0) 
		{
			return "ET7500";
		}
		else if(strcmp(boxtype_name, "et9x00") == 0) 
		{
			return "ET9x00";
		}
		else if(strcmp(boxtype_name, "et9000") == 0) 
		{
			return "ET9000";
		}
		else if(strcmp(boxtype_name, "et9200") == 0) 
		{
			return "ET9200";
		}
		else if(strcmp(boxtype_name, "et9500") == 0) 
		{
			return "ET9500";
		}
		else /** if there is not matching STB name, return value from proc */
		{
			return MACHINE_NAME;
		}
	}
	/** AzBOX DETECTION */
	else if(fileExist("/proc/stb/info/azmodel"))
	{	
		if(fileExist("/proc/stb/info/model"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/model");
			if(strcmp(boxtype_name, "me") == 0) 
			{
				return "Me";
			}
			else if(strcmp(boxtype_name, "minime") == 0) 
			{
				return "Mini Me";
			}
			else if(strcmp(boxtype_name, "premium") == 0) 
			{
				return "Premium";
			}
			else if(strcmp(boxtype_name, "premium+") == 0) 
			{
				return "Premium+";
			}
			else if(strcmp(boxtype_name, "elite") == 0) 
			{
				return "Elite";
			}
			else if(strcmp(boxtype_name, "ultra") == 0) 
			{
				return "Ultra";
			}
			else
			{
				return MACHINE_NAME;
			}
		}
		else
		{
			return MACHINE_NAME;
		}
	}
	else
	{
		return MACHINE_NAME;
	}
}

const char *_getMachineBrand()
{
	char *boxtype_name = NULL;
	
	return MACHINE_BRAND;
}

const char *_getBrandOEM()
{
	return BRAND_OEM;  
}

const char *_getDriverDate()
{
	FILE *driver_file;
	int len = 0;
	char *real_driver_date = NULL;
	char driver_date[30];
	
	/** INI has in each driver build date - NO NEEED TAKE IT FROM BB FILE*/
	if((driver_file = fopen("/proc/stb/info/boxtype", "r")) != NULL) 
	{
		fgets(driver_date, sizeof(driver_date), driver_file);
		fclose(driver_file);
		
		if(startsWith(driver_date, "ini"))
		{
			if((driver_file = fopen("/proc/stb/info/version", "r")) != NULL)
			{
				fgets(driver_date, sizeof(driver_date), driver_file);
				fclose(driver_file);
				
				real_driver_date = malloc(strlen(driver_date) + 1);
				if (real_driver_date)
					strcpy(real_driver_date, driver_date);
				len = strlen(real_driver_date);
				if (len > 0 && real_driver_date[len - 1 ] == '\n')
					real_driver_date[len - 1] = '\0';                                
				return real_driver_date;
			}
			else
			{
				return DRIVERDATE;
			}
		}
		else // if it is not INI box, but use same proc entry, just return passed from BB drivers date
		{
			return DRIVERDATE;
		}
	}
	/** DAGS has in each driver build date - NO NEEED TAKE IT FROM BB FILE*/
	else if((driver_file = fopen("/proc/stb/info/hwmodel", "r")) != NULL)
	{
		fgets(driver_date, sizeof(driver_date), driver_file);
		fclose(driver_file);
		
		if((driver_file = fopen("/proc/stb/info/buildate", "r")) != NULL)
		{
			fgets(driver_date, sizeof(driver_date), driver_file);
			fclose(driver_file);
			
			real_driver_date = malloc(strlen(driver_date) + 1);
			if (real_driver_date)
				strcpy(real_driver_date, driver_date);
			len = strlen(real_driver_date);
			if (len > 0 && real_driver_date[len - 1 ] == '\n')
				real_driver_date[len - 1] = '\0';                                
			return real_driver_date;
		}
		else
		{
			return DRIVERDATE;
		}
	}
	else
	{  
		return DRIVERDATE;  
	}
}

const char *_getImageVersion()
{
	return IMAGEVERSION;
}

const char *_getImageBuild()
{
	return IMAGEBUILD;
}

const char *_getImageDistro()
{
	return DISTRO;
}

const char *_getImageFolder()
{
	return IMAGEDIR;
}

const char *_getImageFileSystem()
{
	return IMAGE_FSTYPES;
}

const char *_getOEVersion()
{
	return OE_VER;  
}

const char *_getMachineBuild()
{
	// this will return BUILD MACHINE e.x MACHINE=mbtwin DISTRO=openvix -> it will return inihdx
	return MACHINE_BUILD;
}

const char *_getMachineMake()
{
	// this will return MAKE MACHINE e.x MACHINE=mbtwin DISTRO=openvix -> it will return mbtwin
	return MACHINE_MAKE;
}

const char *_getMachineMtdRoot()
{
	return MTD_ROOTFS;
}

const char *_getMachineRootFile()
{
	return ROOTFS_FILE;
}

const char *_getMachineMtdKernel()
{
	return MTD_KERNEL;
}

const char *_getMachineKernelFile()
{
	return KERNEL_FILE;
}

const char *_getMachineMKUBIFS()
{
	return MKUBIFS_ARGS;
}

const char *_getMachineUBINIZE()
{
	return UBINIZE_ARGS;
}

const char *_getMachineProcModel() // return just value from proc entry
{
	FILE *boxtype_file;
	char boxtype_name[20];
	char *real_boxtype_name = NULL;
	char *vu_boxtype_name = NULL;
	int len;
	
	if((boxtype_file = fopen("/proc/stb/info/hwmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		
		real_boxtype_name = malloc(strlen(boxtype_name) + 1);
		if (real_boxtype_name)
			strcpy(real_boxtype_name, boxtype_name);
		len = strlen(real_boxtype_name);
		if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
			real_boxtype_name[len - 1] = '\0';                                
		return real_boxtype_name;
	}
	else if((boxtype_file = fopen("/proc/stb/info/boxtype", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		
		if(strcmp(boxtype_name, "gigablue\n") == 0)
		{
			if((boxtype_file = fopen("/proc/stb/info/boxtype", "r")) != NULL)
			{
				fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
				fclose(boxtype_file); 
				
				if((boxtype_file = fopen("/proc/stb/info/gbmodel", "r")) != NULL)
				{
					fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
					fclose(boxtype_file);  
					
				}
			}
		}
		real_boxtype_name = malloc(strlen(boxtype_name) + 1);
		if (real_boxtype_name)
			strcpy(real_boxtype_name, boxtype_name);
		len = strlen(real_boxtype_name);
		if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
			real_boxtype_name[len - 1] = '\0';                                
		return real_boxtype_name;
	}
	/** AzBOX DETECTION */
	else if((boxtype_file = fopen("/proc/stb/info/azmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 
		
		if((boxtype_file = fopen("/proc/stb/info/model", "r")) != NULL)
		{
			fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
			fclose(boxtype_file); 
			
			real_boxtype_name = malloc(strlen(boxtype_name) + 1);
			if (real_boxtype_name)
				strcpy(real_boxtype_name, boxtype_name);
			len = strlen(real_boxtype_name);
			if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
				real_boxtype_name[len - 1] = '\0';                                
			return real_boxtype_name;
		}
		else
		{
			return MACHINE_NAME;
		}
	}
	/** VU+ DETECTION */
	else if((boxtype_file = fopen("/proc/stb/info/vumodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		
		real_boxtype_name = malloc(strlen(boxtype_name) + 1);
		if (real_boxtype_name)
			strcpy(real_boxtype_name, boxtype_name);
		len = strlen(real_boxtype_name);
		if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
			real_boxtype_name[len - 1] = '\0';    
		
		sprintf(real_boxtype_name, "vu%s", boxtype_name);
		
		vu_boxtype_name = malloc(strlen(real_boxtype_name) + 1);
		if (vu_boxtype_name)
			strcpy(vu_boxtype_name, real_boxtype_name);
		len = strlen(vu_boxtype_name);
		if (len > 0 && vu_boxtype_name[len - 1 ] == '\n')
			vu_boxtype_name[len - 1] = '\0';
		return vu_boxtype_name;
	}
	/** DMM DETECTION */
	else
	{
		if((boxtype_file = fopen("/proc/stb/info/model", "r")) != NULL)
		{
			fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
			fclose(boxtype_file); 
			real_boxtype_name = malloc(strlen(boxtype_name) + 1);
			if (real_boxtype_name)
				strcpy(real_boxtype_name, boxtype_name);
			len = strlen(real_boxtype_name);
			if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
				real_boxtype_name[len - 1] = '\0';                                
			return real_boxtype_name;
		}
		else
		{
			return MACHINE_NAME;
		}
	}  
}
