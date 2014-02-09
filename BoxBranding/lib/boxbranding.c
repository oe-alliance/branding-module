#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <Python.h>

const char* VERSION = "2.1";

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

const char *_getBoxType()
{
	// this ugly code will be removed after we will switch tottaly to OE-A 2.0
	char *boxtype_name = NULL;
	char *vu_boxtype_name = NULL;
	
	if(strcmp(OE_VER, "OE-Alliance 2.0") == 0)
	{  
		if(strcmp(BOXTYPE, "xpeedlx") == 0)
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
		else
		{
			return BOXTYPE;  
		}
	}
	else
	{		
		if(fileExist("/proc/stb/info/hwmodel"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/hwmodel");                               
			return boxtype_name;
		}
		/** Gigablue DETECTION */
		else if(fileExist("/proc/stb/info/gbmodel"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/gbmodel");
			return boxtype_name;
		}
		/** Xtrend and other DETECTION */
		else if(fileExist("/proc/stb/info/boxtype"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
			if(strcmp(boxtype_name, "Ixuss One") == 0) 
			{
				return "Ixuss One";
			}
			else if(strcmp(boxtype_name, "Ixuss Zero") == 0) 
			{
				return "Ixuss Zero";
			}
			return boxtype_name;
		}
		/** AzBOX DETECTION */
		else if(fileExist("/proc/stb/info/azmodel"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/model");
			return boxtype_name;
		}
		/** VU+ DETECTION */
		else if(fileExist("/proc/stb/info/vumodel"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/vumodel");
			vu_boxtype_name = malloc(strlen(boxtype_name) + 1);
			sprintf(vu_boxtype_name, "vu%s", boxtype_name);
			return vu_boxtype_name;
		}
		/** DMM DETECTION */
		else if(fileExist("/proc/stb/info/model"))
		{
			boxtype_name = ReadProcEntry("/proc/stb/info/model");
			return boxtype_name;
		}
		else
		{
			return MACHINE_NAME;
		}
	}
}

/** detecting real Box Name for OSD Translations
 */
const char *_getMachineName()
{
	char *boxtype_name = NULL;
	if(fileExist("/proc/stb/info/hwmodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/hwmodel");
		/**brand = "Technomate" "Edision" "Iqon" "Sogno"( not sure, just looked at Capitan Components/RCmodel.py) */
		if(strcmp(boxtype_name, "tmtwinoe") == 0)
		{
			return "TM-TWIN-OE";
		}
		else if(strcmp(boxtype_name, "tm2toe") == 0)
		{
			return "TM-2T-OE";
		}
		else if(strcmp(boxtype_name, "tmsingle") == 0)
		{
			return "TM-SINGLE";
		}
		else if(strcmp(boxtype_name, "tmnanooe") == 0)
		{
			return "TM-NANO-OE";
		}
		else if(strcmp(boxtype_name, "tmnano2t") == 0)
		{
			return "TM-NANO-2T-OE";
		}		
		else if(strcmp(boxtype_name, "ios100hd") == 0)
		{
			return "IOS-100HD";
		}
		else if(strcmp(boxtype_name, "ios200hd") == 0)
		{
			return "IOS-200HD";
		}
		else if(strcmp(boxtype_name, "ios300hd") == 0)
		{
			return "IOS-300HD";
		}
		else if(strcmp(boxtype_name, "optimussos1") == 0)
		{
			return "Optimuss-OS1";
		} 
		else if(strcmp(boxtype_name, "optimussos2") == 0)
		{
			return "Optimuss-OS2";
		}
		else if(strcmp(boxtype_name, "optimussos2") == 0)
		{
			return "Roxxs-200HD";
		}
		else if(strcmp(boxtype_name, "mediabox") == 0)
		{
			return "MediaBox-HD-LX";
		}		
		else if(strcmp(boxtype_name, "sogno-8800hd") == 0) 
		{
			return "8800-HD";
		}
		else
		{
			return boxtype_name; /** if happens it is diffrent*/
		}		
	}
	/** GIGABLUE DETECTION */
	else if(fileExist("/proc/stb/info/gbmodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/gbmodel");
		if(strcmp(boxtype_name, "gb800solo") == 0) 
		{
			return "800 Solo";
		}
		else if(strcmp(boxtype_name, "gb800se") == 0) 
		{
			return "800 SE";
		}
		else if(strcmp(boxtype_name, "gb800ue") == 0) 
		{
			return "800 UE";
		}
		else if(strcmp(boxtype_name, "gbquad") == 0) 
		{
			return "Quad";
		}
		else if(strcmp(boxtype_name, "gb800seplus") == 0) 
		{
			return "800 SE Plus";
		}
		else if(strcmp(boxtype_name, "gb800ueplus") == 0) 
		{
			return "800 UE Plus";
		}
		else if(strcmp(boxtype_name, "gbquadplus") == 0) 
		{
			return "Quad Plus";
		}
		else
		{
			return boxtype_name; /** if happens it is diffrent*/
		}
	}
	else if(fileExist("/proc/stb/info/boxtype"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype");
		/** INI DETECTION */
		if(strcmp(boxtype_name, "ini-1000") == 0) 
		{
			return "HD-e";
		}
		else if(strcmp(boxtype_name, "ini-3000") == 0) 
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
		else if(strcmp(boxtype_name, "ini-1000sv") == 0) 
		{
			return "Premium Mini";
		}
		else if(strcmp(boxtype_name, "ini-5000sv") == 0) 
		{
			return "Premium Twin";
		}
		else if(strcmp(boxtype_name, "ini-1000ru") == 0) 
		{
			return "HD-1000";
		} 
		else if(strcmp(boxtype_name, "ini-5000ru") == 0) 
		{
			return "HD-5000";
		}
		else if(strcmp(boxtype_name, "ini-9000ru") == 0) 
		{
			return "Marvel";
		}
		else if(strcmp(boxtype_name, "ini-1000de") == 0) 
		{
			return "Xpeed LX-x";
		}
		else if(strcmp(boxtype_name, "ini-9000de") == 0) 
		{
			return "Xpeed LX-3";
		}
		/** XP DETECTION */
		else if(strcmp(boxtype_name, "xp1000") == 0) 
		{
			return "XP-1000";
		}
		/** OCTAGON DETECTION */
		else if(strcmp(boxtype_name, "xp1000s") == 0) 
		{
			return "SF8 HD";
		}
		/** ODIN DETECTION */
		else if(strcmp(boxtype_name, "odinm9") == 0) 
		{
			return MACHINE_NAME;
		}
		else if(strcmp(boxtype_name, "odinm7") == 0) 
		{
			return MACHINE_NAME; // And OEM: Optibox EVO, Galaxy Innovations Genius, Starsat LX, Opticum ax-odin, Axas Class M
		}
		else if(strcmp(boxtype_name, "e3hd") == 0) 
		{
			return MACHINE_NAME; // And OEM: Optibox E3HD, Galaxy Innovations E3HD, Axas E3HD
		}		
		/** MIXoS DETECTION */
		else if(strcmp(boxtype_name, "ebox5000") == 0) 
		{
			return MACHINE_NAME; // And OEM: Galaxy Innovations 9196m
		}
		else if(strcmp(boxtype_name, "ebox5100") == 0) 
		{
			return MACHINE_NAME; // And OEM: Galaxy Innovations 9196 lite
		}
		else if(strcmp(boxtype_name, "eboxlumi") == 0) 
		{
			return MACHINE_NAME;
		}		
		else if(strcmp(boxtype_name, "ebox7358") == 0) 
		{
			return MACHINE_NAME;
		}
		/** IXUSS DETECTION */
		else if(strcmp(boxtype_name, "Ixuss One") == 0) 
		{
			return "One";
		}
		else if(strcmp(boxtype_name, "Ixuss Zero") == 0) 
		{
			return "Zero";
		}
		/** XTREND DETECTION */
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
		/** E2BMC ARM BOX */
		else if(strcmp(boxtype_name, "cube") == 0) 
		{
			return "Cube";
		}		
		else /** if there is not matching STB name, return value from proc */
		{
			return boxtype_name;
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
	/** VU+ DETECTION */
	else if(fileExist("/proc/stb/info/vumodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/vumodel");
		if(strcmp(boxtype_name, "solo") == 0) 
		{
			return "Solo";
		}
		else if(strcmp(boxtype_name, "duo") == 0)
		{
			return "Duo";
		}
		else if(strcmp(boxtype_name, "ultimo") == 0) 
		{
			return "Ultimo";
		}
		else if(strcmp(boxtype_name, "solo2") == 0) 
		{
			return "Solo²";
		}
		else if(strcmp(boxtype_name, "duo2") == 0) 
		{
			return "Duo²";
		}
		else
		{
			return MACHINE_NAME;
		}
	}
	/** DMM DETECTION */
	else if (fileExist("/proc/stb/info/model"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/model"); 
		return boxtype_name;
	}
	else
	{
		return MACHINE_NAME;
	}
}

/** detecting real Box Manufactuer for OSD Translations
 */
const char *_getMachineBrand() // Unibox, Miraclebox, Sezam, GI, Octagon, Xtrend, Odin ??, Vu+, Dreambox, AZBox, Technomate
{
	char *boxtype_name = NULL;
	
	// for OEM resellers
	if(fileExist("/proc/stb/info/boxtype"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/boxtype"); 
		if ((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "de")))
		{
			return "GI";
		}
		else if((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "sv")))
		{
			return "Miraclebox";
		}
		else if((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "ru")))
		{
			return "Sezam";
		}
		else if(startsWith(boxtype_name, "ini"))
		{
			return "UNiBOX";
		}
		else if((strcmp(boxtype_name, "xp1000") == 0))
		{
			return MACHINE_BRAND; // OEM: MK-Digital, MAX-Digital
		}		
		else if((strcmp(boxtype_name, "xp1000s") == 0))
		{
			return "Octagon";
		}
		else if(startsWith(boxtype_name, "et"))
		{
			return "Xtrend";
		}
		else if((strcmp(boxtype_name, "gigablue") == 0))
		{
			return "GigaBlue";
		}
		else if(startsWith(boxtype_name, "e3hd"))
		{
			return MACHINE_BRAND; // OEM: Optibox, Galaxy Innovations
		}		
		else if(startsWith(boxtype_name, "odin"))
		{
			return MACHINE_BRAND; // OEM: Optibox, Galaxy Innovations, Starsat, Opticum, Axas
		}
		else if(startsWith(boxtype_name, "ebox"))
		{
			return MACHINE_BRAND; // OEM: Mixos, Galaxy Innovations
		}		
		else if(startsWith(boxtype_name, "ixuss"))
		{
			return "Medi@link Ixuss";
		}
	}
	else if(fileExist("/proc/stb/info/hwmodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/hwmodel"); 
		/**brand = "Technomate" "Edision" "Iqon" "Sogno"( not sure, just looked at Capitan Components/RCmodel.py) */
		if(startsWith(boxtype_name, "tm"))
		{
			return "Technomate";
		}
		else if(startsWith(boxtype_name, "ios"))
		{
			return "Iqon";
		}
		else if(startsWith(boxtype_name, "optimuss"))
		{
			return "Edison";
		}
		else if(startsWith(boxtype_name, "sogno")) 
		{
			return "Sogno";
		}
	}
	else if(fileExist("/proc/stb/info/azmodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/azmodel"); 
		return "AZBox";
	}
	else if(fileExist("/proc/stb/info/vumodel"))
	{
		boxtype_name = ReadProcEntry("/proc/stb/info/vumodel"); 
		return "Vu+";
	}
	else
	{
		return "Dreambox";
	}
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

const char *_getOEVersion()
{
	return OE_VER;  
}

const char *_getMachineBuild()
{
	// this will return real MACHINEBUILD e.x MACHINE=mbtwin DISTRO=vix -> it will return mbtwin
	return BOXTYPE;
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

static PyObject* getMachineProcModel(PyObject* self)
{
    return Py_BuildValue("s", _getMachineProcModel());
}

static PyObject* getMachineBrand(PyObject* self)
{
    return Py_BuildValue("s", _getMachineBrand());
}
 
static PyObject* getMachineName(PyObject* self)
{
    return Py_BuildValue("s", _getMachineName());
}

static PyObject* getMachineBuild(PyObject* self)
{
    return Py_BuildValue("s", _getMachineBuild());
}

static PyObject* getBoxType(PyObject* self)
{
    return Py_BuildValue("s", _getBoxType());
}

static PyObject* getBrandOEM(PyObject* self)
{
    return Py_BuildValue("s", _getBrandOEM());
}

static PyObject* getOEVersion(PyObject* self)
{
    return Py_BuildValue("s", _getOEVersion());
}

static PyObject* getDriverDate(PyObject* self)
{
    return Py_BuildValue("s", _getDriverDate());
}

static PyObject* getImageVersion(PyObject* self)
{
    return Py_BuildValue("s", _getImageVersion());
}

static PyObject* getImageBuild(PyObject* self)
{
    return Py_BuildValue("s", _getImageBuild());
}

static PyObject* getImageDistro(PyObject* self)
{
    return Py_BuildValue("s", _getImageDistro());
}

static PyMethodDef boxbrandingMethods[] = {
		{ "getMachineBuild", getMachineBuild, METH_NOARGS },
		{ "getMachineProcModel", getMachineProcModel, METH_NOARGS },  
		{ "getMachineBrand", getMachineBrand, METH_NOARGS },
		{ "getMachineName", getMachineName, METH_NOARGS },
		{ "getBoxType", getBoxType, METH_NOARGS },
		{ "getBrandOEM", getBrandOEM, METH_NOARGS },
		{ "getOEVersion", getOEVersion, METH_NOARGS },
		{ "getDriverDate", getDriverDate, METH_NOARGS },
		{ "getImageVersion", getImageVersion, METH_NOARGS },
		{ "getImageBuild", getImageBuild, METH_NOARGS },
		{ "getImageDistro", getImageDistro, METH_NOARGS },
		{ NULL, NULL }
};

void initboxbranding() {
	PyObject *m;
	m = Py_InitModule("boxbranding", boxbrandingMethods);
}