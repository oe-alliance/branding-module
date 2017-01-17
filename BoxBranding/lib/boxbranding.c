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
 * This function allocates memory for the returned string.
 * The caller must call free() to prevent memory leaks.
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

char *_getBoxType()	// this will try to find the correct BOX MACHINE e.x MACHINE=ventonhdx DISTRO=openvix -> it will return uniboxhd1   for a UniBox HD1
{
	// this ugly code will be removed after we will switch tottaly to OE-A 2.0
	char *boxtype_name = NULL;

	if(strcmp(BOXTYPE, "xpeedlx") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		if(strcmp(boxtype_name, "ini-1000lx") == 0)
		{
			free(boxtype_name);
			return strdup("xpeedlx2t");
		}
		else if(strcmp(boxtype_name, "ini-1000de") == 0)
		{
			free(boxtype_name);
			boxtype_name = ReadProcEntry("/proc/stb/fp/version");
			if(startsWith(boxtype_name, "2"))
			{
				free(boxtype_name);
				return strdup("xpeedlx2");
			}
			else
			{
				free(boxtype_name);
				return strdup("xpeedlx1");
			}
		}
	}
	else if(strcmp(BOXTYPE, "twinboxlcd") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		if(strcmp(boxtype_name, "7200S") == 0)
		{
			free(boxtype_name);
			return strdup("twinboxlcdci");
		}
	}
	else if(strcmp(BOXTYPE, "ventonhdx") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		if(strcmp(boxtype_name, "ini-3000") == 0)
		{
			free(boxtype_name);
			return strdup("uniboxhd1");
		}
		else if(strcmp(boxtype_name, "ini-5000") == 0)
		{
			free(boxtype_name);
			return strdup("uniboxhd2");
		}
		else if(strcmp(boxtype_name, "ini-7000") == 0)
		{
			free(boxtype_name);
			return strdup("uniboxhd3");
		}
		else if(strcmp(boxtype_name, "ini-7012") == 0)
		{
			free(boxtype_name);
			return strdup("uniboxhd3");
		}
	}
	else if(strcmp(BOXTYPE, "et7x00") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/chipset");
		if(startsWith(boxtype_name, "bcm73625"))
		{
			free(boxtype_name);
			return strdup("et7100");
		}
		else
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
			return boxtype_name;
		}
	}
	else if(strcmp(BOXTYPE, "et6x00") == 0 || strcmp(BOXTYPE, "et9x00") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		return boxtype_name;
	}
	else if(strcmp(BOXTYPE, "dm520") == 0)
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/model");
		if(strcmp(boxtype_name, "dm525") == 0)
		{
			free(boxtype_name);
			return strdup("dm525");
		}
		else
		{
			free(boxtype_name);
			return strdup(BOXTYPE);
		}
	}
	return strdup(BOXTYPE);
}

/** detecting real Box Name for OSD Translations
 */
