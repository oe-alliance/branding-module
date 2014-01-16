#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Python.h>

const char* VERSION = "1.5";

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

const char *_getBoxType()
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
		
		return boxtype_name;
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
					
					return boxtype_name;
				}
				else
				{
					return "gb800solo"; /**no idea why they not put proc entry for this model, thats why it is always 800 Solo*/
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

/** detecting real Box Name for OSD Translations
 */
const char *_getMachineName()
{
	FILE *boxtype_file;
	char boxtype_name[20];
	
	if((boxtype_file = fopen("/proc/stb/info/hwmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		/**brand = "Technomate" "Edision" "Iqon" "Sogno"( not sure, just looked at Capitan Components/RCmodel.py) */
		if(strcmp(boxtype_name, "tmtwinoe\n") == 0) 
		{
			return "TM-TWIN-OE";
		}
		else if(strcmp(boxtype_name, "tm2toe\n") == 0) 
		{
			return "TM-2T-OE";
		}
		else if(strcmp(boxtype_name, "tmsingle\n") == 0) 
		{
			return "TM-SINGLE";
		}
		else if(strcmp(boxtype_name, "tmnanooe\n") == 0) 
		{
			return "TM-NANO-OE";
		}
		else if(strcmp(boxtype_name, "ios100hd\n") == 0) 
		{
			return "IOS-100HD";
		}
		else if(strcmp(boxtype_name, "ios200hd\n") == 0) 
		{
			return "IOS-200HD";
		}
		else if(strcmp(boxtype_name, "ios300hd\n") == 0) 
		{
			return "IOS-300HD";
		}
		else if(strcmp(boxtype_name, "optimussos1\n") == 0) 
		{
			return "Optimuss-OS1";
		} 
		else if(strcmp(boxtype_name, "optimussos2\n") == 0) 
		{
			return "Optimuss-OS2";
		}
		else if(strcmp(boxtype_name, "sogno-8800hd\n") == 0) 
		{
			return "8800-HD";
		}
	}
	else if((boxtype_file = fopen("/proc/stb/info/boxtype", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		
		/** GIGABLUE DETECTION */
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
					if(strcmp(boxtype_name, "gb800solo\n") == 0) 
					{
						return "800 Solo";
					}
					else if(strcmp(boxtype_name, "gb800se\n") == 0) 
					{
						return "800 Se";
					}
					else if(strcmp(boxtype_name, "gb800ue\n") == 0) 
					{
						return "800 Ue";
					}
					else if(strcmp(boxtype_name, "gbquad\n") == 0) 
					{
						return "Quad";
					}
					else if(strcmp(boxtype_name, "gb800seplus\n") == 0) 
					{
						return "800 Se Plus";
					}
					else if(strcmp(boxtype_name, "gb800ueplus\n") == 0) 
					{
						return "800 Ue Plus";
					}
					else if(strcmp(boxtype_name, "gbquadplus\n") == 0) 
					{
						return "Quad Plus";
					}
					else
					{
						return boxtype_name; /** if happens it is diffrent*/
					}
				}
				else
				{
					return "gb800solo"; /**no idea why they not put proc entry for this model, thats why it is always 800 Solo*/
				}
			}
		}
		/** INI DETECTION */
		else if(strcmp(boxtype_name, "ini-1000\n") == 0) 
		{
			return "HD-e";
		}
		else if(strcmp(boxtype_name, "ini-3000\n") == 0) 
		{
			return "HD-1";
		}
		else if(strcmp(boxtype_name, "ini-5000\n") == 0) 
		{
			return "HD-2";
		}
		else if(strcmp(boxtype_name, "ini-7000\n") == 0) 
		{
			return "HD-3";
		}
		else if(strcmp(boxtype_name, "ini-7012\n") == 0) 
		{
			return "HD-3";
		}
		else if(strcmp(boxtype_name, "ini-1000sv\n") == 0) 
		{
			return "Premium Mini";
		}
		else if(strcmp(boxtype_name, "ini-5000sv\n") == 0) 
		{
			return "Premium Twin";
		}
		else if(strcmp(boxtype_name, "ini-1000ru\n") == 0) 
		{
			return "HD-1000";
		} 
		else if(strcmp(boxtype_name, "ini-5000ru\n") == 0) 
		{
			return "HD-5000";
		}
		else if(strcmp(boxtype_name, "ini-9000ru\n") == 0) 
		{
			return "Marvel";
		}
		else if(strcmp(boxtype_name, "ini-1000de\n") == 0) 
		{
			return "Xpeed LX-x";
		}
		else if(strcmp(boxtype_name, "ini-9000de\n") == 0) 
		{
			return "Xpeed LX-3";
		}
		/** XP DETECTION */
		else if(strcmp(boxtype_name, "xp1000\n") == 0) 
		{
			return "XP-1000";
		}
		/** OCTAGON DETECTION */
		else if(strcmp(boxtype_name, "xp1000s\n") == 0) 
		{
			return "SF8 HD";
		}
		/** ODIN DETECTION */
		else if(strcmp(boxtype_name, "odinm9\n") == 0) 
		{
			return "M9";
		}
		else if(strcmp(boxtype_name, "odinm7\n") == 0) 
		{
			return "M7"; // And OEM: Optibox EVO, Galaxy Innovations Genius, Starsat LX, Opticum ax-odin, Axas Class M
		}
		else if(strcmp(boxtype_name, "e3hd\n") == 0) 
		{
			return "E3HD"; // And OEM: Optibox E3HD, Galaxy Innovations E3HD, Axas E3HD
		}		
		/** MIXoS DETECTION */
		else if(strcmp(boxtype_name, "ebox5000\n") == 0) 
		{
			return "F5"; // And OEM: Galaxy Innovations 9196m
		}
		else if(strcmp(boxtype_name, "ebox5100\n") == 0) 
		{
			return "F5mini"; // And OEM: Galaxy Innovations 9196 lite
		}
		else if(strcmp(boxtype_name, "ebox7358\n") == 0) 
		{
			return "F7";
		}
		/** IXUSS DETECTION */
		else if(strcmp(boxtype_name, "ixussone\n") == 0) 
		{
			return "One";
		}
		else if(strcmp(boxtype_name, "ixusszero\n") == 0) 
		{
			return "Zero";
		}
		/** XTREND DETECTION */
		else if(strcmp(boxtype_name, "et9x00\n") == 0) 
		{
			return "ET9x00";
		}
		else if(strcmp(boxtype_name, "et9000\n") == 0) 
		{
			return "ET9000";
		}
		else if(strcmp(boxtype_name, "et9200\n") == 0) 
		{
			return "ET9200";
		}
		else if(strcmp(boxtype_name, "et9500\n") == 0) 
		{
			return "ET9500";
		}
		else if(strcmp(boxtype_name, "et4x00\n") == 0) 
		{
			return "ET4x00";
		}
		else if(strcmp(boxtype_name, "et4000\n") == 0) 
		{
			return "ET4000";
		}
		else if(strcmp(boxtype_name, "et5x00\n") == 0) 
		{
			return "ET5x00";
		}
		else if(strcmp(boxtype_name, "et5000\n") == 0) 
		{
			return "ET5000";
		}		
		else if(strcmp(boxtype_name, "et6000\n") == 0) 
		{
			return "ET6000";
		}
		else if(strcmp(boxtype_name, "et6500\n") == 0) 
		{
			return "ET6500";
		}
		/** E2BMC ARM BOX */
		else if(strcmp(boxtype_name, "cube\n") == 0) 
		{
			return "Cube";
		}		
		else /** if there is not matching STB name, return value from proc */
		{
			return boxtype_name;
		}
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
			
			if(strcmp(boxtype_name, "me\n") == 0) 
			{
				return "Me";
			}
			else if(strcmp(boxtype_name, "minime\n") == 0) 
			{
				return "Mini Me";
			}
			else if(strcmp(boxtype_name, "premium\n") == 0) 
			{
				return "Premium";
			}
			else if(strcmp(boxtype_name, "premium+\n") == 0) 
			{
				return "Premium+";
			}
			else if(strcmp(boxtype_name, "elite\n") == 0) 
			{
				return "Elite";
			}
			else if(strcmp(boxtype_name, "ultra\n") == 0) 
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
	else if((boxtype_file = fopen("/proc/stb/info/vumodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 

		if(strcmp(boxtype_name, "solo\n") == 0) 
		{
			return "Solo";
		}
		else if(strcmp(boxtype_name, "duo\n") == 0) // should it be bm750 ???
		{
			return "Duo";
		}
		else if(strcmp(boxtype_name, "ultimo\n") == 0) 
		{
			return "Ultimo";
		}
		else if(strcmp(boxtype_name, "solo2\n") == 0) 
		{
			return "Solo²";
		}
		else if(strcmp(boxtype_name, "duo2\n") == 0) 
		{
			return "Duo²";
		}
		else
		{
			return MACHINE_NAME;
		}
	}
	/** DMM DETECTION */
	else
	{
		if((boxtype_file = fopen("/proc/stb/info/model", "r")) != NULL)
		{
			fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
			fclose(boxtype_file); 
			return boxtype_name;
		}
		else
		{
			return MACHINE_NAME;
		}
	}
}

/** detecting real Box Manufactuer for OSD Translations
 */
const char *_getBrand() // Unibox, Miraclebox, Sezam, GI, Octagon, Xtrend, Odin ??, Vu+, Dreambox, AZBox, Technomate
{
  	FILE *boxtype_file;
	char boxtype_name[20];

	// for OEM resellers
	if((boxtype_file = fopen("/proc/stb/info/boxtype", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);

		if ((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "de\n")))
		{
			return "GI";
		}
		else if((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "sv\n")))
		{
			return "Miraclebox";
		}
		else if((startsWith(boxtype_name, "ini")) && (endsWith(boxtype_name, "ru\n")))
		{
			return "Sezam";
		}
		else if(startsWith(boxtype_name, "ini"))
		{
			return "UNiBOX";
		}
		else if((strcmp(boxtype_name, "xp1000\n") == 0))
		{
			return "Max-Digital";
		}		
		else if((strcmp(boxtype_name, "xp1000s\n") == 0))
		{
			return "Octagon";
		}
		else if(startsWith(boxtype_name, "et"))
		{
			return "Xtrend";
		}
		else if((strcmp(boxtype_name, "gigablue\n") == 0))
		{
			return "GigaBlue";
		}
		else if(startsWith(boxtype_name, "e3hd"))
		{
			return "Odin"; // OEM: Optibox, Galaxy Innovations
		}		
		else if(startsWith(boxtype_name, "odin"))
		{
			return "Odin"; // OEM: Optibox, Galaxy Innovations, Starsat, Opticum, Axas
		}
		else if(startsWith(boxtype_name, "ebox"))
		{
			return "MixOS"; // OEM: Galaxy Innovations
		}		
		else if(startsWith(boxtype_name, "ixuss"))
		{
			return "Medi@link Ixuss";
		}
	}
	else if((boxtype_file = fopen("/proc/stb/info/hwmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
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
	else if((boxtype_file = fopen("/proc/stb/info/azmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 
		
		return "AZBox";
	}
	else if((boxtype_file = fopen("/proc/stb/info/vumodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 
		
		return "Vu+";
	}
	else
	{
		return "Dreambox";
	}
	return MACHINE_BRAND;
}

const char *_getOEM()
{
  	FILE *boxtype_file;
	char boxtype_name[20];

	// for OEM resellers
	if((boxtype_file = fopen("/proc/stb/info/boxtype", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);

		if(startsWith(boxtype_name, "ini"))
		{
			return "INI";
		}
		else if((strcmp(boxtype_name, "xp1000s\n") == 0) || (strcmp(boxtype_name, "xp1000\n") == 0))
		{
			return MACHINE_OEM;
		}
		else if(startsWith(boxtype_name, "et"))
		{
			return "Xtrend";
		}
		else if((strcmp(boxtype_name, "gigablue\n") == 0))
		{
			return "GIGA";
		}
		else if(startsWith(boxtype_name, "odin"))
		{
			return "Odin";
		}
		else if(startsWith(boxtype_name, "ebox"))
		{
			return "MixOS";
		}		
		else if(startsWith(boxtype_name, "ixuss"))
		{
			return "Medi@link";
		}
	}
	else if((boxtype_file = fopen("/proc/stb/info/hwmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file);
		
		return "DAGS";
	}
	else if((boxtype_file = fopen("/proc/stb/info/azmodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 
		
		return "OpenSAT";
	}
	else if((boxtype_file = fopen("/proc/stb/info/vumodel", "r")) != NULL)
	{
		fgets(boxtype_name, sizeof(boxtype_name), boxtype_file);
		fclose(boxtype_file); 
		
		return "Ceru";
	}
	else
	{
		return "Dream Multimedia";
	}
	return MACHINE_OEM;  
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

const char *_getVersion()
{
	return IMAGEVERSION;
}

const char *_getBuild()
{
	return IMAGEBUILD;
}

static PyObject* getBrand(PyObject* self)
{
    return Py_BuildValue("s", _getBrand());
}
 
static PyObject* getMachineName(PyObject* self)
{
    return Py_BuildValue("s", _getMachineName());
}

static PyObject* getBoxType(PyObject* self)
{
    return Py_BuildValue("s", _getBoxType());
}

static PyObject* getOEM(PyObject* self)
{
    return Py_BuildValue("s", _getOEM());
}

static PyObject* getDriverDate(PyObject* self)
{
    return Py_BuildValue("s", _getDriverDate());
}

static PyObject* getVersion(PyObject* self)
{
    return Py_BuildValue("s", _getVersion());
}

static PyObject* getBuild(PyObject* self)
{
    return Py_BuildValue("s", _getBuild());
}
static PyMethodDef boxbrandingMethods[] = {
		{ "getBrand", getBrand, METH_NOARGS },
		{ "getMachineName", getMachineName, METH_NOARGS },
		{ "getBoxType", getBoxType, METH_NOARGS },
		{ "getOEM", getOEM, METH_NOARGS },
		{ "getDriverDate", getDriverDate, METH_NOARGS },
		{ "getVersion", getVersion, METH_NOARGS },
		{ "getBuild", getBuild, METH_NOARGS },
		{ NULL, NULL }
};

void initboxbranding() {
	PyObject *m;
	m = Py_InitModule("boxbranding", boxbrandingMethods);
}