from boxbranding import getBoxType, getMachineBrand, getMachineBuild
from Tools.StbHardware import getFPVersion
import os

class RcModel:
	def __init__(self):
		pass

	def rcIsDefault(self):
		if self.getRcFolder() != 'dmm0':
			return False
		return True

	def readFile(self, target):
		fp = open(target, 'r')
		out = fp.read()
		fp.close()
		return out.split()[0]

	def getRcFolder(self):
		remotefolder = 'dmm0'
		if os.path.exists('/proc/stb/info/azmodel'):
			f = open("/proc/stb/info/model",'r')
			model = f.readline().strip()
			f.close()
			if model == "premium" or model == "premium+":
				remotefolder = 'azboxhd'
			elif model == "elite" or model == "ultra":
				remotefolder = 'azboxelite'
			elif model == "me" or model == "minime":
				remotefolder = 'azboxme'

		elif getMachineBrand() == 'EVO':
			remotefolder = 'evo'
		elif getMachineBrand() == 'VisionNet':
			remotefolder = 'visionnet'			
		elif getBoxType() in ('gbquad', 'gb800se', 'gb800ue', 'gb800solo', 'gb800seplus', 'gb800ueplus', 'gbipbox'):
			remotefolder = 'gb0'
		elif getBoxType() == 'gbquadplus':
			remotefolder = 'gb1'
		elif getBoxType() in ('mutant2400'):
			remotefolder = 'hd2400'
		elif getMachineBrand() == 'Jepssen':
			remotefolder = 'mediabox'
		elif getBoxType() in ('iqonios100hd', 'iqonios200hd', 'iqonios300hd', 'roxxs200hd', 'mediaart200hd'):
			remotefolder = 'iqon1'
		elif getBoxType() in ('force1'):
			remotefolder = 'iqon2'
		elif getBoxType() == 'formuler1':
			remotefolder = 'formuler1'
		elif getBoxType() == 'dm8000':
			remotefolder = 'dmm0'
		elif getBoxType() in ('dm800', 'dm800se', 'dm500hd'):
			remotefolder = 'dmm1'
		elif getBoxType() in ('dm7020hd', 'dm7020hdv2', 'dm800sev2', 'dm500hdv2'):
			remotefolder = 'dmm2'
		elif getBoxType() in ('tmtwin', 'tm2t'):
			remotefolder = 'tm1'
		elif getBoxType() in ('tmsingle', 'tmnano', 'tmnano2t', 'tmnano2super'):
			remotefolder = 'tm2'
		elif getBoxType() == 'uniboxhd1':
			fp_version = str(getFPVersion())
			if fp_version.startswith('1'):
				remotefolder = 'ini0'
			else:
				remotefolder = 'ini2'
		elif getBoxType() in ('uniboxhd2', 'uniboxhd3'):
			remotefolder = 'ini1'
		elif getBoxType() == 'uniboxhde':
			remotefolder = 'uniboxhde'
		elif getBoxType() in ('sezam1000hd', 'sezam5000hd'):
			remotefolder = 'ini2'
		elif getMachineBrand() == 'Miraclebox': 
			remotefolder = 'ini3'
		elif getMachineBrand() in ('GI', 'Atemio') or getBoxType() in ('sezammarvel'):
			remotefolder = 'ini4'
		elif getBoxType() == 'beyonwizt3':
			remotefolder = 'ini5'
		elif getBoxType() in ('optimussos1', 'optimussos2', 'optimussos1plus', 'optimussos2plus'):
			remotefolder = 'optimuss'
		elif getBoxType() == 'sogno8800hd':
			remotefolder = 'sogno'
		elif getBoxType() in ('et4x00'):
			remotefolder = 'et4x00'
		elif getBoxType() in ('et6x00', 'et6000', 'et5x00', 'et5000'):
			remotefolder = 'et6x00'
		elif getBoxType() == 'et6500':
			remotefolder = 'et6500'
		elif getBoxType() in ('et8000', 'et10000'):
			remotefolder = 'et8000'
		elif getBoxType() in ('et9000', 'et9x00', 'et9200'):
			remotefolder = 'et9x00'
		elif getBoxType() in ('et9500'):
			remotefolder = 'et9500'
		elif getBoxType() in ('vusolo', 'vusolo2', 'vusolose', 'vuduo', 'vuuno'):
			remotefolder = 'vu'
		elif getBoxType() == 'vuultimo':
			remotefolder = 'vu2'
		elif getBoxType() == 'vuduo2':
			remotefolder = 'vu3'
		elif getBoxType() in ('starsatlx', 'axodin', 'axodinc', 'odinm6'):
			remotefolder = 'odinm6'
		elif getBoxType() in ('ixussone'):
			remotefolder = 'ixussone'
		elif getBoxType() in ('ixusszero'):
			emotefolder = 'ixusszero'
		elif getMachineBuild() == 'cube':
			remotefolder = 'cube'
		elif getMachineBuild().startswith('ebox'):
			remotefolder = 'ebox5000'
		elif getMachineBuild() == 'e3hd':
			remotefolder = 'e3hd'
		elif getMachineBuild() == 'odinm7':
			remotefolder = 'odinm7'
		elif getMachineBuild() == 'odinm9':
			remotefolder = 'odinm9'
		elif getMachineBuild() == 'xp1000':
			remotefolder = 'xp1000'

		return remotefolder
		
	def getRcLocation(self):
		baselocation = '/usr/share/enigma2/rc_models/'
		remotefolder = self.getRcFolder()
		return baselocation + remotefolder + '/'

rc_model = RcModel()