char *_getMachineName()
{
	char *boxtype_name = NULL;
	if(fileExist("/proc/stb/info/boxtype"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		/** INI DETECTION */
		if(strcmp(boxtype_name, "ini-3000") == 0)
		{
			free(boxtype_name);
			return strdup("HD-1");
		}
		else if(strcmp(boxtype_name, "ini-5000") == 0)
		{
			free(boxtype_name);
			return strdup("HD-2");
		}
		else if(strcmp(boxtype_name, "ini-7000") == 0)
		{
			free(boxtype_name);
			return strdup("HD-3");
		}
		else if(strcmp(boxtype_name, "ini-7012") == 0)
		{
			free(boxtype_name);
			return strdup("HD-3");
		}
		else if(strcmp(boxtype_name, "ini-1000lx") == 0)
		{
			free(boxtype_name);
			return strdup("LX-2T");
		}
		/** XTREND DETECTION */
		else if(strcmp(boxtype_name, "et4x00") == 0)
		{
			free(boxtype_name);
			return strdup("ET4x00");
		}
		else if(strcmp(boxtype_name, "et4000") == 0)
		{
			free(boxtype_name);
			return strdup("ET4000");
		}
		else if(strcmp(boxtype_name, "et5x00") == 0)
		{
			free(boxtype_name);
			return strdup("ET5x00");
		}
		else if(strcmp(boxtype_name, "et5000") == 0)
		{
			free(boxtype_name);
			return strdup("ET5000");
		}
		else if(strcmp(boxtype_name, "et6000") == 0)
		{
			free(boxtype_name);
			return strdup("ET6000");
		}
		else if(strcmp(boxtype_name, "et6500") == 0)
		{
			free(boxtype_name);
			return strdup("ET6500");
		}
		else if(strcmp(boxtype_name, "et7000") == 0)
		{
			free(boxtype_name);
			boxtype_name = ReadProcEntry("/proc/stb/info/chipset");
			if(startsWith(boxtype_name, "bcm73625"))
			{
				free(boxtype_name);
				return strdup("ET7100");
			}
			else
			{
				free(boxtype_name);
				return strdup("ET7000");
			}
		}
		else if(strcmp(boxtype_name, "et7500") == 0)
		{
			free(boxtype_name);
			return strdup("ET7500");
		}
		else if(strcmp(boxtype_name, "et9x00") == 0)
		{
			free(boxtype_name);
			return strdup("ET9x00");
		}
		else if(strcmp(boxtype_name, "et9000") == 0)
		{
			free(boxtype_name);
			return strdup("ET9000");
		}
		else if(strcmp(boxtype_name, "et9200") == 0)
		{
			free(boxtype_name);
			return strdup("ET9200");
		}
		else if(strcmp(boxtype_name, "et9500") == 0)
		{
			free(boxtype_name);
			return strdup("ET9500");
		}
		else if(strcmp(BOXTYPE, "twinboxlcd") == 0)
		{
			if(strcmp(boxtype_name, "7200S") == 0)
			{
				free(boxtype_name);
				return strdup("TWINBOX LCD CI");
			}
		}
		else /** if there is not matching STB name, return value from proc */
		{
			/*
			 * TODO: The comment above and the code disagree.
			 *
			 * Which should it be? Right now it's the compile time string supplied via configure.
			 */
			free(boxtype_name);
			return strdup(MACHINE_NAME);
		}
	}
	/** AzBOX DETECTION */
	else if (fileExist("/proc/stb/info/azmodel") && fileExist("/proc/stb/info/model"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/model");
		if(strcmp(boxtype_name, "me") == 0)
		{
			free(boxtype_name);
			return strdup("Me");
		}
		else if(strcmp(boxtype_name, "minime") == 0)
		{
			free(boxtype_name);
			return strdup("Mini Me");
		}
		else if(strcmp(boxtype_name, "premium") == 0)
		{
			free(boxtype_name);
			return strdup("Premium");
		}
		else if(strcmp(boxtype_name, "premium+") == 0)
		{
			free(boxtype_name);
			return strdup("Premium+");
		}
		else if(strcmp(boxtype_name, "elite") == 0)
		{
			free(boxtype_name);
			return strdup("Elite");
		}
		else if(strcmp(boxtype_name, "ultra") == 0)
		{
			free(boxtype_name);
			return strdup("Ultra");
		}
		else
		{
			free(boxtype_name);
		}
	}
	else if (fileExist("/proc/stb/info/model"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/model");
		if(strcmp(boxtype_name, "dm525") == 0)
		{
			free(boxtype_name);
			return strdup("DM525");
		}
		else
		{
			free(boxtype_name);
			return strdup(MACHINE_NAME);
		}
	}
	return strdup(MACHINE_NAME);
}

char *_getMachineBrand()
{
	return strdup(MACHINE_BRAND);
}

char *_getBrandOEM()
{
	return strdup(BRAND_OEM);
}

char *_getDriverDate()
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
				return strdup(DRIVERDATE);
			}
		}
		else // if it is not INI box, but use same proc entry, just return passed from BB drivers date
		{
			return strdup(DRIVERDATE);
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
			return strdup(DRIVERDATE);
		}
	}
	else
	{
		return strdup(DRIVERDATE);
	}
}

char *_getImageVersion()
{
	return strdup(IMAGEVERSION);
}

char *_getImageBuild()
{
	return strdup(IMAGEBUILD);
}

char *_getImageDevBuild()
{
	return strdup(IMAGEDEVBUILD);
}

char *_getImageType()
{
	return strdup(DISTRO_TYPE);
}

char *_getImageArch()
{
	return strdup(ARCH_TYPE);
}

char *_getImageDistro()
{
	return strdup(DISTRO);
}

char *_getFeedsUrl()
{
	return strdup(FEEDSURL);
}

char *_getImageFolder()
{
	return strdup(IMAGEDIR);
}

char *_getImageFileSystem()
{
	return strdup(IMAGE_FSTYPES);
}

char *_getOEVersion()
{
	return strdup(OE_VER);
}

char *_getMachineBuild()
{
	// this will return BUILD MACHINE e.x MACHINE=mbtwin DISTRO=openvix -> it will return inihdx
	return strdup(MACHINE_BUILD);
}

char *_getMachineMake()
{
	// this will return MAKE MACHINE e.x MACHINE=mbtwin DISTRO=openvix -> it will return mbtwin
	return strdup(MACHINE_MAKE);
}

char *_getMachineMtdRoot()
{
	return strdup(MTD_ROOTFS);
}

char *_getMachineRootFile()
{
	return strdup(ROOTFS_FILE);
}

char *_getMachineMtdKernel()
{
	return strdup(MTD_KERNEL);
}

char *_getMachineKernelFile()
{
	return strdup(KERNEL_FILE);
}

char *_getMachineMKUBIFS()
{
	return strdup(MKUBIFS_ARGS);
}

char *_getMachineUBINIZE()
{
	return strdup(UBINIZE_ARGS);
}

char *_getMachineProcModel() // return just value from proc entry
{
	FILE *boxtype_file;
	char boxtype_name[20];
	char *real_boxtype_name = NULL;
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
			return strdup(MACHINE_NAME);
		}
	}
	/** VU+ DETECTION */
	else if((boxtype_file = fopen("/proc/stb/info/vumodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);

		real_boxtype_name = malloc(strlen(boxtype_name) + 3);
		if (real_boxtype_name)
			sprintf(real_boxtype_name, "vu%s", boxtype_name);
		len = strlen(real_boxtype_name);
		if (len > 0 && real_boxtype_name[len - 1 ] == '\n')
			real_boxtype_name[len - 1] = '\0';
		return real_boxtype_name;
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
	}
	return strdup(MACHINE_NAME);
}
